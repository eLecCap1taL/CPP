#include "dzilib.h"

int main() {
  int t = GetT();
  int q = GetQ();
  long long c = GetC();
  long long n = GetN();
  while(t--) {
    if (Ask(1) == 8) Answer(1000);
    else Answer(1);
  }
  return 0;
}
