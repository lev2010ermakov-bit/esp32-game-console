idf_component_register(
    SRCS "src/Hardware.c"
         "src/Render.c"
    INCLUDE_DIRS "include/"
    REQUIRES ssd1306 mpu6050 esp_driver_spi
    PRIV_REQUIRES driver i2cdev
)