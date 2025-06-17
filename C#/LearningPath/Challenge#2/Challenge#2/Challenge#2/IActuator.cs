using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Challenge_2
{
    interface IActuator
    {
        void Activate();
        void Deactivate();
        void UpdateSensorData();
    }
}
