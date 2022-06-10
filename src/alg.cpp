// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  int d;
  if (value == 1)
    return false;
  for (d = 2; d * d <= value; d++) {
    if (value % d == 0)
      return false;
  }
    return true;
}

uint64_t nPrime(uint64_t n) {
  int d, k, value;
  bool flag = true;
  value = 2;
  for (k = 0; n != k; ) {
    for (d = 2; d * d <= value; d++) {
      if (value % d == 0) {
        flag = false;
        break;
      }
    }
    if (flag)
      k += 1;
    value += 1;
    flag = true;
  }
  return value - 1;
}

uint64_t nextPrime(uint64_t value) {
  int d;
  value += 1;
    for (d = 2; d * d <= value; d++) {
      if (value % d == 0) {
        value += 1;
        d = 1;
      }
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t d, k, i, s;
  s = 0;
  uint64_t* resh;
  resh = new uint64_t[hbound];
  resh[1] = 0;
  for (i = 2; i <= hbound; i++)
    resh[i] = 1;
    for (d = 2; d * d <= hbound; d++) {
      if (resh[d] == 1) {
        for (k = d * d; k <= hbound; k += d) {
          resh[k] = 0;
        }
      }
    }
  for (i = 0; i < hbound; i++) {
    if (resh[i])
      s += i;
  }
  return s;
}
