#include <stdint.h>

struct gpio {
    volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR,
        AFR[2];
};

#define GPIOA ((struct gpio *)0x40020000)

// Enum values are per datasheet: 0, 1, 2, 3
enum { GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG };

static inline void gpio_set_mode(struct gpio *gpio, uint8_t pin, uint8_t mode) {
    gpio->MODER &= ~(3U << (pin * 2));      // Clear existing setting
    gpio->MODER |= (mode & 3) << (pin * 2); // Set new mode
}
