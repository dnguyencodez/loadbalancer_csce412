#ifndef WEBSERVER_H
#define WEBSERVER_H

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

    bool doProcessing(int sTime, int pTime){
        startTime = sTime;
        endTime = sTime + pTime;
    }

};

#endif