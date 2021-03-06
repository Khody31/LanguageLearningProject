#pragma once

#include "main_menu.h"
#include "grammar_exercise_widget.h"
#include "translation_exercise_widget.h"
#include "result_widget.h"
#include "model.h"
#include "help_widget.h"
#include "records_widget.h"

#include <QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QMenuBar>

class MainWindow : public QWidget {
 Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);

  void TurnOnRightWidget();
  void TurnOffRightWidget();

  void LoadGrammarExercise();
  void LoadTranslationExercise();
  void LoadResult();
  void LoadHelp();
  void LoadMenu();
  void LoadRecords();

  void SetElementary();
  void SetIntermediate();
  void SetAdvanced();

  void SetRussian();
  void SetGerman();
  void SetFrench();
  void SetEnglish();

  void resizeEvent(QResizeEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;
 private:
  QHBoxLayout* layout_;
  QStackedWidget* left_widget_;
  QStackedWidget* right_widget_;
  MainMenu* menu_widget_;
  GrammarExerciseWidget* grammar_widget_;
  TranslationExerciseWidget* translation_widget_;
  ResultWidget* result_widget_;
  HelpWidget* help_widget_;
  RecordsWidget* records_widget_;
  Model model_;
};
