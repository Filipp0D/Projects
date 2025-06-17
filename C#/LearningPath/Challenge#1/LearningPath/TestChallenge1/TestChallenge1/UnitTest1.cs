using Xunit;
using LearningPath;

namespace TestChallenge1
{
    public class UnitTest1
    {
        [Fact]
        public void AddReading_ShouldIncreaseCount_AndAffectAverage()
        {
            // Arrange
            ITemperatureSensor sensor = new TemperatureSensor();

            // Act
            sensor.AddReading(10.0);
            sensor.AddReading(20.0);
            var average = sensor.GetAverageTemperature();

            // Assert
            Assert.Equal(15.0, average);
        }

        [Fact]
        public void GetAverageTemperature_ShouldReturnZero_WhenNoReadings()
        {
            // Arrange
            ITemperatureSensor sensor = new TemperatureSensor();

            // Act
            var average = sensor.GetAverageTemperature();

            // Assert
            Assert.Equal(0, average);
        }

        [Fact]
        public void AddReading_ShouldKeepOnlyLastTenValues()
        {
            // Arrange
            ITemperatureSensor sensor = new TemperatureSensor();

            // Act
            for (int i = 1; i <= 15; i++) // Aggiunge 15 letture
            {
                sensor.AddReading(i); // 6–15 dovrebbero restare
            }

            var average = sensor.GetAverageTemperature(); // media di 6..15 = 10.5

            // Assert
            Assert.Equal(10.5, average);

        }
    }
}