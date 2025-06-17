using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Challenge_2
{
    class ActuatorController : IActuatorController
    {
        private Dictionary<int, Actuator> actuatorDict { get; set; } = new Dictionary<int, Actuator>();

        public void AddActuator(Actuator actuator)
        {
            actuator.CheckAndRaiseEvents += (sender, e) =>
            {
                Console.WriteLine($"[ALERT] Threshold exceeded by actuator ID: {((Actuator)sender).Id}");
            };
            actuator.StateChanged += (sender, isActive) =>
            {
                Console.WriteLine($"[INFO] Actuator ID: {((Actuator)sender).Id} changed state to: {(isActive ? "ACTIVE" : "INACTIVE")}");
            };
            actuatorDict.Add(actuator.Id, actuator);
        }
        public void ActivateActuator(int id)
        {
            actuatorDict[id].Activate();
        }
        public void DeactivateActuator(int id)
        {
            actuatorDict[id].Deactivate();
        }
        public void PrintStatus()
        {
            foreach (var act in actuatorDict)
            {
                Console.WriteLine($"id:{act.Value.Id}; isActive:{act.Value.isActive}; lastUpdated:{act.Value.lastUpdated}; temperature:{act.Value.temperature}; PowerUsage:{act.Value.PowerUsage}");
            }
        }
        public async Task Simulate()
        {
            try
            {
                TimeSpan simulationTime = TimeSpan.FromSeconds(30);
                CancellationTokenSource cts = new CancellationTokenSource(simulationTime);
                var updateTask = Task.Run(async () =>
                {
                    do
                    {
                        foreach (var act in actuatorDict)
                        {
                            act.Value.UpdateSensorData();
                        }
                        await Task.Delay(1000);
                    } while (!cts.IsCancellationRequested);
                });

                var printTask = Task.Run(async () =>
                {
                    do
                    {
                        PrintStatus();
                        await Task.Delay(5000);
                    } while (!cts.IsCancellationRequested);
                });

                var getInputTask = Task.Run(async () =>
                {
                    Console.WriteLine("Press ENTER to end the simulation: ");
                    Console.ReadLine();
                    cts.Cancel();
                });

                await Task.WhenAny(Task.WhenAll(updateTask, printTask), getInputTask);
            }
            catch (OperationCanceledException)
            {
                Console.WriteLine("Simlation cancelled");
            }
        }

        public void GetActiveActuators()
        {
            var ids = actuatorDict.Where(act => act.Value.isActive).Select(act => act.Key);
            Console.WriteLine("Active actuators:");
            foreach (var id in ids)
            {
                Console.WriteLine(id);
            }
        }

        public void GetHighUsageActuators(double threshold)
        {
            var ids = actuatorDict.Where(act => act.Value.PowerUsage > threshold).Select(act => act.Key);
            Console.WriteLine($"Actuators with PowerUsage above {threshold}:");
            foreach (var id in ids)
            {
                Console.WriteLine(id);
            }
        }
    }
}
