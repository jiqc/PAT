def cutnum():
    Z = input()
    k = len(Z)//2
    A = int(Z[0:k])
    B = int(Z[k:])
    if B != 0 and int(Z) % (A * B) == 0:
        return True
    else:
        return False

def func():
    N = int(input())
    for _ in range(N):
        print('Yes'if cutnum() else 'No')
    return 0

if __name__ == '__main__':
    func()
