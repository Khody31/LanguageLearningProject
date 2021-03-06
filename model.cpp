#include <fstream>
#include <iostream>

#include "model.h"

std::string DifficultyToString(Difficulty comp) {
  if (comp == Difficulty::kIntermediate) {
    return "intermediate";
  }
  if (comp == Difficulty::kElementary) {
    return "elementary";
  }
  if (comp == Difficulty::kAdvanced) {
    return "advanced";
  }
  return "unknown";
}

std::string LanguageToString(Language language) {
  if (language == Language::kRussian) {
    return "russian";
  }
  if (language == Language::kFrench) {
    return "french";
  }
  if (language == Language::kGerman) {
    return "german";
  }
  if (language == Language::kEnglish) {
    return "english";
  }
  return "unknown";
}

Language StringToLanguage(const std::string& str) {
  if (str == "russian") {
    return Language::kRussian;
  }
  if (str == "french") {
    return Language::kFrench;
  }
  if (str == "german") {
    return Language::kGerman;
  }
  if (str == "english") {
    return Language::kEnglish;
  }
  return Language::kUnknown;
}


QList<GrammarExercise> Model::GetGrammarExercise() const {
  QList<GrammarExercise> result;

  std::string input_path = "data/" + DifficultyToString(difficulty_) + "_grammar.txt";
  std::ifstream input(input_path);
  int cnt;
  input >> cnt;
  static std::string temp_string;
  static QString question_;
  static Rule rule;
  static QString right_answer;
  static QList<QString> possible_answers;
  getline(input, temp_string);
  for (int i = 0; i < cnt; i++) {
    getline(input, temp_string);
    rule = Exercise::StringToRule(temp_string);
    getline(input, temp_string);
    question_ = QString(temp_string.data());
    getline(input, temp_string);
    right_answer = QString(temp_string.data());
    possible_answers.clear();
    for (int j = 0; j < 4; j++) {
      getline(input, temp_string);
      possible_answers.push_back(
          QString(temp_string.data())
      );
    }
    result.push_back(GrammarExercise(
      question_, right_answer, possible_answers, rule
    ));
  }

  return result;
}

QList<TranslationExercise> Model::GetTranslationExercise() const {
  QList<TranslationExercise> result;
  std::string input_path = "data/" + DifficultyToString(difficulty_) + "_translation.txt";
  std::ifstream input(input_path);
  int cnt;
  input >> cnt;
  static std::string temp_string;
  static Rule rule;
  static QString question_;
  static QString right_answer;
  getline(input, temp_string);
  for (int i = 0; i < cnt; i++) {
    getline(input, temp_string);
    rule = Exercise::StringToRule(temp_string);
    for (int j = 0; j < 4; j++) {
      getline(input, temp_string);
      if (StringToLanguage(temp_string) == language_) {
        getline(input, temp_string);
        question_ = QString(temp_string.data());
      } else {
        getline(input, temp_string);
      }
    }
    getline(input, temp_string);
    right_answer = QString(temp_string.data());
    result.push_back(TranslationExercise(
        question_, right_answer, rule
    ));
  }

  return result;
}

Model::Model() {
  std::ifstream hints_input("data/hints.txt");
  int cnt;
  hints_input >> cnt;
  std::string str;
  getline(hints_input, str);
  for (int i = 0; i < cnt; i++) {
    getline(hints_input, str);
    Rule rule = Exercise::StringToRule(str);
    getline(hints_input, str);
    hints_[rule] = QString(str.data());
  }

  ReadRecords();
}
const QString& Model::GetHint(Rule rule) {
  return hints_.at(rule);
}

void Model::ReadRecords() {
  std::ifstream records_input("data/records.txt");
  int translation, grammar;

  records_input >> translation >> grammar;
  records_.AddRecord(Difficulty::kElementary, translation, grammar);
  records_input >> translation >> grammar;
  records_.AddRecord(Difficulty::kIntermediate, translation, grammar);
  records_input >> translation >> grammar;
  records_.AddRecord(Difficulty::kAdvanced, translation, grammar);
}

void Model::WriteRecords() {
  std::ofstream records_output("data/records.txt");
  Record record;
  record = records_.GetRecord(Difficulty::kElementary);
  records_output << " " << record.translation << " " << record.grammar;
  record = records_.GetRecord(Difficulty::kIntermediate);
  records_output << " " << record.translation << " " << record.grammar;
  record = records_.GetRecord(Difficulty::kAdvanced);
  records_output << " " << record.translation << " " << record.grammar;
}

Model::~Model() {
  WriteRecords();
}

void Model::UpdateTranslationRecord(int score) {
  records_.UpdateTranslationRecord(difficulty_, score);
}

void Model::UpdateGrammarRecord(int score) {
  records_.UpdateGrammarRecord(difficulty_, score);
}

const Record& Model::GetRecord() const {
  return records_.GetRecord(difficulty_);
}

void Model::SetLanguage(Language language) {
  language_ = language;
}

Language Model::GetLanguage() const {
  return language_;
}
