/* 
 * File:   barometric_pressure_sensors.h
 * Author: J Alberto S F
 *
 * Created on 18 de marzo de 2024, 03:45 AM
 */

#ifndef BAROMETRIC_PRESSURE_SENSORS_H
#define	BAROMETRIC_PRESSURE_SENSORS_H

#include "sensor.h"

#define BMP085_SENSOR_ID 50
#define DPS368_SENSOR_ID 51

typedef struct barometricPressure_sensor baroPressure_sensor;
typedef const struct barometricPressure_sensor baroPressure_sensor_c; //Data Hiding

struct barometricPressure_sensor
{
/*Attributes*/
    sensor_t  sensor;
    float     temperature;
    uint16_t  pressure;
    float     altitude;
    uint16_t  seaLevelPressure;
    
/*Methods*/
    uint16_t* (*ReadPressure)(baroPressure_sensor* pSensor, uint8_t id);
    uint16_t* (*ReadTemperature)(baroPressure_sensor* pSensor, uint8_t id);
    uint16_t* (*ReadSeaLevelPressure)(baroPressure_sensor* pSensor, uint8_t id);
};

/*Constructor Prototype*/
baroPressure_sensor* newBaroPressure_Sensor(baroPressure_sensor* pSensor);

#endif	/* BAROMETRIC_PRESSURE_SENSORS_H */

