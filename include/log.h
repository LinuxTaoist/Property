/*
********************************************************************************
* @copyright 2020 Shenzhen Chuangwei-RGB Electronics Co.,Ltd.
* File Name   : log.h
* Author      :
* Version     : V1.0
* Description : Log file
* Journal     : 2020-10-19 init v1.0
* brief       :
* Others      :
********************************************************************************
*/

#ifndef __LOG_H__
#define __LOG_H__

#include <string.h>

#define TEST_GREEN "\033[1;49;32m"
#define TEST_RED   "\033[1;49;31m"
#define TEST_YELLOW "\033[1;49;33m"
#define TEST_NORMAL "\033[0m"

#define DEBUG_LOG_SUPPORT

#define filename(x) strrchr(x,'/')?strrchr(x,'/')+1:x

#define PRINT_ERR(format,x...)    \
do{ printf( "[%sERROR%s] [%s:%d] [%s] info: " format, TEST_RED, TEST_NORMAL,    \
                        filename(__FILE__), __LINE__, __func__, ## x); }while(0)

#define PRINT_WARN(format,x...)    \
do{ printf( "[%sWARN%s] [%s:%d] [%s] info: " format, TEST_YELLOW, TEST_NORMAL,  \
                     filename(__FILE__), __LINE__, __func__, ## x); }while(0)

#define PRINT_INFO(format, x...)   \
do{ printf(format,##x); }while(0)

#ifdef DEBUG_LOG_SUPPORT
#define PRINT_DEBUG(format,x...)  \
do{ printf("[%sDEBUG%s] [%s:%d] [%s] info: " format, TEST_GREEN, TEST_NORMAL,   \
                     filename(__FILE__), __LINE__, __func__, ## x); }while(0)
#else
#define PRINT_DEBUG(format,x...)
#endif

#ifdef MIDDLE_DEBUG_PATH
#undef MIDDLE_DEBUG_PATH
#endif
#define MIDDLE_DEBUG_PATH  "/tmp/debug_print1"

#ifdef PRINT_TO_FILE
#undef PRINT_TO_FILE
#endif
#define PRINT_TO_FILE(str)                                    \
do {                                                          \
    FILE *fd = NULL;                                          \
    char leak_str[30] = {0};                                  \
    fd = fopen(MIDDLE_DEBUG_PATH, "a+");                      \
    if (fd == NULL) {                                         \
        PRINT_ERR("Open \"%s\"failed!\n", MIDDLE_DEBUG_PATH); \
    }                                                         \
    sprintf(leak_str, "leak channel num %d\n", str);          \
    fprintf(fd, "%s", leak_str);                              \
    fclose(fd);                                               \
} while(0)

#endif //__LOG_H__