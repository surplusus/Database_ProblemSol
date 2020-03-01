using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructure_Implement_Csharp
{
    // 동적 배열 구현
    public class MyList<T>
    {
        const int DEFAULT_SIZE = 1;
        T[] data = new T[DEFAULT_SIZE];
        public int Capacity { get => data.Length; }
        public int Count = 0;

        public void Add(T value)
        {
            if (Count >= Capacity)
            {
                T[] newData = new T[Count * 2];
                for (int i = 0; i < Count; ++i)
                {
                    newData[i] = data[i];
                }
                data = newData;
            }

            data[Count] = value;
            Count++;
        }
        public T this[int index]
        {
            get => data[index];
            set => data[index] = value;
        }
        public void RemoveAt(int index)
        {
            for (int i = index-1; i < Count-1; ++i)
            {
                data[i] = data[i + 1];
            }
            data[Count - 1] = default(T);
            Count--;
        }
    }
}
