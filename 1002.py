def func():
    L1 = [float(x) for x in input().split()]
    L2 = [float(x) for x in input().split()]
    res = []
    i1, i2 = 1, 1
    while i1 < len(L1) and i2 < len(L2):
        if L1[i1] == L2[i2]:
            temp = L1[i1 + 1] + L2[i2 +1]
            if temp != 0:
                res.append(L1[i1])
                res.append(temp)
            i1 = i1 + 2
            i2 = i2 + 2
        elif L1[i1] > L2[i2]:
            res.append(L1[i1])
            res.append(L1[i1 + 1])
            i1 = i1 + 2
        else:
            res.append(L2[i2])
            res.append(L2[i2 +1])
            i2 = i2 + 2

    if i1 < len(L1):
        res = res + L1[i1:]
    if i2 < len(L2):
        res = res + L2[i2:]

    print(len(res)//2, end = '')
    for i in range(len(res)):
        if i % 2 == 0:
            res[i] = int(res[i])
            print(' %d' % res[i], end = '')
        else:
            print(' %.1f' % res[i], end = '')
    print('')

if __name__ == '__main__':
    func()
