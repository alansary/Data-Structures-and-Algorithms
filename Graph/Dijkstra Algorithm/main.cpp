#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

// Dijkstra's Algorithm

/*
 * Shortest Paths
 * - Weighted Graphs
 * - Single Source Shortest Paths (SSSP)
 */

class Graph {
	int V;
	list<pair<int, int>> *l;
public:
	Graph(int v) {
		V = v;
		l = new list<pair<int, int>>[V]; // V linked lists
	}

	void addEdge(int i, int j, int weight, bool undirected=true) {
		l[i].push_back({weight, j});
		if (undirected) {
			l[j].push_back({weight, i});
		}
	}

	int dijkstra(int src, int dest) {
		vector<int> dist(V, INT_MAX);
		set<pair<int, int>> s;

		dist[src] = 0;
		s.insert({0, src});

		while (!s.empty()) {
			auto it = s.begin();
			int node = it->second;
			int node_dist = it->first;
			s.erase(it);

			for (auto neighbor_pair : l[node]) {
				int neighbor = neighbor_pair.second;
				int current_edge = neighbor_pair.first;

				if (node_dist + current_edge < dist[neighbor]) {
					// Update distance

					// Remove if pair already exists in the set
					auto f = s.find({dist[neighbor], neighbor});
					if (f != s.end()) {
						s.erase(f);
					}

					// Update distance in dist array
					// Insert new distance
					dist[neighbor] = node_dist + current_edge; // Must update this first
					s.insert({dist[neighbor], neighbor});
				}
			}
		}

		// Single Source Shortest Path
		for (int i = 0; i < V; i++) {
			cout << "Node: " << i << ", Distance: " << dist[i] << endl;
		}

		return dist[dest];
	}
};

int main() {
	Graph g(5);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(0, 2, 4);
	g.addEdge(0, 3, 7);
	g.addEdge(3, 2, 2);
	g.addEdge(3, 4, 3);

	cout << g.dijkstra(0, 4) << endl;

	return 0;
}
