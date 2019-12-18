#include "univers.h"

using namespace std;

Univers::Univers(double nyG)
{
    kinetiskEnergi = 0;
    potensiellEnergi = 0;
    GKonstant = nyG;

}


void Univers::addLegeme(vec nyPos, vec nyHas, double nyMasse){
    legemer.push_back(Legemer(nyPos,nyHas,nyMasse));
}

int Univers::antallLegemer() const{
    return legemer.size();
}
double Univers::totEnergi() const{
    return kinetiskEnergi + potensiellEnergi;
}

double Univers::potEneegi() const{
    return potensiellEnergi;
}
double Univers::kinEnergi() const{
    return kinetiskEnergi;
}
double Univers::angulMom() const{
    return angulartMomentum;
}
