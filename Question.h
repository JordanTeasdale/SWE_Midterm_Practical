#pragma once
#include <vector>
#include <string>
class Question
{
private:
	std::string question;
	std::string correctAnswer;
	std::string option1;
	std::string option2;
	std::string option3;
	std::vector<std::string> options;
	std::vector<std::string> shuffledOptions;
	void ShuffleAnswers();
	bool CheckAnswer(int answer);
public:
	Question(std::string _question, std::string _correctAswer, std::string _option1, std::string _option2, std::string _option3);

	bool DisplayQuestion();


};

