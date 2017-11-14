from collections import deque
def func():
    [N, M] = [int(i) for i in input().split()]
    person = {}
    for _ in range(M):
        tempL = [int(i) for i in input().split()]
        person[tempL[0]] = tempL[2:]
    d = deque()
    d.append(1)
    res = []
    while len(d) > 0:
        L = len(d)
        t = 0
        for _ in range(L):
            s = d.popleft()
            if s in person:
                for x in person[s]:
                    d.append(x)
            else:
                t += 1
        res.append(t)

    print(res[0], end = '')
    for i in res[1:]:
        print('', i, end = '')
    print('')

if __name__ == '__main__':
    func()
