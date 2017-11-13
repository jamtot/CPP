#include "stdafx.h"
#include "Question.h"

Question::Question(string q, aPair a1, aPair a2, aPair a3, aPair a4)
{
	this->_question = q;
	this->_answers.push_back(a1);
	this->_answers.push_back(a2);
	this->_answers.push_back(a3);
	this->_answers.push_back(a4);
}

void Question::printall() {
	cout << _question << endl;
	iter = _answers.begin();
	for (char c = 'a'; iter != _answers.end(); iter++, c++)
	{
		cout << "\t" << c << ")" << (*iter).getAnswer() << endl;
		if ((*iter).getCorrect()) _correct = c;
	}
}

char Question::getAns()
{
	return _correct;
}