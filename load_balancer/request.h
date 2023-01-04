#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>

using namespace std;

class request {
    int IPin;
    int IPout;
    int randTime;

public:
    request() {
        srand(time(NULL));
        IPin = rand() % 56;
        // srand(time(NULL));
        IPout = rand() % 56;
        srand(time(NULL));
        randTime = rand() % 200 + 1;
    }
    int getIPin() {
        return IPin;
    }

    int getIPout() {
        return IPout;
    }

    int getTime() {
        return randTime;
    }
};
#endif