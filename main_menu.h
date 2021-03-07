#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QMenuBar>

#include "enums.h"

class MainMenu : public QWidget {
  Q_OBJECT
 public:
  explicit MainMenu(QWidget* parent = nullptr);

  void resizeEvent(QResizeEvent* ev) override;

  QPushButton* GetTranslationButton() const;
  QPushButton* GetGrammarButton() const;
  QPushButton* GetStatsButton() const;

  void UpdateLabel(Language language);

  friend class MainWindow;
 private:
  QVBoxLayout* layout_;
  QLabel* label_;
  QPushButton* translation_button_;
  QPushButton* grammar_button_;
  QPushButton* records_button_;
  QMenuBar* menu_bar_;
  QMenu* difficulty_menu_;
  QMenu* mother_tongue_menu_;
  QAction* elementary_action_;
  QAction* intermediate_action_;
  QAction* advanced_action_;
  QActionGroup* difficulty_group_;
  QAction* russian_action_;
  QAction* french_action_;
  QAction* german_action_;
  QAction* english_action_;
  QActionGroup* mother_tongue_group_;
};
// some comment
