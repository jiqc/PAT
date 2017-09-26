def func():
    M, N, S = [int(i) for i in input().split()]
    S = S - 1
    candidate = []
    for i in range(M):
        candidate.append(input())
    winner = []
    while S < len(candidate):
        while S < len(candidate) and candidate[S] in winner:
            S += 1
        if S == len(candidate):
            break
        winner.append(candidate[S])
        S += N
    if winner:
        for w in winner:
            print(w)
    else:
        print('Keep going...')

if __name__ == '__main__':
    func()
