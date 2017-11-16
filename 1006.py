from operator import itemgetter
def func():
    M = int(input())
    person = []
    for _ in range(M):
        person.append(input().split())
    unlock = sorted(person, key = itemgetter(1))
    lock = sorted(person, key = itemgetter(2), reverse = True)
    print(unlock[0][0], lock[0][0])

if __name__ == '__main__':
    func()
