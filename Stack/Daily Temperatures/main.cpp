#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Daily Temperatures

/*
 * Given an array of integers temperatures represents the daily temperatures, return an
 * array answer such that answer[i] is the number of days you have to wait after the ith
 * day to get a warmer temperature. If there is no future day for which this is possible,
 * keep answer[i] == 0 instead.
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 *
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 *
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 * Constraints:
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 */

vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> days;
	stack<int> indices;

	for (int i = temperatures.size() - 1; i >= 0; i--) {
		while (!indices.empty() && temperatures[indices.top()] <= temperatures[i]) {
			indices.pop();
		}

		if (indices.size() == 0) {
			days.push_back(0); // Special case if the stack is empty
		} else {
			days.push_back(indices.top() - i);
		}

		indices.push(i);
	}

	reverse(days.begin(), days.end());

	return days;
}

/*
 * 73, 7 7 - 6 = 1
 * 74, 6 6 - 5 = 1
 * 75, 5 5 - 1 = 4
 * 71, 4 4 - 2 = 2 XXX for 75
 * 69, 3 3 - 2 = 1 XXX for 71
 * 72, 2 2 - 1 = 1 xxx for 75
 * 76, 1 special case index-1
 * 73, 0 special case 0 1st XXX for 76
 *
 * Input: [73, 74, 75, 71, 69, 72, 76, 73]
 * Output: [1, 1, 4, 2, 1, 1, 0, 0]
 */

int main() {
	vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> days = dailyTemperatures(temperatures);

	for (int d : days) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}
