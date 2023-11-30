#include "maxHeap.h"
#include "minHeap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
//read the header
void readImage(vector<string>,string,string);
void readHeader(vector<string>fileVector,string folderName)
{
	cout<<"Reading header..."<<endl;
	string headerPath = folderName + "/" + fileVector[0];
	string header;
	string addHeader;
	ifstream headerReader(headerPath);//read the header from the first file
	for(int i = 0;i < 3; i++)
	{
		getline(headerReader,addHeader);
		header += addHeader + "\n";
	}
	headerReader.close();
	readImage(fileVector,header,folderName);
}
