#include "translation_exercise_widget.h"

TranslationExerciseWidget::TranslationExerciseWidget(
    QWidget* parent) : ExerciseWidget(parent),
                       text_edit_(new QTextEdit(this)) {
  main_layout_->addWidget(title_, 2);
  main_layout_->addWidget(text_, 2);
  main_layout_->addWidget(text_edit_, 3);
  main_layout_->addWidget(submit_button_, 2, Qt::AlignCenter);
  main_layout_->addStretch(0);
  main_layout_->addWidget(progress_bar_, 1);

  text_->setWordWrap(true);
  submit_button_->setMinimumSize(90, 40);
  submit_button_->setStyleSheet("background-color: blue");
  progress_bar_->setStyleSheet("QProgressBar::chunk {   background-color: rgb(100, 100, 255)}");

  connect(
      submit_button_,
      &::QPushButton::clicked,
      this,
      &::TranslationExerciseWidget::Submit
  );

  progress_bar_->setTextVisible(false);
  setMinimumSize(400, 450);
}

void TranslationExerciseWidget::Start(
    QList<TranslationExercise> exercises) {
  exercises_ = std::move(exercises);
  cur_exercise_ = -1;
  stats_.Clear();
  progress_bar_->setMaximum(exercises_.size());
  progress_bar_->setValue(0);
  NextExercise();
}

void TranslationExerciseWidget::Submit() {
  QString text = text_edit_->toPlainText();
  text_edit_->setText("");
  if (exercises_.at(cur_exercise_).CheckAnswer(text)) {
    stats_.IncRight();
    stats_.IncScore(cur_score_);
  } else {
    stats_.IncWrong();
    player_->play();
  }

  UpdateScore();

  timer_->stop();

  progress_bar_->setValue(cur_exercise_ + 1);
  if (cur_exercise_ + 1 == exercises_.size()) {
    OnEnd();
    return;
  }
  NextExercise();
}

void TranslationExerciseWidget::NextExercise() {
  timer_->start(1000);
  cur_exercise_++;
  cur_score_ = 300;
  text_->setText(exercises_.at(cur_exercise_).GetText());
}


Rule TranslationExerciseWidget::GetCurrentQuestionsRule() {
  return exercises_.at(cur_exercise_).GetRule();
}

void TranslationExerciseWidget::resizeEvent(QResizeEvent* event) {
  main_layout_->setGeometry(QRect(
      50,
      50,
      width() - 100,
      height() - 100
  ));
}