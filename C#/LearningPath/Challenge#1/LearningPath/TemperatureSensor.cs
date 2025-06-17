using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using Microsoft.Extensions.Logging;

namespace LearningPath
{
    class TemperatureSensor : ITemperatureSensor
    {
        private readonly ILogger<TemperatureSensor> _logger;
        private Queue<TemperatureReading> measurements { get; set; } = new Queue<TemperatureReading>();
        private const int maxMeasures = 10;
        private const double lowerLimitTemperature = -40;
        private const double upperLimitTemperature = 80;

        public TemperatureSensor(ILogger<TemperatureSensor> logger)
        {
            _logger = logger;
        }

        public void AddReading(double temperature)
        {
            if (double.IsNaN(temperature) || double.IsInfinity(temperature))
            {
                _logger.LogError("Temperature is not valid");
                return;
            }

            if (measurements.Count >= maxMeasures)
            {
                measurements.Dequeue();
            }
            measurements.Enqueue(new TemperatureReading(temperature, DateTime.Now));
            _logger.LogInformation("Value= "+measurements.Last().Value.ToString()+"; time= "+ measurements.Last().TimeStamp.ToString());

            if (temperature < lowerLimitTemperature || temperature > upperLimitTemperature)
            {
                _logger.LogWarning($"Temperature read ({temperature}) is out of range");
            }

        }

        public double GetAverageTemperature()
        {
            return measurements.Count > 0 ? measurements.Average(reading => reading.Value) : 0;
        }

        public double GetAverageOver(TimeSpan timeSpan)
        {
            var timespannedReadings = measurements.Where(r => r.TimeStamp >= DateTime.Now - timeSpan).Select(r => r.Value);
            return timespannedReadings.Any() ? timespannedReadings.Average() : 0;
        }

        public double GetMin() => measurements.Min().Value;



        public double GetMax() => measurements.Max().Value;

        public void Log<TState>(LogLevel logLevel, EventId eventId, TState state, Exception exception, Func<TState, Exception, string> formatter)
        {
            throw new NotImplementedException();
        }

        public bool IsEnabled(LogLevel logLevel)
        {
            throw new NotImplementedException();
        }

        public IDisposable BeginScope<TState>(TState state) where TState : notnull
        {
            throw new NotImplementedException();
        }

        private void Log(string v)
        {
            Console.WriteLine(v);
        }
    }

    public class TemperatureReading
    {
        public double Value { get; set; }
        public DateTime TimeStamp { get; set; }

        public TemperatureReading(double value, DateTime timestamp)
        {
            this.Value = value;
            this.TimeStamp = timestamp;
        }
    }
}
