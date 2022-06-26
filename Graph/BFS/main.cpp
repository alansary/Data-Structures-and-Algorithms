#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
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
};

int main() {
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);

	g.printAdjList();

	cout << endl;

	g.BFS(0);

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

	return 0;
}
