using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LearningPath
{
    interface ITemperatureSensor
    {
        void AddReading(double temperature);
        double GetAverageTemperature();

        double GetAverageOver(TimeSpan timeSpan);

        double GetMin();

        double GetMax();
    }
}
