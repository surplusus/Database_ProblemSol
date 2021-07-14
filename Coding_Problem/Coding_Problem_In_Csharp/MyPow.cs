using System;

namespace LeetCode_Problem {
    public class MyPow {
        public double myPow(double x, double n) {
            if (n == 0 || x == 1)
                return 1;
            else if (n == 1 || x == 0)
                return x;
            else if (n < 0)
                return 1 / myPow(x, -n);
            else if (n % 2 == 0)
                return myPow(x * x, n / 2);
            return x * myPow(x, n -1);
        }
    }
}