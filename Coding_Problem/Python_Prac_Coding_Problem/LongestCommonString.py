# Elice Academy
# 최장 공통의 부분 문자열 
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

LongestCommonString()

# 위 알고리즘은 시간초과 나왔음

def string_set_tokenizer(s):
    return {s[i:j] for i in range(len(s)) for j in range(i, len(s)+1)}

in1, in2 = input().split()
result = max(string_set_tokenizer(in1) & string_set_tokenizer(in2))
print(len(result))

# 위 알고리즘은 오답 나왔음