# Controladores GPIO para ESP32

## Descripción

Este repositorio contiene controladores para la gestión de pines de entrada/salida (GPIO) en la ESP32. Estos controladores han sido desarrollados por Guadalupe Méndez Ontiveros, Manuel Francisco Zubiate Loya y Alan Alexis Rodriguez Hernandez para facilitar la configuración y utilización de los pines GPIO en proyectos basados en ESP32.

## Versión del Programa

La versión actual de los controladores es la 5.1.

## Tabla de Contenidos

1. [Estructura del Proyecto](#estructura-del-proyecto)
2. [Instalación](#instalación)
3. [Uso Básico](#uso-básico)
4. [Documentación Detallada](#documentación-detallada)
5. [Enlaces Útiles](#enlaces-útiles)

## Estructura del Proyecto

- `GPIO.c`: Archivo principal que contiene las definiciones de las funciones para el control de GPIO.
- `GPIO.h`: Archivo de encabezado que proporciona las declaraciones de funciones y las definiciones de constantes utilizadas en `GPIO.c`.
- `BSP.h` : Archivo de encabezado que proporciona macros y definiciones de constantes utilizadas en `GPIO.c`.

## Instalacion

link de youtube para instalacion y uso de drivers
Link:hhtp------



## Uso Basico
En el main pricipal de este repositorio se encuentra un ejemplo de como es que se estan implementando los drivers para una aplicacion 
sencilla.

# Documentacion Detallada 

- `GpioModeOutput(uint32_t gpio)`

Configura el GPIO especificado para su uso como salida.

Parámetros:
`gpio`: Número del pin GPIO que se configurará como salida.

 Ejemplo de uso:
 GpioModeOutput(GPIO5);



- `GpioModeInput(uint32_t gpio)`

Configura el GPIO especificado para su uso como entrada.

Parámetros:
`gpio`: Número del pin GPIO que se configurará como entrada.

 Ejemplo de uso:
GpioModeInput(GPIO5);



- `GpioPullUpEnable(uint32_t gpio)`

Activa la resistencia PullUp interna en el GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO en el que se activará la resistencia PullUp.

Ejemplo de uso:
GpioPullUpEnable(GPIO5);



- `GpioPullDownEnable(uint32_t gpio)`

Activa la resistencia PullDown interna en el GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO en el que se activará la resistencia PullDown.

Ejemplo de uso:
GpioPullDownEnable(GPIO5);



- `GpioDigitalWrite(uint32_t gpio, gpio_state state)`

Establece el estado lógico (alto o bajo) en el GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO en el que se establecerá el estado.
`state`: Estado lógico que se desea establecer (GPIO_HIGH o GPIO_LOW).

Ejemplo de uso:
GpioDigitalWrite(GPIO5, GPIO_HIGH);



- `GpioDigitalRead(uint32_t gpio)`

Lee el estado lógico actual del GPIO especificado.

Parámetros:
`gpio`: Número del pin GPIO del que se leerá el estado.

Retorno:
`int`: Valor leído en el GPIO (1 para HIGH, 0 para LOW).

Ejemplo de uso:
int state = GpioDigitalRead(GPIO5);


    



## Enlaces Útiles

