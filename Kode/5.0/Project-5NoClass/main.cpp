#include <iostream>
#include <cmath>
#include <armadillo>


using namespace std;
using namespace arma;



void eulerForward(mat &pos, mat &has);
void eulerForward(vec &posX,vec &posY,vec &hasX,vec &hasY, int i, double h);
void verlet(mat &pos, mat &has);
void verlet(vec &posX,vec &posY,vec &hasX,vec &hasY);

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



    //matriser test
    mat pos = zeros<mat>(n,2);
    mat has = zeros<mat>(n,2);

    //setter opp vector for tid
    vec t = zeros<vec>(n);
    for(int i = 0;i<n;i++){
        t[i] = i*dt;
    }


    // starte beregninger av posisjon til jorden med solen stille i sentrum.

    cout<<"hello!"<<endl;
    return 0;
}


void eulerForward(vec &posX, vec &posY,vec &hasX, vec &hasY, int n, double dt, double masse ){
    double dis, a;
    double massePI = masse*4*(4*atan(1)*4*atan(1));
    for(int i = 0;i<(n-1);i++){
        dis = sqrt(posX[i]*posX[i] +posY[i]*posY[i]);
        a = - (massePI)/(dis*dis*dis);
        //x-komponent
        hasX[i+1] = hasX[i] + dt* a*posX[i];
        posX[i+1] = posX[i] + dt*hasX[i];
        //y-komponent
        hasY[i+1] = hasY[i] + dt* a*posY[i];
        posY[i+1] = posY[i] + dt*hasY[i];
    }
}
void verlet(vec &posX, vec &posY,vec &hasX, vec &hasY, int n, double dt, double masse ){
    double dis, a;
    double massePI = masse*4*(4*atan(1)*4*atan(1));
    for(int i = 0; i<(n-1);i++){
        dis = sqrt(posX[i]*posX[i] +posY[i]*posY[i]);
        a = - (massePI)/(dis*dis*dis);
        //x-komponent
        posX[i+1] = posX[i] + dt*hasX[i]+ 0.5*(dt*dt*a*posX[i]);
        hasX[i+1] = hasX[i] + 0.5*dt* (a*(posX[i]+posX[i+1]));
        //y-komponent
        posY[i+1] = posY[i] + dt*hasY[i]+ 0.5*(dt*dt*a*posY[i]);
        hasY[i+1] = hasY[i] + 0.5*dt* (a*(posY[i]+posY[i+1]));
    }
}

void toFile(string filNavn, vec x, vec y, vec t,int n){
    ofstream outfile;
    outfile.open(filNavn);
    if(outfile.is_open()){
        cout<<"writing to file..."<<endl;
        outfile <<"t"<<"x"<<"y"<<endl;
        for(int j=0;j<n;j++){
            outfile <<t[j]<<x[j]<<y[j]<<endl;
        }
    }else{
        cout<<"could not open file"<<filNavn<<endl;
        exit(1);
    }
    outfile.close();
    cout<<"done writing to file"<<endl;
}
