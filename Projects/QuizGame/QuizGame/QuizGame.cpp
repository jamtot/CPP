// QuizGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Question.h"
using namespace std;

//author Jonathan Morris
/*
This is a little program that asks questions until an incorrect answer is given or it runs out of questions.
*/

int main()
{
	vector<Question> questions;
	// a vector containing questions
	questions.push_back(Question("What is the name of the dance troupe formed by Dublin-born Margaret Kelly in Paris in 1932?", aPair("Bluebell Girls", 1), aPair("Daffodil Girls", 0), aPair("Daisy Girls", 0), aPair("Lily Girls", 0)));
	questions.push_back(Question("Which TV soap features the Beale and Mitchell families?", aPair("Coronation Street", 0), aPair("EastEnders", 1), aPair("Emmerdale", 0), aPair("Hollyoaks", 0)));
	questions.push_back(Question("The small republic of San Marino is completely surrounded by which larger country?", aPair("India", 0), aPair("Iran", 0), aPair("Israel", 0), aPair("Italy", 1)));
	questions.push_back(Question("What was the name of Robert Maxwell's luxury yacht, from which he fell overboard in 1991?", aPair("Lady Chatterley", 0), aPair("Lady Ghislaine", 1), aPair("Lady Godiva", 0), aPair("Lady of Shalott", 0)));
	questions.push_back(Question("Something described as 'tactile' means that it relates to which of the senses?", aPair("Hearing", 0), aPair("Sight", 0), aPair("Taste", 0), aPair("Touch", 1)));
	questions.push_back(Question("The words of which song title appear on the Shankly Gates at Liverpool FC's Anfield stadium?", aPair("Abide With Me", 0), aPair("Follow That Dream", 0), aPair("My Way", 0), aPair("You'll Never Walk Alone", 1)));
	questions.push_back(Question("According to Greek mythology, after Pandora had opened her box to release all the evils of the world, what remained inside after she'd closed it again?", aPair("Charity", 0), aPair("Faith", 0), aPair("Hope", 1), aPair("Love", 0)));
	questions.push_back(Question("In US law enforcement agencies, what do the initials stand for in SWAT team?", aPair("Special War Against Terror", 0), aPair("Special Weapons And Tactics", 1), aPair("Special Women's Assimilation Test", 0), aPair("Special Wrongdoers' Arrest Treatment", 0)));
	questions.push_back(Question("In Treasure Island, Jim Hawkins is hiding in a barrel of what when he overhears Long John Silver's plan to take over the Hispaniola and murder its officers?", aPair("Apples", 1), aPair("Beer", 0), aPair("Flour", 0), aPair("Rum", 0)));
	questions.push_back(Question("When Premium Bonds were introduced in 1956, an individual bond cost how much?", aPair("1", 1), aPair("10", 0), aPair("20", 0), aPair("50", 0)));
	questions.push_back(Question("In bullfighting, what name is given to the horseman who jabs the bull with a lance?", aPair("Picador", 1), aPair("Picaroon", 0), aPair("Picotee", 0), aPair("Piculet", 0)));
	questions.push_back(Question("What is the title of the TV arts programme presented by Melvyn Bragg since 1970?", aPair("The East London Show", 0), aPair("The North Country Show", 0), aPair("The South Bank Show", 1), aPair("The West End Show", 0)));
	questions.push_back(Question("In which country is the Harz mountain range?", aPair("Austria", 0), aPair("Belgium", 0), aPair("Germany", 1), aPair("Spain", 0)));
	questions.push_back(Question("What type of creature is a gecko?", aPair("Bird", 0), aPair("Fish", 0), aPair("Lizard", 1), aPair("Monkey", 0)));
	questions.push_back(Question("During a 1987 court case, who was famously described by the judge as 'fragrant'?", aPair("Mary Archer", 1), aPair("Mary Parkinson", 0), aPair("Mary Poppins", 0), aPair("Mary Quant", 0)));
	questions.push_back(Question("Which US president once claimed to have been 'misunderestimated'?", aPair("George W Bush", 1), aPair("Jimmy Carter", 0), aPair("Gerald Ford", 0), aPair("Ronald Reagan", 0)));
	questions.push_back(Question("Which Shropshire town is named after a famous civil engineer?", aPair("Bridgnorth", 0), aPair("Ludlow", 0), aPair("Telford", 1), aPair("Whitchurch", 0)));
	questions.push_back(Question("Which of these is a type of persimmon?", aPair("Chantelle Fruit", 0), aPair("Brandine fruit", 0), aPair("Sharon fruit", 1), aPair("Tracy Fruit", 0)));
	questions.push_back(Question("What colour is the pigment chlorophyll?", aPair("Blue", 0), aPair("Green", 1), aPair("Red", 0), aPair("Yellow", 0)));
	questions.push_back(Question("Which pre-decimal coin was nicknamed a 'tosheroon'?", aPair("Penny", 0), aPair("Threepenny bit", 0), aPair("Sixpence", 0), aPair("Half-crown", 1)));
	//a python script is used to format the questions

	// questions are from http://www.pubquizarea.com/view_question_and_answer_quizzes.php?cat_title=general-knowledge&type_title=multiple-choice&cat=32&type=1&&id=6284
	// && http://www.pubquizarea.com/view_question_and_answer_quizzes.php?cat_title=general-knowledge&type_title=multiple-choice&cat=32&type=1&&id=6272
	vector<Question>::iterator iter;

	int points = 0;

	char ans;
	for (iter = questions.begin(); iter != questions.end(); iter++)
	{// iterates through the vector to output and take answers for questions
		(*iter).printall();
		cout << "Please choose an answer: ";
		cin >> ans;
		if (ans == (*iter).getAns())
		{// checks for correct answer being chosen
			cout << "Correct!";
			points++;
		}
		else 
		{// exits loop if incorrect answer given
			cout << "Incorrect! Game Over.";
			break;
		}
		cout << " You have " << points << " points!" << endl; 
	}
	// this is used to just pause after the game ends
	system("PAUSE");
}

