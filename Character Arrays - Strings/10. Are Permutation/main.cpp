#include <iostream>
using namespace std;

/*
 * Are Permutation
 * Given two strings A and B. Check if one string is permutation of the other.
 * A permutation of a string is another string that contains same characters, only the order of characters can be different. For example, "abcd" and
 * "dabc" are permutation of each other.
 * Input Format
 * In the function two strings passed.
 * Output Format
 * Return true if B is permutation of A else false.
 *
 * Sample Input
 * string A = "test", B = "ttew"
 * Sample Output
 * NO
 */
bool arePermutation(string A, string B)
{
	// try all different permutations of A with the string B
    for (int i = 0; i < A.length(); i++) {
    	// start A from the current position
    	int j = i;
    	// start B from 0
    	int k = 0;

    	// while there is a match increment indices
    	while (j < A.length() && A[j] == B[k]) {
    		j++;
    		k++;
    	}

    	// if we reached end of string A
    	if (j == A.length()) {
    		// start A from index 0 to check rest of strings if any
    		j = 0;
    		while (j < i && A[j] == B[k]) {
    			j++;
    			k++;
    		}

    		// if we break and characters doesn't match, then not a permutation
    		if (j != i) {
    			continue;
    		}
    		else return true; // permutation
    	} else {
    		continue; // we break because characters doesn't match
    	}

    }
    return false;
}

int main() {
	string A, B;
	A = "test";
	B = "ttew";

	cout << arePermutation(A, B) << endl;

	return 0;
}
