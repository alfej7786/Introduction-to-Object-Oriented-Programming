#ifndef SDDS_QUIZ_H
#define SDDS_QUIZ_H

namespace quizzer {
int LoadQuiz(const char* filename);
int IsQuizValid();
int HasMoreQuestions();
void ShowNextQuestion();
void ShowNextQuestion();
int ShowQuizResults();
}

#endif