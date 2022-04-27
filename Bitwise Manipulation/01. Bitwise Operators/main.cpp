#include <iostream>
using namespace std;

int main() {
	/*
	 * - MSB (Most Significant Bit) = Sign Bit. -ve number
	 * if MSB is 1.
	 * - Numbers are stored in memory in 2s complement form,
	 * to get its magnitude, we first invert the bits then we
	 * add 1 and convert binary to decimal.
	 */

	/*
	 * AND &
	 * 0	0	0
	 * 0	1	0
	 * 1	0	0
	 * 1	1	1
	 * Example: 5 & 7 = 0101 & 0111 = 0101 = 5
	 */
	cout << "Binary AND\n";
	cout << bitset<32>(5).to_string() << "\n&\n" << bitset<32>(7).to_string() << "\n================================\n" << bitset<32>(5).to_string() << endl;
	cout << endl;

	/*
	 * OR |
	 * 0	0	0
	 * 0	1	1
	 * 1	0	1
	 * 1	1	1
	 * Example: 5 | 8 = 0101 | 1000 = 1101 = 13
	 */
	cout << "Binary OR\n";
	cout << bitset<32>(5).to_string() << "\n|\n" << bitset<32>(8).to_string() << "\n================================\n" << bitset<32>(13).to_string() << endl;
	cout << endl;

	/*
	 * XOR ^
	 * 0	0	0
	 * 0	1	0
	 * 1	0	0
	 * 1	1	0
	 * Example: 5 ^ 7 = 0101 ^ 0111 = 0010 = 2
	 */
	cout << "Binary XOR\n";
	cout << bitset<32>(5).to_string() << "\n^\n" << bitset<32>(7).to_string() << "\n================================\n" << bitset<32>(2).to_string() << endl;
	cout << endl;

	/*
	 * One's Complement ~
	 * 0	1
	 * 1	0
	 * Example: ~5 = ~0101 = 1010
	 * Example: ~0 = 1; where 0 is a bit
	 * Example: int a = 0; a represented as 000...0 32 bits in
	 * memory, ~a = 111...1 bits in memory with MSB = sign bit,
	 * to find its magnitude we invert the 2s complement to be
	 * 100...0 where 1 is the sign bit not part of the 2s complement,
	 * then we add 1 100...1 then convert it to -1 decimal.
	 */
	cout << "Binary One's Complement\n";
	cout << "~" << bitset<32>(5).to_string() << "\n=================================\n " << (~bitset<32>(5)).to_string() << endl;
	cout << endl;
	cout << "~" << bitset<32>(0).to_string() << "\n=================================\n " << (~bitset<32>(0)).to_string() << endl;
	cout << endl;
	cout << "~0\n==\n" << (~0) << endl;
	cout << endl;

	/*
	 * Left Shift <<
	 * a << b will multiplies a by 2^b
	 */
	cout << "Binary Left Shift\n";
	cout << bitset<32>(5).to_string() << endl;
	cout << "<<\n" << (bitset<32>(5) << 1).to_string() << endl;
	cout << "<<\n" << (bitset<32>(5) << 2).to_string() << endl;
	cout << "..." << endl;
	cout << "<<\n" << (bitset<32>(5) << 28).to_string() << endl;
	cout << "<<\n" << (bitset<32>(5) << 29).to_string() << endl;
	cout << "<<\n" << (bitset<32>(5) << 30).to_string() << endl;
	cout << "<<\n" << (bitset<32>(5) << 31).to_string() << endl;
	cout << "<<\n" << (bitset<32>(5) << 32).to_string() << endl;
	cout << endl;

	/*
	 * Right Shift >>
	 * a >> b will divides a by 2^b
	 */
	cout << "Binary Right Shift\n";
	cout << bitset<32>(5).to_string() << endl;
	cout << ">>\n" << (bitset<32>(5) >> 1).to_string() << endl;
	cout << ">>\n" << (bitset<32>(5) >> 2).to_string() << endl;
	cout << "..." << endl;
	cout << ">>\n" << (bitset<32>(5) >> 28).to_string() << endl;
	cout << ">>\n" << (bitset<32>(5) >> 29).to_string() << endl;
	cout << ">>\n" << (bitset<32>(5) >> 30).to_string() << endl;
	cout << ">>\n" << (bitset<32>(5) >> 31).to_string() << endl;
	cout << ">>\n" << (bitset<32>(5) >> 32).to_string() << endl;

	return 0;
}
