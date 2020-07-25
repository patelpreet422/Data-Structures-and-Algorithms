#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

void addNumber(unsigned long i, priority_queue<unsigned long> &lower,
               priority_queue<unsigned long, vector<unsigned long>,
                              greater<unsigned long>> &higher);
float getMedian(priority_queue<unsigned long> &lower,
                priority_queue<unsigned long, vector<unsigned long>,
                               greater<unsigned long>> &higher);
void rebalance(priority_queue<unsigned long> &lower,
               priority_queue<unsigned long, vector<unsigned long>,
                              greater<unsigned long>> &higher);

void runningMedian(unsigned long *data, int size, float *medians) {
  priority_queue<unsigned long> lower;
  priority_queue<unsigned long, vector<unsigned long>, greater<unsigned long>>
      higher;
  for (int i = 0; i < size; ++i) {
    addNumber(data[i], lower, higher);
    medians[i] = getMedian(lower, higher);
  }
}

float getMedian(priority_queue<unsigned long> &lower,
                priority_queue<unsigned long, vector<unsigned long>,
                               greater<unsigned long>> &higher) {
  float median = 0;
  if (lower.size() == higher.size()) {
    median = ((float)lower.top() + (float)higher.top()) / 2;
  } else {
    if (lower.size() > higher.size()) {
      median = lower.top();
    } else {
      median = higher.top();
    }
  }
  return median;
}

void addNumber(unsigned long i, priority_queue<unsigned long> &lower,
               priority_queue<unsigned long, vector<unsigned long>,
                              greater<unsigned long>> &higher) {
  if (lower.empty() || i < lower.top()) {
    lower.push(i);
  } else {
    higher.push(i);
  }
  rebalance(lower, higher);
}

void rebalance(priority_queue<unsigned long> &lower,
               priority_queue<unsigned long, vector<unsigned long>,
                              greater<unsigned long>> &higher) {
  int64_t higherSize = higher.size();
  int64_t lowerSize = lower.size();
  if (abs(higherSize - lowerSize) > 1) {
    if (lower.size() > higher.size()) {
      higher.push(lower.top());
      lower.pop();
    } else {
      lower.push(higher.top());
      higher.pop();
    }
  }
}

int main() {
  int size;
  cin >> size;
  unsigned long *data = new unsigned long[size];
  float *medians = new float[size];
  for (int i = 0; i < size; ++i) {
    cin >> data[i];
  }
  runningMedian(data, size, medians);
  for_each(medians, medians + size, [](const auto &m) { printf("%.1f\n", m); });

  delete[] medians;
  delete[] data;
  return 0;
}
