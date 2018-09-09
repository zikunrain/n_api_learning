#include <iostream>

using namespace std;

class Accumulator {
  public:
    int accumulate(int bound);
};

int Accumulator::accumulate(int bound) {
  int sum = 0;
  for (int i = 0; i < bound; i++) {
    sum += i;
  }
  return sum;
}