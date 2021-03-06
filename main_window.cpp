#include "main_window.h"


#include <iostream>

MainWindow::MainWindow(QWidget* parent) :
    QWidget(parent),
    layout_(new QHBoxLayout()),
    left_widget_(new QStackedWidget(this)),
    right_widget_(new QStackedWidget(this)),
    menu_widget_(new MainMenu(this)),
    translation_widget_(new TranslationExerciseWidget(this)),
    grammar_widget_(new GrammarExerciseWidget(this)),
    result_widget_(new ResultWidget(this)),
    help_widget_(new HelpWidget(this)),
    records_widget_(new RecordsWidget(this)) {
  QSizePolicy size_policy(QSizePolicy::Expanding,
                          QSizePolicy::Expanding);

  menu_widget_->setSizePolicy(size_policy);
  grammar_widget_->setSizePolicy(size_policy);
  result_widget_->setSizePolicy(size_policy);
  records_widget_->setSizePolicy(size_policy);

  left_widget_->addWidget(menu_widget_);
  left_widget_->addWidget(help_widget_);
  left_widget_->addWidget(records_widget_);

  right_widget_->addWidget(grammar_widget_);
  right_widget_->addWidget(translation_widget_);
  right_widget_->addWidget(result_widget_);

  layout_->addWidget(left_widget_);
  right_widget_->hide();

  right_widget_->setStyleSheet("background-color: rgb(225, 225, 225)");

  connect(
      menu_widget_->GetGrammarButton(),
      &::QPushButton::clicked,
      this,
      &::MainWindow::LoadGrammarExercise
  );

  connect(
      menu_widget_->GetTranslationButton(),
      &::QPushButton::clicked,
      this,
      &::MainWindow::LoadTranslationExercise
  );

  connect(
      grammar_widget_,
      &GrammarExerciseWidget::OnEnd,
      this,
      &::MainWindow::LoadResult
  );

  connect(
      translation_widget_,
      &TranslationExerciseWidget::OnEnd,
      this,
      &::MainWindow::LoadResult
  );

  connect(
      result_widget_->GetButton(),
      &::QPushButton::clicked,
      this,
      &::MainWindow::TurnOffRightWidget
  );

  connect(
      help_widget_->GetButton(),
      &::QPushButton::clicked,
      this,
      &::MainWindow::LoadMenu
  );

  connect(
      menu_widget_->GetStatsButton(),
      &::QPushButton::clicked,
      this,
      &::MainWindow::LoadRecords
  );

  connect(
      records_widget_->GetButton(),
      &::QPushButton::clicked,
      this,
      &::MainWindow::LoadMenu
  );

  connect(
      menu_widget_->elementary_action_,
      &::QAction::triggered,
      this,
      &::MainWindow::SetElementary
  );

  connect(
      menu_widget_->intermediate_action_,
      &::QAction::triggered,
      this,
      &::MainWindow::SetIntermediate
  );

  connect(
      menu_widget_->advanced_action_,
      &::QAction::triggered,
      this,
      &::MainWindow::SetAdvanced
  );

  connect(
      menu_widget_->russian_action_,
      &::QAction::triggered,
      this,
      &::MainWindow::SetRussian
      );

  connect(
      menu_widget_->german_action_,
      &::QAction::triggered,
      this,
      &::MainWindow::SetGerman
  );

  connect(
      menu_widget_->french_action_,
      &::QAction::triggered,
      this,
      &::MainWindow::SetFrench
  );

  connect(
      menu_widget_->english_action_,
      &::QAction::triggered,
      this,
      &::MainWindow::SetEnglish
  );

  layout_->setGeometry(QRect(0, 0, 400, 450));
  setMinimumSize(400, 450);

  LoadMenu();
}

void MainWindow::LoadGrammarExercise() {
  TurnOnRightWidget();

  grammar_widget_->Start(model_.GetGrammarExercise());
  right_widget_->setCurrentWidget(grammar_widget_);
}

void MainWindow::LoadTranslationExercise() {
  TurnOnRightWidget();

  translation_widget_->Start(model_.GetTranslationExercise());
  right_widget_->setCurrentWidget(translation_widget_);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  layout_->setGeometry(QRect(0, 0, width(), height()));
}

void MainWindow::LoadResult() {
  auto cur_widget =
      dynamic_cast<ExerciseWidget*>(
          right_widget_->currentWidget());
  result_widget_->UpdateText(cur_widget->GetStats());
  right_widget_->setCurrentWidget(result_widget_);

  auto copy = dynamic_cast<GrammarExerciseWidget*>(cur_widget);
  if (copy != nullptr) {
    model_.UpdateGrammarRecord(copy->GetStats().GetScore());
  } else {
    model_.UpdateTranslationRecord(cur_widget->GetStats().GetScore());
  }
}

void MainWindow::TurnOnRightWidget() {
  if (layout_->count() > 1) {
    return;
  }

  right_widget_->show();
  layout_->addWidget(right_widget_);
  setGeometry(QRect(x(), y(), width() * 2, height()));
  setMinimumSize(800, 450);
}

void MainWindow::TurnOffRightWidget() {
  if (layout_->count() < 2) {
    return;
  }

  layout_->removeWidget(right_widget_);
  right_widget_->hide();
  setMinimumSize(400, 450);
  setGeometry(QRect(x(), y(), width() / 2, height()));
}

void MainWindow::LoadHelp() {
  auto exercise = dynamic_cast<ExerciseWidget*>(
      right_widget_->currentWidget());
  if (exercise == nullptr) {
    return;
  }

  help_widget_->SetHint(
      model_.GetHint(exercise->GetCurrentQuestionsRule())
  );
  left_widget_->setCurrentWidget(help_widget_);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_H) {
    if (layout_->count() == 1) {
      return;
    }
    LoadHelp();
    return;
  }

  if (event->key() == Qt::Key_Return) {
    auto cur_widget = dynamic_cast<ExerciseWidget*>(
        right_widget_->currentWidget());
    if (cur_widget == nullptr) {
      return;
    }
    cur_widget->Submit();
  }
}

void MainWindow::LoadMenu() {
  menu_widget_->UpdateLabel(model_.GetLanguage());
  left_widget_->setCurrentWidget(menu_widget_);
}

void MainWindow::LoadRecords() {
  records_widget_->UpdateRecord(model_.GetRecord());
  left_widget_->setCurrentWidget(records_widget_);
}

void MainWindow::SetElementary() {
  model_.SetDifficulty(Difficulty::kElementary);
}

void MainWindow::SetIntermediate() {
  model_.SetDifficulty(Difficulty::kIntermediate);
}

void MainWindow::SetAdvanced() {
  model_.SetDifficulty(Difficulty::kAdvanced);
}

void MainWindow::SetRussian() {
  model_.SetLanguage(Language::kRussian);
  LoadMenu();
}

void MainWindow::SetGerman() {
  model_.SetLanguage(Language::kGerman);
  LoadMenu();
}

void MainWindow::SetFrench() {
  model_.SetLanguage(Language::kFrench);
  LoadMenu();
}

void MainWindow::SetEnglish() {
  model_.SetLanguage(Language::kEnglish);
  LoadMenu();
}
