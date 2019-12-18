#ifndef LEGEMER_H
#define LEGEMER_H
#include <armadillo>


using namespace arma;
class Legemer
{
public:
    double masse;
    vec posisjon;
    vec hastighet;
    vec kraft;
    vec pKraft;
    vec angMom;

    //lage legeme med gitte vektorer for posisjon og hastighet, og massen til legemet
    Legemer(vec nyPos, vec nyHas, double nyMasse);

    void resetKraft();
};

#endif // LEGEMER_H
