import sys

input = sys.stdin.readline

n = int(input())

plus = []
minus = []

ans = 0

for i in range(n):
    num = int(input())
    if num > 1:
        plus.append(num)
    elif num == 1:
        ans += num
    else:
        minus.append(num)

plus.sort(reverse=True)
minus.sort()


for i in range(0, len(plus), 2):
    if i + 1 < len(plus):
        ans += plus[i] * plus[i + 1]
    else:
        ans += plus[i]

for i in range(0, len(minus), 2):
    if i + 1 < len(minus):
        ans += minus[i] * minus[i + 1]
    else:
        ans += minus[i]

print(ans)
