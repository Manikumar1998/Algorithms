parent = []

def get_edges(graph):
    edges = []
    for i in xrange(len(graph)):
        for j in xrange(len(graph[i])):
            if graph[i][j] != 0:
                edges.append([i, j, graph[i][j]])

    return edges

def find(i):
    global parent
    if parent[i] == i:
        return i
    else:
        return find(parent[i])
    
def union(i, j):
    global parent
    parent[i] = parent[j]
    
def kruskal(graph):
    global parent
    nodes = range(len(graph))
    edges = get_edges(graph)
    edges.sort(key=lambda i: i[2])

    added = [False for i in xrange(len(nodes))]
    selected_list = []
    
    while(len(selected_list) <= len(nodes)-1 and edges):
        edge = edges.pop(0)
        node1 = edge[0]
        node2 = edge[1]
        weight = edge[2]

        parent1 = find(node1)
        parent2 = find(node2)

        if parent1 != parent2:
            union(parent1, parent2)
            selected_list.append(edge)    
    print selected_list

if __name__ == '__main__':
    graph = [[0, 2, 0, 6, 0],
             [2, 0, 3, 8, 5], 
             [0, 3, 0, 0, 7], 
             [6, 8, 0, 0, 9], 
             [0, 5, 7, 9, 0]]
    global parent
    parent = [i for i in xrange(len(graph))]

    kruskal(graph)   
