#pragma once

#include <QWidget>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>

#include "statistics.h"
#include "exercise.h"

class ExerciseWidget : public QWidget {
 Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent);
  ~ExerciseWidget() override = default;

  virtual Rule GetCurrentQuestionsRule() = 0;

  void DecreaseScore();
  virtual void Submit() = 0;

  const Statistics& GetStats() const;
 signals:
  void OnEnd();
 protected:
  void UpdateScore();

  Statistics stats_;
  int cur_score_ = 100;

 protected:
  QVBoxLayout* main_layout_;
  QLabel* title_;
  QLabel* text_;
  QLabel* score_label_;
  QPushButton* submit_button_;
  QProgressBar* progress_bar_;
  QTimer* timer_;
  QMediaPlayer* player_;
};
