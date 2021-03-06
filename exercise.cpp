#include "exercise.h"

Exercise::Exercise(
    QString text,
    QString right_answer,
    Rule rule) :
    text_(std::move(text)),
    right_answer_(std::move(right_answer)),
    rule_(rule) {}

const QString& Exercise::GetText() const {
  return text_;
}
const QString& Exercise::GetRightAnswer() const {
  return right_answer_;
}

Rule Exercise::StringToRule(const std::string& str) {
  if (str == "past_habits") {
    return Rule::kPastHabits;
  }
  if (str == "past_perfect") {
    return Rule::kPastPerfect;
  }
  if (str == "phrasal_verbs") {
    return Rule::kPhrasalVerbs;
  }
  if (str == "question_tags") {
    return Rule::kQuestionTags;
  }
  if (str == "past_continuous") {
    return Rule::kPastContinuous;
  }
  return Rule::kUnknown;
}

Rule Exercise::GetRule() const {
  return rule_;
}

