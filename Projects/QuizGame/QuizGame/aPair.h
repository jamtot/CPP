#pragma once
#include <string>
class aPair
{
private:
	std::string _answer;
	bool _correct;
public:
	aPair(std::string answer, bool correct);
	~aPair();
	bool getCorrect() { return _correct; }
	std::string getAnswer() { return _answer; }
};

