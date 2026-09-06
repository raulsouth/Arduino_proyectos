# DistanceSensor

![GitHub Workflow Status (with branch)](https://img.shields.io/github/actions/workflow/status/Segilmez06/DistanceSensor/build-examples.yml?branch=development&color=blue&label=Build%20examples%20%28Uno%29&logo=github&logoColor=white)
![GitHub Workflow Status (with branch)](https://img.shields.io/github/actions/workflow/status/Segilmez06/DistanceSensor/check-linting.yml?branch=development&color=blue&label=Linting%20Check&logo=github&logoColor=white)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/Segilmez06/DistanceSensor?display_name=tag&label=Latest%20Release&color=blue&logo=Github&logoColor=white&style=flat)
![GitHub repo size](https://img.shields.io/github/repo-size/Segilmez06/DistanceSensor?color=yellow&label=Repo%20Size&logo=github&logoColor=white)
![GitHub all releases](https://img.shields.io/github/downloads/Segilmez06/DistanceSensor/total?color=yellow&label=Downloads&logo=Github&logoColor=white)
[![arduino-library-badge](https://www.ardu-badge.com/badge/DistanceSensor.svg?)](https://www.ardu-badge.com/DistanceSensor)

A simple library for the HC-SR04 ultrasonic distance sensor. It measures the time between the sensor's trigger and echo pins. The library is designed to be used with the Arduino IDE. Compitable with most Arduino and ESP boards.

## Installation

### With Arduino Library Manager

1. Open the Arduino IDE
2. Go to `Sketch > Include Library > Manage Libraries...`
3. Search for `DistanceSensor`
4. Click on the library and click `Install`

### With Zip file

1. Download the library from the [Releases page](https://github.com/Segilmez06/DistanceSensor/releases).
2. Open the Arduino IDE
3. Go to `Sketch > Include Library > Add .ZIP Library...`
4. Select the downloaded file

### Manual Installation

1. Download the library from the [Releases page](https://github.com/Segilmez06/DistanceSensor/releases).
2. Unzip the file
3. Go to `Documents/Arduino/libraries`
4. Copy contents of the zip file to `Documents/Arduino/libraries`

## Usage

```c++
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
```

## Credits

Original library from [Afstandssensor](https://github.com/Teknologiskolen/HCSR04) authors.

I just translated it to English and added some examples.
