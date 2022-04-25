#include <iostream>
#include <vector>
using namespace std;

/*
 * Sort Fruits!
 * Given a vector of pairs of a string and an integer
 * representing names and prices of different fruits. A string
 * is also passed as a parameter with name equals either "price",
 * meaning you have to sort the fruits on the basis of their
 * price or "name", which means you have to sort the fruit on
 * the basis of their name.
 * Input Format
 * In the function an integer vector of pairs is passed.
 * Output Format
 * Return an integer vector of pairs in sorted order.
 *
 * Sample Input
 * { {"Mongo", 100}, {"Guava", 70}, {"Grapes", 40},
 *   {"Apple", 60}, {"Banana", 30} }, S = "price"
 * Sample Output
 * { {"Banana", 30}, {"Grapes", 40}, {"Apple", 60},
 *   {"Guava", 70}, {"Mongo", 100} }
 */

bool compPrice(pair<string, int> f1, pair<string, int> f2) {
	return f1.second < f2.second;
}

bool compName(pair<string, int> f1, pair<string, int> f2) {
	return f1.first < f2.first;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){
	if (S == "price")
		sort(v.begin(), v.end(), compPrice);
	else if (S == "name")
		sort(v.begin(), v.end(), compName);

   return v;
}

int main() {
	vector<pair<string, int>> v = {
			{"Mongo", 100},
			{"Guava", 70},
			{"Grapes", 40},
			{"Apple", 60},
			{"Banana", 30}
	};

	string S = "price";
	vector<pair<string, int>> v_sorted_price = sortFruits(v, S);;

	for (pair p : v_sorted_price)
		cout << "(" << p.first << ", " << p.second << ")" << " ";
	cout << endl;

	S = "name";
	vector<pair<string, int>> v_sorted_name = sortFruits(v, S);

	for (pair p : v_sorted_name)
		cout << "(" << p.first << ", " << p.second << ")" << " ";
	cout << endl;


	return 0;
}
