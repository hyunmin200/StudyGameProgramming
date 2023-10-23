using System;
using System.Collections.Specialized;

namespace MyApp // Note: actual namespace depends on the project name.
{
    class Program
    {
        interface IFlyable
        {
            void Fly();
        }

        class Bird : IFlyable
        {
            public void Fly()
            {
                Console.WriteLine("Fly~~");
            }
        }

        static void DoFly(IFlyable flyer)
        {
            flyer.Fly();
        }

        static void Main(string[] args)
        {
            Bird bird = new Bird();
            DoFly(bird);
        }
    }
}