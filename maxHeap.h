//class decleration for max heap
//the basic idea and logic structure is from the textbook (Ch17.2),
//I did some manipulation to fit our specific requirements
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
using namespace std;
class MaxHeap
{
public:
	MaxHeap();//construct an empty heap
	void push(int);//add new element into heap
	void pop();//remove the max element in this heap
	int top();//gets the max element in this heap
	int size();//return the size of this heap
private:
	void fix_heap();//when the tree no follows the heap condition, reheap it
	int get_left_child_index(int);//receives a index of a node, returns the index of the left child of the given node
	int get_right_child_index(int);//receives a index of a node, returns the index of the right child of the given node
	int get_parent_index(int);//receives a index of a node, returns the index of the parent of the given node
	int get_left_child(int);//receives a index of a node, returns the value of the left child of the given node
	int get_right_child(int);//receives a index of a node, returns the value of the right child of the given node
	int get_parent(int);//receives a index of a node, returns the value of the parent of the given node
	/*
	We can either use vector or array to store heap values, if we don't know the number of elements, 
	it's better to use vector since it can dynamically expanded, if we have a fixed size (such as 9 in this lab), 
	we can also use array. But since the textbook is using vector, I just follow the book here.
	*/
	vector<int> elements;
};
#endif
	
