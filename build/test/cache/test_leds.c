#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"




















void setUp(void) {



}



void tearDown(void) {

}



void test_Leds_Create(void) {

   uint16_t ledsVirtuales=0xFFFF;

   Leds_Create(&ledsVirtuales);



   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_HEX16);

}







void test_TurnOnLedOne(void) {

    uint16_t ledsVirtuales;

    Leds_Create(&ledsVirtuales);

    Led_TurnOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffOneLed(void) {

    int16_t ledsVirtuales;

    Leds_Create(&ledsVirtuales);

    Led_TurnOn(5);

    Led_TurnOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAndOffOneLed(void) {

    int16_t ledsVirtuales;

    Leds_Create(&ledsVirtuales);

    Led_TurnOn(3);

    Led_TurnOn(5);

    Led_TurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_HEX16);

}



void test_Turnonall(void){

     int16_t ledsVirtuales;

    Leds_Create(&ledsVirtuales);

    Leds_TurnALL(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX16);

}



void test_status_bit(void){

    int16_t ledsVirtuales;

    Leds_Create(&ledsVirtuales);

    Led_TurnOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((led_bit_status(&ledsVirtuales,5))), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

}
