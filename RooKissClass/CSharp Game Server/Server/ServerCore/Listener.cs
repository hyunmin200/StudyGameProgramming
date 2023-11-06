using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ServerCore
{
    public class Listener
    {
        Socket _listenSocket;
        private Func<Session> _sessionFactory;

        public void Init(IPEndPoint endPoint, Func<Session> sessionFactory)
        {
            _listenSocket = new Socket(endPoint.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            _sessionFactory += sessionFactory;

            // 문지기 교육
            _listenSocket.Bind(endPoint);

            // 영업 시작
            // backlog : 최대 대기수
            _listenSocket.Listen(10);

            SocketAsyncEventArgs args = new SocketAsyncEventArgs();
            args.Completed += new EventHandler<SocketAsyncEventArgs>(OnAcceptCompleted);
            RegisterAccept(args); // 낚시대를 던짐
        }

        void RegisterAccept(SocketAsyncEventArgs args) // 등록 되었을 때
        {
            args.AcceptSocket = null; // 기존의 잔재들을 모두 없애고 시작하기 위해 null로 초기화

            bool pending = _listenSocket.AcceptAsync(args); // 물고기가 잡혔는가? 여부
            if (pending == false) // 바로 잡히면 처리
                OnAcceptCompleted(null, args);
            // 만약 잡히지 않으면 위에 EventHandler에서 처리해서 OnAcceptCompleted 실행
        }

        void OnAcceptCompleted(object sender, SocketAsyncEventArgs args) // 처리가 완료 되었을 때
        {
            if (args.SocketError == SocketError.Success) // 소켓 에러가 성공이라면
            {
                // 세션 만들어 주기!
                Session session = _sessionFactory.Invoke();
                session.Start(args.AcceptSocket);
                session.OnConnected(args.AcceptSocket.RemoteEndPoint);
            }
            else // 에러 뜨면
                Console.WriteLine(args.SocketError.ToString());

            RegisterAccept(args); // 다시 낚시대 던지기
        }
    }
}
