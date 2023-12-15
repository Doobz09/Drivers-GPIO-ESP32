 /*FileName:         main.c                                                                                             */
 /* Dependencies:    None                                                                                               */
 /* Processor:       ESP32                                                                                              */
 /* Board:           ESP32-PANTHER48                                                                                    */
 /* Program version: 5.1                                                                                                */
 /* Company:         Espressif Systems                                                                                  */
 /* Description:     Aplicacion sencilla de un blink con variacion en el parpadeo.                                      */
 /* Authors:         Guadalupe Méndez Ontiveros, Manuel Francisco Zubiate Loya, Alan Alexis Rodriguez Hernandez.        */                                        
 /*Updated:          12/2023                                                                                            */


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../drivers/GPIO.h"



void app_main(void)
{
    uint32_t delay_ms =100;

    GpioModeOutput(GPIO2);/*Establecemos el GPIO2 Como Salida*/

    GpioModeInput(GPIO18);/*Establecemos el GPIO18 como entrada*/
    GpioPullUpEnable(GPIO18);/*Activamos la resistencia PullUp interna del GPIO18*/

    while (1)
    {
        GpioDigitalWrite(GPIO2,GPIO_LOW);   /*Mandamos un 0 al GPIO2*/
        vTaskDelay(pdMS_TO_TICKS(delay_ms));     /*Retardo de 100 milisegundos*/
        GpioDigitalWrite(GPIO2,GPIO_HIGH);  /*Mandamos un 1 al GPIO2*/
        vTaskDelay(pdMS_TO_TICKS(delay_ms));     /*Retardo de 100 milisegundos*/

        if(GpioDigitalRead(GPIO18)==GPIO_LOW)
            delay_ms+=10;                 /*Aumentamos el delay en 10 cada que se presiona el boton en el GPIO18*/

    }
    

}
