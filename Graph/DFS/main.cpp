#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Adjacency List Representation

class Graph {
	int V;
	list<int> *l;
public:
	Graph(int v) {
		V = v;
		l = new list<int>[V]; // V linked lists
	}

	void addEdge(int i, int j, bool undirected=true) {
		l[i].push_back(j);
		if (undirected) {
			l[j].push_back(i);
		}
	}

	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << i << " -> [";
			for (int e : l[i]) {
				cout << e << ", ";
			}
			cout << "]\n";
		}
	}

	// O(V + E)
	void BFS(int source) {
		queue<int> q;
		q.push(source);
		bool *visited = new bool[V]{0};
		visited[source] = true;

		while (!q.empty()) {
			int front = q.front();
			q.pop();
			cout << front << " -> ";

			// Push the neighbors
			for (auto neighbor : l[front]) {
				if (!visited[neighbor]) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		cout << endl;
	}

	// O(V + E)
	void DFS(int source) {
		stack<int> s;
		s.push(source);
		bool *visited = new bool[V]{0};
		visited[source] = true;

		while (!s.empty()) {
			int top = s.top();
			s.pop();
			cout << top << " -> ";

			// Push the neighbors
			for (auto neighbor : l[top]) {
				if (!visited[neighbor]) {
					s.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		cout << endl;
	}

	void DFSHelper(int node, bool *visited) {
		visited[node] = true;
		cout << node << " -> ";

		// Make a recursive call on all unvisited neighbors
		for (auto neighbor : l[node]) {
			if (!visited[neighbor])
				DFSHelper(neighbor, visited);
		}

		return;
	}

	void DFSRecursive(int node) {
		bool *visited = new bool[V]{0};
		DFSHelper(node, visited);
		cout << endl;
	}
};

// Adjacency List Representation with Node Class

class Node {
private:
	string city;
	list<string> neighbors;
public:
	Node(string city) {
		this->city = city;
	}

	friend class GraphNC;
};

class GraphNC {
	unordered_map<string, Node*> m;
public:
	GraphNC(vector<string> cities) {
		for (auto city : cities) {
			m[city] =  new Node(city);
		}
	}

	void addEdge(string x, string y, bool undirected=false) {
		m[x]->neighbors.push_back(y);
		if (undirected) {
			m[y]->neighbors.push_back(x);
		}
	}

	void printAdjList() {
		for (auto city_pair : m) {
			cout << city_pair.first << " -> [";
			for (auto city : city_pair.second->neighbors) {
				cout << city << ", ";
			}
			cout << "]\n";
		}
	}

	// O(V + E)
	void BFS(string source) {
		queue<string> q;
		q.push(source);
		unordered_map<string, bool> visited;
		visited[source] = true;

		while (!q.empty()) {
			string front = q.front();
			q.pop();
			cout << front << " -> ";

			// Push the neighbors
			for (auto neighbor : m[front]->neighbors) {
				if (visited.find(neighbor) == visited.end()) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		cout << endl;
	}

	// O(V + E)
	void DFS(string source) {
		stack<string> s;
		s.push(source);
		unordered_map<string, bool> visited;
		visited[source] = true;

		while (!s.empty()) {
			string top = s.top();
			s.pop();
			cout << top << " -> ";

			// Push the neighbors
			for (auto neighbor : m[top]->neighbors) {
				if (visited.find(neighbor) == visited.end()) {
					s.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		cout << endl;
	}
};

int main() {
	Graph g(7);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(5, 6);

	g.printAdjList();
	cout << endl;

	g.BFS(1);
	g.DFS(1);
	g.DFSRecursive(1);
	cout << endl;

	vector<string> cities = {"Cairo", "Alexandria", "Matrouh", "Sinai"};
	GraphNC gnc(cities);
	gnc.addEdge("Cairo", "Sinai");
	gnc.addEdge("Alexandria", "Cairo");
	gnc.addEdge("Matrouh", "Alexandria");
	gnc.addEdge("Sinai", "Matrouh");

	gnc.printAdjList();
	cout << endl;

	gnc.BFS("Matrouh");
	gnc.DFS("Matrouh");

	return 0;
}
