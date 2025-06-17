using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;

namespace LearningPath
{
    class Program
    {
        static void Main(string[] args)
        {

            using IHost host = Host.CreateDefaultBuilder(args)
            .ConfigureServices((context, services) =>
            {
                services.AddTransient<MyService>();
            })
            .Build();

            var logger = host.Services.GetRequiredService<ILogger<TemperatureSensor>>();

            TemperatureSensor ts = new TemperatureSensor(logger);
            ts.AddReading(3.14);
            ts.AddReading(5.09);
            ts.AddReading(21.4);
            ts.AddReading(82.75);


            Console.WriteLine(ts.GetAverageTemperature());
        }

        class MyService
        {
            private readonly ILogger<MyService> _logger;

            public MyService(ILogger<MyService> logger)
            {
                _logger = logger;
                _logger.LogInformation("Servizio avviato");
            }
        }
    }
}
