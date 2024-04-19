# 迷宫生成Prim
import random as rd
import visual

def gnr(n,m):
    ops = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    maze = [[1 for j in range(m)] for i in range(n)]
    vis = [[0 for j in range(m)] for i in range(n)]
    v = [[0 for j in range(m)] for i in range(n)]
    pre = [[[0 for k in range(2)] for j in range(m)] for i in range(n)]
    dis = [[[-1 for k in range(2)] for j in range(m)] for i in range(n)]
    cnt=0
    for i in range(0,n,2):
        for j in range(0,m,2):
            maze[i][j]=0
    ls=[]

    now=[0,m-1]
    vis[now[0]][now[1]]=1
    for op in ops:
        new=[now[0]+op[0],now[1]+op[1]]
        if new[0]>=0 and new[0]<n and new[1]>=0 and new[1]<m and maze[new[0]][new[1]]==1:
            ls.append([new[0],new[1],op[0],op[1]])
    
    while len(ls)!=0:
        
        now=ls.pop(rd.randrange(len(ls)))
        tmp=[]
        new=[now[0]+now[2],now[1]+now[3]]
        if not(new[0]>=0 and new[0]<n and new[1]>=0 and new[1]<m):
            continue
        if (maze[new[0]][new[1]]==1 or vis[new[0]][new[1]]==1):
            continue
        else:
            #visual.look_look( maze, v, pre, dis, [0,0], cnt,fontsiz=20,t=0.1,t_end=10)
            maze[now[0]][now[1]]=0
            now=new
            vis[now[0]][now[1]]=1
            for op in ops:
                new=[now[0]+op[0],now[1]+op[1]]
                if new[0]>=0 and new[0]<n and new[1]>=0 and new[1]<m and maze[new[0]][new[1]]==1:
                    ls.append([new[0],new[1],op[0],op[1]])
    for item in maze:
        print(item)
    visual.look_look( maze, v, pre, dis, [0,0], cnt,fontsiz=20,t=10,t_end=15)
    return maze


maze=gnr(31,31)
# for item in maze:
#     print(item)