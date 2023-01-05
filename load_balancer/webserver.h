/**

    @file webserver.h
    @brief Webserver class
    This file contains the declaration of the Webserver class. The Webserver class represents a
    web server in a web server system, and contains attributes for the start time and end time of
    its current request. It has a default constructor which initializes these values to 0. It also
    has member functions to check the availability of the web server and to simulate the processing
    of a request by the web server.
*/

#ifndef WEBSERVER_H
#define WEBSERVER_H
#include <bits/stdc++.h>

using namespace std;

class Webserver{
 public:
    int startTime; ///< start time of the current request being processed by the web server
    int endTime; ///< end time of the current request being processed by the web server

    /**
     * @brief default constructor
     * 
     * This is the default constructor for the Webserver class. It initializes the start and end 
     * times of the current request to 0.
     * 
     */
    Webserver(){
        startTime = 0;
        endTime = 0;
    }

    /**
     * @brief checks if the web server is available
     * 
     * This function checks if the web server is currently available to process a new request, based 
     * on the current clock time.
     * 
     * @param clockTime current clock time
     * @return true if the web server is available, false otherwise
     * 
     */
    bool isAvailable(int clockTime) {
        if(clockTime >= endTime){
            return true;
        }else{
            return false;
        }
    }

    /**
     * @brief simulates the processing of a request by the web server
     * 
     * This function simulates the processing of a request by the web server by updating the start 
     * and end times of the current request being processed.
     * 
     * @param sTime start time of the request
     * @param pTime processing time of the request
     * 
     */
    void doProcessing(int sTime, int pTime){
        startTime = sTime;
        endTime = sTime + pTime;
    }

};

#endif