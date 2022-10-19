makeCXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
OBJS=llrec.o llrec-test.o

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

llrec-test.o: llrec.cpp llrec.h llrec-test.cpp 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp


stack_test: stack_test.cpp stack.h
	g++ -g -Wall -std=c++11 stack_test.cpp -o stack_test
	./stack_test

my_heap_test: my_heap_test.cpp heap.h
	g++ -g -Wall -std=c++11 my_heap_test.cpp -o my_heap_test
	./my_heap_test

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 