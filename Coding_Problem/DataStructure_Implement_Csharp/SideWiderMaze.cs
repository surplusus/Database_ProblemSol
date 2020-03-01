using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructure_Implement_Csharp
{
    class SideWiderMazeBuilder
    {
        Maze maze;
        public SideWiderMazeBuilder(Maze origin)
        {
            maze = origin;
        }
        public SideWiderMazeBuilder SetSize(int size)
        {
            maze.Size = size;
            maze.Grid = new GridType[size, size];
            return this;
        }
        public SideWiderMazeBuilder SetDefaultMap()
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
        public SideWiderMazeBuilder SetMaze()
        {
            int lastEmpty = maze.Size - 1;
            Random rand = new Random();
            for (int r = 0; r < lastEmpty; ++r)
            {
                if (r % 2 == 0)
                    continue;

                int count = 1;
                for (int c = 0; c < lastEmpty; ++c)
                {
                    if (c % 2 == 0)
                        continue;
                    if (rand.Next(0,2) == 0)
                    {
                        maze.Grid[r, c + 1] = c + 1 == lastEmpty ? GridType.Wall : GridType.Empty;
                        count++;
                    }
                    else
                    {
                        int randIdx = rand.Next(0, count);
                        maze.Grid[r + 1, c - randIdx * 2] = r + 1 == lastEmpty ? GridType.Wall : GridType.Empty;
                        count = 1;
                    }
                }
            }
            return this;
        }
    }
}
