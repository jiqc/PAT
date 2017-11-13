import queue  
from collections import namedtuple

Edge = namedtuple('Edge', ['vertex', 'weight'])


class GraphUndirectedWeighted(object):  
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count
        self.adjacency_list = [[] for _ in range(vertex_count)]
        self.teams_store = []

    def add_edge(self, source, dest, weight):
        assert source < self.vertex_count
        assert dest < self.vertex_count
        self.adjacency_list[source].append(Edge(dest, weight))
        self.adjacency_list[dest].append(Edge(source, weight))

    def add_teams(self, teams_list):
        self.teams_store = teams_list[::]

    def get_edge(self, vertex):
        for e in self.adjacency_list[vertex]:
            yield e

    def get_vertex(self):
        for v in range(self.vertex_count):
            yield v


def dijkstra(graph, source, dest):  
    q = queue.PriorityQueue()
    parents = []
    distances = []
    teams_gather = []
    visited = []
    start_weight = float("inf")

    for i in graph.get_vertex():
        if source == i:
            distances.append(0)
            parents.append(1)
            teams_gather.append(graph.teams_store[source])
        else:
            distances.append(start_weight)
            parents.append(0)
            teams_gather.append(0)
        visited.append(0)

    q.put(([0, source]))

    while not q.empty():
        v_tuple = q.get()
        v = v_tuple[1]
        while visited[v] == 1:
            v_tuple = q.get()
            v = v_tuple[1]
        visited[v] = 1

        if v == dest:
            break

        for e in graph.get_edge(v):
            if visited[e.vertex] == 1:
                continue
            candidate_distance = distances[v] + e.weight
            if distances[e.vertex] > candidate_distance:
                distances[e.vertex] = candidate_distance
                parents[e.vertex] = parents[v]
                teams_gather[e.vertex] = teams_gather[v] + graph.teams_store[e.vertex]
                q.put(([distances[e.vertex], e.vertex]))
            elif distances[e.vertex] == candidate_distance:
                parents[e.vertex] = parents[v] + parents[e.vertex]
                teams_gather[e.vertex] = max(teams_gather[v] + graph.teams_store[e.vertex], teams_gather[e.vertex])

    return parents[dest], teams_gather[dest]


def main():
    [vertex_count, edge_count, sourse, dest] = [int(i) for i in input().split()]
    g = GraphUndirectedWeighted(vertex_count)
    g.add_teams([int(i) for i in input().split()])
    for i in range(edge_count):
        [edge_a, edge_b, length] = [int(i) for i in input().split()]
        g.add_edge(edge_a, edge_b, length)

    shortest_path, teams_count = dijkstra(g, sourse, dest)
    print(shortest_path, teams_count)

if __name__ == "__main__":  
    main()
