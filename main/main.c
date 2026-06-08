#include <stdint.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <Hardware.h>
#include <string.h>

#define ADDR MPU6050_I2C_ADDRESS_HIGH

const char* sentance = "working display with my own program";
bool gyroWorking;
void PrintDisp(int page, const char* text, bool invert);

void app_main(void){
    InitHardware();

    while (true){
        Motion data={
            .acceleration = {0, 0, 0},
            .rotation = {0, 0, 0}
        };
        data = GetGyroData();

        char ax[16];
        char ay[16];
        char az[16];
        
        char rx[16];
        char ry[16];
        char rz[16];

        snprintf(ax, sizeof(ax), " x: %.4f", data.acceleration.x);
        snprintf(ay, sizeof(ay), " y: %.4f", data.acceleration.y);
        snprintf(az, sizeof(az), " z: %.4f", data.acceleration.z);

        snprintf(rx, sizeof(rx), " x: %.4f", data.rotation.x);
        snprintf(ry, sizeof(ry), " y: %.4f", data.rotation.y);
        snprintf(rz, sizeof(rz), " x: %.4f", data.rotation.z);

        PrintDisp(0, "acceleration:", true);
        PrintDisp(1, ax, false);
        PrintDisp(2, ay, false);
        PrintDisp(3, az, false);
        //if (!gyroWorking)
        //    PrintDisp(5, "can't accses gyro", true);
        //else
        //    ssd1306_clear_line(&display, 5, false);
        PrintDisp(4, "rotation:", true);
        PrintDisp(5, rx, false);
        PrintDisp(6, ry, false);
        PrintDisp(7, rz, false);
    }
}
void PrintDisp(int page, const char* text, bool invert){
    ssd1306_display_text(&display, page, text, strlen(text), invert);
}