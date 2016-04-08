#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

int stringToInt(string s);
vector<int> getSqFromText(string sqr);
void fillArrayFromVector(int ** array, const int SIZE, vector<int> intVect);
void populateArray(int ** array, string input);
vector< vector<int> > getYaVecVec(string sqr);
void printVecvec(vector< vector<int> > vec2d);

int main(){
	string input0 = "15 14 1 4\n"
					"12 6 9 7\n"
					"2 11 8 13\n"
					"5 3 16 10\n";
	
	printVecvec(getYaVecVec(input0));
}

void printVecvec(vector< vector<int> > vec2d){
	for (unsigned int i = 0; i < vec2d.size(); i++){
		for (unsigned int j = 0; j < vec2d[0].size(); j++){
			cout << vec2d[i][j] << " ";
		}
		cout << endl;
	}
}

vector< vector<int> > getYaVecVec(string sqr){
	int start=0, end = 0;
	vector< vector<int> > vecvec;	
	int unsigned i = 0;
	
	while (i < sqr.length()){
		vector<int> vint;
		
		while (sqr[i] != '\n' || i != (sqr.length()-1)){
			if (sqr[i] == ' '){

				end = i;
				vint.push_back( stringToInt(sqr.substr(start, end-start )) );
				start=end+1;
			} else if (sqr[i] == '\n') break;// isn't breaking without this
			i++;
		}
		
		if (sqr[i] == '\n'){
			end = i;
			vint.push_back( stringToInt(sqr.substr(start, end-start )) );
			start=end+1;
		}
		else if (i == sqr.length()-1){
			end = i+1;
			vint.push_back( stringToInt(sqr.substr(start, end-start )) );
			start=end+1;
		}
		

		vecvec.push_back(vint);
		i++;
	}
	
	return vecvec;
}

void populateArray(int ** array, string input){
	vector<int> thingy = getSqFromText(input);
	const int SIZE = sqrt(thingy.size());
	array = new int*[SIZE];
	for (int i = 0; i < SIZE; ++i){
		array[i] = new int [SIZE];
	}
	fillArrayFromVector(array, SIZE, thingy);
}


void fillArrayFromVector(int ** array, const int SIZE, vector<int> intVect){

	int x = 0;
	for (vector<int>::iterator it = intVect.begin(); it != intVect.end(); ++it, x++){
		array[x/SIZE][x%SIZE] = *it;
	}
	
	for (int i =0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

vector<int> getSqFromText(string sqr){
	int start=0, end = 0;
	vector<int> vint;
	int count = 0;
	for (unsigned int i = 0; i < sqr.length(); i++){
		if (sqr[i] == ' '){
			end = i;
			vint.push_back( stringToInt(sqr.substr(start, end-start )) );
			start=end+1;
			count++;
		} else if (sqr[i] == '\n'){
			end = i;
			vint.push_back( stringToInt(sqr.substr(start, end-start )) );
			start=end+1;
			count++;
		} else if (i == sqr.length()-1){// str[i]=='/0' didn't work
			end = i+1;
			vint.push_back( stringToInt(sqr.substr(start, end-start )) );
			start=end+1;
			count++;
		}
	}
	return vint;
}

int stringToInt(string s){
	return atoi(s.c_str());
}
