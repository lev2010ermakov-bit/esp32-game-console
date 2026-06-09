#pragma once

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c_master.h"
#include "ssd1306.h"
#include "mpu6050.h"
#include "Vec3.h"

extern SSD1306_t display;
extern mpu6050_dev_t gyro;

typedef struct{
    vec3 acceleration;
    vec3 rotation;
} Motion;

void InitHardware(void);
void InitDisplay(void);
void InitGyro(void);
Motion GetGyroData(void);