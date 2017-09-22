def func():
    n = int(input())
    l = [int(i) for i in input().split(' ')]
    newl = sorted(l, reverse = True)
    m = 0
    while m < n and newl[m] > m+1:
        m += 1
    print(m)

if __name__ == '__main__':
    func()
