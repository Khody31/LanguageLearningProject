#include "main_menu.h"


MainMenu::MainMenu(QWidget* parent) :
    QWidget(parent),
    layout_(new QVBoxLayout()),
    label_(new QLabel("Bonjour", this)),
    translation_button_(new QPushButton("Translation", this)),
    grammar_button_(new QPushButton("Grammar", this)),
    records_button_(new QPushButton("Stats", this)),
    menu_bar_(new QMenuBar(this)),
    difficulty_menu_(menu_bar_->addMenu("Proficiency")),
    mother_tongue_menu_(menu_bar_->addMenu("Mother tongue")),
    elementary_action_(new QAction("Elementary")),
    intermediate_action_(new QAction("Intermediate")),
    advanced_action_(new QAction("Advanced")),
    difficulty_group_(new QActionGroup(this)),
    russian_action_(new QAction("Русский")),
    french_action_(new QAction("French")),
    german_action_(new QAction("Deutsch")),
    english_action_(new QAction("English")),
    mother_tongue_group_(new QActionGroup(this)) {
  menu_bar_->setFont(QFont("Arial", 12));

  difficulty_menu_->addAction(elementary_action_);
  difficulty_menu_->addAction(intermediate_action_);
  difficulty_menu_->addAction(advanced_action_);

  elementary_action_->setCheckable(true);
  intermediate_action_->setCheckable(true);
  advanced_action_->setCheckable(true);

  difficulty_group_->addAction(elementary_action_);
  difficulty_group_->addAction(intermediate_action_);
  difficulty_group_->addAction(advanced_action_);

  elementary_action_->setChecked(true);

  difficulty_menu_->setFont(QFont("Arial", 12));
  //difficulty_menu_->setStyleSheet("background-color: blue");

  mother_tongue_menu_->addAction(russian_action_);
  mother_tongue_menu_->addAction(french_action_);
  mother_tongue_menu_->addAction(german_action_);
  mother_tongue_menu_->addAction(english_action_);

  russian_action_->setCheckable(true);
  french_action_->setCheckable(true);
  german_action_->setCheckable(true);
  english_action_->setCheckable(true);

  russian_action_->setChecked(true);

  mother_tongue_group_->addAction(russian_action_);
  mother_tongue_group_->addAction(french_action_);
  mother_tongue_group_->addAction(german_action_);
  mother_tongue_group_->addAction(english_action_);

  mother_tongue_menu_->setFont(QFont("Arial", 12));

  layout_->addWidget(label_, 5, Qt::AlignCenter);
  layout_->addStretch(1);
  layout_->addWidget(translation_button_, 10);
  layout_->addStretch(1);
  layout_->addWidget(grammar_button_, 10);
  layout_->addStretch(1);
  layout_->addWidget(records_button_, 10);

  QSizePolicy size_policy(QSizePolicy::Expanding,
                          QSizePolicy::Expanding);
  label_->setSizePolicy(size_policy);
  translation_button_->setSizePolicy(size_policy);
  grammar_button_->setSizePolicy(size_policy);
  records_button_->setSizePolicy(size_policy);

  translation_button_->setStyleSheet("background-color: blue");
  grammar_button_->setStyleSheet("background-color: rgb(0, 125, 150)");

  setMinimumSize(400, 450);
}

void MainMenu::resizeEvent(QResizeEvent* ev) {
  QWidget::resizeEvent(ev);
  int from_top = 100;
  int from_left = 75;

  layout_->setGeometry(QRect(from_left,
                             from_top,
                             width() - 2 * from_left,
                             height() - 2 * from_top)
  );

}

QPushButton* MainMenu::GetTranslationButton() const {
  return translation_button_;
}

QPushButton* MainMenu::GetGrammarButton() const {
  return grammar_button_;
}

QPushButton* MainMenu::GetStatsButton() const {
  return records_button_;
}

void MainMenu::UpdateLabel(Language language) {
  if (language == Language::kRussian) {
    label_->setText("Привет!");
  } else if (language == Language::kEnglish) {
    label_->setText("Hello!");
  } else if (language == Language::kGerman) {
    label_->setText("Hallo!");
  } else {
    label_->setText("Bonjour!");
  }
}
