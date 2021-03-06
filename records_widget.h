#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

#include "user_records.h"

class RecordsWidget : public QWidget {
 Q_OBJECT
 public:
  explicit RecordsWidget(QWidget* parent = nullptr);

  void UpdateRecord(const Record& record);

  QPushButton* GetButton();
  void resizeEvent(QResizeEvent *event) override;
 private:
  QGridLayout* layout_;
  QLabel* translation_record_text_;
  QLabel* translation_record_num_;
  QLabel* grammar_record_text_;
  QLabel* grammar_record_num_;
  QPushButton* button_;
};
