#include "Question.h"
#include <string.h>
#include <iostream>
#include "Helper.h"

Question::Question(std::string _question, std::string _correctAnswer, std::string _option1, std::string _option2, std::string _option3) {
	question = _question;
	option1 = _option1;
	option2 = _option2;
	option3 = _option3;
	correctAnswer = _correctAnswer;

	options.push_back(correctAnswer);
	options.push_back(option1);
	options.push_back(option2);
	options.push_back(option3);

	ShuffleAnswers();

}

bool Question::DisplayQuestion() {
	std::cout << question << '\n';
	for (int i = 1; i < 5; ++i) {
		std::cout << i << ". " << shuffledOptions[i - 1] << '\n';
	}
	return CheckAnswer(Helper::GetValidatedInt("Choice? ", 1, (int)shuffledOptions.size()));
}

void Question::ShuffleAnswers() {
	int index;
	int num = 4;
	srand((unsigned int)time(NULL));
	while (options.size() > 0) {
		index = rand() % num--;
		auto iter = options.begin();
		for (int i = 0; i < index; ++i)
			++iter;
		shuffledOptions.push_back(*iter);
		iter = options.erase(iter);
	}
}

bool Question::CheckAnswer(int answer) {
	if (shuffledOptions[answer-1] == correctAnswer) {
		std::cout << "Correct!" << '\n';
		return true;
	}
	else {
		std::cout << "Incorrect!" << '\n';
		return false;
	}
}