""" 
Implemente o método de Dijkstra e use sua implementação para resolver as seguintes
questões:

Considerando que estamos em Seattle, e queremos conhecer o Empire State Building. Diga qual a rota que devemos seguir, e quanto será a distância percorrida.

Diga também qual a distância para cada uma das cidades dos Estados Unidos a partir de Seatle
"""

from collections import defaultdict
import heapq

class Graph:
    def __init__(self):
        self.edges = defaultdict(list)
        self.weights = {}

    def add_edge(self, from_node, to_node, weight):
        self.edges[from_node].append(to_node)
        self.edges[to_node].append(from_node)
        self.weights[(from_node, to_node)] = weight
        self.weights[(to_node, from_node)] = weight

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

graph.add_edge('Seattle', 'Minneapolis', 2661)
graph.add_edge('Seattle', 'Denver', 2161)
graph.add_edge('Seattle', 'San Francisco', 2250)
graph.add_edge('Minneapolis', 'Chicago', 661)
graph.add_edge('Minneapolis', 'Denver', 1483)
graph.add_edge('Minneapolis', 'Dallas', 1532)
graph.add_edge('Denver', 'Dallas', 1258)
graph.add_edge('San Francisco', 'Las Vegas', 919)
graph.add_edge('San Francisco', 'Los Angeles', 629)
graph.add_edge('Los Angeles', 'Las Vegas', 435)
graph.add_edge('Las Vegas', 'Denver', 1225)
graph.add_edge('Las Vegas', 'Dallas', 1983)
graph.add_edge('Chicago', 'Boston', 1613)
graph.add_edge('Chicago', 'Wash DC', 1145)
graph.add_edge('Wash DC', 'Boston', 725)
graph.add_edge('Wash DC', 'New York', 383)
graph.add_edge('New York', 'Boston', 338)
graph.add_edge('Dallas', 'Wash DC', 2113)
graph.add_edge('Dallas', 'Miami', 2161)
graph.add_edge('Wash DC', 'Miami', 383)
graph.add_edge('Miami', 'New York', 2145)

# Rota
print(shortest_path(graph, 'Seattle', 'New York'))

# Calcular distancia percorrida até new york
visited, paths = dijkstra(graph, 'Seattle')
print(visited['New York'])

# a distância para cada uma das cidades dos Estados Unidos a partir de Seatle
visited, paths = dijkstra(graph, 'Seattle')
for city in visited:
    print(city, visited[city])



