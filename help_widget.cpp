#include "help_widget.h"

HelpWidget::HelpWidget(QWidget* parent) :
    QWidget(parent),
    layout_(new QVBoxLayout()),
    hint_(new QLabel(this)),
    button_(new QPushButton("OK!", this)) {
  layout_->addWidget(hint_);
  layout_->addWidget(button_);

  hint_->setWordWrap(true);
  setMinimumSize(400, 450);
}

QPushButton* HelpWidget::GetButton() {
  return button_;
}

void HelpWidget::SetHint(const QString& text) {
  hint_->setText(text);
}

void HelpWidget::resizeEvent(QResizeEvent* event) {
  layout_->setGeometry(QRect(50,
                             50,
                             width() - 100,
                             height() - 100));
}
