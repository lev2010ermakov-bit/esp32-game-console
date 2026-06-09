#include <GyroTest.h>
#include <Hardware.h>
#include <Render.h>


void GyroTestLoop(){
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
    PrintDisp(4, "rotation:", true);
    PrintDisp(5, rx, false);
    PrintDisp(6, ry, false);
    PrintDisp(7, rz, false);
}