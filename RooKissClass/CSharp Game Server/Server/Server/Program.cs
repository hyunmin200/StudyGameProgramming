using System;
using static System.Collections.Specialized.BitVector32;
using System.Net;
using System.Text;
using ServerCore;

namespace Server // Note: actual namespace depends on the project name.
{


    class Program
    {
        static Listener _listener = new Listener();

        static void Main(string[] args)
        {
            // DNS (Domain Name System)
            string host = Dns.GetHostName();
            IPHostEntry ipHost = Dns.GetHostEntry(host);
            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint endPoint = new IPEndPoint(ipAddr, 7777); // 최종 주소


            _listener.Init(endPoint, () => { return new ClientSession(); });
            Console.WriteLine("Listening...");

            while (true)
            {
                ; // 프로그램 종료 되지 않게
            }
        }
    }
}