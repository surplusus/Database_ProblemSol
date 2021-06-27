using System;
using LeetCode_Problem;

namespace Coding_Problem_In_Csharp {
    internal class Program {
        public static void Main(string[] args) {
            var func = new MajorityElement();
            int[] arr = new int[] {2, 2, 1, 1, 1, 2, 2};
            int[] arr1 = new int[] {3,2,3};
            int[] arr2 = new int[] {6,5,5};
            Console.WriteLine(func.Majority_Element(arr2));
            
        }
    }
}