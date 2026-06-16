```cpp
/*
====================================================
TriVision Smart Driver Monitoring Board
ESP32-S3 + MAX30102 + MPU6050
Version 1.0
Author: Anushri Logesh
====================================================
*/

#include <Wire.h>
#include <MAX30105.h>
#include <MPU6050.h>

MAX30105 particleSensor;
MPU6050 mpu;

// Pin Definitions
#define SDA_PIN     8
#define SCL_PIN     9

#define GREEN_LED   21
#define RED_LED     48

#define BUZZER_PIN  4

#define MAX_INT     15
#define MPU_INT     16

void setup()
{
    Serial.begin(115200);

    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);

    Wire.begin(SDA_PIN, SCL_PIN);

    // MAX30102 Initialization
    if (!particleSensor.begin(Wire))
    {
        Serial.println("MAX30102 not detected");
    }
    else
    {
        Serial.println("MAX30102 Initialized");
    }

    // MPU6050 Initialization
    mpu.initialize();

    if (mpu.testConnection())
    {
        Serial.println("MPU6050 Connected");
    }
    else
    {
        Serial.println("MPU6050 Connection Failed");
    }

    digitalWrite(GREEN_LED, HIGH);
}

void loop()
{
    monitorHeartSensor();
    monitorMotionSensor();

    delay(200);
}

void monitorHeartSensor()
{
    long irValue = particleSensor.getIR();

    Serial.print("IR Value: ");
    Serial.println(irValue);

    // Finger removed or weak signal
    if (irValue < 5000)
    {
        triggerAlert("Finger Not Detected");
    }
}

void monitorMotionSensor()
{
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    mpu.getMotion6(
        &ax, &ay, &az,
        &gx, &gy, &gz
    );

    Serial.print("GX:");
    Serial.print(gx);

    Serial.print(" GY:");
    Serial.print(gy);

    Serial.print(" GZ:");
    Serial.println(gz);

    // Sudden movement threshold
    if (abs(gx) > 20000 ||
        abs(gy) > 20000 ||
        abs(gz) > 20000)
    {
        triggerAlert("Sudden Motion Detected");
    }
}

void triggerAlert(String reason)
{
    Serial.println(reason);

    digitalWrite(RED_LED, HIGH);

    tone(BUZZER_PIN, 2000);
    delay(500);
    noTone(BUZZER_PIN);

    digitalWrite(RED_LED, LOW);
}
```
