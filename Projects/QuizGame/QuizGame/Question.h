#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <iostream>
#include <vector>
#include "aPair.h"
using namespace std;

class Question
{
public:
	Question(string q, aPair a1, aPair a2, aPair a3, aPair a4);
	void printall();
	char getAns();
private:
	string _question;
	vector<aPair> _answers;
	vector<aPair>::iterator iter;
	char _correct;
	
};

#endif
