#include "cli.h"

static cli_cmd_t cli_cmds[] = {
    {"help", cli_help, "help"},
    {"version", cli_version, "version"},
};

/**
 * @brief 命令解析器
 *
 * @param argc
 * @param argv
 * @return uint32_t  输出缓冲区长度
 */
uint32_t cli_parser(uint8_t *inbuffer, uint32_t inlen, uint8_t *outbuffer, uint32_t outlen)
{
    uint32_t retlen = 0;
    uint32_t argc = 0;
    uint8_t *argv[16];
    char *token = strtok((char*)inbuffer, " ");

    // 检查命令前缀
    if (token == NULL || strncmp("cli", &token[0], strlen("cli")) != 0)
        return 0;

    while (token != NULL)
    {
        argv[argc++] = (uint8_t *)token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
    for (int i = 0; i < sizeof(cli_cmds) / sizeof(cli_cmds[0]); i++)
    {
        if (strcmp((char *)argv[1], (char *)cli_cmds[i].cmd) == 0)
        {
            retlen = cli_cmds[i].func(argc, argv);
            if (retlen > 0 && retlen <= outlen)
            {
                memcpy((char *)outbuffer, (char *)cli_outbuffer, retlen);
                return retlen;
            }
            else
                retlen = 0;
        }
    }
    retlen = cli_help(argc, argv);
    if (retlen > 0 && retlen <= outlen)
    {
        memcpy((char *)outbuffer, (char *)cli_outbuffer, retlen);
    }  
    return retlen;
}
