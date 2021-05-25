dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def init(N):
    visited = [[0] * M for _ in range(N)] 
    return visited

def dfs(x, y, sx, sy, color):
    if visited[x][y] == True:
        return True

    visited[x][y] = True

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < N and 0 <= ny < M:
            if (nx, ny) == (sx, sy):
                continue
            if board[nx][ny] == color:
                if dfs(nx, ny, x, y, color):
                    return True
    return False

if __name__ == "__main__":

    N, M = map(int, input().split())
    visited = init(M)
    board = [list(input()) for _ in range(N)]

    result = False

    for i in range(N):
        for j in range(M):
            if visited[i][j] == True:
                continue
            
            if dfs(i, j, -1, -1, board[i][j]):
                result = True
                break

    if result:
        print("Yes")

    else:
        print("No")