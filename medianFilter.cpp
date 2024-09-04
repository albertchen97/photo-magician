//use MinHeap and MaxHeap to get the median value
#include "maxHeap.h"
#include "minHeap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
void writeImage(vector<int>,string);
void medianFilter(vector<vector<int>>pixel_with_same_index,vector<int>pixel_of_each_file,int size,string header)
{
	cout<<"Median Filter is working..."<<endl;
	vector<int>medianVector;
	int median = 0;
	for(int i=0;i<size;i++)
	{
		//push pixel_with_same_index into heap to calculate the median
		MinHeap min;
		MaxHeap max;
		for(int j=0;j<pixel_with_same_index.size();j++)
		{
			//accessing the value of 2d vector, means: get the [i]th element from the [j]th vector
			int value = pixel_with_same_index[j][i];
			min.push(value);
			max.push(value);
		}
		//get the median
		while(min.top()!=max.top())
		{
			min.pop();
			max.pop();
		}
		median = min.top();
		// if(min.top()==max.top())
		// {
		// 	int median = min.top();
		// 		medianVector.push_back(median);
		// }
		// else
		// {
		// 	cout<<"Data error!"<<endl;
		// 	i=pixel_of_each_file.size();//end the loop
		// }
		medianVector.push_back(median);
	}
	cout<<"All images has been processed!"<<endl;
	//pass the medianVector to writeImage to get the result image
	writeImage(medianVector,header);
}