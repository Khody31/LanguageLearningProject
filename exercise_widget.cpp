#include "exercise_widget.h"

const Statistics& ExerciseWidget::GetStats() const {
  return stats_;
}

ExerciseWidget::ExerciseWidget(QWidget* parent) :
    QWidget(parent),
    main_layout_(new QVBoxLayout),
    title_(new QLabel(this)),
    text_(new QLabel(this)),
    score_label_(new QLabel("Score: 0", this)),
    submit_button_(new QPushButton("Submit", this)),
    progress_bar_(new QProgressBar(this)),
    timer_(new QTimer(this)),
    player_(new QMediaPlayer(this)) {
  player_->setVolume(100);
  player_->setMedia(QUrl::fromLocalFile(
      "/home/egoruskha/Downloads/all-every-iphone-system-and-ui-s.mp3"));

  progress_bar_->setTextVisible(false);

  main_layout_->addWidget(score_label_);

  connect(
      timer_,
      &::QTimer::timeout,
      this,
      &::ExerciseWidget::DecreaseScore
  );
}

void ExerciseWidget::DecreaseScore() {
  cur_score_ = std::max(0, cur_score_ - 10);
  if (cur_score_ == 0) {
    Submit();
  }
}

void ExerciseWidget::UpdateScore() {
  score_label_->setText(
      tr("Score: ") + QString::number(stats_.GetScore()));
}


