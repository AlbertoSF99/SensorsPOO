/* 
 * File:   sensor.h
 * Author: J Alberto S F
 *
 * Created on 17 de marzo de 2024, 06:47 PM
 */

#ifndef SENSOR_H
#define	SENSOR_H

#include <stdint.h>

/*Sensors Interfaces*/
typedef union
{
    uint8_t analog_iface;  //Analogic Interface
    uint8_t i2c_iface;     //I2C Interface
    uint8_t spi_iface;     //SPI Interface
    uint8_t swi_iface;     //Single Wire Interface
}interface_t;

/*Abstract Class Sensor*/
typedef struct
{
/*Attributes*/
    uint8_t     *name;      //Cadena de texto (uint8_t es igual que unsigned char)
    uint8_t     id;         //Valor entero constante para el id
    interface_t interface;  //Tipo de dato union redefinido para interfaces
    uint8_t     *value;     //Valor de medición
    
/*Methods*/
    void        (*init)(void* pvS, uint8_t *name, uint8_t id);  //Pointer to function to initialize sensors
    void        (*config)(void* pvS, uint8_t id);               //Pointer to function to configure sensors
    void        (*calibrate)(void* pvS, uint8_t id);            //Pointer to function to calibrate sensors
    uint8_t*    (*read)(void* pvS, uint8_t id);                 //Pointer to function that returns a u-char pointer
    void        (*write)(void* pvS, uint8_t id, uint8_t *data); //Pointer to function to write data
    
/*Getters & Setters*/
    void        (*setName)(void* pvS, uint8_t *name);
    uint8_t*    (*getName)(void* pvS);
    void        (*setId)(void *pvS, uint8_t id);
    uint8_t     (*getId)(void *pvS);
}sensor_t;

#endif	/* SENSOR_H */

