class UnionSet(object):
    def __init__(self, num):
        self.num = num
        self.birds = [i for i in range(num+1)]
        self.rank = [0 for i in range(num+1)]

    def find(self, x):
        if self.birds[x] == x:
            return x
        else:
            self.birds[x] = self.find(self.birds[x])
            return self.birds[x]

    def connect(self, x, y):
        return self.find(x) == self.find(y)

    def union(self, x, y):
        fx ,fy = self.find(x), self.find(y)
        if fx == fy:
            return
        if self.rank[fx] > self.rank[fy]:
            self.birds[fy] = fx
        else:
            self.birds[fx] = fy
            if self.rank[fx] == self.rank[fy]:
                self.rank[fy] += 1
        self.num -= 1

def func():
    n = int(input())
    dic_pic = [[0] for _ in range(n)]
    numbird = 0
    for i in range(n):
        dic_pic[i] = [int(j) for j in input().split()[1:]]
        numbird = max(numbird, max(dic_pic[i]))
            
    un = UnionSet(numbird)
    for pic_data in dic_pic:
        for i in range(len(pic_data)-1):
            un.union(pic_data[i], pic_data[i+1])
    
    print(un.num, numbird)
    q = int(input())
    for _ in range(q):
        x, y = map(int, input().split())
        if un.connect(x, y):
            print('Yes')
        else:
            print('No')
    
if __name__ == '__main__':
    func()
