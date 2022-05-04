#include<iostream>
#include "deq.h"

int main(int argc, char const *argv[]) {
	Deque deque;
	deque.push_front("str");
	deque.push_front("char");
	deque.printFront();
	deque.printBack();
	deque.printCount();
	return 0;
}
