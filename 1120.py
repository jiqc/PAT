def func():
    d = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
    n = int(input())
    nums = input().split()
    s = set()
    for num in nums:
        t = 0
        for c in num:
            t += d[c]
        s.add(t)
    res = sorted(s)
    print(len(res))
    if res:
        print(res[0],end = '')
        for x in res[1:]:
            print(' ', x, sep = '', end = '')
        print('',end = '\n')
    
if __name__ == '__main__':
    func()
