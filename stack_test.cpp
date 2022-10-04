#include "stack.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	std::cout <<"TESTING STACK" << endl;
	Stack<int> test;
	if(test.empty() == true){
		std::cout << "empty working correctly" << endl;
	}
	else{
		std::cout << "empty not working" << endl;
	}
	cout << "Size: " << test.size() << endl;
	test.push(6);
	test.push(42);
	cout << "Size: " << test.size() << endl;
	if(test.empty() == false){
		std::cout << "not empty" << endl;
	}
	else{
		std::cout << "empty" << endl;
	}
	cout << "Top: " << test.top() << endl;
	cout << "Size: " << test.size() << endl;
	test.pop();
	cout << "Size: " << test.size() << endl;
	cout << "Top: " << test.top() << endl;
	test.pop();
	cout << "Size: " << test.size() << endl;
	test.push(13);
	cout << "Size: " << test.size() << endl;
}