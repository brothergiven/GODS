import functools

def compare(x,y):
    sol1 = x+y
    sol2 = y+x
    if int(sol1) > int(sol2):
        return 1  
    elif int(sol1) < int(sol2):
        return -1  
    return 0

def solution(numbers):
    n = [str(x) for x in numbers]
    n= sorted(n, key=functools.cmp_to_key(compare),reverse=True) #cmp_to_key 비교함수 compare-> 키 함수로 변환함
        #문자열의 비교 = 길이가 짧고 첫 문자가 같은 경우, 더 짧은 문자열이 더 큰 것으로 간주됨
    return str(int(''.join(n)))
    return answer
