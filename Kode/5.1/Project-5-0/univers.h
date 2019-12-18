#ifndef UNIVERS_H
#define UNIVERS_H


#include <legemer.h>

class Univers
{
protected:
    double kinetiskEnergi;
    double potensiellEnergi;
    double angulartMomentum;
    double GKonstant;

    std::vector<Legemer> legemer;

public:
    Univers();
    Univers(double G);
    //legger et legeme til i universet/systemet vårt
    void addLegeme(vec pos, vec has, double masse);


    // get-funksjoner for ulike verdier av interesse
    int antallLegemer() const;
    double totEnergi() const;
    double kinEnergi() const;
    double potEneegi() const;
    double angulMom() const;


};

#endif // UNIVERS_H
