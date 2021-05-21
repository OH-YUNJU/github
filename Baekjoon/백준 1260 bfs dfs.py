from collections import deque

dlist = []
blist = []

def init(V):
    visited = [False for _ in range(V)]
    return visited

def insert_edge(V, E):
    adj_mat = [[0 for _ in range(V)] for _ in range(V)]
    for edge in E:
        adj_mat[edge[1]][edge[0]] = 1
        adj_mat[edge[0]][edge[1]] = 1
    return adj_mat

def dfs(V, adj_mat, vertex, visited):
    visited[vertex] = True
    dlist.append(vertex)

    for i in range(V):
        if adj_mat[vertex][i] == 1 and visited[i] == False:   # 아직 방문안했는데 방문해야할 곳
            dfs(V, adj_mat, i, visited)
            
def bfs(V, adj_mat, vertex, visited):
    visited[vertex] = True
    blist.append(vertex)
    
    queue = deque()
    queue.append(vertex)

    while queue:
        vertex = queue.popleft()
        for i in range(V):
            if adj_mat[vertex][i] == 1 and visited[i] == False:
                visited[i] = True #방문 확인
                blist.append(i)
                queue.append(i)
                

if __name__ == "__main__":
    #undirected graph 
    #start = int(input("시작할 정점: "))
    V, E, start = map(int, input().split()) #정점, 간선의 개수
    #시작 index는 0부터
    V += 1
    E = [list(map(int, input().split())) for _ in range(E)]

    adj_mat = insert_edge(V, E)
    visited = init(V)

    dfs(V, adj_mat, start, visited)

    visited = init(V)
    
    bfs(V, adj_mat, start, visited)

    for i in dlist:
        print(i, end = " ")
    print()
    for i in blist:
        print(i, end = " ")
