# baekjoon problem / 1541
# 잃어버린 괄호(greedy)
# '-' 표시가 나오면 다음 인덱스에 '('를 넣고
# 다음 '-'가 나오면 직전 인덱스에 ')'를 넣는다
# 쉬운 방법 : 그냥 - 부호를 만나면 이후 모든 숫자는 뺀다

N = str(input())

def output():
    token = '0'
    arr_plus = []
    arr_minus = []
    result = 0
    st = 0
    
    # 예외처리 : 부호가 없을 때
    if N.count('-') == 0 and N.count('+') == 0:
        return int(N)

    # 다음 연산자부터 반복
    m_flag = False
    cnt = 0;
    for i in range(len(N)):
        if N[i].isdigit():
            token += N[i]
        if  (i == len(N)-1) or not N[i].isdigit():
            if m_flag:
                result -= int(token)
            else:
                result += int(token)
            token = ''
        if N[i] == '-':
            m_flag = True
    return result

print(output())
