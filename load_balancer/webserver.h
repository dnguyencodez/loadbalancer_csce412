#ifndef WEBSERVER_H
#define WEBSERVER_H
#include <bits/stdc++.h>

using namespace std;

class Webserver{
 public:
    int startTime;
    int endTime;

    Webserver(){
        startTime = 0;
        endTime = 0;
    }

    bool isAvailable(int clockTime) {
        if(clockTime >= endTime){
            return true;
        }else{
            return false;
        }
    }

    void doProcessing(int sTime, int pTime){
        startTime = sTime;
        endTime = sTime + pTime;
    }

};

#endif