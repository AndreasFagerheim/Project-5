#include "integrand.h"
#include "univers.h"
#include "legemer.h"

Integrand::Integrand(double dt) : tidsSteg(dt)
{

}
Integrand::Integrand(double dt, bool euler) : tidsSteg(dt), bEuler(euler)
{

}

void Integrand::integrateSteg(class Univers &univers){
    if(bEuler){
        Integrand::intStegEuler(univers);
    }else{
        Integrand::intStegVerlet(univers);
    }
}

void Integrand::intStegEuler(Univers &univers){


}

void Integrand::intStegVerlet(Univers &univers){


}
