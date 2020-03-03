using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructure_Implement_Csharp
{
    public enum GridType
    {
        Empty,
        Wall,
    }

    class Maze
    {
        public GridType[,] Grid { get; set; }
        public int Size;
        Player player = null;
        int DestX, DestY = 0;
        
        public Maze SetDestination(int x, int y)
        {
            DestX = x;
            DestY = y;
            return this;
        }
        public void SetPlayer(Player p)
        {
            player = p;
        }
        public void Render()
        {
            if (Grid == null)
                return;

            for (int r = 0; r < Size; ++r)
            {
                for (int c = 0; c < Size; ++c)
                {
                    // 바닥 그리기
                    switch (Grid[r, c])
                    {
                        case GridType.Empty:
                            Console.ForegroundColor = ConsoleColor.Green;
                            break;
                        case GridType.Wall:
                            Console.ForegroundColor = ConsoleColor.Red;
                            break;
                        default:
                            break;
                    }
                    // player 그리기
                    if (player.PosX == c && player.PosY == r)
                        Console.ForegroundColor = ConsoleColor.Blue;
                    // Destination 그리기
                    if (DestX == c && DestY == r)
                        Console.ForegroundColor = ConsoleColor.DarkYellow;
                    Console.Write(Program.CIRCLE);
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = ConsoleColor.White;
        }
    }
}
