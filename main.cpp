/**************************************************************************
 * Copyright (C) 2019-3019 Haoze Chen, Yunhao Du, Lanaiya Wu, Jong Bin Beak
 * 
 * This file is a part of CS-124-02 team project named "Photo Magician"
 * 
 * This project can be copied and/or distributed without the express
 * permission of anybody!
 ***************************************************************************/
#include "maxHeap.h"
#include "minHeap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
void readHeader(vector<string>,string);
void readImage(vector<string>,string,string);
void writeImage(vector<int>,string);
void medianFilter(vector<vector<int>>,vector<int>,int,string);
using namespace std;
int main()
{
	cout<<"Welcome to HYJL's Photo Magician!"<<endl;
	int choice=0;
	while(choice!=2)
	{
		cout<<"What do you want to do?"<<endl;
		cout<<"1 - Remove peopel from photoes"<<endl;
		cout<<"2 - Quit"<<endl;
		cin>>choice;
		while(choice!=1&&choice!=2)
			cin>>choice;
		// First read all the image files that we have
		vector<string>fileVector; //vector to store file name
		string fileName;//fileName elements to be stored into fileVector
		cout<<"Enter the file folder name that you want to process (image1 or image2): ";
		string folderName;
		cin>>folderName;
		//string str = "cd " + folderName + " && ls *.ppm > ../fileNameLog && cd ..";
		//const char* command = str.c_str();
		//system(command);//get file name into fileNames, and go back to project directory
		ifstream fileNameReader("fileNameLog");
		while(getline(fileNameReader,fileName))
			fileVector.push_back(fileName);//push file names into files vector	
		readHeader(fileVector,folderName);
		cout<<"Display the result image?(1-yes / 2-No): ";
		cin>>choice;
		while(choice!=1&&choice!=2)
			cin>>choice;
		if(choice==1)
			system("display result.ppm");
	}
	return 0;
}
