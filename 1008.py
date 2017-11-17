def func():
    L = [int(i) for i in input().split()]
    L[0] = 0
    res = 0
    for i in range(len(L))[1:]:
        t = L[i] - L[i-1]
        if t > 0:
            res += t * 6
        else:
            res += t * (-4)
    res += 5 *(len(L)-1)
    print(res)

if __name__ == '__main__':
    func()

