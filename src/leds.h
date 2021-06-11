#include "stdint.h"                     //para agregar lo de uint16_t


uint16_t led_to_bit(uint8_t led);

void Leds_Create(uint16_t * puerto);

void Led_TurnOn(uint16_t led);

void Led_TurnOff(uint16_t led);

void Leds_TurnALL(uint16_t * puerto);



uint16_t led_bit_status(uint16_t * puerto, uint8_t led);