#include "legemer.h"
#include <armadillo>

Legemer::Legemer(vec nyPos, vec nyHas, double nyMasse){

    posisjon = nyPos;
    hastighet = nyHas;
    masse = nyMasse;
    angMom = cross(posisjon, hastighet);
}

void Legemer::resetKraft(){
    pKraft = kraft;                 // setter tidligere kraft til ny kraft
    kraft <<0<<endr<<0<<endr<<0;    // setter kreften til null
}
