/**
    * @file loadbalancer.h
    * @brief Loadbalancer class
    * This file contains the declaration of the Loadbalancer class. The Loadbalancer class
    simulates the functionality of a load balancer in a web server system. It contains
    attributes for the number of web servers, the running time of the load balancer, the
    total queue processing time, a vector of web servers, and a queue of requests. It has
    default and parameterized constructors, and various member functions to simulate the
    processing of requests by the load balancer.
*/

#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include "webserver.h"
#include "request.h"
#include <bits/stdc++.h>

using namespace std;

class Loadbalancer {
    int initNumServers; ///< initial number of web servers
    int numServers; ///< current number of web servers
    int loadBal_time; ///< running time of the load balancer
    long long int totalQueueTime; ///< total queue processing time
    vector<Webserver> servers; ///< vector of web servers
    queue<Request> request_queue; ///< queue of requests

public:
    // default constructor
    Loadbalancer() {
        loadBal_time = 0;
        totalQueueTime = 0;
        numServers = 0;
        initNumServers = 0;
    }

    // parameterized constructor
    Loadbalancer(int numServers, int runTime) {
        totalQueueTime = 0;
        this->numServers = numServers;
        initNumServers = numServers;
        loadBal_time = runTime;
        for (int i=0; i < numServers; i++) { // initialize web servers
            Webserver newServer;
            servers.push_back(newServer);
        }

        srand(time(NULL));
        int currNumReq = (numServers * 20) + 1;        
        for (int i=0 ; i < currNumReq; i++) {
            Request newRequest;
            totalQueueTime += newRequest.getTime();
            request_queue.push(newRequest);
        }

        cout << "Total number of webservers: " << numServers << endl;
        cout << "Load balancer runtime: " << loadBal_time << endl;
        cout << "Current number of requests in the queue: " << currNumReq << endl;
        cout << "Total request queue processing time: " << totalQueueTime << endl;
        cout << "Load balancer starting now..." << endl;
    }

    /**
         * @brief adds new requests to the queue
         * 
         * This function generates a random number of new requests and adds them to the request queue.
         * It also updates the total queue processing time.
         * 
     */

    void addNewRequest() {
        cout << "New request incoming..." << endl;
        Request newRequest;
        request_queue.push(newRequest);
        cout << "Request added to the queue" << endl;
        totalQueueTime += newRequest.getTime();
        cout << "New total queue processing time: " << totalQueueTime << endl;
    }

    /**
     * @brief distributes requests to web servers
     * 
     * This function simulates the distribution of requests from the request queue to the web servers.
     * It also adds or removes web servers as needed based on the size of the request queue.
     * 
     */

    void distribute_requests() {
        int i=0;
        int numServersToIterate = numServers;
        while (i < loadBal_time) {
            cout << "----------------------------------------------------------------" << endl;
            cout << "Clock cycle #" << i << ":" << endl;
            cout << "Request queue size: " << request_queue.size() << endl;

            int sendRequest = rand() % 4;
            if (sendRequest == 0) {
                addNewRequest();
            }

            
            int start=0;
            
            if(request_queue.size() > initNumServers * 20 * 0.8){
                if(numServersToIterate == numServers){
                    cout << "Creating a new server" << endl;
                    Webserver newServer;
                    servers.push_back(newServer);
                    numServers++;
                        
                    numServersToIterate = numServers;
                }else{
                    cout << "Adding an existing server" << endl;
                    numServersToIterate++;
                }
            } else {
                cout << "Removing one server" << endl;
                numServersToIterate--;
            }
            

            for (int j=start; j < numServersToIterate; j++) {
                int currNumAvailable = 0;
                if (servers[j].isAvailable(i) && request_queue.size() > 0) {
                    Request reqToSend = request_queue.front();
                    cout << "Web server " << j << " is available" << endl;
                    totalQueueTime -= reqToSend.getTime();
                    servers[j].doProcessing(i, reqToSend.getTime());
                    string currReqIP = reqToSend.getIPout();
                    request_queue.pop();
                    cout << "Sent request " << currReqIP << " to web server " << j << endl;
                }
            }

            cout << "----------------------------------------------------------------" << endl;
            i++;
        }

        cout << "Clock cycle complete. Load balancer finished." << endl;
    }
};
#endif