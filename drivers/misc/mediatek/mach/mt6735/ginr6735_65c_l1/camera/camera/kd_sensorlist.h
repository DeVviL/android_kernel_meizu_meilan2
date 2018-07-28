/*
 * s_add new sensor driver here
 */

UINT32 S5K3L2_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 S5K3L2_MIPI_RAW_SensorInit_GEER(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 OV5670_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 OV5670_MIPI_RAW_SensorInit_GEER(PSENSOR_FUNCTION_STRUCT *pfFunc);

/* Add Sensor Init function here
 * Note:
 * 1. Add by the resolution from ""large to small"", due to large sensor
 *    will be possible to be main sensor.
 *    This can avoid I2C error during searching sensor.
 * 2. This file should be the same as mediatek\custom\common\hal\imgsensor\src\sensorlist.cpp
 */
ACDK_KD_SENSOR_INIT_FUNCTION_STRUCT kdSensorList[MAX_NUM_OF_SUPPORT_SENSOR+1] = {

/* 13M */
#if defined(S5K3L2_MIPI_RAW)
	{S5K3L2_SENSOR_ID, SENSOR_DRVNAME_S5K3L2_MIPI_RAW, S5K3L2_MIPI_RAW_SensorInit},
#endif
#if defined(S5K3L2_MIPI_RAW_GEER)
	{S5K3L2_SENSOR_ID_GEER, SENSOR_DRVNAME_S5K3L2_MIPI_RAW_GEER, S5K3L2_MIPI_RAW_SensorInit_GEER},
#endif
/* 8M */

/* 5M */
#if defined(OV5670_MIPI_RAW)
	{OV5670MIPI_SENSOR_ID, SENSOR_DRVNAME_OV5670_MIPI_RAW, OV5670_MIPI_RAW_SensorInit},
#endif
#if defined(OV5670_MIPI_RAW_GEER)
	{OV5670MIPI_SENSOR_ID_GEER, SENSOR_DRVNAME_OV5670_MIPI_RAW_GEER, OV5670_MIPI_RAW_SensorInit_GEER},
#endif
/* 2M */

/* 0.3M */

/* ================================eastaeon==================================== */

/*  ADD sensor driver before this line */
	{0, {0}, NULL}, /* end of list */
};
/* e_add new sensor driver here */

