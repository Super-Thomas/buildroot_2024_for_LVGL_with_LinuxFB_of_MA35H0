/**
 * @file lv_tslib.h
 *
 */

#ifndef LV_TSLIB_H
#define LV_TSLIB_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "../../indev/lv_indev.h"

#if LV_USE_TSLIB

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create evdev input device.
 * @param type LV_INDEV_TYPE_POINTER or LV_INDEV_TYPE_KEYPAD
 * @param dev_path device path, e.g., /dev/input/event0 (TSLIB_TSDEVICE)
 * @return pointer to input device or NULL if opening failed
 */
lv_indev_t * lv_tslib_create(lv_indev_type_t indev_type, const char * dev_path);

#endif /*LV_USE_TSLIB*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_TSLIB_H*/
