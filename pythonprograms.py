# Bubble Sort with user input

arr = list(map(int, input("Enter numbers separated by space: ").split()))
n = len(arr)

for i in range(n):
    for j in range(n - i - 1):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]

print("Bubble Sort:", arr)

# Selection Sort with user input

arr = list(map(int, input("Enter numbers separated by space: ").split()))
n = len(arr)

for i in range(n):
    min_index = i
    for j in range(i + 1, n):
        if arr[j] < arr[min_index]:
            min_index = j
    arr[i], arr[min_index] = arr[min_index], arr[i]

print("Selection Sort:", arr)

# Merge Sort with user input

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        merge_sort(left)
        merge_sort(right)

        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

arr = list(map(int, input("Enter numbers separated by space: ").split()))
merge_sort(arr)
print("Merge Sort:", arr)

# Quick Sort with user input

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left = [x for x in arr[1:] if x < pivot]
    right = [x for x in arr[1:] if x >= pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)

arr = list(map(int, input("Enter numbers separated by space: ").split()))
sorted_arr = quick_sort(arr)
print("Quick Sort:", sorted_arr)

# Matrix Chain Multiplication with user input

def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0] * n for _ in range(n)]

    for L in range(2, n + 1):
        for i in range(n - L + 1):
            j = i + L - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if cost < m[i][j]:
                    m[i][j] = cost

    return m[0][n - 1]

# Input format: number of matrices = n => you input n+1 dimensions
p = list(map(int, input("Enter the dimensions (e.g., for 3 matrices A(10x30),B(30x5),C(5x60): 10 30 5 60): ").split()))
print("Minimum number of multiplications:", matrix_chain_order(p))

# Ford-Fulkerson Algorithm with user input

from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(dict)

    def add_edge(self, u, v, w):
        self.graph[u][v] = w
        self.graph[v].setdefault(u, 0)  # reverse edge

    def dfs(self, s, t, visited, parent):
        visited[s] = True
        if s == t:
            return True
        for v in self.graph[s]:
            if not visited[v] and self.graph[s][v] > 0:
                parent[v] = s
                if self.dfs(v, t, visited, parent):
                    return True
        return False

    def ford_fulkerson(self, source, sink):
        max_flow = 0
        parent = {}
        while True:
            visited = [False] * self.V
            parent = {}
            if not self.dfs(source, sink, visited, parent):
                break
            path_flow = float('inf')
            v = sink
            while v != source:
                u = parent[v]
                path_flow = min(path_flow, self.graph[u][v])
                v = u
            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = u
            max_flow += path_flow
        return max_flow

# Input section
V = int(input("Enter number of vertices: "))
E = int(input("Enter number of edges: "))

g = Graph(V)
print("Enter edges in format: from to capacity")
for _ in range(E):
    u, v, w = map(int, input().split())
    g.add_edge(u, v, w)

source = int(input("Enter source node: "))
sink = int(input("Enter sink node: "))
print("Maximum Flow:", g.ford_fulkerson(source, sink))

# Floyd-Warshall Algorithm with user input

INF = float('inf')

def floyd_warshall(graph):
    V = len(graph)
    dist = [row[:] for row in graph]
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist

# Input section
V = int(input("Enter number of vertices: "))
graph = []
print("Enter adjacency matrix row-wise (use 99999 for infinity):")

for i in range(V):
    row = list(map(int, input().split()))
    row = [INF if x == 99999 else x for x in row]
    graph.append(row)

shortest = floyd_warshall(graph)

print("All-pairs shortest path matrix:")
for row in shortest:
    print(row)

