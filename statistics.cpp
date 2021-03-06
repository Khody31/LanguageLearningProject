//
// Created by egoruskha on 28.02.21 г..
//

#include "statistics.h"
void Statistics::IncRight() {
  right_++;
  total_++;
}

void Statistics::IncWrong() {
  total_++;
}

int Statistics::GetRight() const {
  return right_;
}

int Statistics::GetWrong() const {
  return total_ - right_;
}

int Statistics::GetTotal() const {
  return total_;
}

void Statistics::Clear() {
  total_ = 0;
  right_ = 0;
  score_ = 0;
}
void Statistics::IncScore(int points) {
  score_ += points;
}
int Statistics::GetScore() const {
  return score_;
}
