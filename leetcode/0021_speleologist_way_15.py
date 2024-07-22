import sys


def main():
    n = int(input())
    n2 = n*n
    n3 = n*n*n

    cave = [0 for i in range(n3)]
    s = set()

    for i in range(n):
        input()

        for j in range(n):
            line = input()

            for k in range(n):
                c = i*n2+j*n+k

                match line[k]:
                    case '#':
                        cave[c] = -1

                    case '.':
                        cave[c] = 0

                    case 'S':
                        cave[c] = 0
                        s.add(c)

    l = 0

    while len(s) > 0:
        l += 1
        next_s = set()

        for c in s:
            if c < n2:
                print(l-1)

                return

            cave[c] = l

        for c in s:
            i = c//n2
            j = (c % n2)//n
            k = c % n

            if i > 0 and cave[c-n2] == 0:
                next_s.add(c-n2)

            if i < n-1 and cave[c+n2] == 0:
                next_s.add(c+n2)

            if j > 0 and cave[c-n] == 0:
                next_s.add(c-n)

            if j < n-1 and cave[c+n] == 0:
                next_s.add(c+n)

            if k > 0 and cave[c-1] == 0:
                next_s.add(c-1)

            if k < n-1 and cave[c+1] == 0:
                next_s.add(c+1)

        s = next_s

    print(-1)


if __name__ == '__main__':
    main()
