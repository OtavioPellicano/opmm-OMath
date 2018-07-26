#include "OMath.h"

namespace opmm {

OMath::OMath()
{

}

OMath::OMath(const vecDb &vecMedidas)
    :mVecMedidas(vecMedidas)
{

}

double OMath::mediana(vecDb &vecMeds)
{
    std::sort(vecMeds.begin(), vecMeds.end());
    size_t tam = vecMeds.size();

    if(tam == 0)
        return -1;

    if(tam%2 == 0)
    {
        if(tam == 2 )
            return (vecMeds[0] + vecMeds[1])/2;
        return (vecMeds[tam/2] + vecMeds[tam/2 - 1])/2;
    }
    else
    {
        return vecMeds[tam/2];
    }
}

double OMath::mediana()
{
    if(mVecMedidas.empty())
        return -1;

    return mediana(mVecMedidas);
}

double OMath::media(vecDb &vecMeds)
{
    double sum = 0;
    size_t i;
    for(i = 0; i < vecMeds.size(); ++i)
    {
        sum+=vecMeds[i];
    }

    if(i != 0)
        return sum/i;

    return -1;
}

double OMath::media()
{
    if(mVecMedidas.empty())
        return -1;

    return media(mVecMedidas);
}

double OMath::desvioPadraoP(vecDb &vecMeds)
{
    double mmedia = media(vecMeds);

    double somaDiffQuadratica = 0;
    size_t i;

    for(i = 0; i < vecMeds.size(); ++i)
    {
        somaDiffQuadratica += pow(vecMeds[i] - mmedia,2);
    }

    if(i != 0)
        return sqrt(somaDiffQuadratica/i);

    return -1;

}

double OMath::desvioPadraoP()
{
    if(mVecMedidas.empty())
        return -1;
    return desvioPadraoP(mVecMedidas);
}

double OMath::desvioPadraoA(vecDb &vecMeds)
{
    double mmedia = media(vecMeds);

    double somaDiffQuadratica = 0;
    size_t i;

    for(i = 0; i < vecMeds.size(); ++i)
    {
        somaDiffQuadratica += pow(vecMeds[i] - mmedia,2);
    }

    if(i != 0)
        return sqrt(somaDiffQuadratica/(i-1));

    return -1;
}

double OMath::desvioPadraoA()
{
    if(mVecMedidas.empty())
        return -1;
    return desvioPadraoA(mVecMedidas);
}

double OMath::max(vecDb &vecMeds)
{
    double max = std::numeric_limits<double>::min();
    for(auto itVec = vecMeds.begin(); itVec != vecMeds.end(); ++itVec)
    {
        if(*itVec > max)
            max = *itVec;
    }
    return max;
}

double OMath::max()
{
    if(mVecMedidas.empty())
        return -1;
    return max(mVecMedidas);
}

double OMath::min(vecDb &vecMeds)
{
    double min = std::numeric_limits<double>::max();
    for(auto itVec = vecMeds.begin(); itVec != vecMeds.end(); ++itVec)
    {
        if(*itVec < min)
            min = *itVec;
    }
    return min;
}

double OMath::min()
{
    if(mVecMedidas.empty())
        return -1;
    return min(mVecMedidas);
}

vecDb OMath::vecMedidas() const
{
    return mVecMedidas;
}

void OMath::setVecMedidas(const vecDb &vecMeds)
{
    mVecMedidas = vecMeds;
}

}
