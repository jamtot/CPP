#include <iostream>
#include <cstring>

using namespace std;

char cypher(char c){
	int offset;
	int cval = int(c);
	bool change = true;
	if (cval > 64 && cval < 91) {
		offset = 65;
	} else if (cval > 96 && cval < 123) { 
		offset = 97; 
	} else { change = false; }
	if (change)
		c = char((25-(cval-offset))+offset);
	return c;
}

string cyphstring(string s){
	for (unsigned int i = 0; i < s.length(); i++){
		s[i] = cypher(s[i]);
	}
	return s;
}

void print(string s){
	cout << s << endl;
}

int main(){
	string input0 = "abcxyz...ABCXYZ";
	string input1 = "foobar";
	string input2 = "wizard";
	string input3 = "/r/dailyprogrammer";
	string input4 = "gsrh rh zm vcznkov lu gsv zgyzhs xrksvi";
	string input5 = "Gsrh kivhvievh xzkrgzo ovggvih, zmw kfmxgfzgrlm.";
	
	print(cyphstring(input0));
	print(cyphstring(input1));
	print(cyphstring(input2));
	print(cyphstring(input3));
	print(cyphstring(input4));
	print(cyphstring(input5));


}
