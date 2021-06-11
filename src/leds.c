#include "leds.h"

#define ALL_LEDS_OFF  0x0000
#define ALL_LEDS_ON  0xFFFF
#define LED_ON 1
#define LED_OFFSET 1

static uint16_t * puerto;

uint16_t led_to_bit(uint8_t led) {
    return (LED_ON << (led-LED_OFFSET));
}

void Leds_Create(uint16_t * puntero){       //borra el puerto
    puerto=puntero;
    *puerto = ALL_LEDS_OFF;
}

void Led_TurnOn(uint16_t led){      //prende un led
    *puerto |= led_to_bit(led);
}

void Led_TurnOff(uint16_t led){     //apagada un led
    *puerto &= ~led_to_bit(led);
}

void Leds_TurnALL(uint16_t * puntero){
     puerto=puntero;
    *puerto = ALL_LEDS_ON;
}

uint16_t led_bit_status(uint16_t * puntero, uint8_t led) {
    uint16_t au;
    puerto=puntero;
    au=(LED_ON << (led-LED_OFFSET));
    if ((*puerto && au)==0){
        return(0);
    }
    else{
        return(1);
    }
    
}