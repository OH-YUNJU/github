import sys
sys.setrecursionlimit(10**5)

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def init(N):
    rain = [[False] * N for _ in range(N)]
    return rain

def dfs(x,y,z):
    rain[x][y] = True

    for i in range(4):
        X = x + dx[i]
        Y = y + dy[i]

        if X < 0 or X >= N or Y < 0 or Y >= N:
            continue

        if not rain[X][Y] and bored[X][Y] > z:
                dfs(X, Y, z)


if __name__ == "__main__":
    result = 0
    N = int(input())
    rain = init(N)
    bored = [list(map(int, input().split())) for _ in range(N)]

    for i in range(max(max(bored))):
        count = 0
        rain = init(N)
        for j in range(N):
            for k in range(N):
                if not rain[j][k] and bored[j][k] > i:
                    dfs(j, k, i)
                    count = count + 1          
        result = max(result, count)

    print(result)