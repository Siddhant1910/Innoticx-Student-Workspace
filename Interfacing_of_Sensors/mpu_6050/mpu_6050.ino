#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22); // SDA, SCL

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 Connected Successfully!");
  } else {
    Serial.println("MPU6050 Connection Failed!");
    while (1);
  }
}

void loop() {
  // Read raw values
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Print Accelerometer values
  Serial.print("Accel -> ");
  Serial.print("X: "); Serial.print(ax);
  Serial.print(" | Y: "); Serial.print(ay);
  Serial.print(" | Z: "); Serial.print(az);

  // Print Gyroscope values
  Serial.print(" || Gyro -> ");
  Serial.print("X: "); Serial.print(gx);
  Serial.print(" | Y: "); Serial.print(gy);
  Serial.print(" | Z: "); Serial.print(gz);

  Serial.println();

  delay(500);
}
