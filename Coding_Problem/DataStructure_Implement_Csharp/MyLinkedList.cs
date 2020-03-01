using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructure_Implement_Csharp
{
    // 양방향 연결리스트 구현
    public class MyLinkedListNode<T>
    {
        public MyLinkedListNode<T> Next;
        public MyLinkedListNode<T> Prev;
        public T data;
    }
    class MyLinkedList<T>
    {
        MyLinkedListNode<T> root = null;
        MyLinkedListNode<T> tail = null;
        
        public MyLinkedListNode<T> AddLast(T value)
        {
            MyLinkedListNode<T> newNode = new MyLinkedListNode<T>();

            if (root == null)
            {
                root = newNode;
                root.Next = tail;
                tail = newNode;
            }

            if (tail != null)
            {
                newNode.Prev = tail;
                tail.Next = newNode;
                tail = newNode;
            }
            newNode.data = value;
            return newNode;
        }
        public void Remove(MyLinkedListNode<T> value)
        {
            MyLinkedListNode<T> cur = root;
            while(cur != null)
            {
                if (cur == value)
                {
                    cur.Prev.Next = cur.Next;
                    cur.Next.Prev = cur.Prev;
                    cur = null;
                    return;
                }
                cur = cur.Next;
            }
        }
        public void Remove(T value)
        {
            MyLinkedListNode<T> cur = root;
            while (true)
            {
                if (cur == null)
                    return;
                if (cur.data.Equals(value))
                    break;
                cur = cur.Next;
            }
            if (cur != null)
            {
                cur.Prev.Next = cur.Next;
                cur.Next.Prev = cur.Prev;
                cur = null;
            }
        }
    }
}
