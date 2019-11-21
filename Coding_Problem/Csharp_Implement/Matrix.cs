using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_Implement
{
    class Matrix
    {
        public int[,] val { get; set; }
        public Matrix()
        {
            val = new int[2, 2];
        }
        public Matrix(int[,] arr)
        {
            val = arr;
        }
        public int this[int idx1, int idx2]
        {
            get { return val[idx1, idx2]; }
            set { val[idx1, idx2] = value; }
        }
        public static Matrix operator * (Matrix mat1, Matrix mat2)
        {
            Matrix result = new Matrix();
            result[0, 0] = mat1[0, 0] * mat2[0, 0] + mat1[0, 1] * mat2[1, 0];
            result[0, 1] = mat1[0, 0] * mat2[1, 0] + mat1[0, 1] * mat2[1, 1];
            result[1, 0] = mat1[1, 0] * mat2[0, 0] + mat1[1, 1] * mat2[1, 0];
            result[1, 1] = mat1[1, 0] * mat2[1, 0] + mat1[1, 1] * mat2[1, 1];
            return result;
        }
        public void Print()
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    Console.Write($"{val[i, j]} ");
                }
                Console.WriteLine();
            }
        }
    }
}
