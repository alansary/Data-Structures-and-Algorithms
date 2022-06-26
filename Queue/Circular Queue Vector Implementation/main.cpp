#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    // 1. Initialize a queue.
    Queue q(4);
    // 2. Push new element.
    q.push(5);
    q.print();
    q.push(13);
    q.print();
    q.push(8);
    q.print();
    q.push(6);
    q.print();
    // 3. Check if queue is empty.
    if(q.empty()){
        cout << "Queue is empty!" << endl;
    }
    // 4. Pop an element.
    q.pop();
    q.print();
    // 5. Get the first element.
    cout << "The first element is: " << q.front() << endl;
    // 6. Get the last element.
    cout << "The last element is: " << q.back() << endl;
    // 7. Get the size of the queue.
    cout << "The size is: " << q.size() << endl;

    cout << "Queue Elements:" << endl;
    while (!q.empty()) {
    	cout << q.front() << endl;
    	q.pop();
    }

	return 0;
}
