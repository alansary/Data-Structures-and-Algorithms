#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
 * Array Intersection!
 *
 * Given two integer arrays nums1 and nums2, return an array of their intersection.
 * Each element in the result must be unique and you may return the result vector in
 * the sorted order.
 *
 * Example:
 * Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
 * Output: [2]
 *
 * Constraints:
 * - 0 <= nums1.length, nums2.length <= 1000
 * - 0 <= nums1[i], nums2[i] <= 1000
 */

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> nums;
	vector<int> output;

	for (int e: nums1) {
		nums[e]++;
	}
	for (int e: nums2) {
		if (nums[e]) {
			output.push_back(e);
			nums[e] = 0;
		}
	}

	sort(output.begin(), output.end());

	return output;
}

vector<int> intersection_set_approach(vector<int>& nums1, vector<int>& nums2) {
	// Create sets
	set<int> s1, s2;

	// Insert elements in sets
	for (int e : nums1) s1.insert(e);
	for (int e : nums2) s2.insert(e);

	// Get the intersection
	vector<int> common_data;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(common_data));
	return common_data;
}

int main() {
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	vector<int> output = intersection(nums1, nums2);
	for (int e : output) {
		cout << e << " ";
	}
	cout << endl;

	output = intersection_set_approach(nums1, nums2);
	for (int e : output) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
