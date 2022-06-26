#include <iostream>
#include <queue>
using namespace std;

/*
 * Interleave two halves of a queue
 *
 * Given a queue of integers of even length, rearrange the elements by interleaving the
 * first half of the queue with the second half of the queue.
 *
 * Input Format: In the function an integer queue passed.
 * Output Format: Return the interleaved queue.
 *
 * Sample Input: 11 12 13 14 15 16 17 18 19 20
 * Sample Output: 11 16 12 17 13 18 14 19 15 20
 */

queue<int> interLeave(queue<int> q){
	queue<int> q1, q2;

	int size = q.size() / 2;
	for (int i = 0; i < size; i++) {
		q1.push(q.front());
		q.pop();
	}

	size = q.size();
	for (int i = 0; i < size; i++) {
		q2.push(q.front());
		q.pop();
	}

	size = q1.size();
	for (int i = 0; i < size; i++) {
		q.push(q1.front());
		q.push(q2.front());
		q1.pop();
		q2.pop();
	}

	return q;
}

int main() {
	queue<int> input;
	input.push(11);
	input.push(12);
	input.push(13);
	input.push(14);
	input.push(15);
	input.push(16);
	input.push(17);
	input.push(18);
	input.push(19);
	input.push(20);

	queue<int> output = interLeave(input);
	while (!output.empty()) {
		cout << output.front() << " ";
		output.pop();
	}
	cout << endl;

	return 0;
}
