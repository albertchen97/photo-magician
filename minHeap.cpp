//minHeap member function definition
#include "minHeap.h"
MinHeap::MinHeap()
{
	int dummy;//"dummy" holds nothing, only to fill up the index 0
	elements.push_back(dummy);
}
void MinHeap::push(int new_element)
{
	//add a new leaf to heap
	int dummy;
	elements.push_back(dummy);
	int index = elements.size() - 1;
	//demote (level down the position) parents that are greater than the new element
	while(index>1 && get_parent(index)>new_element)
	{
		elements[index] = get_parent(index);
		index = get_parent_index(index);
	}
	//store the new element into the vacant slot
	elements[index] = new_element;
}
int MinHeap::top()
{
	return elements[1];
}
void MinHeap::pop()
{
	//to remove the min value (elements[1]) in the heap, we need to assign the min_index (which is elements[1])
	//of the value of the last element (elements[last_index]) and delete the memory of the last index (by pop_back())
	int last_index = elements.size() - 1;
	int last = elements[last_index];//store the value of the last index to "last"
	elements.pop_back();//delet the memory
	if(last_index>1)//if what we delete is not the root of the heap, assign the root of the heap value of the last element
	{
		elements[1] = last;
		fix_heap();//then reheap
	}
}
void MinHeap::fix_heap()//to reheap the heap, make sure the root is the max
{
	int root = elements[1];
	int last_index = elements.size() - 1;
	int index = 1;
	bool done = false;
	while(!done)
	{
		//child_index: to store the index of one of the two child that need to compare with the root
		//first we compare the root with the left child
		int child_index = get_left_child_index(index);
		//but before comparing, we need to know if the right child is smaller than left child
		//if so, the child_index should change to right_child_index
		if(child_index <= last_index)
		{
			int child = get_left_child(index);//the value of left child
			if(get_right_child_index(index) <= last_index && child > get_right_child(index))
			{
				//explanation of the if statement condition:
				//the first part means: we must make sure we are not using a index that out of range (greater than last index)
				//the second part is true when the value of the right_child greater than the value of the left_child
				child_index = get_right_child_index(index);//move the child_index from left to right
				child = get_right_child(index);//child need to compare with root becomes right child
			}
			//now we can compare the child with the root
			if(root > child)
			{
				//promote child
				elements[index] = child;
				index = child_index;//then move the index to child_index, so that we can compare next level
			}
			else
			{
				//if root is smaller than both child, end the loop
				done = true;
			}
		}
		else 
		{
			//if there are no children, end the loop and assign the first elements to root
			done = true;
		}
	}
	//store root element in vacant slot
	elements[index] = root;
}
int MinHeap::size()
{
	return elements.size() - 1;
}
int MinHeap::get_left_child_index(int index)
{
	return 2*index;
}
int MinHeap::get_right_child_index(int index)
{
	return 2*index + 1;
}
int MinHeap::get_parent_index(int index)
{
	return index / 2;
}
int MinHeap::get_left_child(int index)
{
	return elements[2*index];
}
int MinHeap::get_right_child(int index)
{
	return elements[2*index + 1];
}
int MinHeap::get_parent(int index)
{
	return elements[index / 2];
}

		
	
	
		
				
		
