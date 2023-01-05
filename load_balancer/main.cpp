#include <bits/stdc++.h>
#include "request.h"
#include "loadbalancer.h"
using namespace std;

int main(int argc, char* argv[]) {
    int numServers = atoi(argv[1]);
    int lbTime = atoi(argv[2]);

    // srand(time(NULL));
    Loadbalancer lb(numServers, lbTime);
    lb.distribute_requests();
    // Request req;
    // int ipin = req.getIPin();
    // int ipout = req.getIPout();
    // int procTime = req.getTime();

    // cout << "ipin: " << ipin << endl;
    // cout << "ipout: " << ipout << endl;
    // cout << "proctime: " << procTime << endl;
}