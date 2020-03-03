 using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace DataStructure_Implement_Csharp
{

    class Program
    {
        public const char CIRCLE = '\u25cf';
        const long TIME_LIMIT = 1000 / 10;
        static int FPS = 0;
        static void Main(string[] args)
        {
            // 동적 배열 링크드리스트 테스트
            {
                //MyList<int> myList = new MyList<int>();
                //myList.Add(101);
                //myList.Add(102);
                //myList.Add(103);
                //myList.Add(104);
                //myList.Add(105);
                //myList.RemoveAt(3);
                //MyLinkedList<int> linkedList = new MyLinkedList<int>();
                //linkedList.AddLast(101);
                //linkedList.AddLast(102);
                //var node = linkedList.AddLast(103);
                //linkedList.AddLast(104);
                //linkedList.AddLast(105);
                //linkedList.Remove(node);
                //linkedList.Remove(104);
            }
            // 길찾기 게임 루틴
            #region 초기 설정
            //int currentTick = Environment.TickCount;
            Stopwatch watch = Stopwatch.StartNew();
            var currentTime = watch.ElapsedMilliseconds;
            long currentTick = watch.ElapsedMilliseconds;
            int accumulatedCount = 0;
            Console.CursorVisible = false;
            #endregion
            var dest = new { X = 25 - 2, Y = 25 - 2 };
            var maze = new Maze();
            new BinaryMazeBuilder(maze).SetSize(25).SetDefaultMap().SetMaze();
            new SideWiderMazeBuilder(maze).SetSize(25).SetDefaultMap().SetMaze();
            var player = new Player().SetStartPos(1, 1).SetMaze(maze).SetDestination(dest.X, dest.Y);
            maze.SetDestination(dest.X, dest.Y).SetPlayer(player);
            while (true)
            {
                #region 프로그램 중지 루틴
                if (Console.KeyAvailable)
                {
                    ConsoleKeyInfo key = Console.ReadKey(false);
                    Console.WriteLine("\n ESC를 누르면 종료됩니다.");
                    if (key.Key == ConsoleKey.Escape)
                        break;
                }
                #endregion
                #region FPS
                //int elapsedTick = Environment.TickCount;
                //if (elapsedTick - currentTick < TIME_LIMIT)
                //    continue;
                //currentTick = Environment.TickCount;
                long elapsedTick = watch.ElapsedMilliseconds;
                long deltaTick = elapsedTick - currentTick;
                if (deltaTick < TIME_LIMIT)
                    continue;
                currentTick = watch.ElapsedMilliseconds;

                long elapsedTime = watch.ElapsedMilliseconds;
                accumulatedCount++;
                if (elapsedTime - currentTime >= 1000)
                {
                    currentTime = elapsedTime;
                    FPS = accumulatedCount;
                    accumulatedCount = 0;
                }
                #endregion
                // 입력

                // 로직
                player.Update(deltaTick);
            // 그리기
                Console.SetCursorPosition(0, 0);
                Console.WriteLine(FPS);
                maze.Render();
            }
            watch.Stop();
        }
    }
}
