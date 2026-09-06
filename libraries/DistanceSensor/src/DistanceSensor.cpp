/*
  DistanceSensor - HC-SR04 distance sensor library.
  Modified by Segilmez06, 22 April 2023.
  Made by Jørgen Larsen, 30 October 2019.
  Inspired by Martin Sosic, June 11, 2016.
*/

#include "Arduino.h"
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor (int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

double DistanceSensor::getCM() {
    // The speed of sound is approximately 343m/s at 19,307 degrees Celsius.
    return getCM(19.307);
}

double DistanceSensor::getCM(float temperature) {
    // Make sure trigPin is LOW
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Send the signal by activating trigPin for 10 microseconds.
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Sensor sets echoPin HIGH for the duration of the pulse.
    unsigned long duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in cm.
    // Approx ≈ (331.3 + 0.606 ⋅ ϑ) m/s
    double speed = 0.03313 + 0.0000606 * temperature; // Values is in cm/ms 
    double distance = duration / 2.0 * speed;

    // If distance is out of range, return 400.
    if(distance > 400){
        return 400;
    }

    // If distance is 0, return 0.
    else if(distance == 0){
        return 0;
    }

    // Else return the distance.
    else {
        return distance;
    }
}
