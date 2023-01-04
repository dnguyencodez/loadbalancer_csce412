#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Request{
 public:
    std::string IP_In;
    std::string IP_Out;
    int time = 0;

    Request(){
        std::srand(std::time(nullptr));
        IP_In = randomIP();
        IP_Out = randomIP();
        time = randomTime();
    }

 private:
    std::string randomIP(){
        // Generate random numbers for the four octets of the IP address
        int octet1 = std::rand() % 256;
        int octet2 = std::rand() % 256;
        int octet3 = std::rand() % 256;
        int octet4 = std::rand() % 256;

        // Return the IP address as a string
        return std::to_string(octet1) + "." + std::to_string(octet2) + "." + std::to_string(octet3) + "." + std::to_string(octet4);
    }
    
    int randomTime(){ 
        return std::rand() % 222 + 1;;
    }



};
#endif  // REQUEST_H