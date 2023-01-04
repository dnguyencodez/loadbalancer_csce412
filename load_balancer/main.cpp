#include <bits/stdc++.h>
#include "request.h"
using namespace std;

int main() {
    request req;
    int ipin = req.getIPin();
    int ipout = req.getIPout();
    int procTime = req.getTime();

    cout << "ipin: " << ipin << endl;
    cout << "ipout: " << ipout << endl;
    cout << "proctime: " << procTime << endl;
}