#pragma once

#include "enums.h"

#include <map>

struct Record {
  int translation = 0;
  int grammar = 0;
};

class UserRecords {
 public:
  UserRecords() = default;

  const Record& GetRecord(Difficulty dif) const;
  void UpdateTranslationRecord(Difficulty dif, int score);
  void UpdateGrammarRecord(Difficulty dif, int score);
  void UpdateRecord(Difficulty dif, Record rec);
  void AddRecord(Difficulty dif, int translation_score = 0, int grammar_score = 0);
 private:
  std::map<Difficulty, Record> data_;
};
