""" 
Implemente o método de Dijkstra e use sua implementação para resolver as seguintes
questões:
Considere o grafo da figura abaixo e execute o algoritmo de Dijkstra para descobrir o menor caminho entre os vértices 'a' e 'd'.
"""

from collections import defaultdict
import heapq

class Graph:
    def __init__(self):
        self.edges = defaultdict(list)
        self.weights = {}

    def add_edge(self, from_node, to_node, weight):
        self.edges[from_node].append(to_node)
        self.weights[(from_node, to_node)] = weight

def dijkstra(graph, initial):
    visited = {initial: 0}
    path = {}

    nodes = set(graph.edges.keys())

    while nodes: 
        min_node = None
        for node in nodes:
            if node in visited:
                if min_node is None:
                    min_node = node
                elif visited[node] < visited[min_node]:
                    min_node = node

        if min_node is None:
            break

        nodes.remove(min_node)
        current_weight = visited[min_node]

        for edge in graph.edges[min_node]:
            weight = current_weight + graph.weights[(min_node, edge)]
            if edge not in visited or weight < visited[edge]:
                visited[edge] = weight
                path[edge] = min_node

    return visited, path

def shortest_path(graph, origin, destination):
    visited, paths = dijkstra(graph, origin)
    full_path = [destination]
    while destination != origin:
        destination = paths[destination]
        full_path.append(destination)
    full_path.reverse()
    return full_path

graph = Graph()

graph.add_edge('a', 'b', 8)
graph.add_edge('a', 'c', 4)
graph.add_edge('b', 'c', 6)
graph.add_edge('b', 'd', 2)
graph.add_edge('c', 'e', 4)
graph.add_edge('b', 'f', 4)
graph.add_edge('f', 'b', 2)
graph.add_edge('c', 'f', 1)
graph.add_edge('f', 'e', 4)
graph.add_edge('e', 'f', 5)
graph.add_edge('f', 'd', 7)

print(shortest_path(graph, 'a', 'd'))


