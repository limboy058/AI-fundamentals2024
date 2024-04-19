import matplotlib.pyplot as plt
import matplotlib.style
matplotlib.style.use('fast')
from collections import deque
import visual
import generate

ops = [[0, 1], [1, 0], [0, -1], [-1, 0]]

def dfs(maze, n, m):
    cnt=0
    fig = plt.figure(figsize=(len(maze[0]), len(maze)))
    plt.show(block=False)

    vis = [[0 for j in range(m)] for i in range(n)]
    dis = [[-1 for j in range(m)] for i in range(n)]
    pre = [[[-1 for k in range(2)] for j in range(m)] for i in range(n)]
    q = deque()
    q.append([0, 0])
    dis[0][0] = 0
    while len(q) != 0:
        now = q.pop()
        cnt+=1
        vis[now[0]][now[1]] = 1

        for op in ops:
            new = [now[0] + op[0], now[1] + op[1]]
            if new[0] >= 0 and new[0] < n and new[1] >= 0 and new[
                    1] < m and maze[new[0]][new[1]] == 0 and (
                        dis[new[0]][new[1]] > dis[now[0]][now[1]] + 1
                        or dis[new[0]][new[1]] == -1):
                q.append(new)
                dis[new[0]][new[1]] = dis[now[0]][now[1]] + 1
                vis[new[0]][new[1]] = 0
                pre[new[0]][new[1]] = now
        visual.look_look( maze, vis, pre, dis, now, cnt,fontsiz=20,t=0.03,t_end=1)
    visual.look_look( maze, vis, pre, dis, [n-1,m-1], cnt,fontsiz=20,t=0.1,t_end=10)

if __name__ == '__main__':
    n = 10
    m = 10
    maze= [[0,1,1,1,1,1,1,1,0,0],
[0,1,0,0,1,0,0,0,1,0],
[0,0,1,0,0,1,0,1,1,0],
[1,0,0,0,0,0,0,1,0,0],
[1,0,1,0,1,0,1,0,0,1],
[0,0,1,0,1,0,0,0,1,0],
[0,1,0,0,0,1,0,1,1,0],
[0,0,0,1,0,1,0,0,0,0],
[1,1,1,0,0,0,1,0,1,0],
[0,0,0,0,1,0,0,0,1,0]]
    dfs(maze, n, m)
    #dfs(generate.gnr(13,13), 13, 13)