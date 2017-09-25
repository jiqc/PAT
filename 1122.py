class graph(object):
    def __init__(self, numvertex, numedge):
        self.vertex = numvertex
        self.edge = numedge
        self.cross = [[0 for j in range(numvertex+1)] for i in range(numvertex+1)]

    def buildcross(self):
        for _ in range(self.edge):
            va, vb = [int(j) for j in input().split()]
            self.cross[va][vb] = 1
            self.cross[vb][va] = 1

    def hamiltoniarn(self):
        path = [int(i) for i in input().split()[1:]]
        if len(path) == self.vertex + 1 and path[len(path)-1] == path[0]:
            visit = [0 for _ in range(self.vertex + 1)]
            for i in range(1, len(path)):
                if not self.cross[path[i]][path[i-1]] or visit[path[i]]:
                    print('NO')
                    return
                visit[path[i]] += 1
            
            print('YES')
            return

        print('NO')
        return

def func():
    N, M = [int(j) for j in input().split()]
    g = graph(N, M)
    g.buildcross()
    K = int(input())
    for _ in range(K):
        g.hamiltoniarn()
    return

if __name__ == '__main__':
    func()
