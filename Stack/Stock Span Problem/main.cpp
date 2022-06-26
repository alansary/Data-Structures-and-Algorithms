#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * Write a class StockSpanner which collects daily price quotes for some stock, and returns
 * the span of that stock's for the current day.
 * The span of the stock's price today is defined as the maximum number of consecutive days
 * (starting from today and going backwards) for which the price of the stock was less than
 * or equal to today's price.
 * For example, if the price of a stock over the next 7 days were
 * [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
 */

vector<int> stockSpanner(vector<int> &stocks) {
	stack<int> s; // Indices of the day
	s.push(0);
	vector<int> span(stocks.size(), 0);
	span[0] = 1;

	// Loop through days
	int n = stocks.size();
	for (int i = 1; i < n; i++) {
		// Top most element that is higher than the current stock price
		int current_price = stocks[i];

		while (!s.empty() and stocks[s.top()] <= current_price) {
			s.pop();
		}

		if (s.empty()) {
			span[i] = i + 1;
		} else {
			span[i] = i - s.top();
		}

		// Push element into stack
		s.push(i);
	}

	return span;
}

int main() {
	vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};
	vector<int> span = stockSpanner(stocks);

	for (int i : span) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
