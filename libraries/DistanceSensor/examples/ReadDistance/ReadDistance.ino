/*
    This example reads the distance from a HC-SR04 sensor and
    prints it to the serial port.

    by Segilmez06, 22 April 2023.
*/

#include <DistanceSensor.h>

// Define pins
const int echoPin = 12;
const int trigPin = 13;

// Start the sensor
DistanceSensor sensor(trigPin, echoPin);

void setup () {
    // Start serial port
    Serial.begin(115200);
}

void loop () {
    // Get distance in cm
    int distance = sensor.getCM();

    // Write values to serial port
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");

    // Wait a bit
    delay(500);
}
