using System;
using LeetCode_Problem;

namespace Coding_Problem_In_Csharp {
    internal class Program {
        public static void Main(string[] args) {
            var func1 = new MajorityElement();
            int[] arr = new int[] {2, 2, 1, 1, 1, 2, 2};
            int[] arr1 = new int[] {3,2,3};
            int[] arr2 = new int[] {6,5,5};
            // Console.WriteLine(func1.Majority_Element(arr2));

            var func2 = new MyPow();
            Console.WriteLine(func2.myPow(2.000, 3));
            Console.WriteLine(func2.myPow(2.1000, 3));
            Console.WriteLine(func2.myPow(2.0000, -2147483648));

            var func3 = new BestTimeToBuyAndSellStock();
            Console.WriteLine(func3.Calculate(new []{7,1,5,3,6,4}));
        }
    }
}