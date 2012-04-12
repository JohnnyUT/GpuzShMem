using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GpuzDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            GpuzWrapper gpuz = new GpuzWrapper();
            gpuz.Open();

            Console.WriteLine(gpuz.ListAllData());
            Console.WriteLine();

            Console.WriteLine(gpuz.ListAllSensors());
            Console.WriteLine();

            Console.WriteLine(gpuz.DataKey(0) + ": " + gpuz.DataValue(0));
            Console.WriteLine(gpuz.SensorName(0) + ": " + gpuz.SensorValue(0) + " " + gpuz.SensorUnit(0));

            gpuz.Close();
            Console.WriteLine("Press ENTER to quit");
            Console.ReadLine();
        }
    }
}
