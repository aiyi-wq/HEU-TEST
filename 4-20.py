#!/usr/bin/env python
# coding=utf-8

def main2(n):
    a = [0]*10000
    ans = 1
    if n <= 2:
        print('1')
        return 1
    elif n <= 4:
        print('%d' % (n - 1))
        return n - 1
    sum = 0
    l = 0
    left = 0
    for i in range(2, n + 1):
        a[l] = i
        l += 1
        sum += i
        if sum > n:
            sum -= i
            l -= 1
            left = n - sum
            break
    i=l-1
    while left !=0:
        a[i] += 1
        i -= 1
        if i < 0:
            i = l - 1
        left -=1
    for i in range(0, l):
        ans *= a[i]
    return ans

# 每次初始化ans
ans = 1
# 读取文件的数据
file_readpath = 'input.txt'
with open(file_readpath) as file:
    txt = file.read()
n = eval(txt)
ans = main2(n)
print(ans)
# 将结果存入文件output.txt
file_writepath = 'output.txt'
file = open(file_writepath, "w")
file.write(str(ans))
file.close()
