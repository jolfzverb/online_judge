# https://coderun.yandex.ru/problem/sntp


def main():
    before = map(int, input().split(":"))
    server = map(int, input().split(":"))
    after = map(int, input().split(":"))

    diff = list(map(lambda a: a[1]-a[0], zip(before, after)))

    if diff[2] < 0:
        diff[2] += 60
        diff[1] -= 1

    if diff[1] < 0:
        diff[1] += 60
        diff[0] -= 1

    if diff[0] < 0:
        diff[0] += 24

    result = list(map(lambda a: a[0]+a[1]//2, zip(server, diff)))

    if diff[2] % 2:
        result[2] += 1

    if diff[1] % 2:
        result[2] += 30

    if diff[0] % 2:
        result[1] += 30

    result[1] += result[2]//60
    result[2] = result[2] % 60

    result[0] += result[1]//60
    result[1] = result[1] % 60

    result[0] = result[0] % 24

    print(f"{result[0]:02d}:{result[1]:02d}:{result[2]:02d}")


if __name__ == '__main__':
    main()
