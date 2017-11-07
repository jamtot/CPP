// QuizGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Question.h"
using namespace std;


int main()
{
	vector<Question> questions;
	questions.push_back(Question("What is the capital of Spain?", aPair("Madrid", 1), aPair("Salou", 0), aPair("Barcelona", 0), aPair("Catalonia", 0)));
	questions.push_back(Question("What is the capital of Denmark?", aPair("Copenhagen", 1), aPair("Odense", 0), aPair("Kolding", 0), aPair("Malmo", 0)));
	questions.push_back(Question("What is the capital of Ireland?", aPair("Belfast", 0), aPair("Cork", 0), aPair("Dublin", 1), aPair("Galway", 0)));

	vector<Question>::iterator iter;
	char ans;
	for (iter = questions.begin(); iter != questions.end(); iter++)
	{
		(*iter).printall();
		cout << "Please choose an answer: ";
		cin >> ans;
	}
	cin.get();
}

