def test(tree, color):
    if len(tree) == 0:
        return [True, 0]
    
    root = tree[0]
    '''
    color = True black
    color = False red
    '''
    if not color and root < 0:
        return [False, 0]
    
    if len(tree) == 1:
        if root > 0:
            return [True, 1]
        else:
            return [True, 0]
    
    lr = 1
    for i in range(1,len(tree)):
        if abs(tree[i]) > abs(root):
            lr = i
            break
    left = tree[1:lr]
    right = tree[lr:len(tree)]

    res_left = test(left, root > 0)
    res_right = test(right, root > 0)

    res = [True, 0]
    res[0] = res_left[0] and res_right[0] and res_left[1] == res_right[1]
    if root > 0:
        res[1] = res_left[1] + 1
    else:
        res[1] = res_left[1]
    return res
    

def case():
    N = int(input())
    tree = [int(i) for i in input().split()]
    if tree[0] < 0:
        return False
    return test(tree, True)[0]

def func():
    K = int(input())
    for _ in range(K):
        if case():
            print('Yes')
        else:
            print('No')

if __name__ == '__main__':
    func()
