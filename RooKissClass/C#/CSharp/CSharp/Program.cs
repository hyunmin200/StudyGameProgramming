namespace CSharp
{
    internal class Program
    {
        // 주석
        static void Main(string[] args)
        {
            // 데이터 + 로직
            // 체력 100 -> 0(데이터로 저장) 죽음(로직)

            // byte(1바이트, 양수 가능 0~255), short(2바이트), int(4바이트) ,long(8바이트)
            // sbyte(1바이트, 양수 음수 사용 가능 -128~127), ushort, uint, ulong
            int hp = 0;
            // id 계열은 Long으로 하는게 좋음

            int a = 0x0FFF;
            Console.WriteLine(a);

        }
    }
}