// Euler Class Implementation

#include <iostream>
#include <vector>
#include <cmath>

#include "Euler.h"

using namespace std;

Euler::Euler() {}

Euler::Euler(float phi, float theta, float psi) {

    Matrix B;
    B.set_val(0,0,cos(psi/2));
    B.set_val(0,1,sin(psi/2));
    B.set_val(1,0,-1*sin(psi/2));
    B.set_val(1,1,cos(psi/2));
    B.set_val(2,2,1);

    Matrix C;
    C.set_val(0,0,1);
    C.set_val(1,1,cos(theta/2));
    C.set_val(1,2,sin(theta/2));
    C.set_val(2,1,-1*sin(theta/2));
    C.set_val(2,2,cos(theta/2));

    Matrix D;
    D.set_val(0,0,cos(phi/2));
    D.set_val(0,1,sin(phi/2));
    D.set_val(1,0,-1*sin(phi/2));
    D.set_val(1,1,cos(phi/2));
    D.set_val(2,2,1);

    A = (B*C)*D;
}

vector<float> Euler::rotate(vector<float> initPt) {
    vector<float> finalPt;
    for (i=0; i<3; i++) {
        vector<float> row = get_row(i);
        finalPt[i] = row[0]*initPt[0] + row[1]*initPt[1] + row[2]*initPt[2];
    }
    return finalPt;
}


int main() {
    return 0;
}