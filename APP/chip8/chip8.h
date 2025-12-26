#ifndef CHIP8_H_
#define CHIP8_H_

#include <stdint.h>

#define multi_lcd (7)
typedef struct
{
    uint8_t  chip8_rom[4096];
    volatile uint8_t  V[16];            
    volatile uint16_t I;                
    volatile uint16_t pc;                

    volatile uint16_t stack[16];
    volatile uint8_t  sp;

    volatile uint8_t  delay_timer;
    volatile uint8_t  sound_timer;
    volatile uint8_t  draw_flag;     

    uint8_t  gfx[64 * 32];   
    uint8_t  lastgfx[64 * 32];     
    volatile uint8_t  keypad[16];   

}chip8_t;

extern uint8_t testopcode[478];
extern uint8_t testkeypad[913];
extern unsigned char Pong1player[246];

extern chip8_t chip8_emulator;

void chip8_init(chip8_t *c);

void chip8_load_rom(chip8_t *c, const uint8_t *rom, uint32_t size);

void chip8_step(chip8_t *c);

void chip8_clear_key(chip8_t *c);

void chip8_set_key(chip8_t *c, uint8_t key, uint8_t state);

void chip8_clear_screen(chip8_t *c);

void chip8_draw(chip8_t *c, uint8_t x, uint8_t y, uint8_t height);

void chip8_timer_tick(chip8_t *c);

#endif
