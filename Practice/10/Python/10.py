s = int(input())
l1 = int(input())
r1 = int(input())
l2 = int(input())
r2 = int(input())

if (s >= l1+l2 and s<=r1+r2):
    if (l1 + r2 - s == 0):
        print(l1, r2)
    elif (l1 + r2 - s < 0):
        print(l1-(l1+r2-s))
    elif (l1 + r2 - s > 0):
        print(l1, r2-(l1+r2-s))
else: print(-1)       
    



