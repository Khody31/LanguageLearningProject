//
// Created by egoruskha on 28.02.21 г..
//

#include "result_widget.h"

ResultWidget::ResultWidget(QWidget* parent) :
  QWidget(parent),
  layout_(new QVBoxLayout()),
  button_(new QPushButton("OK", this)),
  label_(new QLabel(this)) {
  layout_->addWidget(label_);
  layout_->addWidget(button_);

  layout_->setGeometry(QRect(0, 0, 400, 450));
  setMinimumSize(400, 450);
}

void ResultWidget::resizeEvent(QResizeEvent* event) {
  layout_->setGeometry(QRect(50,
                             50,
                             width() - 100,
                             height() - 100));
  QWidget::resizeEvent(event);
}

void ResultWidget::UpdateText(const Statistics& stats) {
  label_->setText(tr("Your result: \n") + QString::number(stats.GetRight()) +
                  tr(" right answers from ") + QString::number(stats.GetTotal()) +
                  tr("\nScore: ") + QString::number(stats.GetScore()));

}

QPushButton* ResultWidget::GetButton() {
  return button_;
}
