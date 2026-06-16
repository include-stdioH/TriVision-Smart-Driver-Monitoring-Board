```c
/*
====================================================
TriVision Smart Driver Monitoring Board
ESP32-S3 + MAX30102 + MPU6050
Version 1.0
Author: Anushri Logesh
====================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Pin Definitions */
#define SDA_PIN      8
#define SCL_PIN      9

#define GREEN_LED    21
#define RED_LED      48

#define BUZZER_PIN   4

#define MAX_INT      15
#define MPU_INT      16

/* Function Prototypes */
void setup(void);
void loop(void);
void monitorHeartSensor(void);
void monitorMotionSensor(void);
void triggerAlert(const char *reason);

/* Simulated Sensor Values */
long getIRValue(void);
void getMotionData(int16_t *ax, int16_t *ay, int16_t *az,
                   int16_t *gx, int16_t *gy, int16_t *gz);

int main(void)
{
    setup();

    while (1)
    {
        loop();
    }

    return 0;
}

void setup(void)
{
    printf("Initializing TriVision System...\n");

    printf("MAX30102 Initialized\n");
    printf("MPU6050 Connected\n");

    printf("GREEN LED ON\n");
}

void loop(void)
{
    monitorHeartSensor();
    monitorMotionSensor();

    /* Simulated delay */
}

void monitorHeartSensor(void)
{
    long irValue = getIRValue();

    printf("IR Value: %ld\n", irValue);

    /* Finger removed or weak signal */
    if (irValue < 5000)
    {
        triggerAlert("Finger Not Detected");
    }
}

void monitorMotionSensor(void)
{
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    getMotionData(&ax, &ay, &az, &gx, &gy, &gz);

    printf("GX:%d GY:%d GZ:%d\n", gx, gy, gz);

    /* Sudden movement threshold */
    if (abs(gx) > 20000 ||
        abs(gy) > 20000 ||
        abs(gz) > 20000)
    {
        triggerAlert("Sudden Motion Detected");
    }
}

void triggerAlert(const char *reason)
{
    printf("ALERT: %s\n", reason);

    printf("RED LED ON\n");
    printf("BUZZER ON (2000 Hz)\n");

    /* Simulated buzzer delay */

    printf("BUZZER OFF\n");
    printf("RED LED OFF\n");
}

/* Simulated MAX30102 IR Reading */
long getIRValue(void)
{
    return 4500;
}

/* Simulated MPU6050 Motion Data */
void getMotionData(int16_t *ax, int16_t *ay, int16_t *az,
                   int16_t *gx, int16_t *gy, int16_t *gz)
{
    *ax = 100;
    *ay = 200;
    *az = 300;

    *gx = 21000;
    *gy = 500;
    *gz = 1000;
}
```
