using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Challenge_2
{
    interface IActuatorController
    {
        void AddActuator(Actuator actuator);
        void ActivateActuator(int id);
        void DeactivateActuator(int id);
        void PrintStatus();
        Task Simulate();
        void GetActiveActuators();
        void GetHighUsageActuators(double threshold);

    }
}
