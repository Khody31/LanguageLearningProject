#pragma once

#include "grammar_exercise.h"
#include "statistics.h"
#include "exercise_widget.h"

#include <QMainWindow>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QProgressBar>
#include <QTimer>

class GrammarExerciseWidget : public ExerciseWidget {
 Q_OBJECT
 public:
  explicit GrammarExerciseWidget(QWidget* parent = nullptr);
  ~GrammarExerciseWidget() override = default;

  void Start(QList<GrammarExercise> exercises);
  void Submit() override;

  Rule GetCurrentQuestionsRule() override;
  void resizeEvent(QResizeEvent* event) override;
 private:
  void NextExercise();

 private:
  QButtonGroup* possible_answers_;
  QRadioButton* answer_a;
  QRadioButton* answer_b;
  QRadioButton* answer_c;
  QRadioButton* answer_d;

 private:
  QList<GrammarExercise> exercises_;
  int next_exercise_num_ = 0;
};
