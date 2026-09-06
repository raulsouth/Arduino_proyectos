#ifndef COSMO_URM10_H
#define COSMO_URM10_H
#include <Arduino.h>


class Cosmo_URM10
{
  public:

  Cosmo_URM10(){};

  float getDistanceCM(int trigPin, int echoPin);
  float getDistanceIN(int trigPin, int echoPin);

  private:

  uint64_t myPulseIn(uint32_t pin, uint32_t value, long maxDuration = 100000);

};

#endif
