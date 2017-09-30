def func():
    N = int(input())
    visited = [0 for i in range(N+1)]
    datas = [[] for i in range(N+1)]
    for i in range(1, N+1):
        data = input().split()
        data[1] = int(data[1])
        if data[1] > 0:
            visited[data[1]] = 1
        data[2] = int(data[2])
        if data[2] > 0:
            visited[data[2]] = 1
        datas[i] = data
    for i in range(1,N+1):
        if visited[i] == 0:
            head = i
            break
        
    def build(k):
        ph = False
        if datas[k][1] > 0:
            left = build(datas[k][1])
            ph = True
        else:
            left = ''
        if datas[k][2] > 0:
            right = build(datas[k][2])
            ph = True
        else:
            right = ''
        if ph and k != head:
            return '('+left+datas[k][0]+right+')'
        else:
            return left+datas[k][0]+right

    print(build(head))

if __name__ == '__main__':
    func()
        
