#include "records_widget.h"
RecordsWidget::RecordsWidget(QWidget* parent) :
  QWidget(parent),
  layout_(new QGridLayout()),
  translation_record_text_(new QLabel("TranslationRecord: ", this)),
  translation_record_num_(new QLabel(this)),
  grammar_record_text_(new QLabel("GrammarRecord: ", this)),
  grammar_record_num_(new QLabel(this)),
  button_(new QPushButton("Ok", this)) {
  layout_->addWidget(translation_record_text_, 0, 0);
  layout_->addWidget(translation_record_num_, 0, 1);
  layout_->addWidget(grammar_record_text_, 1, 0);
  layout_->addWidget(grammar_record_num_, 1, 1);
  layout_->addWidget(button_, 2, 0, 2, Qt::AlignCenter);

  setMinimumSize(400, 450);
}

void RecordsWidget::resizeEvent(QResizeEvent* event) {
  layout_->setGeometry(QRect(25, 25, width() - 50, height() - 100));
}

void RecordsWidget::UpdateRecord(const Record& record) {
  translation_record_num_->setText(QString::number(record.translation));
  grammar_record_num_->setText(QString::number(record.grammar));
}
QPushButton* RecordsWidget::GetButton() {
  return button_;
}
