def solution(bandage, health, attacks):
    success= bandage[0]
    recovery = bandage[1]
    add_health = bandage[2]
    
    max_health = health #최대 체력
    max_time = attacks[-1][0] #마지막 몬스터 공격 시간
    t=0 #현재 시간
    count = 0#붕대 회복 누적 시간
    
    while t < max_time:
        t+=1
        #공격 받을때
        if t== attacks[0][0]:
            health -= attacks[0][1]
            attacks.pop(0)
            #죽음
            if health<=0: 
                return -1
            count=0
        #공격 받지 않을때
        else:
            health +=recovery
            count+=1
            if count==success:
                health+=add_health
                count =0
                #체력 꽉 참
            if health>max_health:
                health = max_health
    return health
