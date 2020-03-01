using System;
using System.Collections.Generic;

namespace DataStructure_Implement_Csharp
{
    class Program
    {
        int[] staticList = new int[3];
        static void Main(string[] args)
        {
            MyList<int> myList = new MyList<int>();
            myList.Add(101);
            myList.Add(102);
            myList.Add(103);
            myList.Add(104);
            myList.Add(105);
            myList.RemoveAt(3);
            MyLinkedList<int> linkedList = new MyLinkedList<int>();
            linkedList.AddLast(101);
            linkedList.AddLast(102);
            var node = linkedList.AddLast(103);
            linkedList.AddLast(104);
            linkedList.AddLast(105);
            linkedList.Remove(node);
            linkedList.Remove(104);
            Console.WriteLine("Hello World!");
        }
    }
}
