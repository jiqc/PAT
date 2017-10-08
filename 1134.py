def func():
    M = int(input().split()[1])
    edges = []
    for _ in range(M):
        edges.append([int(i) for i in input().split()])

    def vc():
        test = set([int(i) for i in input().split()])
        for edge in edges:
            if edge[0] not in test and edge[1] not in test:
                return False
        return True

    K = int(input())
    for _ in range(K):
        if vc():
            print('Yes')
        else:
            print('No')

if __name__ == '__main__':
    func()
        
