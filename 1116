from math import sqrt

def isprime(num):
    if num > 1 and num % 2:
        for i in range(3,int(sqrt(num)) + 1,2):
            if (num % i) == 0:
                return False
        return True
    return False

def func():
    d = {}
    n = int(input())
    for i in range(1, n+1):
        id = input()
        if i == 1:
            d[id] = 1
        elif isprime(i):
            d[id] = 2
        else:
            d[id] = 3
    k = int(input())
    for _ in range(k):
        id = input()
        s = d.get(id, 4)
        if s == 1:
            print(id + ': Mystery Award')
        elif s == 2:
            print(id + ': Minion')
        elif s == 3:
            print(id + ': Chocolate')
        elif s == 4:
            print(id + ': Are you kidding?')
        else:
            print(id + ': Checked')
        if s != 4:
            d[id] = 0

if __name__ == '__main__':
    func()
        
