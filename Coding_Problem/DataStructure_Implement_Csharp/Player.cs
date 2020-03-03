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
        const long INTERVAL_TICK = 50;
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
        int[] dx = new int[4] { -1, 0, 1, 0 };
        int[] dy = new int[4] { 0, -1, 0, 1 };
        enum DIRECT
        {
            LEFT = 0, UP = 1, RIGHT, DOWN, END
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
        int fPos = (int)DIRECT.END;
        void 우수법칙으로길찾기()
        {
            // 바라보는 방향 만들기
            if (fPos == (int)DIRECT.END)
            {
                for (int i = 0; i < 4; ++i)
                {
                    int fwY = PosY + dy[i];
                    int fwX = PosX + dx[i];
                    if (maze.Grid[fwY, fwX] == GridType.Empty)
                    {
                        fPos = i;
                        break;
                    }
                }
            }

            int left = fPos - 1;
            int forward = (int)fPos;
            int right = Math.Clamp((int)fPos + 1, 0, (int)DIRECT.END -1);
            int[] dir = new int[4] { (fPos + 1) % 4, fPos, (fPos - 1 + 4) % 4, (fPos + 2) % 4 };
            
            int dr = 0, dc = 0;
            Func<int, bool> func_IsAbleToRotate = delegate(int d)
            {
                dr = PosY + dy[d]; dc = PosX + dx[d];
                if (maze.Grid[dr, dc] == GridType.Empty)
                    return true;
                return false;
            };
            //  
            foreach (int d in dir)
            {
                dr = PosY + dy[d]; dc = PosX + dx[d];
                if (maze.Grid[dr, dc] == GridType.Empty 
                    && dr >0 && dc>0 && dr<maze.Size && dc<maze.Size)
                {
                    PosX = dc; PosY = dr;
                    fPos = d;
                    return;
                }
            }
        }
    }
}
