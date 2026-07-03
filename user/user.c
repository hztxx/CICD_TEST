#include "user.h"


// 全局变量 g_前缀
static StUserData g_user_main_data;

// 静态全局 s_前缀
static uint16_t s_user_timeout = k_user_default_timeout;

void user_init(void)
{
    // 局部变量 纯小写下划线
    uint16_t buf_index = 0;
    
    // 清空全局数据
    for(buf_index = 0; buf_index < USER_DATA_MAX_LEN; buf_index++)
    {
        g_user_main_data.buf[buf_index] = 0;
    }
    g_user_main_data.len = 0;
}

void user_set_data(StUserData *data, const uint8_t *src, uint16_t len)
{
    if(len > USER_DATA_MAX_LEN)
    {
        len = USER_DATA_MAX_LEN;
    }
    uint16_t copy_idx = 0;
    for(copy_idx = 0; copy_idx < len; copy_idx++)
    {
        data->buf[copy_idx] = src[copy_idx];
    }
    data->len = len;
}

uint16_t user_get_timeout(void)
{
    return s_user_timeout;
}