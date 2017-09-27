def func():
    N = int(input())
    level = [[] for _ in range(N)]   
    inorder = input().split()
    postorder = input().split()
    
    def getlevel(pst,ped,ist,ied,l):
        if pst > ped or ist > ied:
            return
        k = ist
        while k <= ied and inorder[k]!=postorder[ped]:k+=1
        level[l].append(postorder[ped])
        getlevel(pst,pst+k-1-ist,ist,k-1,l+1)
        getlevel(pst+k-ist,ped-1,k+1,ied,l+1)

    getlevel(0, N-1, 0,N-1, 0)
    s = []
    for i in range(N):
        if level[i]:
            if i%2:
                s.append(' '.join(level[i]))
            else:
                s.append(' '.join(level[i][::-1]))
        else:
            break
    print(' '.join(s))

if __name__ == '__main__':
    func()
