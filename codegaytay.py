import sys

def top_right_to_bottom_left(matrix: list[list[int]]) -> int:
    answer = -sys.maxsize
    m, n = len(matrix), len(matrix[0])
    for diff in range(-m + 1, n):  # diff = i - j
        sum = 0
        for i in range(m):
            j = i - diff
            if 0 <= j < n:
                sum += matrix[i][j]
        answer = max(answer, sum)

    return answer

def top_left_to_bottom_right(matrix: list[list[int]]) -> int:
    answer = -sys.maxsize
    m, n = len(matrix), len(matrix[0])
    for diff in range(m + n - 1):  # diff = i + j
        sum = 0
        for i in range(m):
            j = diff - i
            if 0 <= j < n:
                sum += matrix[i][j]
        answer = max(answer, sum)

    return answer

n, m = map(int, input().split())
N = int(1e3) + 5
a = [[0 for _ in range(N)] for _ in range(N)]

for i in range(n):
    row = list(map(int, input().split()))
    for j in range(m):
        a[i][j] = row[j]

max_row = max_column = -sys.maxsize

for i in range(n):
    max_row = max(max_row, sum(a[i]))

# print(max_row)

for j in range(m):
    temp_sum = 0
    for i in range(n):
        temp_sum += a[i][j]
    max_column = max(max_column, temp_sum)

# print(max_column)

print('{} {} {} {}'.format(max_row, max_column, top_right_to_bottom_left(a), top_left_to_bottom_right(a)))
sys.exit(0)
