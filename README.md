# CHIP-8 Emulator on STM32F767

一个运行在 **STM32F767** 微控制器上的 **CHIP-8 模拟器**，  
支持 **USB HID 设备输入**，用于验证在资源受限的嵌入式平台上实现完整虚拟机的能力。

---

## 项目简介

本项目从零开始实现了一个 **CHIP-8 虚拟机**，运行于 STM32F767（216MHz Cortex-M7），  
不依赖现成模拟器框架，核心目标是：
- 理解并实现 CHIP-8 的 **指令译码与执行模型**
- 在 **FreeRTOS** 环境下完成时间与外设调度
- 使用 **USB HID 设备** 作为输入（键盘 / 鼠标）
- 用**TFT-LCD**作为显示输出

---

## CHIP-8 架构概览

- 16 × 8-bit 通用寄存器（V0–VF）
- 16-bit 索引寄存器 I
- 16-bit 程序计数器 PC
- 4KB 内存模型
- 64 × 32 单色显示缓冲区
- 16 键输入系统
- 2 个 60Hz 定时器（Delay / Sound）

---

## 硬件平台

| 项目 | 说明 |
|----|----|
| MCU | STM32F767 |
| 主频 | 216 MHz |
| 架构 | ARM Cortex-M7 |
| USB | OTG FS |
| 输入 | USB HID（键盘 / 鼠标） |
| 显示 | TFT-LCD / 上位机串口DEBUG输出 |

---

## 输入系统（USB HID）

- 使用 STM32 USB Host
- 支持 HID 键盘 / 鼠标
- HID 键值映射为 CHIP-8 的 16 键输入

---

## 输出系统（LCD TFT）
- 使用3.5寸 TFT LCD模块
- 显示刷新 | ~60 Hz |

## 效果图：
-测试结果
<img width="720" height="540" alt="924b793493b8468abe73c640ebbfe5e8" src="https://github.com/user-attachments/assets/3ece0322-5f91-48d4-b07a-3885f3ae6283" />
-运行《pong》
https://github.com/user-attachments/assets/6743f598-599f-4694-bb5a-81368ab212d6


