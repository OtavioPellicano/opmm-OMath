#ifndef MATH_H
#define MATH_H

#include <vector>
#include <algorithm>
#include <cstddef>
#include <cmath>
#include <limits>

using namespace std;

namespace opmm {

typedef std::vector<double> vecDb;

class OMath
{
public:
    OMath();
    OMath(const vecDb &vecMedidas);

    double mediana(vecDb &vecMeds);
    double mediana();

    double media(vecDb &vecMeds);
    double media();

    double desvioPadraoP(vecDb &vecMeds);
    double desvioPadraoP();

    double desvioPadraoA(vecDb &vecMeds);
    double desvioPadraoA();

    double max(vecDb& vecMeds);
    double max();

    double min(vecDb& vecMeds);
    double min();

    vecDb vecMedidas() const;
    void setVecMedidas(const vecDb &vecMeds);

private:
    vecDb mVecMedidas;
};

}


#endif // MATH_H
