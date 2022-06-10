// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    int a;
    if (value < 2)
            return 0;
    for (a = 2; a <= value; a++) {
        if (value%a == 0)
            if (value != a)
                return 0;
    }
    return 1;
}

uint64_t nPrime(uint64_t n) {
    int a = 0, c = 0;
    while (true) {
        a++;
        if (checkPrime(a))
            c++;
        if (c == n)
            return a;
    }
    return c;
}

uint64_t nextPrime(uint64_t value) {
    int val = value+1;
    while (true) {
        if (checkPrime(val))
            return val;
        val++;
    }
    return val;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t s = 0, a;
    for (a = 0; a < hbound; a++)
    if (checkPrime(a))
        s += a;
    return s;
}
