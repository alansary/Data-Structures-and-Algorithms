#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool predicate(int haystack_element, int arr_element) {
	return (haystack_element == arr_element-1);
}

int main() {
	vector<int> arr = {10, 11, 2, 3, 4, 6, 7, 8};
	int key = 11;

	// linear search
	vector<int>::iterator it = find(arr.begin(), arr.end(), key); // address of the element

	if (it == arr.end())
		cout << "Element NOT found!" << endl;
	else
		cout << "Element at index: " << it - arr.begin() << endl; // address - base_address

	// search for sequence of elements
	vector<int> haystack;

	for (int i =1; i < 10; i++) haystack.push_back(i * 10); // haystack: 10 20 30 40 50 60 70 80 90

	int n = 4;
	int needle[] = {40, 50, 60, 70};
	it = search(haystack.begin(), haystack.end(), needle, needle+n);

	if (it != haystack.end())
		cout << "Needle found at position " << (it - haystack.begin()) << endl;
	else
		cout << "Needle NOT found!\n";

	needle[0] = 41;
	needle[1] = 51;
	needle[2] = 61;
	needle[3] = 71;
	it = search(haystack.begin(), haystack.end(), needle, needle+n, predicate);

	if (it != haystack.end())
		cout << "Needle found at position " << (it - haystack.begin()) << endl;
	else
		cout << "Needle NOT found!\n";

	vector<int> hs = {1, 2, 3, 4, 6, 7, 8, 9};
	// binary_search() - returns bool - O(logn)
	cout << binary_search(hs.begin(), hs.end(), 4) << endl;
	cout << binary_search(hs.begin(), hs.end(), 5) << endl;

	// lower_bound()
	auto lower = lower_bound(hs.begin(), hs.end(), 4);
	cout << *lower << " at index " << (lower - hs.begin()) << endl;
	// Search for first element x such that 5 ≤ x
	lower = lower_bound(hs.begin(), hs.end(), 5);
	cout << *lower << " at index " << (lower - hs.begin()) << endl;

	// upper_bound()
	auto upper = upper_bound(hs.begin(), hs.end(), 4);
	cout << *upper << " at index " << (upper - hs.begin()) << endl;
	// Search first element that is greater than 5
	upper = upper_bound(hs.begin(), hs.end(), 5);
	cout << *upper << " at index " << (upper - hs.begin()) << endl;

	return 0;
}
