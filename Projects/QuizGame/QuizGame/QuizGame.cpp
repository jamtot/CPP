// QuizGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Question.h"
using namespace std;


int main()
{
	vector<Question> questions;
	questions.push_back(Question("What is the capital of Spain?", aPair("Madrid", 0), aPair("Salou", 0), aPair("Barcelona", 1), aPair("Catalonia", 0)));
	questions.push_back(Question("What is the capital of Denmark?", aPair("Copenhagen", 1), aPair("Odense", 0), aPair("Kolding", 0), aPair("Malmo", 0)));

	vector<Question>::iterator iter;
	for (iter = questions.begin(); iter != questions.end(); iter++)
	{
		(*iter).printall();
	}
	cin.get();
}

