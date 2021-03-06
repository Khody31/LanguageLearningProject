#include "user_records.h"
const Record& UserRecords::GetRecord(Difficulty dif) const {
  return data_.at(dif);
}

void UserRecords::UpdateTranslationRecord(Difficulty dif, int score) {
  data_.at(dif).translation = std::max(data_.at(dif).translation, score);
}

void UserRecords::UpdateGrammarRecord(Difficulty dif, int score) {
  data_.at(dif).grammar = std::max(data_.at(dif).translation, score);
}

void UserRecords::UpdateRecord(Difficulty dif, Record rec) {
  data_.at(dif) = rec;
}

void UserRecords::AddRecord(
    Difficulty dif,
    int translation_score,
    int grammar_score) {
  data_[dif] = {translation_score, grammar_score};
}

