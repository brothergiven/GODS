def solution(arr):
    result=[]
    result.append(arr[0])
    i=0
    while(i<len(arr)-1):
        if arr[i]==arr[i+1]:
            i+=1
        else:
            result.append(arr[i+1])
            i+=1
              
    return result
arr=[4,4,4,3,3]
print(solution(arr))
