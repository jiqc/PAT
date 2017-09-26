def func():
    input()
    ropes = sorted([int(i) for i in input().split()])
    if len(ropes) == 0:
        print(0)
    res = ropes[0]
    for rope in ropes[1:]:
        res = (res + rope) // 2
    print(res)

if __name__ == '__main__':
    func()
