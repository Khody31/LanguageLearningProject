#pragma once

#include "exercise.h"

class TranslationExercise : public Exercise {
 public:
  TranslationExercise(QString text, QString right_answer, Rule rule);

  bool CheckAnswer(const QString &answer) const override;
};
