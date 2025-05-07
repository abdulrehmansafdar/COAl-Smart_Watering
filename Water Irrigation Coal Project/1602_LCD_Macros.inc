.ifndef LCD_MACROS_INC
.set LCD_MACROS_INC = 1

; Include required files but only if not already included
.ifndef DELAY_MACRO_INC
.include "delay_Macro.inc"
.endif
.include "UART_Macros.inc"
.include "div_Macro.inc"

; Define LCD pins
.equ LCD_RS = 0  ; Example - adjust to your hardware
.equ LCD_EN = 1  ; Example - adjust to your hardware
.equ LCD_PORT = PORTB
.equ LCD_DDR = DDRB
.equ LCD_PIN = PINB
.equ LCD_BACKLIGHT_PIN = 2  ; Example - adjust to your hardware

.macro LCD_init
    ; Set LCD pins as output
    sbi LCD_DDR, LCD_RS
    sbi LCD_DDR, LCD_EN
    sbi LCD_DDR, LCD_BACKLIGHT_PIN
    
    ; Initialize LCD in 4-bit mode
    ; (Add specific initialization steps for your LCD)
    delay 50  ; Wait for LCD to power up
    
    ; Send initialization commands
    ; (Add specific commands for your LCD model)
.endmacro

.macro LCD_backlight_ON
    sbi LCD_PORT, LCD_BACKLIGHT_PIN
.endmacro

.macro LCD_backlight_OFF
    cbi LCD_PORT, LCD_BACKLIGHT_PIN
.endmacro

.macro LCD_send_a_command
    ; Send command to LCD
    ; @0 contains the command byte
    ; (Add code to send command to your LCD)
.endmacro

.macro LCD_send_a_string
    ; Send string pointed by Z register to LCD
    ; R20 should contain the string length
    ; (Add code to send string to your LCD)
.endmacro

.macro LCD_send_a_character
    ; Send character to LCD
    ; @0 contains the character
    ; (Add code to send character to your LCD)
.endmacro

.macro LCD_send_a_register
    ; Send register value to LCD
    ; @0 is the register to send
    ; (Add code to convert register value to characters and send to LCD)
.endmacro

.endif