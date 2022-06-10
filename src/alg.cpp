// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    int i;
    if(value < 2)
            return 0;
    for(i = 2; i <= value; i++) {
        
        if(value%i == 0)
            if(value != i)
                return 0;
    }
    return 1;
}

uint64_t nPrime(uint64_t n) {
    int i=0, c=0;
    while(true) {
        i++;
        if(checkPrime(i))
            c++;
        if(c==n)
            return i;
    }
    return c;
}

uint64_t nextPrime(uint64_t value) {
    int a=value+1;
    while(true) {
        if(checkPrime(a))
            return a;
        a++;
    }
    return a;
}

uint64_t sumPrime(uint64_t hbound) {
    int sum=0,i;
    for(i = 0; i<hbound; i++)
    if(checkPrime(i))
        sum+=i;
    return sum;
}
