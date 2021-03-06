#include "grammar_exercise.h"
GrammarExercise::GrammarExercise(
    QString text,
    QString right_answer,
    QList<QString> possible_answers,
    Rule rule) :
    Exercise(std::move(text),
             std::move(right_answer),
             rule),
    possible_answers_(std::move(possible_answers)) {}

bool GrammarExercise::CheckAnswer(const QString& answer) const {
  return answer == right_answer_;
}

const QList<QString>& GrammarExercise::GetPossibleAnswers() const {
  return possible_answers_;
}

