# HackerRank
# Lists

if __name__ == '__main__':
    N = int(input())

result = []
while N > 0:
    N -= 1
    q = input().split()
    order = q[0]
    if order == "insert":
        result.insert(int(q[1]),int(q[2]))
    elif order == "print":
        print(result)
    elif order == "remove":
        result.remove(int(q[1]))
    elif order == "append":
        result.append(int(q[1]))
    elif order == "sort":
        result.sort()
    elif order == "pop":
        result.pop()
    elif order == "reverse":
        result.reverse()
