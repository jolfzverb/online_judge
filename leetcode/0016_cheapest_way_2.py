# https://coderun.yandex.ru/problem/cheapest-way

import sys


def main():
    p = list(map(int, input().split()))

    N = p[0]
    M = p[1]

    vals = [[0 for j in range(M)] for i in range(N)]

    for i in range(N):
        l = list(map(int, input().split()))

        for j in range(M):
            c = l[j]

            if j == 0:
                if i == 0:
                    vals[i][j] = c
                else:
                    vals[i][j] = c + vals[i-1][j]
            else:
                if i == 0:
                    vals[i][j] = c + vals[i][j-1]
                else:
                    vals[i][j] = c + min(vals[i][j-1], vals[i-1][j])

    print(vals[N-1][M-1])


if __name__ == '__main__':
    main()
