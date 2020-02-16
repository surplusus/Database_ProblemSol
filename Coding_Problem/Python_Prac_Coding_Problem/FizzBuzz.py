import sys
from math import cos, radians

print("Hello Python World!")

prograsive_radian = []
for i in range(360,0,-20):
    prograsive_radian.append(cos(radians(i)))

def fizzbuzz():
    for i in range(30):
        is_fizz = i % 3 == 0
        is_buzz = i % 5 == 0
        if is_fizz or is_buzz:
            print('Fizz' * is_fizz + 'Buzz' * is_buzz)
        else:
            print(i)

fizzbuzz()


    