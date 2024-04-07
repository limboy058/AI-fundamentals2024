import random as rd
import matplotlib.pyplot as plt
import numpy as np

def get_puzzle(n:int,m:int):
    ret = np.zeros((n, m))
    for i in range(0,n):
        for j in range(0,m):
            if(rd.random()>0.3):
                ret[i][j]=1
    return ret

rd.seed(0)
for t in range(0,1):
    mp=get_puzzle(10,10)
    #print(mp)

def get_puzzle(n, m):
    import random
    
    # Initialize the maze with walls
    maze = [[1] * m for _ in range(n)]
    
    # Make odd rows and columns corridors
    for i in range(1, n, 2):
        for j in range(1, m, 2):
            maze[i][j] = 0
    
    # Make random connections between odd rows
    for i in range(1, n, 2):
        for j in range(2, m, 2):
            if random.randint(0, 1):
                maze[i][j - 1] = 0
            else:
                maze[i][j] = 0
    
    # Make random connections between odd columns
    for i in range(2, n, 2):
        for j in range(1, m, 2):
            if random.randint(0, 1):
                maze[i - 1][j] = 0
            else:
                maze[i][j] = 0
    
    # Ensure start and end are clear
    maze[0][1] = 0
    maze[-1][-2] = 0
    
    return maze


maze = get_puzzle(5, 5) 
for raw in maze:
    print(raw)
