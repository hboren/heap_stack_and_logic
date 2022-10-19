#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> m_heap;
	void trickleUp(int loc, PComparator comp);
	void heapify(int idx, PComparator comp);
	PComparator m_comp;


};

// Add implementation of member functions here

//recursively swap a node at a given index until in correct place
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx, PComparator comp){
	//if idx is a leaf node, return
  if((idx*2)+2 > (int)size()) return;
	//start with left child
  int betterChild = 2*idx + 1;
	//if the right child exists
  if((int)size() > betterChild + 1){
		int rChild = betterChild +1;
		//if the right child is better then the left child, set the better child 
    //to be the right child
    if(comp(m_heap[rChild], m_heap[betterChild]))
			betterChild = rChild;
	}
  //if the better child is better than the parent (aka idx), 
  //swap parent and better child, then call heapify again with the now child node
	if(comp(m_heap[betterChild], m_heap[idx])){
		T temp = m_heap[idx];
		m_heap[idx] = m_heap[betterChild];
		m_heap[betterChild] = temp;
		heapify(betterChild, comp);
	}
}

//recursively promote node at idx up while it is better than its parent
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc, PComparator comp){
	int parent = (loc - 1)/2;
	//while the parent exists and given node is better than its parent
  //swap node w parent and reset indices so now node is the parent and 
  //parent is at the nodes old location
  while(parent >=0 && comp(m_heap[loc], m_heap[parent])){
		T temp = m_heap[loc];
		m_heap[loc] = m_heap[parent];
		m_heap[parent] = temp;
		loc = parent;
		parent = (loc - 1)/2;
	}
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_comp(c){

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
    return m_heap.std::vector<T>::size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
    //implement   
    return m_heap.std::vector<T>::empty();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    throw std::underflow_error("Tried to call top on empty heap");
    // ================================
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return m_heap.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    throw std::underflow_error("Tried to call pop on empty heap");
    // ================================
  }
	if(size() == 1 || size() == 2){
		m_heap[0] = m_heap.back();
		m_heap.pop_back();
		return;
	}
	else{
		//set top element to the back element and remove back element
		m_heap[0] = m_heap.back();
		m_heap.pop_back();
    //call heapify to maintain heap property
		heapify(0, m_comp);
	}


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  //add item to back and call trickleUp to maintain heap property
	m_heap.push_back(item);
	trickleUp(m_heap.size()-1, m_comp);
}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}



#endif

