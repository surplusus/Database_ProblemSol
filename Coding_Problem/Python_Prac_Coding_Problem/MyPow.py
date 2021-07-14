# LeetCode - 50. Pow(x, n)
# https://leetcode.com/problems/powx-n/

def myPow(self, x: float, n: int) -> float:
    if n == 0 or x == 1:
        return 1
    if x == 0 or n == 1:
        return x
    if x % 2:
        return self.myPow(x * x, n / 2)
    if n < 0:
        return 1 / self.myPow(x, -n)
    return x * self.myPow(x, n - 1)


# print(myPow(float(2.000), int(3)))
print(myPow(2.1000, 3))
print(myPow(2.0000, -2))
