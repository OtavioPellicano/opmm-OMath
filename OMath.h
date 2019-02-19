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

    double varianciaP(vecDb &vecMeds);
    double varianciaP();

    double varianciaA(vecDb &vecMeds);
    double varianciaA();

    double max(vecDb& vecMeds);
    double max();

    double min(vecDb& vecMeds);
    double min();

    bool truncar(vecDb& vecMeds, const size_t &numDigitos);
    bool truncar(const size_t &numDigitos);
    bool truncar(double& medida, const size_t& numDigitos);

    bool arredondar(vecDb& vecMeds, const size_t &numDigitos);
    bool arredondar(const size_t& numDigitos);
    bool arredondar(double& medida, const size_t& numDigitos);

    double tendencia(vecDb& vecMeds);
    double tendencia();

    vecDb vecMedidas() const;
    void setVecMedidas(const vecDb &vecMeds);

    vecDb* vecMedidas();

private:
    vecDb mVecMedidas;
};

}


#endif // MATH_H
