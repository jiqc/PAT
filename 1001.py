def func():
    [a, b] = [int(x) for x in input().split()]
    s = a + b
    if s == 0:
        print('0')
    else:
        if s < 0:
            print('-', end = '')
            s = -s
        res = []
        while s >= 1000:
            res.append(str(s % 1000 + 1000)[1:])
            s = s // 1000
        res.append(str(s))
        print(','.join(res[::-1]))

if __name__ == '__main__':
    func()
