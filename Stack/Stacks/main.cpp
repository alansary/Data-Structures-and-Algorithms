#include <iostream>
//#include "stack.h"
#include "vector_stack.h"
using namespace std;

int main() {
//	Stack<char> s;
	Stack<char> s;
	s.push('h');
	s.push('e');
	s.push('l');
	s.push('l');
	s.push('o');
	while (!s.is_empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
