#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CLI_INBUFFER_SIZE 128
#define CLI_OUTBUFFER_SIZE 128

typedef uint32_t (*cli_func_t)(uint32_t argc, uint8_t **argv);

typedef struct {
    const char *cmd;
    cli_func_t func;
    const char *help;
} cli_cmd_t;


extern uint8_t cli_inbuffer[CLI_INBUFFER_SIZE];
extern uint8_t cli_outbuffer[CLI_OUTBUFFER_SIZE];

extern uint32_t cli_help(uint32_t argc, uint8_t **argv);
extern uint32_t cli_version(uint32_t argc, uint8_t **argv);

extern uint32_t cli_parser(uint8_t *inbuffer, uint32_t inlen, uint8_t *outbuffer, uint32_t outlen);

#endif
