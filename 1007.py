def func():
    K = int(input())
    L = [int(i) for i in input().split()]
    temp_sum = 0
    temp_left = L[0]
    res_sum = -1
    res_right = L[K-1]
    res_left = L[0]
    for i in range(K):
        temp_sum += L[i]
        if temp_sum > res_sum:
            res_sum = temp_sum
            res_left = temp_left
            res_right = L[i]
        elif temp_sum < 0 and i < K -1:
            temp_sum = 0
            temp_left = L[i + 1]

    if res_sum == -1:
        res_sum = 0
    print(res_sum, res_left, res_right)
    

if __name__ == '__main__':
    func()
