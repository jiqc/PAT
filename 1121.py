def func():
    couple = {}
    N = int(input())
    for _ in range(N):
        A, B = input().split()
        couple[A] = B
        couple[B] = A
    input()
    guests = input().split()
    single = []
    part = set()
    for guest in guests:
        temp = couple.get(guest, '')
        if temp != '':
            if temp not in part:
                part.add(guest)
            else:
                part.remove(couple[guest])
        else:
            single.append(guest)
            
    single += list(part)
    print(len(single))
    if single:
        print(' '.join(sorted(single)))
    
if __name__ == '__main__':
    func()
