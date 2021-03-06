#pragma once

#include <QList>
#include <QString>
#include <map>

#include "grammar_exercise.h"
#include "translation_exercise.h"
#include "enums.h"
#include "user_records.h"

class Model {
 public:
  Model();
  ~Model();
  QList<GrammarExercise> GetGrammarExercise() const;
  QList<TranslationExercise> GetTranslationExercise() const;

  void SetDifficulty(Difficulty dif) {
    difficulty_ = dif;
  }

  void SetLanguage(Language language);
  Language GetLanguage() const;
  const QString& GetHint(Rule rule);
  void UpdateTranslationRecord(int score);
  void UpdateGrammarRecord(int score);
  const Record& GetRecord() const;

 private:
  void ReadRecords();
  void WriteRecords();

  std::map<Rule, QString> hints_;
  UserRecords records_;
  Difficulty difficulty_ = Difficulty::kElementary;
  Language language_ = Language::kRussian;
};
