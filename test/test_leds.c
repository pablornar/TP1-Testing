/* 
 * Se pueden prender todos los LEDs de una vez.
 * Se pueden apagar todos los LEDs de una vez.
 * Se puede consultar el estado de un LED apagado.
 * Se puede consultar el estado de un LED 
 * Revisar limites de los parametros. 
*/
#include "unity.h"
#include "leds.h"

#define Led 5

void setUp(void) {      //función de inicialización, que se llama antes de cada prueba;
   // Leds_Create(&ledsVirtuales);
}

void tearDown(void) { //llamado después de cada prueba;
}

void test_Leds_Create(void) {       //función de instancia de prueba, que se puede cambiar según el propósito de la prueba
   uint16_t ledsVirtuales=0xFFFF;
   Leds_Create(&ledsVirtuales);         //estoy haciendo un moc del puerto
   //TEST_FAIL_MESSAGE("EMPEZAMOS");   //CON ESTO falla el test
   TEST_ASSERT_EQUAL_HEX16(0X0000, ledsVirtuales);  //compara si son iguales
}


//prender un led
void test_TurnOnLedOne(void) {
    uint16_t ledsVirtuales;
    Leds_Create(&ledsVirtuales);
    Led_TurnOn(Led);
    TEST_ASSERT_EQUAL_HEX16(1 << (Led-1), ledsVirtuales);     
}

//apagar un led
void test_TurnOffOneLed(void) {
    int16_t ledsVirtuales;
    Leds_Create(&ledsVirtuales);
    Led_TurnOn(Led);
    Led_TurnOff(Led);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);     
}

//prender y apagar un led
void test_TurnOnAndOffOneLed(void) {
    int16_t ledsVirtuales;
    Leds_Create(&ledsVirtuales);
    Led_TurnOn(3);
    Led_TurnOn(Led);
    Led_TurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 << (Led-1), ledsVirtuales);
}

void test_Turnonall(void){
     int16_t ledsVirtuales;
    Leds_Create(&ledsVirtuales);
    Leds_TurnALL(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

void test_status_bit(void){
    int16_t ledsVirtuales;
    Leds_Create(&ledsVirtuales);
    Led_TurnOn(Led);
    TEST_ASSERT_EQUAL_HEX16(1 , led_bit_status(&ledsVirtuales,Led));
}

