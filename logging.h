/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (C) 2019-2020, Raspberry Pi (Trading) Limited
 *
 * logging.h - logging macros
 */
#pragma once

#include <stdio.h>

#ifndef V4L2_LOGGING_ENABLE
#define V4L2_LOGGING_ENABLE 1
#endif

#ifndef V4L2_WARNING_ENABLE
#define V4L2_WARNING_ENABLE 1
#endif

#define V4L2_LOG(M, ...)                                                       \
    do {                                                                       \
        if (V4L2_LOGGING_ENABLE)                                               \
            printf("%s ," M "\n", __FUNCTION__, ##__VA_ARGS__);                \
    } while (0)

#define V4L2_WARN(M, ...)                                                      \
    do {                                                                       \
        if (V4L2_WARNING_ENABLE)                                               \
            printf("%s ***WARNING*** " M "\n", __FUNCTION__, ##__VA_ARGS__);   \
    } while (0)

#define ASSERT(condition)                                                      \
    do {                                                                       \
        if (!(condition))                                                      \
            V4L2_WARN("assertion \"" #condition "\" failed");                  \
    } while (0)
