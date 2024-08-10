#include <stdio.h>
#include <stdint.h>
#include "temp_sensor.h"

/*Function Prototypes (Forward Declaration)*/
static void     initTempSensor(void* pSensor, uint8_t *name, uint8_t id);
static void     setNameTempSensor(void* pSensor, uint8_t *name);
static uint8_t* getNameTempSensor(void* pSensor);
static void     setIdTempSensor(void* pSensor, uint8_t id);
static uint8_t  getIdTempSensor(void* pSensor);
static uint8_t* readTempSensor(void* pSensor, uint8_t id);

/*Constructor*/

/*Create New Temperature Sensor Object*/
temp_sensor* newTempSensor(temp_sensor *pSensor)
{
    /*Method Mapping*/
    pSensor->sensor.init =    initTempSensor;
    pSensor->sensor.setName = setNameTempSensor;
    pSensor->sensor.getName = getNameTempSensor;
    pSensor->sensor.setId =   setIdTempSensor;
    pSensor->sensor.getId =   getIdTempSensor;
    pSensor->sensor.read =    readTempSensor;
    return pSensor;
}

/*Functions*/

static void initTempSensor(void* pSensor, uint8_t *name, uint8_t id)
{
    /*Initialize logic control of pSensor sensor with a name and Id*/
    setNameTempSensor(pSensor, name);
    setIdTempSensor(pSensor, id);
    printf("Initializing %s temperature sensor with ID: %d\n", getNameTempSensor(pSensor), getIdTempSensor(pSensor));
}

static void setNameTempSensor(void* pSensor, uint8_t *name)
{
    temp_sensor *pTempSensor = (temp_sensor*)pSensor;
    pTempSensor->sensor.name = name;
}

static uint8_t* getNameTempSensor(void* pSensor)
{
    temp_sensor *pTempSensor = (temp_sensor*)pSensor;
    return pTempSensor->sensor.name;
}

static void setIdTempSensor(void* pSensor, uint8_t id)
{
    temp_sensor *pTempSensor = (temp_sensor*)pSensor;
    pTempSensor->sensor.id = id;
}

static uint8_t getIdTempSensor(void* pSensor)
{
    temp_sensor *pTempSensor = (temp_sensor*)pSensor;
    return pTempSensor->sensor.id;
}

static uint8_t* readTempSensor(void* pSensor, uint8_t id)
{
    temp_sensor *pTempSensor = (temp_sensor*)pSensor;
    
    switch(pTempSensor->sensor.id)
    {
        case EMC1001_SENSOR_ID:
            printf("\nAccessing to the EMC1001 sensor drivers...\n");
            /*Sensor EMC1001 Temperature Measurement*/
            pTempSensor->sensor.value = 20;
            break;
            
        case DS1624_SENSOR_ID:
            printf("\nAccessing to the DS1624 sensor drivers...\n");
            /*Sensor DS1624 Temperature Measurement*/
            pTempSensor->sensor.value = 10;
            break;
            
        case MCP9808_SENSOR_ID:
            printf("\nAccessing to the MCP9808 sensor drivers...\n");
            /*Sensor MCP9808 Temperature Measurement*/
            pTempSensor->sensor.value = 15;
            break;
    }
    return pTempSensor->sensor.value;
}
