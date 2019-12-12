using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_Implement
{
    class MyList<T> : IEnumerable<T>, IEnumerator<T>
    {
        private T[] array;
        int position = -1;

        public MyList()
        {
            array = new T[3];
        }
        public T this[int idx]
        {
            get
            {
                return array[idx];
            }
            set
            {
                if (idx >= array.Length)
                {
                    Array.Resize<T>(ref array, idx + 1);
                    Console.WriteLine($"Array Resized : {array.Length}");
                }
                array[idx] = value;
            }
        }
        public int Length { get { return array.Length; } }
        public IEnumerator<T> GetEnumerator()
        {
            for (int i = 0; i < array.Length; i++)
            {
                yield return array[i];
            }
        }
        public T Current { get { return array[position]; } }
        object IEnumerator.Current { get { return array[position]; } }
        public void Reset()
        {
            position = -1;
        }
        public bool MoveNext()
        {
            if (position == array.Length - 1)
            {
                Reset();
                return false;
            }
            ++position;
            return (position < array.Length);
        }
        public void Dispose()
        {
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            for (int i = 0; i < array.Length; ++i)
                yield return array[i];
        }
    }
}
