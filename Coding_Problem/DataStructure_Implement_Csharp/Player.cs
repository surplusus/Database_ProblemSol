using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructure_Implement_Csharp
{
    class Player
    {
        public int PosX { get; private set; } = 0;
        public int PosY { get; private set; } = 0;
        public int DestX { get; private set; }
        public int DestY { get; private set; }
        Maze maze = null;
        
        public Player SetMaze(Maze m)
        {
            maze = m;
            return this;
        }
        public Player SetStartPos(int x, int y)
        {
            PosX = x;
            PosY = y;
            return this;
        }
        public Player SetDestination(int x, int y)
        {
            DestX = x;
            DestY = y;
            return this;
        }
        const long INTERVAL_TICK = 100;
        long accumulateTick = 0;
        public void Update(long delta)
        {
            accumulateTick += delta;
            if (accumulateTick < INTERVAL_TICK)
                return;
            accumulateTick = 0;
            Update();
        }
        //상하좌우
        int[] dx = new int[4] { 0, 0, -1, 1 };
        int[] dy = new int[4] { -1, 1, 0, 0 };
        enum DIRECT
        {
            UP = 0, DOWN = 1, LEFT, RIGHT,
        }
        Random rand = new Random();
        void Update()
        {
            //랜덤으로길찾기();
            우수법칙으로길찾기();
            if (IsArrived())
            {
                Console.SetCursorPosition(15, 15);
                Console.WriteLine("도착해따!!!!!!!!!!!!");
                Environment.Exit(0);
            }
        }
        bool IsArrived()
        {
            if (PosX == DestX && PosY == DestY)
                return true;
            return false;
        }
        void 랜덤으로길찾기()
        {
            int direct = rand.Next(0, 4);
            int dr = PosY + dy[direct];
            int dc = PosX + dx[direct];
            if (dc > 0 && dr > 0 && dc < maze.Size && dr < maze.Size
                && maze.Grid[dr, dc] == GridType.Empty)
            {
                PosX = dc;
                PosY = dr;
            }
        }
        int fwX,fwY = 0;
        void 우수법칙으로길찾기()
        {
            // 바라보는 방향 만들기
            if (fwX == 0 && fwY == 0)
            {
                for (int i = 0; i < 4; ++i)
                {
                    fwX = PosX + dx[i];
                    fwY = PosY + dy[i];
                    if (maze.Grid[fwY, fwX] == GridType.Empty)
                        break;
                }
            }
            // 오른쪽으로 갈 수 있는지 확인

            // 직진으로 갈 수 있는지 확인

            // 왼쪽으로 간다
        }
    }
}
