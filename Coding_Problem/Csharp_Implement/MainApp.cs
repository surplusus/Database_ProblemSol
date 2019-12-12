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
            //int[,] arr1 = { { 3, 2 }, { 1, 4 } };
            //int[,] arr2 = { { 9, 2 }, { 1, 7 } };
            //Matrix mat1 = new Matrix(arr1);
            //Matrix mat2 = new Matrix(arr2);
            //Matrix mul = mat1 * mat2;
            //mul.Print();
            #endregion
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
            #endregion
        }
    }
}
