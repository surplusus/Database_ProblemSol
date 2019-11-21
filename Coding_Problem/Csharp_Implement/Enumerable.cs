using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_Implement
{
    class MyList : IEnumerable, IEnumerator
    {
        private int[] array;
        int position = -1;

        public MyList()
        {
            array = new int[3];
        }
        public int this[int idx]
        {
            get
            {
                return array[idx];
            }
            set
            {
                if (idx >= array.Length)
                {
                    Array.Resize<int>(ref array, idx + 1);
                    Console.WriteLine($"Array Resized : {array.Length}");
                }
                array[idx] = value;
            }
        }
        public object Current
        {
            get
            {
                return array[position];
            }
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
        public void Reset()
        {
            position = -1;
        }
        public IEnumerator GetEnumerator()
        {
            for (int i = 0; i < array.Length; ++i)
            {
                yield return (array[i]);
            }
        }
    }

}
