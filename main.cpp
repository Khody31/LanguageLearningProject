#include <QApplication>
#include <QPushButton>

#include "main_window.h"
#include "main_menu.h"
#include "grammar_exercise_widget.h"
#include "result_widget.h"
#include "records_widget.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QApplication::setStyle("Breeze");
  QApplication::setFont(QFont("Arial", 18));

  MainWindow application;
  application.setFocus();
  application.show();

  // RecordsWidget records;
  // records.UpdateRecord({1, 1});
  // records.show();

  // MainMenu menu;
  // menu.show();

  // ResultWidget result;
  // result.show();

  // GrammarExerciseWidget widget;
  // widget.show();

  return QApplication::exec();
}
