#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * Finding Cabs
 *
 * Given N Cartesian points in a 2D plane, each represents the location of the cab. You are
 * standing at the origin, you want to know the names of nearest K cars.
 *
 * Sample Input: N = 5, K = 3, C1 1 1, C2 2 1, C3 3 2, C4 0 1, C5 2 3.
 * Input: 5 3 C1 1 1 C2 2 1 C3 3 2 C4 0 1 C5 2 3
 * Sample Output: C4, C1, C2.
 * Output: C4 C1 C2
 *
 * Approaches:
 * Sort - O(nlogn + k)
 * Min Heap - O(n + klogn)
 * Better? O(k + (n-k) logk), if we want the result sorted, this will add O(klogk)
 * 1. Build a max heap of size k
 * 2. Push the first k elements
 * 3. For all subsequent elements, if element is smaller than the heap max, replace it with
 * heap max
 * 4. After finishing all elements, your max heap will contain the top k smallest elements
 */

class Car {
public:
	string id;
	int x, y;

	Car(string id, int x, int y) {
		this->id = id;
		this->x = x;
		this->y = y;
	}

	int dist() const {
		// Get Euclidean distance from a and b to origin
		// Not need to take sqrt for comparison
		return x * x + y * y;
	}
};

//class CompareMinHeap {
//public:
//	bool operator()(Car a, Car b) {
//		// Get Euclidean distance from a and b to origin
//		// Not need to take sqrt for comparison
//		int dist1 = a.x * a.x + a.y * a.y;
//		int dist2 = b.x * b.x + b.y * b.y;
//
//		return dist1 > dist2;
//	}
//};
//
//void printNearestCarsMinHeap(vector<Car> &cars, int k) {
//	// Push cars to priority queue
//	priority_queue<Car, vector<Car>, CompareMinHeap> h(cars.begin(), cars.end());
//
//	// Print nearest k cars
//	for (int i = 0; i < k; i++) {
//		cout << h.top().id << " ";
//		h.pop();
//	}
//	cout << endl;
//}

class Compare {
public:
	bool operator()(const Car a, const Car b) {
		return a.dist() < b.dist(); // max heap
	}
};

bool distCompare(Car a, Car b) {
	return a.dist() < b.dist();
}

void printNearestCars(vector<Car> &cars, int k) {
	// Push first k cars to priority queue
	priority_queue<Car, vector<Car>, Compare> h(cars.begin(), cars.begin() + k);

	// Remaining (n - k) cars
	for (int i = k; i < cars.size(); i++) {
		auto car = cars[i];

		if (car.dist() < h.top().dist()) {
			h.pop(); // Remove the root node (largest node)
			h.push(car);
		}
	}

	// Store output into vector
	vector<Car> output;
	while (!h.empty()) {
		output.push_back(h.top());
		h.pop();
	}

//	// Sort output vector
//	sort(output.begin(), output.end(), distCompare);
	// Or reverse the output vector
	reverse(output.begin(), output.end());

	// Print all heap nodes
	for (auto car : output) {
		cout << car.id << " ";
	}
	cout << endl;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<Car> cars;
	string id;
	int x, y;

	for (int i = 0; i < n; i++) {
		cin >> id >> x >> y;
		cars.push_back(Car(id, x, y));
	}

//	printNearestCarsMinHeap(cars, k);
	printNearestCars(cars, k);

	return 0;
}
