#pragma once

#include "exercise.h"

#include <QList>

class GrammarExercise : public Exercise {
 public:
  GrammarExercise() = default;
  GrammarExercise(QString text,
                  QString right_answer,
                  QList<QString> possible_answers,
                  Rule rule);
  ~GrammarExercise() override = default;

  const QList<QString>& GetPossibleAnswers() const;

  bool CheckAnswer(const QString& answer) const override;
 private:
  QList<QString> possible_answers_;
};
