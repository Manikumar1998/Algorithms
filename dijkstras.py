import sys

def get_min(graph, keys, isvisited):
    minimum = sys.maxint
    min_index = None
    for i in xrange(len(keys)):
        if keys[i] < minimum and isvisited[i] == False:
            minimum = keys[i]
            min_index = i
    return min_index

def dijkstras(graph, N):
    keys = [sys.maxint for i in xrange(N)]
    parent = range(N)
    isvisited = [False for i in xrange(N)]
    
    keys[0] = 0
    n = N
    while(n):
        index = get_min(graph, keys, isvisited)
        isvisited[index] = True
        
        for i in xrange(len(graph)):
            if graph[index][i] != 0 and keys[index] + graph[index][i] < keys[i]:
                keys[i] = graph[index][i] + keys[index]
                parent[i] = index
        n -= 1
    print keys

if __name__ == '__main__':
    graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0], 
           [4, 0, 8, 0, 0, 0, 0, 11, 0], 
           [0, 8, 0, 7, 0, 4, 0, 0, 2], 
           [0, 0, 7, 0, 9, 14, 0, 0, 0], 
           [0, 0, 0, 9, 0, 10, 0, 0, 0], 
           [0, 0, 4, 14, 10, 0, 2, 0, 0], 
           [0, 0, 0, 0, 0, 2, 0, 1, 6], 
           [8, 11, 0, 0, 0, 0, 1, 0, 7], 
           [0, 0, 2, 0, 0, 0, 6, 7, 0] 
          ]; 
    dijkstras(graph, len(graph))
