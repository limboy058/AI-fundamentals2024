import matplotlib.pyplot as plt
import matplotlib.style
matplotlib.style.use('fast')

def rs(i, j, color, alpha=1):#染色四边形
    plt.fill([j - 0.5, j - 0.5, j + 0.5, j + 0.5],
             [i - 0.5, i + 0.5, i + 0.5, i - 0.5],
             color=color,
             alpha=alpha)
def rs_3(i, j, color, alpha=1):#染色三角形
    plt.fill([j - 0.5, j + 0.5, j + 0.5],
             [ i + 0.5, i + 0.5, i - 0.5],
             color=color,
             alpha=alpha)
    


def look_look(maze, vis, pre, dis, now,cnt,fontsiz,t,t_end):  #迷宫,访问过的地区,节点的前继,所有点的最短距离,当前所处位置,探索次数,字体大小,显示时间,终止时显示时间
    plt.imshow(maze, cmap='Greys', interpolation='nearest',alpha=0.7)  # 使用灰度色图，并关闭插值

    plt.xticks(range(len(maze[0])))
    plt.yticks(range(len(maze)))
    plt.gca().set_xticks([x - 0.5 for x in range(1, len(maze[0]))], minor=True)
    plt.gca().set_yticks([y - 0.5 for y in range(1, len(maze))], minor=True)
    plt.gca().xaxis.tick_top()
    plt.grid(which="minor", color="black", linestyle='-', linewidth=2)
    plt.axis('on')  # 显示坐标轴


    rs(0, 0, 'lightgreen')
    rs(len(maze) - 1, len(maze[0]) - 1, 'lightgreen')

    for i in range(len(maze)):
        for j in range(len(maze[0])):
            if type(dis[i][j])==int and dis[i][j]!=-1 :
                plt.text(j,
                         i,
                         dis[i][j],
                         fontsize=22,
                         ha='center',
                         va='center')
                if vis[i][j]==0:
                    rs_3(i, j, 'orange')
            if type(dis[i][j])==list and dis[i][j]!=[-1,-1] :
                plt.text(j,
                         i,
                         str(dis[i][j][0])+','+str(dis[i][j][1]),
                         fontsize=fontsiz,
                         ha='center',
                         va='center')
                if vis[i][j]==0:
                    rs_3(i, j, 'orange')
            if vis[i][j] == 1 and maze[i][j]==0:
                rs(i, j, 'silver')

    
    rs(now[0], now[1], 'violet')

    path = []
    p = now
    path.append((p[0], p[1]))
    while 1:
        if p[0] == 0 and p[1] == 0:
            break
        p = pre[p[0]][p[1]]
        path.append((p[0], p[1]))

    path_x, path_y = zip(*path)
    plt.plot(path_y,
             path_x,
             marker='o',
             markersize=8,
             color='violet',
             linewidth=5)

    
    plt.text(((len(maze[0]) - 1) / 2),
                -1,
                 'try:'+str(cnt),
                 fontsize=16,
                 ha='center',
                 va='center')
    if now[0] == len(maze) - 1 and now[1] == len(maze[0]) - 1:
        plt.text(((len(maze[0]) - 1) / 2),
                 len(maze) - 0.2,
                 'finished',
                 fontsize=18,
                 ha='center',
                 va='center')
        plt.pause(t_end)
    plt.pause(t)
    plt.cla()