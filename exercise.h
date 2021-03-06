#pragma once

#include <QString>

#include "enums.h"

class Exercise {
 public:
  Exercise() = default;
  Exercise(QString text, QString right_answer, Rule rule);
  virtual ~Exercise() = default;

  const QString& GetText() const;
  const QString& GetRightAnswer() const;

  Rule GetRule() const;

  virtual bool CheckAnswer(const QString& answer) const = 0;
  static Rule StringToRule(const std::string& str);
 protected:
  QString text_;
  QString right_answer_;
  Rule rule_ = Rule::kUnknown;
};

