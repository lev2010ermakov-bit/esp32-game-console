#include "../include/Hardware.h"
#include "i2cdev.h"

SSD1306_t display;
mpu6050_dev_t gyro; 

void InitHardware(){
    // ---------- INIT DISPLAY ---------- //
    i2c_master_init(&display, 21, 22, 15);
    ssd1306_init(&display, 128, 64);
    ssd1306_clear_screen(&display, false);
    ssd1306_contrast(&display, 0xff);


    // ---------- INIT GYRO ---------- //
    i2cdev_init();
    mpu6050_init_desc(&gyro, MPU6050_I2C_ADDRESS_LOW, I2C_NUM_1, 18, 19);
    mpu6050_init(&gyro);
    gyro.i2c_dev.cfg.master.clk_speed = 400000;


    // ---------- INIT JOYSTICK --------- //
    
    // [...] //


    // ---------- INIT BUTTON ---------- //

    // [...] //
}

Motion GetGyroData(){
    Motion res;
    mpu6050_acceleration_t acceleration;
    mpu6050_rotation_t rotation;
    mpu6050_get_motion(&gyro, &acceleration, &rotation);
    res.acceleration = (vec3){acceleration.x, acceleration.y, acceleration.z};
    res.rotation = (vec3){rotation.x, rotation.y, rotation.z};

    return res;
}