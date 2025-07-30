/**
 * @file lv_tslib.c
 *
 */

/**********************
 *      INCLUDES
 **********************/
#include "lv_tslib.h"
#if LV_USE_TSLIB

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <tslib.h>

#include "../../misc/lv_assert.h"
//#include "../../misc/lv_log.h"

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    struct tsdev *ts_dev;
} lv_tslib_t;


/**
 * Read the coordinate of point
 */
static void _tslib_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    struct ts_sample sample;
    int ret;
    
    lv_tslib_t * dsc = lv_indev_get_driver_data(indev);
    LV_ASSERT_NULL(dsc);
    
    ret = ts_read(dsc->ts_dev, &sample, 1);
    if (ret < 0) {
        LV_LOG_ERROR("ts_read error\n");
        ts_close(dsc->ts_dev);
        exit(1);
    }
    
    if (ret != 1) {
        return true;
    }
    
    if (sample.pressure > 0) {
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }

    data->point.x = sample.x;
    data->point.y = sample.y;

    return false;
}

lv_indev_t * lv_tslib_create(lv_indev_type_t indev_type, const char * dev_path)
{
    lv_tslib_t * dsc = lv_malloc_zeroed(sizeof(lv_tslib_t));
    LV_ASSERT_MALLOC(dsc);
    if (dsc == NULL) return NULL;
    
    dsc->ts_dev = ts_setup(dev_path, 1);
    if (!dsc->ts_dev) {
        LV_LOG_ERROR("Failed to setup ts_setup()\n");
        lv_free(dsc);
        return NULL;
    }
    
    lv_indev_t * indev = lv_indev_create();
    
    lv_indev_set_type(indev, indev_type);
    lv_indev_set_read_cb(indev, _tslib_read);
    lv_indev_set_driver_data(indev, dsc);
    
    return indev;
}

void lv_tslib_delete(lv_indev_t * indev)
{
    lv_tslib_t * dsc = lv_indev_get_driver_data(indev);
    LV_ASSERT_NULL(dsc);
   
    lv_free(dsc);
    lv_indev_delete(indev);
}

#endif /*LV_USE_TSLIB*/
