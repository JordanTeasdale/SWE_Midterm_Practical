#include <iostream>
#include "Question.h"

// Enables memory leak detection
#define _CRTDBG_MAP_ALLOC

int studentScore;

int main() {
	// Memory leak detection code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// This function call will set a breakpoint at the location of a leaked block
	// Set the parameter to the identifier for a leaked block
	_CrtSetBreakAlloc(-1);

	Question question1("What is 2+2?", "4", "2", "3", "1");
	if (question1.DisplayQuestion()) 
		++studentScore;
		
	system("pause");
	system("cls");

	Question question2("What state is Mount Rushmore in?", "South Dakota", "California", "Montana", "Nevada");
	if (question2.DisplayQuestion()) 
		++studentScore;
	system("pause");
	system("cls");

	Question question3("What year was the Declaration of Independence signed?", "1776", "1812", "1692", "1786");
	if (question3.DisplayQuestion()) 
		++studentScore;
	system("pause");
	system("cls");

	Question question4("When was Full Sail University founded?", "1979", "1982", "1973", "2001");
	if (question4.DisplayQuestion())
		++studentScore;
	system("pause");
	system("cls");

	Question question5("What is 243 * 3?", "729", "732", "735", "738");
	if (question5.DisplayQuestion())
		++studentScore;
	system("pause");
	system("cls");

	std::cout << "You got " << studentScore << "/5 correct. (" << ((float)studentScore / 5) * 100 << "%)" << '\n';


	std::cout << "\n\n";
	system("pause");
	return 0;
}