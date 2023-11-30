//to write median pixels into a image file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
void writeImage(vector<int> medianVector,string header)
{
	cout<<"Writing the result image into result.ppm file..."<<endl;
	ofstream writeResult("result.ppm");
	writeResult<<header;
	for(auto i:medianVector)
		writeResult<<i<<" "<<endl;
	cout<<"Done!"<<endl;
}
