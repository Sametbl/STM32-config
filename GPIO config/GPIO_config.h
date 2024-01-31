#ifndef GPIO_config_H
#define GPIO_config_H

#include "stm32f10x.h"
#include "stdbool.h"
// Another name for PORT
#define PORTA					GP                     IOA
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


enum STATE{LOW,HIGH};
// Pin Modos
enum PinMode{INPUT, OUT_10, OUT_2, OUT_50};

// Input config
enum Input_config{INPUT_ANALOG , INPUT_FLOAT, INPUT_PULL, INPUT_RES};

// Output config
enum GPO_AFO{GPO_PP, GPO_OD, AFO_PP, AFO_OD};


typedef struct{
		GPIO_TypeDef *port;
		uint8_t  pin;
		uint8_t  mode;
		uint8_t  mode_type;
		uint8_t  pull;
		uint8_t  speed;
		uint8_t  alt_func;
} GPIO_spec;
void GPIO_init( GPIO_spec MaPin);



// Note: remember to Enable Ports
void pin_config(GPIO_TypeDef *port, uint8_t pinNumber, uint8_t mode, uint8_t mode_type);  

void GPIO_Write(GPIO_TypeDef *port, uint8_t pinNumber, bool state);         

bool GPIO_Read(GPIO_TypeDef *port, uint8_t pinNumber);

void GPIO_Toggle(GPIO_TypeDef *port, uint8_t pinNumber);



// Custom Port Manipulation
void DDR(GPIO_TypeDef *port);
void PORT(GPIO_TypeDef *port);
void PIN(GPIO_TypeDef *port);



#endif

