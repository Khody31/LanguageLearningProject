#pragma once

#include "exercise_widget.h"
#include "translation_exercise.h"

#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QList>
#include <QProgressBar>

class TranslationExerciseWidget : public ExerciseWidget {
 public :
  explicit TranslationExerciseWidget(QWidget* parent = nullptr);

  Rule GetCurrentQuestionsRule() override;
  void Start(QList<TranslationExercise> exercises);
  void Submit() override;

  void resizeEvent(QResizeEvent* event) override;

 private:
  void NextExercise();

 private:
  QTextEdit* text_edit_;
  QList<TranslationExercise> exercises_;
  int cur_exercise_ = -1;
};
