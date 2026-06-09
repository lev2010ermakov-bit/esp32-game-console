#include <stdint.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/projdefs.h"
#include <esp_log.h>
#include "freertos/task.h"
#include <Hardware.h>
#include <GyroTest.h>

#define ADDR MPU6050_I2C_ADDRESS_HIGH

const char* sentance = "working display with my own program";
bool gyroWorking;

void app_main(void){
    InitDisplay();

    ssd1306_clear_screen(&display, true);
    
    uint8_t intensity = 0x00;
    bool torwards = true;
    while (true){
        if (torwards){
            intensity+=0x11;
            if (intensity == 0xff)
                torwards = false;
        }
        else{
            intensity -= 0x11;
            if (intensity == 0x00)
                torwards = true;
        }
        vTaskDelay(pdMS_TO_TICKS(50));
        ssd1306_contrast(&display, intensity);
        ESP_LOGD("", "Intensity changed");
    }
}