#include "hid_report_parser.h"
#include "app_init.h"
#include "main.h"

const uint8_t keymap[128]=
{
    0, 0, 0, 0, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3','4', '5', '6', '7', '8', '9', '0',
    [0x28] = '\n', // Enter
    [0x2C] = ' ', // Space
};

const uint8_t keymap_shift[128]=
{
    0, 0, 0, 0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
    [0x28] = '\n', // Enter
    [0x2C] = ' ', // Space
};


/**
 * @brief 解析 HID 报告
 *
 * @param report  HID 报告指针
 * @param len     HID 报告长度
 * @param event   解析后的事件指针
 */
hid_input_event_type_t hid_parse_report(uint8_t *report, uint32_t len, hid_input_event_t *event)
{
    if (event->type == HID_EVT_KEYBOARD)
    {
        event->keyboard.modifier = report[0];
        event->keyboard.reserved = 0;
        memcpy(event->keyboard.keycode, &report[2], 6);
        //printf("HID_EVT_KEYBOARD\n");
        return HID_EVT_KEYBOARD;
    }
    else if (event->type == HID_EVT_MOUSE)
    {
        /* code */
        event->mouse.x = report[1];
        event->mouse.y = report[2];
        event->mouse.wheel = report[3];
        event->mouse.buttons = report[0];
        //printf("HID_EVT_MOUSE\n");
        return HID_EVT_MOUSE;
    }
    else
    {
        return HID_EVT_NONE;
    }
}

