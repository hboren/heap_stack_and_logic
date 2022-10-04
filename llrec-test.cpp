#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

//returns true if a node should be removed (KEEP EVENS)!
//if even, return false aka keep, if
struct isOdd {
    bool operator()(int x) { return x % 2 == 0; } };
struct isEven {
    bool operator()(int x) { return x % 2 == 1; } };



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head1 = readList(argv[1]);
    Node* head2 = readList(argv[1]);
		Node* head3 = readList(argv[1]);
    cout << "Original list: ";
    print(head1);

    // Test out your linked list code
    //testing llpivot
    Node* smaller = head3;
    Node* larger = head3;
    cout<<"testing with garbage values: " << endl;
    print(smaller);
    print(larger);
    cout << endl;
    llpivot(head3, smaller, larger, 5);
    cout << "Smaller list (pivot 5): ";
    print(smaller);
    cout << "Larger list (pivot 5): ";
    print(larger);

    if(head3 == nullptr){
        cout << "head is null" << endl;
    }
    else{
        cout << "head is not null" << endl;
    }

    //testing llfilter
    isOdd c1;
    isEven c2;
    Node *evens = llfilter(head1, c2);
    cout << "Filtering for evens: "<<endl;
    print(evens);

    Node *odds = llfilter(head2, c1);
    cout << "Filtering for odds: "<<endl;
    print(odds);

		dealloc(odds);
		dealloc(evens);
		dealloc(smaller);
		dealloc(larger);
    
    return 0;

}
