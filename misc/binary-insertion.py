def binaryInsertion(a, e):
    if len(a) == 0:
        return 0   
    elif e <= a[0]:
        return 0    
    elif e > a[len(a)-1]:
         return len(a)    
    else:
        start = 0
        end = len(a)-1
        while start <= end: 
            m = (start + end) // 2
            if a[m-1] < e and a[m] >= e:
                return m
            elif e < a[m]:
                end = m-1
            elif e > a[m]:
                start = m+1
