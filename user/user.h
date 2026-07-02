#ifndef USER_H
#define USER_H

#include "main.h"
#include "stm32f4xx_hal.h"
// 宏：全大写，符合规则
#define USER_DATA_MAX_LEN 128

// 常量：k_前缀 + 小写下划线
static const uint16_t k_user_default_timeout = 500;

// 结构体：大驼峰
typedef struct StUserData
{
    uint8_t buf[USER_DATA_MAX_LEN];
    uint16_t len;
} StUserData;

// 函数：小写下划线
void user_init(void);
void user_set_data(StUserData *data, const uint8_t *src, uint16_t len);
uint16_t user_get_timeout(void);

#endif