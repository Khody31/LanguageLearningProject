//
// Created by egoruskha on 28.02.21 г..
//
#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QResizeEvent>

#include "statistics.h"

class ResultWidget : public QWidget {
Q_OBJECT
 public:
  explicit ResultWidget(QWidget* parent = nullptr);
  ~ResultWidget() override = default;

  void resizeEvent(QResizeEvent *event) override;
  void UpdateText(const Statistics& stats);
  QPushButton* GetButton();
 private:
  QVBoxLayout* layout_;
  QPushButton* button_;
  QLabel* label_;
};
