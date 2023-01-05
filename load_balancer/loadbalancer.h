#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include "webserver.h"
#include "request.h"
#include <bits/stdc++.h>

using namespace std;

class Loadbalancer {
    int initNumServers;
    int numServers;
    int loadBal_time;
    long long int totalQueueTime;
    vector<Webserver> servers;
    queue<Request> request_queue;

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
            // cout << totalQueueTime << endl;
            request_queue.push(newRequest);
        }

        cout << "Total number of webservers: " << numServers << endl;
        cout << "Load balancer runtime: " << loadBal_time << endl;
        cout << "Current number of requests in the queue: " << currNumReq << endl;
        cout << "Total request queue processing time: " << totalQueueTime << endl;
        cout << "Load balancer starting now..." << endl;
    }

    // bool newRequest() {
    //     // following initialize a generator to randomly assign a boolean that determines whether to send a new request or not
    //     random_device rd;
    //     mt19937 gen(rd());
    //     uniform_int_distribution<> dis(0, 1);

    //     return dis(gen);
    // }

    void addNewRequest() {
        int numReqs = rand() % 10;
        for (int i=0; i < numReqs; i++){
            cout << "New request incoming..." << endl;
            Request newRequest;
            request_queue.push(newRequest);
            cout << "Request added to the queue" << endl;
            totalQueueTime += newRequest.getTime();
            cout << "New total queue processing time: " << totalQueueTime << endl;
        }
    }

    void distribute_requests() {
        int i=0;
        int numServersToIterate = numServers;
        while (i < loadBal_time) {
            cout << "----------------------------------------------------------------" << endl;
            cout << "Clock cycle #" << i << ":" << endl;
            cout << "Request queue size: " << request_queue.size() << endl;

            // srand(time(NULL));
            int sendRequest = rand() % 3;
            if (sendRequest == 0) {
                addNewRequest();
            }

            
            int start=0;
            
            if(request_queue.size() > initNumServers * 20 * 0.8){
                if(numServersToIterate == numServers){
                    // for(int j = 0; j < numServersToIterate; j++){
                            cout << "Creating a new server" << endl;
                            Webserver newServer;
                            servers.push_back(newServer);
                            numServers++;
                            // 
                    // }
                    numServersToIterate = numServers;
                }else{
                    cout << "Adding an existing server" << endl;
                    numServersToIterate++;
                }
            }else {
                cout << "removing one server" << endl;
                numServersToIterate--;
            }
            

            for (int j=start; j < numServersToIterate; j++) {
                int currNumAvailable = 0;
                if (servers[j].isAvailable(i) && request_queue.size() > 0) {
                    Request reqToSend = request_queue.front();
                    cout << "Web server " << j << " is available" << endl;
                    totalQueueTime -= reqToSend.getTime();
                    servers[j].doProcessing(i, reqToSend.getTime());
                    int currReqIP = reqToSend.getIPout();
                    request_queue.pop();
                    cout << "Sent request " << currReqIP << " to web server " << j << endl;
                }
            }

            cout << "----------------------------------------------------------------" << endl;
            i++;
        }

        cout << "Load balancer finished" << endl;
    }
};
#endif