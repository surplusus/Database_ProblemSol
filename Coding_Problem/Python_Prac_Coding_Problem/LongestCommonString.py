# Elice Academy
# 최장 공통의 부분 문자열 (DP로 풀었음)

#### 시간초과 나왔음 ####
def LongestCommonString():
    in1 = input("입력1 :")
    in2 = input("입력2 :")

    sLong = in1
    sShort = in2
    if len(in1) < len(sShort):
        sLong, sShort = sShort, sLong

    for i in range(len(sLong)):
        for j in range(i + 1):
            sComp = sLong[j:len(sLong) - i + j]
            if sComp in sShort:
                print(sComp)
                print(len(sComp))
                return
    else:
        print("없습니다")

#LongestCommonString()


#### 오답 나왔음 ####
def string_set_tokenizer(s):
    return {s[i:j] for i in range(len(s)) for j in range(i, len(s)+1)}

#in1, in2 = input().split()
#result = max(string_set_tokenizer(in1) & string_set_tokenizer(in2))
#print(len(result))



#### 정답 나왔음 ####
def FindLCS(str1, str2):
    table = [[0] * (len(str2) + 1) for i in range(len(str1)+1)]
    LCS = 0;
    pos = 0;
    for r in range(1, len(str1) + 1):
        for c in range(1, len(str2) + 1):
            if str1[r - 1] == str2[c - 1]:
                table[r][c] = table[r-1][c-1] + 1
                if LCS <= table[r][c]:
                    LCS = table[r][c]
                    pos = r

    print(LCS)
    print(str1[pos-LCS:pos])
    #print(str1[pos:1])

in1, in2 = input().split()
FindLCS(in1, in2)