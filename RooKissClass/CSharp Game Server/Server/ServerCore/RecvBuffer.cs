using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ServerCore
{
    public class RecvBuffer
    {
        private ArraySegment<byte> _buffer;
        // 커서
        private int _readPos;
        private int _writePos;

        public RecvBuffer(int bufferSize)
        {
            _buffer = new ArraySegment<byte>(new byte[bufferSize], 0, bufferSize);
        }

        // 유효 범위 ( WritePos - ReadPos )
        public int DataSize
        {
            get { return _writePos - _readPos; }
        }

        // 남은 범위 ( 사용할 수 있는 범위 )
        public int FreeSize
        {
            get { return _buffer.Count - _writePos; }
        }

        // 유효 범위의 세그먼트 ( 어디부터 데이터를 읽으면 되나요? )
        public ArraySegment<byte> ReadSegment
        {
            get { return new ArraySegment<byte>(_buffer.Array, _buffer.Offset + _readPos, DataSize); }
        }

        // 남은 범위 ( 사용할 수 있는 범위 )
        public ArraySegment<byte> WriteSegment
        {
            get { return new ArraySegment<byte>(_buffer.Array, _buffer.Offset + _writePos, FreeSize); }
        }

        // 중간중간 커서들을 초기화 ( 버퍼 고갈을 막기 위해 )
        public void Clean()
        {
            int dataSize = DataSize;
            // r, w 위치가 같다. ( 모든 데이터 처리 완료 )
            if (dataSize == 0)
            {
                // 남은 데이터가 없으면 복사하지 않고 커서 위치만 리셋
                _readPos = _writePos = 0;
            }
            else
            {
                // 남은 찌그레기가 있으면 시작 위치로 복사
                Array.Copy(_buffer.Array, _buffer.Offset + _readPos, _buffer.Array, _buffer.Offset, dataSize);
                _readPos = 0;
                _writePos = dataSize;
            }
        }

        public bool OnRead(int numOffBytes)
        {
            if (numOffBytes > DataSize)
                return false;

            _readPos += numOffBytes;
            return true;
        }

        public bool OnWirte(int numOfbytes)
        {
            if(numOfbytes > FreeSize) 
                return false;

            _writePos += numOfbytes;
            return true;
        }
    }
}
