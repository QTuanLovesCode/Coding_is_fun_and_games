import sys

t = int(input())

while t > 0:
    n, k = map(int, input().split())
    x = list(map(int, input().split()))
    ans = 1
    flowers_watered = k
    check = [False] * (n + 1)
    for i in range(k):
        check[x[i]] = True

    # print(check)

    while flowers_watered < n:
        new_check = check[:]
        for i in range(1, n + 1):
            if check[i]:
                if i - 1 > 0 and not check[i - 1]:
                    flowers_watered += 1
                    new_check[i - 1] = True
                if i + 1 <= n and not check[i + 1]:
                    flowers_watered += 1
                    new_check[i + 1] = True
        check = new_check
        ans += 1
        # print(check)

    print(ans)
    t -= 1

sys.exit(0)
