#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int> v) {
	int total_sum = 0;

	for (int i = 0; i < v.size(); i++) total_sum += v[i];

	return total_sum;
}

bool comparator(pair<string, vector<int>> s1, pair<string, vector<int>> s2) {
	return sum(s1.second) > sum(s2.second);
}

int main() {
	vector<pair<string, vector<int>>> student_marks = {
			{"Mohamed", {10, 20, 11}},
			{"Ahmed", {10, 21, 3}},
			{"Mahmoud", {4, 5, 6}},
			{"Youssef", {10, 13, 20}}
	};

	sort(student_marks.begin(), student_marks.end(), comparator);

	for (int i = 0; i < student_marks.size(); i++) {
		cout << student_marks[i].first << ": " << sum(student_marks[i].second) << endl;
	}

	return 0;
}
