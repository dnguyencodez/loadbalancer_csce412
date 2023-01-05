/**

    @file main.cpp
    @brief main function
    This file contains the main function which simulates the functionality of a load balancer
    in a web server system. It creates a Loadbalancer object with the number of web servers
    and running time specified as command line arguments, and calls the distribute_requests
    member function to simulate the processing of requests.

    To compile the code and create the executable file:
    g++ main.cpp

    To run the executable file and include arguments:
    ./a.out s t
    where s is the number of servers and t is the clock cycle for the load balancer.
    If you want to output to a text file:
    ./a.out s t > output.txt
*/


#include <bits/stdc++.h>
#include "request.h"
#include "loadbalancer.h"
using namespace std;

/**

    @brief main function

    This function takes in two command line arguments: the number of web servers and the running

    time of the load balancer. It creates a Loadbalancer object with these values, and calls

    the distribute_requests member function to simulate the processing of requests.

    @param argc number of command line arguments

    @param argv array of command line arguments

    @return 0 upon successful execution
*/

int main(int argc, char* argv[]) {
    int numServers = atoi(argv[1]);
    int lbTime = atoi(argv[2]);

    Loadbalancer lb(numServers, lbTime);
    lb.distribute_requests();
}