#include <iostream>
#include <vector>
using namespace std;

/*
 * Subset Sum Queries
 * Given an array and N number of queries, where in each query you have to check whether a
 * subset whose sum is equal to given number exists in the array or not.
 * Input Format
 * In the function two vectors num and query are passed.
 * Output Format
 * Return a bool vector of size N representing each query.
 *
 * Sample Input
 * num[] = {1, 2, 3}
 * query[] = {5, 3, 8}
 *
 * Sample Output
 * {Yes, Yes, No}
 *
 * Explanation
 * There is a subset with sum 5, subset is {2, 3}
 * There is a subset with sum 3, subset is {1, 2}
 * There is no subset with sum 8
 *
 * Idea
 * Using bitset, we can precalculate the existence all the subset sums in an array in O(n) and
 * answer subsequent queries in just O(1).
 * Size of bit[] should be at least sum of all array elements plus 1 to answer all queries.
 * We keep of bit[x] as 1 if x is a subset sum of given array.
 *
 * 00000001
 * 00000001 | 00000010 = 00000011 // bit |= (bit << num[i]) and i = 1
 * 00000011 | 00001100 = 00001111 // bit |= (bit << num[i]) and i = 2
 * 00001111 | 01111000 = 01111111 // bit |= (bit << num[i]) and i = 3
 * bit[5] ? true
 * bit[3] ? true
 * bit[8] ? false
 */

vector<bool> subsetSum(vector<int> num, vector<int> query)
{
    int n = query.size();
    vector<bool> output(n);

    bitset<10000> bit;
    bit.reset();
    bit[0] = 1;

    for (int i = 0; i < num.size(); ++i)
        bit |= (bit << num[i]); // bit[x] will be 1 if x is a subset sum of num[], else 0

    for(int i = 0; i < n; i++)
    {
        int x = query[i];
        bit[x] ? output[i] = true : output[i] = false;
    }

    return output;
}

int main() {
	vector<int> num {1, 2, 3};
	vector<int> query {5, 3, 8};
	vector<bool> output;

	output = subsetSum(num, query);

	for (int i = 0; i < output.size(); i++) {
		cout << (output[i] ? "Yes" : "No") << " ";
	}
	cout << endl;

	return 0;
}
