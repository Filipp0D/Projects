using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Challenge_2
{
    class Program
    {
        static async Task Main(string[] args)
        {
            
            Actuator actuator = new Actuator(0);
            ActuatorController actuatorController = new ActuatorController();
            actuatorController.AddActuator(actuator);
            actuatorController.AddActuator(new Actuator(1));
            actuatorController.AddActuator(new Actuator(2));
            actuatorController.AddActuator(new Actuator(3));

            actuatorController.ActivateActuator(2);
            actuatorController.DeactivateActuator(0);
            actuatorController.PrintStatus();

            Actuator actuator4 = new Actuator(4);
            actuator4.Activate();
            actuatorController.AddActuator(actuator4);
            await actuatorController.Simulate();

            actuatorController.GetActiveActuators();
            actuatorController.GetHighUsageActuators(400);

        }
    }
}
