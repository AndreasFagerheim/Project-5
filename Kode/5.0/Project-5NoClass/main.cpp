#include <iostream>
#include <cmath>
#include <armadillo>


using namespace std;
using namespace arma;



void eulerChromer(mat &pos, mat &has);
void eulerChromer(vec &posX,vec &posY,vec &posZ,vec &hasX,vec &hasY,vec &hasZ);
void verlet(mat &pos, mat &has);
void verlet(vec &posX,vec &posY,vec &posZ,vec &hasX,vec &hasY,vec &hasZ);

int main(int argc, char *argv[])
{
    double start = 0;
    double stop = 1;
    int n = atoi(argv[1]);
    double dt = (stop-start)/(n-1);

    //delt opp i vektor for x,y,z komponenter
    vec posX = zeros<vec>(n);
    vec hasX = zeros<vec>(n);

    vec posY = zeros<vec>(n);
    vec hasY = zeros<vec>(n);

    vec posZ = zeros<vec>(n);
    vec hasZ = zeros<vec>(n);

    //matriser test
    mat pos = zeros<mat>(n,3);
    mat has = zeros<mat>(n,3);

    //setter opp vector for tid
    vec t = zeros<vec>(n);
    for(int i = 0;i<n;i++){
        t[i] = i*dt;
    }


    // starte beregninger av posisjon til jorden med solen stille i sentrum.

    cout<<"hello!"<<endl;
    return 0;
}


void eulerChromer(vec &posX, vec &posY, vec &posZ){

}
