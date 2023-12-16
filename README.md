# Controladores GPIO para ESP32

## Descripción

Este repositorio contiene controladores para la gestión de pines de entrada/salida (GPIO) en la ESP32. Estos controladores han sido desarrollados por Guadalupe Méndez Ontiveros, Manuel Francisco Zubiate Loya y Alan Alexis Rodriguez Hernandez para facilitar la configuración y utilización de los pines GPIO en proyectos basados en ESP32.

## Versión del Programa

La versión actual de los controladores es la 5.1.

## Tabla de Contenidos

1. [Estructura del Proyecto](#estructura-del-proyecto)
2. [Instalación](#instalación)
3. [Uso Básico](#uso-básico)
4. [Documentación Detallada](#Documentación-detallada)
5. [Enlaces Útiles](#enlaces-útiles)

# Estructura del Proyecto

- `GPIO.c`: Archivo principal que contiene las definiciones de las funciones para el control de GPIO.
- `GPIO.h`: Archivo de encabezado que proporciona las declaraciones de funciones y las definiciones de constantes utilizadas en `GPIO.c`.
- `BSP.h` : Archivo de encabezado que proporciona macros y definiciones de constantes utilizadas en `GPIO.c`.

# Instalación

1. **Clona este Repositorio:**
    clona el repostorio dentro de una carpeta en donde quieras guardarlo.
    git clone https://github.com/Doobz09/Drivers-GPIO-ESP32.git

2. **Copia la carpeta Drivers en el proyecto en el que quieras trabajar:**
    La carpeta drivers contiene los siguientes archivos:
    drivers:
        - `GPIO.c`
        - `GPIO.h`
        - `BSP.h`




3.**Aegurate de que el compilador Cmake enlace los drivres:**
    Es importante agrear la ruta `"../drivers/GPIO.c"` en el archivo CMakeLists.txt para no  tener problemas.

    idf_component_register(SRCS "main.c" "../drivers/GPIO.c"
                    INCLUDE_DIRS ".")

4. **Incluye el archivo de cabezera en tu proyecto para empezar a usar los drivers:**

 ```c 
 #include "../drivers/GPIO.h" 
 ```
    

5. **Compila y disfruta los drivers:**
    Si no te quedo claro las intrucciones en el apartado de enlaces utiles, encontraras un enlace a YouTube donde
    se mostrara un tutorial de como instalar los drivers en un proyecto nuevo. 



# Uso-básico
En el main pricipal de este repositorio se encuentra un ejemplo de como es que se estan implementando los drivers para una aplicacion 
sencilla.

**Ejemplos**

**BLINK**
```c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../drivers/GPIO.h"

void app_main(void)
{
    GpioModeOutput(GPIO2);              /*ESTABLECEMOS EL GPIO2 COMO SALIDA*/
    GpioDigitalWrite(GPIO2,GPIO_LOW);   /*ESTABLECEMOS EL ESTADO LOGICO DEL GPIO2 COMO BAJO PARA APAGAR EL LED*/

    while(1){
        GpioDigitalWrite(GPIO2,GPIO_HIGH);    /*ENCENDEMOS EL LED MANDANDO UN ALTO AL GPIO2*/
        vTaskDelay(pdMS_TO_TICKS(100));       /*RETARDO DE 100 MILISEGUNDOS*/
        GpioDigitalWrite(GPIO2,GPIO_LOW);     /*APAGAMOS EL LED MANDANDO UN BAJO AL GPIO2*/
        vTaskDelay(pdMS_TO_TICKS(100)); 
    }
} 
```

**TOGGLE**
```c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../drivers/GPIO.h"

void app_main(void)
{
    uint8_t estado_led=0;

    GpioModeInput(GPIO18);        /*ESTABLECEMOS EL GPIO18 COMO ENTRADA*/
    GpioPullUpEnable(GPIO18);     /*HABILITAMOS LA RESISTENCIA PULLUP INTERNA DEL GPIO18*/

    GpioModeOutput(GPIO2);       /*ESTABLECEMOS EL GPIO2 COMO SALIDA*/

    while(1){
        GpioDigitalWrite(GPIO2,estado_led);     /*ESTABLECEMOS EL ESTADO LOGICO DEL GPIO2 SEGUN EL VALOR DE LA VARIABLE ESTADO_LED*/

        if(GpioDigitalRead(GPIO18)==GPIO_LOW){   /*LEEMOS EL VALOR DEL GPIO18 Y SI ESTE ES PRESIONADO Y SOLATADO CAMBIA EL VALOR DE ESTADO_LED*/
            while(GpioDigitalRead(GPIO18)==GPIO_LOW);
            estado_led= !estado_led;                      
        }
            
        vTaskDelay(pdMS_TO_TICKS(50));

    }

}
```
**Lectura de entrada en configuracion de resistencia Pull down**
```c
#include <stdio.h>
#include "../drivers/GPIO.h"
void app_main(void)
{
 GpioModeInput(GPIO4); /*pin que usaremos cono entrada*/
 GpioModeOutput(GPIO2); /*Led integrado en la tarjeta DevKit*/
 GpioPullDownEnable(GPIO4);

 while(1){
 	 if( GpioDigitalRead(GPIO4)==1){  /*Leemos la entrada*/
 		 GpioDigitalWrite(GPIO2,GPIO_HIGH);/*Enciende Led*/
 	 }
 	 else{
 		 GpioDigitalWrite(GPIO2,GPIO_LOW); /*Apaga Led*/
 	 }

 	}
}
```

# Documentación-detallada 
1. [GpioModeOutput(uint32_t gpio)](###gpiomodeoutput)
2. [GpioModeInput(uint32_t gpio)](#gpiomodeinput)
3. [GpioPullUpEnable(uint32_t gpio)](#gpiopullupenable)
4. [GpioPullDownEnable(uint32_t gpio)](#gpiopulldownenable)
5. [GpioDigitalWrite(uint32_t gpio, gpio_state state)](#gpiodigitalwrite)
6. [GpioDigitalRead(uint32_t gpio)](#gpiodigitalread)

### GpioModeOutput(uint32_t gpio)

Configura el GPIO especificado para su uso como salida.

Parámetros:
`gpio`: Número del pin GPIO que se configurará como salida.

 Ejemplo de uso:
 GpioModeOutput(GPIO5);



### GpioModeInput(uint32_t gpio)

Configura el GPIO especificado para su uso como entrada.

Parámetros:
`gpio`: Número del pin GPIO que se configurará como entrada.

 Ejemplo de uso:
GpioModeInput(GPIO5);



### GpioPullUpEnable(uint32_t gpio)

Activa la resistencia PullUp interna en el GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO en el que se activará la resistencia PullUp.

Ejemplo de uso:
GpioPullUpEnable(GPIO5);



### GpioPullDownEnable(uint32_t gpio)

Activa la resistencia PullDown interna en el GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO en el que se activará la resistencia PullDown.

Ejemplo de uso:
GpioPullDownEnable(GPIO5);



### GpioDigitalWrite(uint32_t gpio, gpio_state state)

Establece el estado lógico (alto o bajo) en el GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO en el que se establecerá el estado.
`state`: Estado lógico que se desea establecer (GPIO_HIGH o GPIO_LOW).

Ejemplo de uso:
GpioDigitalWrite(GPIO5, GPIO_HIGH);



### GpioDigitalRead(uint32_t gpio)

Lee el estado lógico actual del GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO del que se leerá el estado.

Retorno:
`int`: Valor leído en el GPIO (1 para HIGH, 0 para LOW).

Ejemplo de uso:
int state = GpioDigitalRead(GPIO5);


    



# Enlaces Útiles

- Tutorial de Instalación en YouTube: [Ver Video](https://www.youtube.com/watch?v=39Y9ccPP4lo)

- Explicación de las funciones `GpioModeOutput` y `GpioDigitalWrite`: [Ver Video](https://www.youtube.com/watch?v=fnq7XpH4JNg)

- Demostración de `GpioDigitalRead`, `GpioPullUpEnable` y `GpioModeInput`: [Ver Video](https://www.youtube.com/watch?v=yoAUmNgFuao&list=PL8iwJR9vABu3u63JPcMa7BSwXpqoU4lDE&index=3)

- Ejemplo adicional utilizando `GpioPullDownEnable(uint32_t gpio)`: [Ver Video](https://www.youtube.com/watch?v=Ki9ZyHPGTjI&list=PL8iwJR9vABu3u63JPcMa7BSwXpqoU4lDE&index=4)


 

