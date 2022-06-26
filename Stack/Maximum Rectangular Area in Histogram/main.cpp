#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * Maximum Rectangular Area in Histogram
 *
 * Find the largest rectangular area possible in a given histogram where the largest rectangle can
 * be made of a number of contiguous bars. Assume that all bars have width of 1 unit.
 *
 * Input Format: In the function an integer vector representing height of the bars is passed.
 * Output Format: Return an integer representing the maximum possible area.
 *
 * Sample Input: {6, 2, 5, 4, 5, 1, 6}
 * Sample Output: 12
 * Explanation: Max Area = 3 x 4 = 12
 */

int getMaxArea(vector<int> hist) {
    int n = hist.size();
    stack<int> s;

    int max_area = 0;
    int tp;
    int area_with_top;

    int i = 0;
    while (i < n) {
        if (s.empty() || hist[s.top()] <= hist[i]) {
        	s.push(i++);
        } else {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i :
                                   i - s.top() - 1);;
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i :
                                i - s.top() - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main() {
	vector<int> v = {6, 2, 5, 4, 5, 1, 6};
	cout << getMaxArea(v) << endl;

	return 0;
}
