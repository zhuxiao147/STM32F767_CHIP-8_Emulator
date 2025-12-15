#include "cli.h"

uint8_t cli_inbuffer[CLI_INBUFFER_SIZE];
uint8_t cli_outbuffer[CLI_OUTBUFFER_SIZE];

/**
 * @brief 帮助命令
 * 
 * @return int  输出缓冲区长度
 */
uint32_t cli_help(uint32_t argc, uint8_t **argv)
{
    memset((char *)cli_outbuffer, 0, CLI_OUTBUFFER_SIZE);
    sprintf((char *)cli_outbuffer, "help:\n  help - 显示帮助信息\n  version - 显示版本信息\n");
    return 54;
}

/**
 * @brief 版本命令
 * 
 * @return int  输出缓冲区长度
 */
uint32_t cli_version(uint32_t argc, uint8_t **argv)
{
    memset((char *)cli_outbuffer, 0, CLI_OUTBUFFER_SIZE);
    sprintf((char *)cli_outbuffer, "version: 0.0.1\n");
    return 16;
}
