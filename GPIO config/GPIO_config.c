#include "GPIO_config.h"
void pin_config(GPIO_TypeDef *port, uint8_t pinNumber, uint8_t mode, uint8_t mode_type){
	if (pinNumber < 8){
		uint8_t start_bit = pinNumber *4;
		switch(mode){
			case INPUT:
				port -> CRL &= ~(  1<<start_bit | 1<<(start_bit + 1)   );
				break;
			case OUT_2:
				port -> CRL &= ~(  1<<start_bit  );
			  port -> CRL |= 1<<(start_bit + 1);
				break;
		  case OUT_10:
			  port -> CRL |=  1<<start_bit;
				port -> CRL &= ~(  1<<(start_bit + 1)  );
				break;
			case OUT_50:
			  port -> CRL |= 1<<start_bit | 1<<(start_bit + 1);
				break;				
		}
		
		switch(mode_type){
			case GPO_PP | INPUT_ANALOG:
				port -> CRL &= ~( 1<<(start_bit+2) | 1<<(start_bit+3)  );
				break;
			case INPUT_FLOAT | GPO_OD:
				port -> CRL |= 1<<(start_bit+2);
			  port -> CRL &= ~(  1<<(start_bit+3)  );
				break;				
			case INPUT_PULL | AFO_PP:
				port -> CRL |= 1<<(start_bit+3);
			  port -> CRL &= ~(  1<<(start_bit+2)  );
				break;						
			case INPUT_RES | AFO_OD:
				port -> CRL |=  1<<(start_bit+2) | 1<<(start_bit+3)  ;
				break;		
		}
	} //-------------------------------- CHR -----------------------------------
		else if (pinNumber >=8 && pinNumber <16){
				uint8_t start_bit = (pinNumber-8)*4;
		switch(mode){
			case INPUT:
				port -> CRH &= ~(  1<<start_bit | 1<<(start_bit + 1)   );
				break;
			case OUT_2:
				port -> CRH &= ~(  1<<start_bit  );
			  port -> CRH |= 1<<(start_bit + 1);
				break;
		  case OUT_10:
			  port -> CRH |= 1<<start_bit;
				port -> CRH &= ~(  1<<(start_bit + 1)  );
				break;
			case OUT_50:
			  port -> CRH |= 1<<start_bit | 1<<(start_bit + 1);
				break;				
		}
		
		switch(mode_type){
			case GPO_PP | INPUT_ANALOG:
				port -> CRH &= ~( 1<<(start_bit+2) | 1<<(start_bit+3)  );
				break;
			case INPUT_FLOAT | GPO_OD:
				port -> CRH |= 1<<(start_bit+2);
			  port -> CRH &= ~(  1<<(start_bit+3)  );
				break;				
			case INPUT_PULL | AFO_PP:
				port -> CRH |= 1<<(start_bit+3);
			  port -> CRH &= ~(  1<<(start_bit+2)  );
				break;						
			case INPUT_RES | AFO_OD:
				port -> CRH |=  1<<(start_bit+2) | 1<<(start_bit+3)  ;
				break;		
		}
	}
}
	

void GPIO_Write(GPIO_TypeDef *port, uint8_t pinNumber, bool state){
	if (state == 1){
			port -> BSRR |=    1<<pinNumber;
		   port -> BSRR &= ~( 1<<(pinNumber +16) );
		}
	else if (state == 0){
			port -> BSRR |=    1<<(pinNumber + 16);
		   port -> BSRR &= ~( 1<<pinNumber );
	}		
}

void GPIO_Toggle(GPIO_TypeDef *port, uint8_t pinNumber){
	port -> ODR ^= 1<<pinNumber;     //Only change if ODR initially 0 
}

void GPIO_init( GPIO_spec MaPin){
	if (MaPin.port == PORTA)      ENABLE_PORTA;
	if (MaPin.port == PORTB)      ENABLE_PORTB;
	if (MaPin.port == PORTC)      ENABLE_PORTC;
	if (MaPin.port == PORTE)      ENABLE_PORTD;
	if (MaPin.port == PORTD)      ENABLE_PORTE;
	pin_config(MaPin.port, MaPin.pin, MaPin.mode, MaPin.mode_type);
	// Unfinished function, I'll complete this when I need it at a specific task

}

bool GPIO_Read(GPIO_TypeDef *port, uint8_t pinNumber){
    // Read the input value of the specified pin
    if ( (port->IDR & (1 << pinNumber)) != 0) {
        return HIGH;
    } else {
        return LOW;
    }
}
