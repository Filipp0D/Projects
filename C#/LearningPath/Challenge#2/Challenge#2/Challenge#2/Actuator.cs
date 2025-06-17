using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Challenge_2
{
    class Actuator : IActuator
    {
        public int Id { get; set; }
        public bool isActive { get; set; }
        public DateTime lastUpdated { get; set; }
        public double temperature { get; set; }
        public double PowerUsage { get; set; }
        public const double threshold = 60;
        public event EventHandler CheckAndRaiseEvents;
        public event EventHandler<bool> StateChanged;

        private static readonly Random _random = new Random();

        public Actuator(int id)
        {
            Id = id;
            this.isActive = false;
            this.lastUpdated = DateTime.Now;
            UpdateSensorData();
        }

        public void Activate()
        {
            isActive = true;
            lastUpdated = DateTime.Now;
        }

        public void Deactivate()
        {
            isActive = false;
            lastUpdated = DateTime.Now;
        }

        public void UpdateSensorData()
        {
            temperature = _random.NextDouble() * (100 - 20) + 20;
            if (isActive)
            {
                PowerUsage = _random.Next(0,500);
            }
            else
            {
                PowerUsage = 0;
            }

            OnCheckAndRaiseEvents(EventArgs.Empty);
           
        }

        public void OnCheckAndRaiseEvents(EventArgs e)
        {
            if (temperature > threshold)
            {
                CheckAndRaiseEvents?.Invoke(this, EventArgs.Empty);
            }
            StateChanged?.Invoke(this, isActive);
        }
    }
}
