#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class HelpWidget : public QWidget {
 Q_OBJECT
 public:
  explicit HelpWidget(QWidget* parent);
  ~HelpWidget() override = default;

  QPushButton* GetButton();
  void SetHint(const QString& text);
  void resizeEvent(QResizeEvent* event) override;
 private:
  QVBoxLayout* layout_;
  QLabel* hint_;
  QPushButton* button_;
  QPushButton* some_another_button_; 
};
