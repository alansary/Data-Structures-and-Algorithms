#include <iostream>
#include "queue_vector_implementation.h"
#include "circular_queue.h"
#include <queue>
using namespace std;

int main() {
	// Queue Vector Implementation
	cout << "Queue Vector Implementation\n";
    MyQueue myQueue;
    myQueue.enQueue(5);
    myQueue.enQueue(3);
    if (!myQueue.isEmpty()) {
        cout << myQueue.Front() << endl;
    }
    myQueue.deQueue();
    if (!myQueue.isEmpty()) {
        cout << myQueue.Front() << endl;
    }
    myQueue.deQueue();
    if (!myQueue.isEmpty()) {
        cout << myQueue.Front() << endl;
    }

    // Circular Queue
    cout << "\nCircular Queue\n";
    MyCircularQueue myCircularQueue(3);
    cout << myCircularQueue.enQueue(1) << endl; // return True
    cout << myCircularQueue.enQueue(2) << endl; // return True
    cout << myCircularQueue.enQueue(3) << endl; // return True
    cout << myCircularQueue.enQueue(4) << endl; // return False
    cout << myCircularQueue.Rear() << endl;     // return 3
    cout << myCircularQueue.isFull() << endl;   // return True
    cout << myCircularQueue.deQueue() << endl;  // return True
    cout << myCircularQueue.enQueue(4) << endl; // return True
    cout << myCircularQueue.Rear() << endl;     // return 4

//    MyCircularQueue testQueue(6);
//    cout << testQueue.enQueue(6) << endl;
//    cout << testQueue.Rear() << endl;
//    cout << testQueue.Rear() << endl;
//    cout << testQueue.deQueue() << endl;
//    cout << testQueue.enQueue(5) << endl;
//    cout << testQueue.Rear() << endl;
//    cout << testQueue.deQueue() << endl;
//    cout << testQueue.Front() << endl;
//    cout << testQueue.deQueue() << endl;
//    cout << testQueue.deQueue() << endl;
//    cout << testQueue.deQueue() << endl;

    // Built-in Queue
    cout << "\nBuilt-in Queue\n";

    // 1. Initialize a queue.
    queue<int> q;
    // 2. Push new element.
    q.push(5);
    q.push(13);
    q.push(8);
    q.push(6);
    // 3. Check if queue is empty.
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    // 4. Pop an element.
    q.pop();
    // 5. Get the first element.
    cout << "The first element is: " << q.front() << endl;
    // 6. Get the last element.
    cout << "The last element is: " << q.back() << endl;
    // 7. Get the size of the queue.
    cout << "The size is: " << q.size() << endl;
}
