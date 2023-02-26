import random

t = 1
file = open('testCases.txt', 'w')
file.write(str(t) + "\n")
for tc in range(1, t + 1):
    n = random.randint(1, 4000)
    m = random.randint(1, 4000)
    file.write(str(n) + "\n")
    file.write(str(m) + "\n")
    j = tc
    lst = []
    for j in range(tc, tc + m):
        startHouse = random.randint(1, tc + m)
        endHouse = random.randint(1, tc + m)
        while endHouse == startHouse:
            endHouse = random.randint(1, tc + m)
        if startHouse > endHouse:
            startHouse, endHouse = endHouse, startHouse
        lst.append([startHouse, endHouse])
    lst.sort()
    for num in lst:
        file.write("{} {}\n".format(num[0], num[1]))
