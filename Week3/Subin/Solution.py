def solution(n, arr1, arr2):
    answer = []
    for x in range(n):
        binary = (bin(arr1[x]|arr2[x])[2:]) #or 비트연산자를 이용해 2진수를 비교했다.
        binary = '0'*(n-len(binary))+binary #길이가 다르니 오류가 나서 길이를 맞추기 위해 앞에 0을 추가했다
        binary = binary.replace('1','#').replace('0',' ') #1을 #으로 0을 빈칸으로 대치했다
        answer.append(binary) #연산결과를 배열 answer에 추가했다.
    return answer        



