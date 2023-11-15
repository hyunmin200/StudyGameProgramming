using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ServerCore
{
    class Program
    {
        static Listener _listener = new Listener();

        static void OnAcceptHandler(Socket ClientSocket)
        {
            try
            {
                Session session = new Session();

                session.Start(ClientSocket);
               
                // 전송한다..
                byte[] sendBuff = Encoding.UTF8.GetBytes($"WelComeToServer");
                session.Send(sendBuff);

                Thread.Sleep(1000);

                session.Disconnet();
            } 
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

        }

        static void Main(string[] args)
        {
            string host = Dns.GetHostName();
            IPHostEntry ipHost = Dns.GetHostEntry(host);
            IPAddress ipaddr = ipHost.AddressList[0];
            IPEndPoint endPoint = new IPEndPoint(ipaddr, 7777);

            _listener.Init(endPoint, OnAcceptHandler);
            Console.WriteLine("Listening...");

            // 프로그램 종료되지 않게
            while (true)
            {

            }
        }
    }
}