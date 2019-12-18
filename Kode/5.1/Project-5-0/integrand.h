#ifndef INTEGRAND_H
#define INTEGRAND_H

#include <string>
class Integrand
{
public:
    double tidsSteg;
    bool bEuler;
    Integrand(double dt);
    Integrand(double dt, bool euler);

    void integrateSteg(class Univers &univers);
    void intStegEuler(class Univers &univers);
    void intStegVerlet(class Univers &univers);
};

#endif // INTEGRAND_H
