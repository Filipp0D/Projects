#include <iostream>
#include <vector>
#include "TemperatureSensor.hpp"
using namespace std;
int main()
{
    TemperatureSensor temperatureSensor;
    temperatureSensor.addReading(23.5);
    temperatureSensor.addReading(54.2);
    temperatureSensor.addReading(14.8);
    temperatureSensor.addReading(27.0);

    double avg = temperatureSensor.getAverageTemperature();
    cout << avg << endl;
    Measurement min = temperatureSensor.getMin();
    Measurement max = temperatureSensor.getMax();

}

