//
// Created by egoruskha on 23.02.21 г..
//

#include "translation_exercise.h"
TranslationExercise::TranslationExercise(
    QString text,
    QString right_answer,
    Rule rule)
    : Exercise(
    std::move(text),
    std::move(right_answer),
    rule) {}

bool TranslationExercise::CheckAnswer(const QString& answer) const {
    // TODO coolest algorithm
    return answer == right_answer_;
}
