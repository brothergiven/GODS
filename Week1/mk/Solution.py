def solution(a, b, g, s, w, t):
    left, right = 0, 10**9
    answer = right
    
    while left <= right:
        mid = (left + right) // 2
        total_gold = 0
        total_silver = 0
        total_mineral = 0
        for i in range(len(g)):
            max_transport = (mid // (2 * t[i])) * w[i] 
            if mid % (2 * t[i]) >= t[i]:  
                max_transport += w[i]
            
            transport_gold = min(g[i], max_transport)
            transport_silver = min(s[i], max_transport)
            
            total_gold += transport_gold
            total_silver += transport_silver
            total_mineral += min(g[i] + s[i], max_transport)
        
        if total_gold >= a and total_silver >= b and total_mineral >= a + b:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return answer
