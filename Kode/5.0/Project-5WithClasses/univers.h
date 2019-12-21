#ifndef UNIVERS_H
#define UNIVERS_H
#include <legemer.h>

using namespace std;

class Univers
{
protected:
    double              kinetiskEnergi;
    double              potensiellEnergi;
    double              konstantG;
    double              angMoment;
    std::vector<Legemer> legemer;        // samling av legemer

    bool                bFixedSun = false;      //for å sette sol i sentrum
public:
    Univers();
    Univers(double nyG);

    // Lager et legeme (planet) med gitt posisjon, hastighet og masse
    void lagLegeme(vec pos, vec has, double massen);
    // Legger til et legme i systemet
    void addLegeme(const Legemer &legeme);


    // Metoder for å finne status for universet
    void finnKraftEnergiTo();
    void finnKraftEnergi();
    void finnAngMoment();

    //getters for ulike verdier(const = read only)
    double      totEnergi() const;
    double      getKinetiskEnergi() const;
    double      getPotensiellEnergi() const;
    double      getAngMoment() const;
    int         getAntallLegemer() const;
    bool        isSunFixed() const;
    std::vector<Legemer> &getLegemer();


    void skrivTilFil(string filNavn);



};

#endif // UNIVERS_H
