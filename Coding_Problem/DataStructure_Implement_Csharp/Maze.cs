using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructure_Implement_Csharp
{
    class Maze
    {
        public GridType[,] Grid;
        public int Size;

        public void Render()
        {
            if (Grid == null)
                return;

            for (int r = 0; r < Size; ++r)
            {
                for (int c = 0; c < Size; ++c)
                {
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
                    Console.Write(Program.CIRCLE);
                }
                Console.WriteLine();
            }
        }
    }
}
