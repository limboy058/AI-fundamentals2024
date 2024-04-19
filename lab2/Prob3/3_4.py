import matplotlib.pyplot as plt
import queue
import visual
import generate

ops = [[0, 1], [1, 0], [0, -1], [-1, 0]]

def fun(i, j, n, m):
    return n - 1 - i + m - 1 - j

def astar(maze, n, m,magic):
    cnt=0
    fig = plt.figure(figsize=(len(maze[0]), len(maze)))
    plt.show(block=False)

    vis = [[0 for j in range(m)] for i in range(n)]
    dis = [[[-1 for k in range(2)] for j in range(m)] for i in range(n)]
    pre = [[[-1 for k in range(2)] for j in range(m)] for i in range(n)]
    q = queue.PriorityQueue()
    q.put((0 + fun(0, 0, n, m), [0, 0, 0, fun(0, 0, n, m)]))
    dis[0][0] = [0, 0 + fun(0, 0, n, m)]
    while not q.empty():
        now = q.get()
        cnt+=1
        now = now[1]
        d = now[2]
        vis[now[0]][now[1]] = 1

        
        for op in ops:
            new = [now[0] + op[0], now[1] + op[1]]
            if new[0] >= 0 and new[0] < n and new[1] >= 0 and new[1] < m:
                if maze[new[0]][new[1]] == 0 and (dis[new[0]][new[1]][1] > d + 1 + fun(new[0], new[1], n, m) or dis[new[0]][new[1]][1] == -1):
                    q.put((d + 1 + fun(new[0], new[1], n, m),[new[0], new[1], d + 1,fun(new[0], new[1], n, m)]))
                    dis[new[0]][new[1]] = [d + 1, d + 1 + fun(new[0], new[1], n, m)]
                    vis[new[0]][new[1]] = 0
                    pre[new[0]][new[1]] = now
                if magic and maze[new[0]][new[1]] == 1 and (dis[new[0]][new[1]][1] > d + 5 + fun(new[0], new[1], n, m) or dis[new[0]][new[1]][1] == -1):
                    q.put((d + 5 + fun(new[0], new[1], n, m),[new[0], new[1], d + 5,fun(new[0], new[1], n, m)]))
                    dis[new[0]][new[1]] = [d + 5, d + 5 + fun(new[0], new[1], n, m)]
                    vis[new[0]][new[1]] = 0
                    pre[new[0]][new[1]] = now
        visual.look_look(maze, vis, pre, dis, now, cnt,fontsiz=16,t=0.1,t_end=10)
        if now[0] == n - 1 and now[1] == m - 1:
            return


if __name__ == '__main__':
    n = 10
    m = 10
    maze = [[0, 1, 1, 1, 1, 1, 1, 1, 0, 0], [0, 1, 0, 0, 1, 0, 0, 0, 1, 0],
            [0, 0, 1, 0, 0, 1, 0, 1, 1, 0], [1, 0, 0, 1, 0, 0, 0, 1, 0, 0],
            [1, 0, 1, 0, 1, 0, 1, 0, 0, 1], [0, 0, 1, 0, 1, 0, 0, 0, 1, 0],
            [0, 1, 0, 0, 0, 1, 0, 1, 1, 0], [0, 0, 0, 1, 0, 1, 0, 0, 0, 0],
            [1, 1, 1, 0, 0, 0, 1, 0, 1, 0], [0, 0, 0, 0, 1, 0, 0, 0, 1, 0]]
    astar(maze, n, m,magic=False)
    #astar(generate.gnr(11,11), 11, 11,True)