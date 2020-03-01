using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructure_Implement_Csharp
{
    class BinaryMazeBuilder
    {
        public BinaryMazeBuilder(Maze origin)
        {
            maze = origin;
        }

        Maze maze;

        public BinaryMazeBuilder SetSize(int size)
        {
            maze.Size = size;
            maze.Grid = new GridType[size, size];
            return this;
        }
        public BinaryMazeBuilder SetDefaultMap()
        {
            //  기본 맵 만들기
            for (int r = 0; r < maze.Size; ++r)
            {
                for (int c = 0; c < maze.Size; ++c)
                {
                    maze.Grid[r, c] = GridType.Empty;
                    if (r == maze.Size - 1 || c == maze.Size - 1 || r % 2 == 0 || c % 2 == 0)
                        maze.Grid[r, c] = GridType.Wall;
                }
            }
            return this;
        }
        public BinaryMazeBuilder SetMaze()
        {
            // 벽 뚫기
            Random rand = new Random();
            int lastEmpty = maze.Size - 1;
            for (int r = 1; r < lastEmpty; ++r)
            {
                for (int c = 1; c < lastEmpty; ++c)
                {
                    if (r % 2 == 1 && c % 2 == 1)
                    {
                        if (rand.Next(0, 2) == 0)
                            maze.Grid[r, c +1] = c + 1 == lastEmpty ? GridType.Wall : GridType.Empty;
                        else
                            maze.Grid[r +1, c] = r + 1 == lastEmpty ? GridType.Wall : GridType.Empty;
                    }
                }
            }
            return this;
        }
    }
}
