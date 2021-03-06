#include "grammar_exercise_widget.h"
#include <QMessageBox>

#include <iostream>

GrammarExerciseWidget::GrammarExerciseWidget(
    QWidget* parent
) : ExerciseWidget(parent),
   possible_answers_(new QButtonGroup(this)),
    answer_a(new QRadioButton(" ", this)),
    answer_b(new QRadioButton(" ", this)),
    answer_c(new QRadioButton(" ", this)),
    answer_d(new QRadioButton(" ", this)) {
  title_->setText("Chose the right answer");

  possible_answers_->addButton(answer_a);
  possible_answers_->addButton(answer_b);
  possible_answers_->addButton(answer_c);
  possible_answers_->addButton(answer_d);

  text_->setWordWrap(true);
  submit_button_->setStyleSheet("background-color: rgb(0, 125, 150)");
  submit_button_->setMinimumSize(90, 40);
  progress_bar_->setStyleSheet(
      "QProgressBar::chunk {   background-color: rgb(0, 125, 150)}");

  main_layout_->addWidget(title_, 4, Qt::AlignCenter);
  main_layout_->addWidget(text_, 4);
  main_layout_->addWidget(answer_a, 1);
  main_layout_->addWidget(answer_b, 1);
  main_layout_->addWidget(answer_c, 1);
  main_layout_->addWidget(answer_d, 1);
  main_layout_->addWidget(submit_button_, 4, Qt::AlignCenter);
  main_layout_->addWidget(progress_bar_);

  setMinimumSize(400, 450);

  QFont title_font("Arial", 20);
  title_->setFont(title_font);

  QFont text_font("Arial", 16);
  text_->setFont(text_font);

  answer_a->setFont(text_font);
  answer_b->setFont(text_font);
  answer_c->setFont(text_font);
  answer_d->setFont(text_font);

  QSizePolicy size_policy(QSizePolicy::Expanding,
                          QSizePolicy::Expanding);
  text_->setSizePolicy(size_policy);

  connect(submit_button_,
          &::QPushButton::clicked,
          this,
          &::GrammarExerciseWidget::Submit
  );
}

void GrammarExerciseWidget::NextExercise() {
  const GrammarExercise& cur = exercises_.at(next_exercise_num_++);
  text_->setText(cur.GetText());

  cur_score_ = 100;
  timer_->start(1000);

  const QList<QString>& possible_answers = cur.GetPossibleAnswers();
  answer_a->setText(possible_answers.at(0));
  answer_b->setText(possible_answers.at(1));
  answer_c->setText(possible_answers.at(2));
  answer_d->setText(possible_answers.at(3));

  auto checked_button = possible_answers_->checkedButton();
  if (checked_button != nullptr) {
    checked_button->setChecked(false);
  }
}

void GrammarExerciseWidget::Submit() {
  auto answer = dynamic_cast<QRadioButton*>(
      possible_answers_->checkedButton()
  );
  if (answer == nullptr) {
    return;
  }

  timer_->stop();

  player_->play();

  const GrammarExercise& cur_exercise =
      exercises_.at(next_exercise_num_ - 1);

  if (cur_exercise.CheckAnswer(answer->text())) {
    stats_.IncRight();
    stats_.IncScore(cur_score_);
  } else {
    // QMessageBox::information(this, "you're wrong",
    //                          QString("Right answer is ") + cur_exercise.GetRightAnswer());
    player_->play();
    stats_.IncWrong();
  }

  if (stats_.GetWrong() > 2) {
    OnEnd();
  }

  UpdateScore();

  if (next_exercise_num_ == exercises_.size()) {
    OnEnd();
    return;
  }

  progress_bar_->setValue(next_exercise_num_);
  NextExercise();
}

void GrammarExerciseWidget::Start(QList<GrammarExercise> exercises) {
  exercises_ = std::move(exercises);
  next_exercise_num_ = 0;
  stats_.Clear();
  progress_bar_->setMaximum(exercises_.size());
  progress_bar_->setValue(0);
  NextExercise();
}

Rule GrammarExerciseWidget::GetCurrentQuestionsRule() {
  return exercises_.at(next_exercise_num_ - 1).GetRule();
}

void GrammarExerciseWidget::resizeEvent(QResizeEvent* event) {
  main_layout_->setGeometry(QRect(
      50,
      50,
      width() - 100,
      height() - 100
  ));
}


