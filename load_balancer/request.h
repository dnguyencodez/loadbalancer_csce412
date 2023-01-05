/**

    @file request.h
    @brief Request class
    This file contains the declaration of the Request class. The Request class represents a request
    in a web server system, and contains attributes for the incoming IP address, outgoing IP address,
    and processing time of the request. It has a default constructor which generates random values
    for these attributes. It also has member functions to retrieve the values of these attributes.
*/


#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>

using namespace std;

class Request {
    string IPin; ///< incoming IP address of the request
    string IPout; ///< outgoing IP address of the request
    int randTime; ///< processing time of the request

public:

/**
    * @brief default constructor
    *
    * This is the default constructor for the Request class. It generates random values for the
    * incoming and outgoing IP addresses, and the processing time of the request.
    *
*/
    Request() {
        int IPin1 = rand() % 256;
        int IPin2 = rand() % 256;
        int IPin3 = rand() % 256;
        int IPin4 = rand() % 256;
        IPin = to_string(IPin1) + "." + to_string(IPin2) + "." + to_string(IPin3) + "." + to_string(IPin4);

        int IPout1 = rand() % 256;
        int IPout2 = rand() % 256;
        int IPout3 = rand() % 256;
        int IPout4 = rand() % 256;
        IPout = to_string(IPout1) + "." + to_string(IPout2) + "." + to_string(IPout3) + "." + to_string(IPout4);

        randTime = rand() % 502;
    }

    /**
         * @brief retrieves incoming IP address of the request
         * 
         * @return string incoming IP address of the request
         * 
     */
    string getIPin() {
        return IPin;
    }

    /**
     * @brief retrieves outgoing IP address of the request
     * 
     * @return string outgoing IP address of the request
     * 
     */

    string getIPout() {
        return IPout;
    }

    /**
     * @brief retrieves processing time of the request
     * 
     * @return int processing time of the request
     * 
     */
    int getTime() {
        return randTime;
    }
};
#endif