#include "univers.h"


Univers::Univers(){
    kinetiskEnergi = 0;
    potensiellEnergi = 0;
    konstantG = 4*(4*atan(2)*4*atan(1));  // 4pi^2

}
Univers::Univers(double nyG)
{
    kinetiskEnergi = 0;
    potensiellEnergi = 0;
    konstantG = nyG;
}

void Univers::lagLegeme(vec pos, vec has, double massen){
    legemer.push_back(Legemer(pos,has,massen));
}
void Univers::addLegeme(const Legemer &legeme){
    legemer.push_back(legeme);
}

//Finner kraft og energi til de to legemene (oppgave a,b,c,d)
void Univers::finnKraftEnergiTo(){
    kinetiskEnergi = 0;
    potensiellEnergi = 0;
    legemer[0].resetKraft();
    legemer[1].resetKraft();
    Legemer &leg1 = legemer[0]; //alltid solen?
    Legemer &leg2 = legemer[1];

    double avstand = norm(leg1.posisjon-leg2.posisjon); //avstanden mellom legemene
    double krefter = konstantG*leg1.masse*leg2.masse/(avstand*avstand);

    leg2.kraft = leg2.kraft+krefter*leg1.posisjon/avstand;
    potensiellEnergi = potensiellEnergi-krefter*avstand;
    kinetiskEnergi = kinetiskEnergi + 0.5*leg2.masse*(dot(leg2.hastighet,leg2.hastighet));
}
// Finner den nåeværende kraften hver planet opplever og dens kinetiske og potensielle energi
// metoden kan brukes for systemer av ønsket antall legemer
void Univers::finnKraftEnergi(){
    kinetiskEnergi = 0;
    potensiellEnergi = 0;

    //setter kraften til hvert legeme i systemet til null
    for(Legemer &legeme:legemer){
        legeme.resetKraft();
    }

    for(int i = 0;i<getAntallLegemer();i++){
        Legemer &legeme2 = legemer[i];
        for(int j=i+1;j<getAntallLegemer();j++){
            Legemer &legeme3 = legemer[j];
            vec rVec = legeme2.posisjon -legeme3.posisjon; // avstanden mellom to legemer
            double rNorm = norm(rVec);
            double kraft = konstantG*legeme2.masse*legeme3.masse/(rNorm*rNorm);
            vec     kraftVec = kraft* rVec/rNorm;

            // ikke relativistikk ->gjør følgende
            legeme2.kraft -= kraftVec;
            legeme3.kraft += kraftVec;
            potensiellEnergi -= kraft*rNorm;
        }
        double v2 = dot(legeme2.hastighet,legeme2.hastighet);
        kinetiskEnergi += legeme2.masse*0.5*v2;
    }
    //hvis solen er fast midtpunkt settes kraften til null for å hindre bevegelse
    if(isSunFixed()){
        legemer[0].kraft <<0<<0<<0;
    }
}
// må lages
void Univers::finnAngMoment(){
    vec angMomVec ;
    angMomVec <<0<<0<<0;

    for(Legemer &legeme:legemer){
        angMomVec+= legeme.masse*cross(legeme.posisjon,legeme.hastighet);
    }
    angMoment = norm(angMomVec);
}

double Univers::totEnergi() const{
    return kinetiskEnergi+potensiellEnergi;
}
double Univers::getKinetiskEnergi() const{
    return kinetiskEnergi;
}
double Univers::getPotensiellEnergi() const{
    return potensiellEnergi;
}

double Univers::getAngMoment() const{
    return angMoment;
}

int Univers::getAntallLegemer() const{
    legemer.size();
}
bool Univers::isSunFixed() const{
    return bFixedSun;
}
vector<Legemer> &Univers::getLegemer(){
    return legemer;
}
//må lages
void Univers::skrivTilFil(string filNavn){

}
