//to read pixel data from origin images
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
void medianFilter(vector<vector<int>>,vector<int>, int ,string);
void readImage(vector<string> files,string header,string folderName)
{
	cout<<"Reading image..."<<endl;
	int size;//to store the size of pixel_of_each_file vector
	vector<vector<int>>pixel_with_same_index;	//use 2d vector (a vector of vectors) to store pixel data
	vector<int>pixel_of_each_file;
	//Then we need to store pixel data
	//1. Each file has a vector to hold all the pixels
	//2. Another vector holds pixels with same indices in each file
	//3. By putting the second vector into heap, we can get median
	int header_length = 0;
	for(int i=0;header[i];i++)//to count how many characters to ignore in header
		header_length++;
	for(int i=0;i<files.size();i++)
	{
		string filePath = folderName + "/" + files[i];
		ifstream reader;
		reader.open(filePath);
		int getPixel;
		reader.ignore(header_length);//ignore the header (which have 12 characters)
		string line;
		while(getline(reader,line))
		{
			istringstream readPixel(line);
			while(readPixel>>getPixel)//getPixel is int type, as long as readPixel reads an integer it will store it into pixel.
				pixel_of_each_file.push_back(getPixel);	
		}
		pixel_with_same_index.push_back(pixel_of_each_file);
		size = pixel_of_each_file.size();//save the size
		pixel_of_each_file.clear();//clear the vector so that it can store pixels of next file
		reader.close();
		cout<<files[i]<<" has been read!"<<endl;
	}
	cout<<"All images in folder has been read!"<<endl;
	medianFilter(pixel_with_same_index , pixel_of_each_file , size , header);
}
