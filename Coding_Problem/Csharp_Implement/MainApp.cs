using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Csharp_Implement
{
    class MainApp
    {
        static void Main(string[] args)
        {
            #region IEnumerable, IEnumerator
            //MyList list = new MyList();
            //for (int i = 0; i < 5; ++i)
            //    list[i] = i;
            //
            //foreach (int e in list)
            //    Console.WriteLine(e);
            #endregion
            #region Matrix
            //int[,] arr1 = { { 3, 2 }, { 1, 4 } };
            //int[,] arr2 = { { 9, 2 }, { 1, 7 } };
            //Matrix mat1 = new Matrix(arr1);
            //Matrix mat2 = new Matrix(arr2);
            //Matrix mul = mat1 * mat2;
            //mul.Print();
            #endregion
<<<<<<< HEAD
            #region EnumerableGeneric
            MyList<string> str_list = new MyList<string>();
            str_list[0] = "abc";
            str_list[1] = "def";
            str_list[2] = "ghi";
            str_list[3] = "jkl";
            str_list[4] = "mno";

            foreach (string str in str_list)
            {
                Console.WriteLine(str);
            }
            Console.WriteLine();

            MyList<int> int_list = new MyList<int>();
            int_list[0] = 0;
            int_list[1] = 1;
            int_list[2] = 2;
            int_list[3] = 3;
            int_list[4] = 4;

            foreach (int n in int_list)
            {
                Console.WriteLine(n);
            }
=======
            #region Serialization
            //Stream ws = new FileStream("a.dat", FileMode.Create);
            //BinaryFormatter serializer = new BinaryFormatter();
            //
            //NameCard nc = new NameCard() { Name = "박상현", Phone = "010-123-4567", Age = 33 };
            //
            //serializer.Serialize(ws, nc);
            //ws.Close();
            //
            //Stream rs = new FileStream("a.dat", FileMode.Open);
            //BinaryFormatter deserializer = new BinaryFormatter();
            //
            //NameCard nc2;
            //nc2 = (NameCard)deserializer.Deserialize(rs);
            //rs.Close();
            //
            //Console.WriteLine($"Name : {nc2.Name}");
            //Console.WriteLine($"Phone : {nc2.Phone}");
            //Console.WriteLine($"Age  : {nc2.Age}");
            #endregion
            #region BasicThread
            //Thread t1 = new Thread(new ThreadStart(BasicThread.DoSomething));
            //
            //Console.WriteLine("Starting thread...");
            //
            //t1.Start();
            //
            //for (int i = 0; i < 5; i++)
            //{
            //    Console.WriteLine($"main : {i}");
            //    Thread.Sleep(10);
            //}
            //
            //Console.WriteLine("Wating until thread stops...");
            //t1.Join();
            //
            //Console.WriteLine("Finished");
            #endregion
            #region InterruptingThread
            //SideTask task = new SideTask(100);
            //Thread t1 = new Thread(new ThreadStart(task.KeepAlive));
            //
            //Console.WriteLine("Starting thread..");
            //t1.Start();
            //
            //Thread.Sleep(10);
            //
            //Console.WriteLine("Interrupting thread...");
            //t1.Interrupt();
            //
            //Console.WriteLine("Wating until thread stops....");
            //t1.Join();
            //
            //Console.WriteLine("Finished");
            #endregion
            #region Syncronize
            //Counter counter = new Counter();
            //Thread incThread = new Thread(new ThreadStart(counter.Increase));
            //Thread decThread = new Thread(new ThreadStart(counter.Decrease));
            //
            //incThread.Start();
            //decThread.Start();
            //
            //incThread.Join();
            //decThread.Join();
            //
            //Console.WriteLine(counter.Count);
            #endregion
            #region UsingTask
            //string srcFile = args[0];
            //
            //Action<object> FileCopyAction = (object state) =>
            //{
            //    string[] paths = (String[])state;
            //    File.Copy(paths[0], paths[1]);
            //
            //    Console.WriteLine("TaskID:{0}, ThreadID: {1}, {2} was copied to {3}"
            //        , Task.CurrentId, Thread.CurrentThread.ManagedThreadId
            //        , paths[0], paths[1]);
            //};
            //
            //Task t1 = new Task(FileCopyAction, new string[] { srcFile, srcFile + ".copy1" });
            //
            //Task t2 = Task.Run(() =>
            // {
            //     FileCopyAction(new string[] { srcFile, srcFile + ".copy2" });
            // });
            //
            //t1.Start();
            //
            //Task t3 = new Task(FileCopyAction, new string[] { srcFile, srcFile + ".copy3" });
            //
            //t3.RunSynchronously();
            //
            //t1.Wait();
            //t2.Wait();
            //t3.Wait();
>>>>>>> fec48350cc5abd928186c25326a8a2cad892d388
            #endregion
        }
    }
}
