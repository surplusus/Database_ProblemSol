# baekjoon problem / 11399
# ATM (greedy)
# 입력값만큼 사람들이 인출하는데 시간이 걸린다
# 시간을 누적하여 돈뽑는 최소 시간을 만들자
# 인출 시간이 적게 걸리는 순으로 정렬하고 
# 새로운 list에 누적 시간을 기입하자

if __name__ == '__main__':
    N = int(input())
    P = list(map(int, input().split()))

P.sort()
result = [int(P[0])]
sum = P[0];
for i in range(1, len(P)):
    tmp = result[i-1] + P[i]
    result.append(tmp)
    sum += result[i]

print(sum)