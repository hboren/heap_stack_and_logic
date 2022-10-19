#include "heap.h"
#include <iostream>
using namespace std;

template <typename T, typename PComparator>
void print_heap(Heap<T,PComparator> my_heap){
	Heap<T,PComparator> temp = my_heap;
	for(int i = 0; i < (int)my_heap.size(); i++){
		cout << temp.top() << ", ";
		temp.pop();
	}
	cout << endl;
}


int main(int argc, char* argv[])
{
	std::cout <<"TESTING STRING HEAP" << endl;
	Heap<string> test2;
	if(test2.empty() == true){
		std::cout << "empty working correctly" << endl;
	}
	else{
		std::cout << "empty not working" << endl;
	}
	cout << "Size: " << test2.size() << endl;
	test2.push("b");
	print_heap(test2);
	test2.push("a");
	print_heap(test2);
	test2.push("aa");
	print_heap(test2);
	std::cout << endl;
	std::cout <<"TESTING INT HEAP" << endl;
	Heap<int> test;
	if(test.empty() == true){
		std::cout << "empty working correctly" << endl;
	}
	else{
		std::cout << "empty not working" << endl;
	}
	cout << "Size: " << test.size() << endl;
	//testing exception handling
	//test.pop();
	//test.top();
	test.push(42);
	print_heap(test);
	test.push(13);
	print_heap(test);
	test.push(6);
	print_heap(test);
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
	cout << "Top: " << test.top() << endl;
	cout << "Size: " << test.size() << endl;
	test.pop();
	cout << "Size: " << test.size() << endl;
	//cout << "Top: " << test.top() << endl;
	test.push(9);
	cout << "Size: " << test.size() << endl;

}