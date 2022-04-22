#include <iostream>
#include <vector>
using namespace std;

/*
 * Chopsticks
 * Given N sticks and an array length where each length[i] represents length of each stick. Your task is to make maximum number of pairs of
 * these sticks such that the difference between the length of two sticks is at most D. A stick can't be part of more than one pair of sticks.
 * Input Format
 * In the function an integer vector length and number D is passed.
 * Output Format
 * Return an integer representing total number of such pairs.
 * Sample Input
 * {1, 3, 3, 9, 4}, x = 2
 * Sample Output
 * 2
 * Explanation
 * (1st, 3rd) and (2nd, 5th) can be paired together.
 * Key Idea
 * Minimum difference is the difference between two sorted elements.
 */
int pairSticks(vector<int> length, int D)
{
    // counting sort
	int n = length.size();

	// get maximum
	int maximum = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (length[i] > maximum) {
			maximum = length[i];
		}
	}

	// frequency array
	vector<int> frequency(maximum + 1, 0);
	for (int i = 0; i < n; i++) {
		frequency[length[i]] += 1;
	}

	// put elements back in the original array
	int j = 0;
	for (int i = 0; i < maximum + 1; i++) {
		while (frequency[i] > 0) {
			length[j++] = i;
			frequency[i]--;
		}
	}

	// check pairs in length with max difference D
	int pairs = 0;
	for(int i = 0; i < n - 1; i++) {
        if (length[i + 1] - length[i] <= D) { pairs++; i++;}
    }

	return pairs;
}

int main() {
	vector<int> length = {1, 3, 3, 9, 4};

	cout << pairSticks(length, 2) << endl;

	return 0;
}
