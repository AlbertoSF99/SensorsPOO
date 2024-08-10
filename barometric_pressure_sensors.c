#include <stdio.h>
#include <stdint.h>
#include "barometric_pressure_sensors.h"

/*Function Prototypes (Forward Declaration)*/
static void initBaroPressureSensor(void* pSensor, uint8_t *name, uint8_t id);
static void setNameBaroPressureSensor(void* pSensor, uint8_t *name);
static uint8_t* getNameBaroPressureSensor(void* pSensor);
static void setIdBaroPressureSensor(void* pSensor, uint8_t id);
static uint8_t getIdBaroPressureSensor(void* pSensor);
static uint16_t* readPressureBaroSensor(void* pvSensor, uint8_t id);

/*Constructor*/

/*Create New Barometric Pressure Sensor Object*/
baroPressure_sensor* newBaroPressure_Sensor(baroPressure_sensor* pSensor)
{
    /*Method Mapping*/
    pSensor->sensor.init =    initBaroPressureSensor;
    pSensor->sensor.setName = setNameBaroPressureSensor;
    pSensor->sensor.getName = getNameBaroPressureSensor;
    pSensor->sensor.setId =   setIdBaroPressureSensor;
    pSensor->sensor.getId =   getIdBaroPressureSensor;
    pSensor->ReadPressure =   readPressureBaroSensor;
    return pSensor;
}

/*Functions*/

static void initBaroPressureSensor(void* pSensor, uint8_t *name, uint8_t id)
{
    /*Initialize logic control of pSensor sensor with a name and Id*/
    setNameBaroPressureSensor(pSensor, name);
    setIdBaroPressureSensor(pSensor, id);
    printf("Initializing %s barometric pressure sensor with ID: %d\n", getNameBaroPressureSensor(pSensor), getIdBaroPressureSensor(pSensor));
}

static void setNameBaroPressureSensor(void* pSensor, uint8_t *name)
{
    baroPressure_sensor *pBaroPressureSensor = (baroPressure_sensor*)pSensor;
    pBaroPressureSensor->sensor.name = name;
}

static uint8_t* getNameBaroPressureSensor(void* pSensor)
{
    baroPressure_sensor *pBaroPressureSensor = (baroPressure_sensor*)pSensor;
    return pBaroPressureSensor->sensor.name;
}

static void setIdBaroPressureSensor(void* pSensor, uint8_t id)
{
    baroPressure_sensor *pBaroPressureSensor = (baroPressure_sensor*)pSensor;
    pBaroPressureSensor->sensor.id = id;
}

static uint8_t getIdBaroPressureSensor(void* pSensor)
{
    baroPressure_sensor *pBaroPressureSensor = (baroPressure_sensor*)pSensor;
    return pBaroPressureSensor->sensor.id;
}

static uint16_t* readPressureBaroSensor(void *pvSensor, uint8_t id)
{
    baroPressure_sensor *pBaroPressureSensor = (baroPressure_sensor*)pvSensor;
    switch(pBaroPressureSensor->sensor.id)
    {
        case BMP085_SENSOR_ID:
            printf("\nAccessing to the BMP085 sensor drivers...\n");
            pBaroPressureSensor->pressure = 400;
            break;
        case DPS368_SENSOR_ID:
            printf("\nAccessing to the DPS368 sensor drivers...\n");
            pBaroPressureSensor->pressure = 500;
            break;
    }
    return pBaroPressureSensor->pressure;
}
