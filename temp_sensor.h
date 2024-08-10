/* 
 * File:   temp_sensor.h
 * Author: J Alberto S F
 *
 * Created on 17 de marzo de 2024, 09:43 PM
 */

#ifndef TEMP_SENSOR_H
#define	TEMP_SENSOR_H

#include <stdint.h>
#include "sensor.h"

#define EMC1001_SENSOR_ID   10
#define DS1624_SENSOR_ID    11
#define MCP9808_SENSOR_ID   12

typedef struct temperature_sensor temp_sensor;
typedef const struct temperature_sensor temp_sensor_c; //Data Hiding

struct temperature_sensor
{
/*Attributes*/
    sensor_t sensor;
    uint8_t  range;
    
/*Methods*/
    void (*displayTemp)(temp_sensor *pSensor);
};

/*Constructor Prototype*/
temp_sensor* newTempSensor(temp_sensor *pSensor);

#endif	/* TEMP_SENSOR_H */

