#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>

using namespace std;

class Request {
    int IPin;
    int IPout;
    int randTime;

public:
    Request() {
        // srand(time(NULL));
        IPin = rand() % 256;
        // srand(time(NULL));
        IPout = rand() % 256;
        // srand(time(NULL));
        randTime = rand() % 502;
        // cout << "reqTime: " << randTime << endl;
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