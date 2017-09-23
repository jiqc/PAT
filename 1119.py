class ordertree(object):
    def __init__(self, num, preodr, postodr):
        self.num = num
        self.preodr = preodr
        self.postodr = postodr
        self.inodr = []
        self.unique = True

    def getin(self):
        def find(pr_st, pr_ed, pt_st, pt_ed):
            if pr_st == pr_ed:
                return [self.preodr[pr_st]]
            if self.preodr[pr_st + 1] == self.postodr[pt_ed - 1]:
                self.unique = False
            res = [self.preodr[pr_st]]
            f = pr_st + 1
            while self.preodr[f] != self.postodr[pt_ed - 1]:f += 1
            if f - pr_st > 1:
                left = find(pr_st+1, f-1, pt_st, pt_st+f-pr_st-2)
                res = left + res
            if pr_ed >= f:
                right = find(f, pr_ed, pt_st+f-pr_st-1, pt_ed-1)
                res = res + right
            return res
        self.inodr = find(0,self.num-1,0,self.num-1)
    
def func():
    n = int(input())
    preodr = [int(i) for i in input().split()]
    postodr = [int(i) for i in input().split()]
    
    t = ordertree(n, preodr, postodr)
    t.getin()

    print ('Yes' if t.unique else 'No')
    print (t.inodr[0], end = '')
    for x in t.inodr[1:]:
        print(' ',x,sep = '',end = '')
    print('',end='\n')
    
if __name__ == '__main__':
    func()
