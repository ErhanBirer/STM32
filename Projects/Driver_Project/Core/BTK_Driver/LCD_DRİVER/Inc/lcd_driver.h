/*
 * lcd_driver.h
 *
 *  Created on: Mar 11, 2026
 *      Author: erhan
 */

#ifndef INC_LCD_DRIVER_H_
#define INC_LCD_DRIVER_H_
#include "main.h"
#include "stdbool.h"
#include "stdarg.h"
#include "string.h"
#include "stdio.h"


#define LCD_I2C_DEVICE_ADDRESS 0x4E

// Function Set Flags
#define LCD_8BIT_MODE 0X10
#define LCD_4BIT_MODE 0X00
#define LCD_2_LINE 0X08
#define LCD_1_LINE 0X00
#define LCD_5X10_DOTS  0X04
#define LCD_5X8_DOTS 0X00

// Entry Mode Set Flags
#define LCD_ENTRY_RIGHT 0X00
#define LCD_ENTRY_LEFT 0X02
#define LCD_ENTRY_SHIFT_INCREMENT 0X01
#define LCD_ENTRY_SHIFT_DECREMENT 0X00

/****** LCD Commands *****/
typedef enum
{
	LCD_CMD_ClearDisplay = 0x01,
	LCD_CMD_ReturnHome = 0x02,
	LCD_CMD_EntryMode = 0x04,
	LCD_CMD_DisplayOnOff = 0x08,
	LCD_CMD_CursorShıft = 0x10,
	LCD_CMD_FunctionSet = 0x20,
	LCD_CMD_SetCGRAM_Address = 0x40,
	LCD_CMD_SetDDRAM_Address = 0x80
}LCD_COMMANDS;
/****** Display Setups *****/
typedef enum
{
LCD_Display_ON = 0x04,
LCD_Cursor_On = 0x02,
LCD_Cursor_Blink_On = 0x01
}LCD_Cursor_Control;

/****** LCD Structure *****/
typedef struct
{
	I2C_HandleTypeDef *hi2c;
	uint8_t i2c_address;
	uint8_t colums;
	uint8_t rows;
	bool backlight;
	uint8_t display_control;
}LCD_t;

/****** LCD APIs Functions *****/
void LCD_Initialization(LCD_t *lcd);
void LCD_Clear(LCD_t *lcd);
void LCD_Home(LCD_t *lcd);
void LCD_Set_Cursor(LCD_t *lcd, uint8_t row, uint8_t col);
void LCD_Send_Char(LCD_t *lcd, char ch);
void LCD_Send_String(LCD_t *lcd, const char *str);
void LCD_Send_Command(LCD_t *lcd, uint8_t cmd);
void LCD_Send_Data(LCD_t *lcd, uint8_t data);
void LCD_Backlight_On(LCD_t *lcd);
void LCD_Backlight_Off(LCD_t *lcd);
void LCD_Cursor_Show(LCD_t *lcd);
void LCD_Cursor_Hide(LCD_t *lcd);
void LCD_Printf(LCD_t *lcd, const char *format, ...);
void LCD_Scroll_Text(LCD_t *lcd, const char *text, uint8_t row, uint16_t delayMs);
void LCD_Send_InitNibble(LCD_t *lcd , uint8_t nibble);





#endif /* INC_LCD_DRIVER_H_ */
