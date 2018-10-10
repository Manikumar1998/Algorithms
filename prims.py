import sys

def min_node(graph, keys, mst):
    minimum = sys.maxint
    min_index = None
    for i in xrange(len(keys)):
        if mst[i] == False and keys[i] < minimum:
            minimum = keys[i]
            min_index = i
    return min_index
            
def prims(graph, N):
    mst = [False for i in xrange(N)]
    keys = [sys.maxint for i in xrange(N)]
    edges = []

    keys[0] = 0

    new_index = min_node(graph, keys, mst)
    while(new_index != None):
        mst[new_index] = True

        for i in xrange(len(graph)):
            if graph[new_index][i] < keys[i] and graph[new_index][i] != 0:
                keys[i] = graph[new_index][i]
                edges.append([new_index, i, keys[i]])
        new_index = min_node(graph, keys, mst)
    print edges

if __name__ == '__main__':
    graph = [[0, 2, 0, 6, 0],
             [2, 0, 3, 8, 5], 
             [0, 3, 0, 0, 7], 
             [6, 8, 0, 0, 9], 
             [0, 5, 7, 9, 0]]
    prims(graph, len(graph))
    
