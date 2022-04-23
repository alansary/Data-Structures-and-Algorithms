#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 * Binary String to Number
 * Given a binary string as input, convert into its decimal form and return it as an integer.
 * Input Format
 * In the function a binary string is passed.
 * Output Format
 * Return an integer.
 *
 * Sample Input
 * 111
 *
 * Sample Output
 * 7
 */
int binaryToDecimal(string s)
{
    int decimal = 0;
    int power = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
    	if (s[i] == '1') decimal += pow(2, power);
    	power++;
    }

    return decimal;
}

int main() {
	string s = "1011";

	cout << binaryToDecimal(s) << endl;

	return 0;
}
