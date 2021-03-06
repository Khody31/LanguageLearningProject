#pragma once
#include <cstdint>

class Statistics {
 public:
  Statistics() = default;

  void IncRight();
  void IncWrong();
  void IncScore(int points);
  void Clear();

  int GetRight() const;
  int GetWrong() const;
  int GetTotal() const;
  int GetScore() const;
 private:
  int right_ = 0;
  int total_ = 0;
  int score_ = 0;
};
