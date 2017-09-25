import collections

class avlnode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.height = 0
        
class avltree(object):
    def __init__(self):
        self.root = None
        self.complete = True
        self.bfs = []

    def levelsearch(self):
        if not self.root:
            return
        queue = collections.deque()
        queue.append(self.root)
        ctn = True
        while queue:
            T = queue.popleft()
            self.bfs.append(str(T.val))
            if T.left:
                queue.append(T.left)
                if not ctn:
                    self.complete = False
            else:
                ctn = False
            if T.right:
                queue.append(T.right)
                if not ctn:
                    self.complete = False
            else:
                ctn = False
        return
        

    def insert(self, val):
        def height(T):
            if T:
                return T.height
            else:
                return -1

        def SingleRotateWithLeft(k2):
            k1 = k2.left
            k2.left = k1.right
            k1.right = k2
            k2.height = max(height(k2.left), height(k2.right)) + 1
            k1.height = max(height(k1.left), k2.height) + 1
            return k1

        def SingleRotateWithRight(k1):
            k2 = k1.right
            k1.right = k2.left
            k2.left = k1
            k1.height = max(height(k1.left), height(k1.right)) + 1
            k2.height = max(k1.height, height(k2.right)) + 1
            return k2

        def DoubleRotateWithLeft(k3):
            k3.left = SingleRotateWithRight(k3.left)
            return SingleRotateWithLeft(k3)

        def DoubleRotateWithRight(k3):
            k3.right = SingleRotateWithLeft(k3.right)
            return SingleRotateWithRight(k3)
            
        def ist(x, T):
            if not T:
                T = avlnode(val)
            elif x < T.val:
                T.left = ist(x, T.left)
                if height(T.left) - height(T.right) == 2:
                    if x < T.left.val:
                        T = SingleRotateWithLeft(T)
                    else:
                        T = DoubleRotateWithLeft(T)
            elif x > T.val:
                T.right = ist(x, T.right)
                if height(T.right) - height(T.left) == 2:
                    if x > T.right.val:
                        T = SingleRotateWithRight(T)
                    else:
                        T = DoubleRotateWithRight(T)
            T.height = max(height(T.left), height(T.right)) + 1
            return T
        
        self.root = ist(val, self.root)

def func():
    tree = avltree()
    input()
    nums = [int(i) for i in input().split()]
    for num in nums:
        tree.insert(num)
    tree.levelsearch()
    print(' '.join(tree.bfs))
    print('YES' if tree.complete else 'NO')
    return

if __name__ == '__main__':
    func()
