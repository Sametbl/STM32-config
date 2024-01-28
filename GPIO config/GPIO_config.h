#ifndef GPIO_config_H
#define GPIO_config_H
#include "stm32f10x.h"

// Alternate name for PORT
#define PORTA					GPIOA
#define PORTB					GPIOB
#define PORTC					GPIOC
#define PORTD					GPIOD
#define PORTE					GPIOE

//Enable ports
#define ENABLE_PORTA        ( RCC -> APB2ENR |= 1<<2 )
#define ENABLE_PORTB        ( RCC -> APB2ENR |= 1<<3 )
#define ENABLE_PORTC        ( RCC -> APB2ENR |= 1<<4 )
#define ENABLE_PORTD        ( RCC -> APB2ENR |= 1<<5 )
#define ENABLE_PORTE        ( RCC -> APB2ENR |= 1<<6 )
#define ENABLE_AFIO         ( RCC -> APB2ENR |= 1<<0 )

// Pin Modes
#define INPUT 				0x00
#define OUT_2         0x02
#define OUT_10        0x01
#define OUT_50        0x03

// Input config
#define INPUT_ANALOG	0x00
#define INPUT_FLOAT 	0x01
#define INPUT_PULL		0x02
#define INPUT_RES			0x03

// Output config
#define GPO_PP    		0x00
#define GPO_OD				0x01
#define AFO_PP   			0x02
#define AFO_OD        0x03

typedef struct{
		GPIO_TypeDef *port;
		uint8_t  pin;
		uint8_t  mode;
		uint8_t  modet_ype;
		uint8_t  pull;
		uint8_t  speed;
		uint8_t  alt_func;
} GPIO_type;

void pin_config(GPIO_TypeDef *port, uint8_t pinNumber, uint8_t mode, uint8_t mode_type);  

            
#endif
