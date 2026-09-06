/*
  DistanceSensor - HC-SR04 distance sensor library.
  Modified by Segilmez06, 22 April 2023.
  Made by Jørgen Larsen, 30 October 2019.
  Inspired by Martin Sosic, June 11, 2016.
*/

#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "Arduino.h"

class DistanceSensor {
 public:
    /**
     * DistanceSensor constructor
     * @param trigPin Pin for triggering the ultrasonic signal (output).
     * @param echoPin Pin for receiving the ultrasonic signal (input).
     */
    DistanceSensor(int trigPin, int echoPin);

    /**
     * Measures the distance. Uses a standard temperature of 19.307 degrees Celsius (approximately 343m/s for sound).
     * @returns The distance to do object in cm. If distane is out of range, 400 is returned.
     */
    double getCM();

    /**
     * Measures the distance. Uses passed temperature.
     * @returns The distance to do object in cm. If distane is out of range, 400 is returned.
     * @param temperature Temperature as Celsius.
     */
    double getCM(float temp);
 private:
    int trigPin, echoPin;
};

#endif // DISTANCESENSOR_H
