import random
t = 10
file = open('geek.txt','w')
file.write(str(t) + "\n")
for i in range(1, t+1):
    n = random.randint(1, 10); m = random.randint(1, 10)
    file.write(str(n) + "\n")
    file.write(str(m) + "\n")
    j = i
    lst = []
    for j in range(i, i+m):
        startHouse = random.randint(1, i+m)
        endHouse = random.randint(1, i+m)
        while(endHouse == startHouse):
            endHouse = random.randint(1, i+m)
        if startHouse > endHouse:
            startHouse, endHouse = endHouse, startHouse
        lst.append([startHouse, endHouse])
    lst.sort()
    for num in lst:
        file.write("{} {}\n".format(num[0], num[1]))