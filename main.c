#include <stdio.h>
#include "temp_sensor.h"
#include "barometric_pressure_sensors.h"

int main()
{
    /*----------------------Objects-------------------------*/
    //++++++++++++Temperature Sensors Objects++++++++++++//
    temp_sensor_c tempSensor_emc1001;
    temp_sensor_c *pTempSensor_emc1001 = newTempSensor(&tempSensor_emc1001);
    
    temp_sensor_c tempSensor_ds1624;
    temp_sensor_c *pTempSensor_ds1624 = newTempSensor(&tempSensor_ds1624);
    
    temp_sensor_c tempSensor_mcp9808;
    temp_sensor_c *pTempSensor_mcp9808 = newTempSensor(&tempSensor_mcp9808);
    
    //++++++++++++Barometric Pressure Sensors Objects++++++++++++//
    baroPressure_sensor_c baroSensor_bmp085;
    baroPressure_sensor_c *pBaroSensor_bmp085 = newBaroPressure_Sensor(&baroSensor_bmp085);
    
    baroPressure_sensor_c baroSensor_dps368;
    baroPressure_sensor_c *pBaroSensor_dps368 = newBaroPressure_Sensor(&baroSensor_dps368);
    /*----------------------------------------------------------------------------------------------*/
    
    /*--------------------------Temperature Sensors Initialization--------------------------*/
    pTempSensor_emc1001->sensor.init(pTempSensor_emc1001, "EMC1001", EMC1001_SENSOR_ID);
    
    /*Testing the temp_sensor name's change through the setter*/
//    pTempSensor_emc1001->sensor.setName(pTempSensor_emc1001, "TS1");
//    printf("The new sensor name is: %s\n", pTempSensor_emc1001->sensor.getName(pTempSensor_emc1001));
    /*Testing how is the id change possible ONLY IF having pTempSensor_emc1001 as a temp_sensor type*/
//    pTempSensor_emc1001->sensor.id = 100;
//    printf("The new sensor id is: %d\n", pTempSensor_emc1001->sensor.getId(pTempSensor_emc1001));
    
    pTempSensor_ds1624->sensor.init(pTempSensor_ds1624, "DS1624", DS1624_SENSOR_ID);
    pTempSensor_mcp9808->sensor.init(pTempSensor_mcp9808, "MCP9808", MCP9808_SENSOR_ID);
    /*----------------------------------------------------------------------------------------------*/
    
    /*--------------------------Barometric Pressure Sensors Initialization--------------------------*/
    pBaroSensor_bmp085->sensor.init(pBaroSensor_bmp085, "BMP085", BMP085_SENSOR_ID);
    pBaroSensor_dps368->sensor.init(pBaroSensor_dps368, "DPS368", DPS368_SENSOR_ID);
    /*----------------------------------------------------------------------------------------------*/
    
    printf("Sensor %s | Temperature: %u\n", pTempSensor_emc1001->sensor.getName(pTempSensor_emc1001), pTempSensor_emc1001->sensor.read(pTempSensor_emc1001, EMC1001_SENSOR_ID));
    printf("Sensor %s | Temperature: %u\n", pTempSensor_ds1624->sensor.getName(pTempSensor_ds1624), pTempSensor_ds1624->sensor.read(pTempSensor_ds1624, DS1624_SENSOR_ID));
    printf("Sensor %s | Temperature: %u\n", pTempSensor_mcp9808->sensor.getName(pTempSensor_mcp9808), pTempSensor_mcp9808->sensor.read(pTempSensor_mcp9808, MCP9808_SENSOR_ID));
    
    printf("Sensor %s | Pressure: %u hPa\n", pBaroSensor_bmp085->sensor.getName(pBaroSensor_bmp085), pBaroSensor_bmp085->ReadPressure(pBaroSensor_bmp085, BMP085_SENSOR_ID));
    printf("Sensor %s | Pressure: %u hPa\n", pBaroSensor_dps368->sensor.getName(pBaroSensor_bmp085), pBaroSensor_dps368->ReadPressure(pBaroSensor_dps368, DPS368_SENSOR_ID));
    
    return 1;
}
