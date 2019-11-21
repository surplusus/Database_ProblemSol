using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
            int[,] arr1 = { { 3, 2 }, { 1, 4 } };
            int[,] arr2 = { { 9, 2 }, { 1, 7 } };
            Matrix mat1 = new Matrix(arr1);
            Matrix mat2 = new Matrix(arr2);
            Matrix mul = mat1 * mat2;
            mul.Print();
            #endregion
        }
    }
}
