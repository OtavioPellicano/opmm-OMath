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

double OMath::varianciaP(vecDb &vecMeds)
{
    double mmedia = media(vecMeds);

    double somaDiffQuadratica = 0;
    size_t i;

    for(i = 0; i < vecMeds.size(); ++i)
    {
        somaDiffQuadratica += pow(vecMeds[i] - mmedia,2);
    }

    if(i != 0)
        return somaDiffQuadratica/i;

    return -1;
}

double OMath::varianciaP()
{
    if(mVecMedidas.empty())
        return -1;
    return varianciaP(mVecMedidas);

}

double OMath::varianciaA(vecDb &vecMeds)
{
    double mmedia = media(vecMeds);

    double somaDiffQuadratica = 0;
    size_t i;

    for(i = 0; i < vecMeds.size(); ++i)
    {
        somaDiffQuadratica += pow(vecMeds[i] - mmedia,2);
    }

    if(i != 0)
        return somaDiffQuadratica/(i-1);

    return -1;

}

double OMath::varianciaA()
{
    if(mVecMedidas.empty())
        return -1;
    return varianciaA(mVecMedidas);

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

bool OMath::truncar(vecDb &vecMeds, const size_t& numDigitos)
{
    for(auto itVec = vecMeds.begin(); itVec != vecMeds.end(); ++itVec)
    {
        if(!truncar(*itVec, numDigitos))
            return false;
    }

    return true;
}

bool OMath::truncar(const size_t &numDigitos)
{
    if(mVecMedidas.empty())
        return false;
    return truncar(mVecMedidas, numDigitos);
}

bool OMath::truncar(double &medida, const size_t &numDigitos)
{
    std::string str;
    std::string::iterator posStr;
    std::string::iterator itStr;

    str = std::to_string(medida);
    try {
        itStr = std::find(str.begin(), str.end(), '.');
        if(itStr != str.end())
        {
            posStr = itStr  + 1 + numDigitos;
            if(posStr <= str.end())
            {
                str = std::string(str.begin(), posStr);
            }
            else
            {
                str = medida;
            }
        }
        else
        {
            str = medida;
        }
    } catch (...) {
        return false;
    }

    medida = std::stod(str);

    return true;
}

bool OMath::arredondar(vecDb &vecMeds, const size_t &numDigitos)
{
    for(auto itVec = vecMeds.begin(); itVec != vecMeds.end(); ++itVec)
    {
        if(!arredondar(*itVec, numDigitos))
            return false;
    }

    return true;
}

bool OMath::arredondar(const size_t &numDigitos)
{
    if(mVecMedidas.empty())
        return false;
    return arredondar(mVecMedidas, numDigitos);
}

bool OMath::arredondar(double &medida, const size_t &numDigitos)
{
    std::string str;
    std::string::iterator posStr;
    std::string::iterator posStrArred;
    std::string::iterator itStr;
    int intTemp;

    str = std::to_string(medida);
    try {
        itStr = std::find(str.begin(), str.end(), '.');
        if(itStr != str.end())
        {
            posStr = itStr  + 1 + numDigitos;
            if(posStr <= str.end())
            {
                posStrArred = posStr;
                if(*posStr != '.' && *posStr != '-')
                {
                    intTemp = int(*posStr);        //normalizando da tabela ASCII
                    if(intTemp - 48 >= 5)
                    {
                        --posStr;
                        for(;posStr != str.begin();--posStr)
                        {
                            if(*posStr == '.')
                                continue;

                            if(*posStr == '-')
                                break;

                            intTemp = int(*posStr);    //normalizando da tabela ASCII
                            ++intTemp;
                            if(intTemp - 48 > 9)
                            {
                                *posStr = 48;   //0 no ASCII
                            }
                            else
                            {
                                *posStr = intTemp;
                                break;
                            }
                        }

                    }
                }

                posStr = posStrArred;

                str = std::string(str.begin(), posStr);
            }
            else
            {
                str = medida;
            }
        }
        else
        {
            str = medida;
        }
    } catch (...) {
        return false;
    }

    medida = std::stod(str);

    return true;
}

double OMath::tendencia(vecDb &vecMeds)
{
    if(vecMeds.empty())
    {
        return -1;
    }
    else if(vecMeds.size() == 1)
    {
        return 1;
    }
    else
    {
        std::vector<double> vecTemp{vecMeds.begin(), vecMeds.end() - 1};
        return vecMeds.back()/media(vecTemp);
    }

}

double OMath::tendencia()
{
    if(mVecMedidas.empty())
        return -1;
    return tendencia(mVecMedidas);
}

vecDb OMath::vecMedidas() const
{
    return mVecMedidas;
}

void OMath::setVecMedidas(const vecDb &vecMeds)
{
    mVecMedidas = vecMeds;
}

vecDb *OMath::vecMedidas()
{
    return &mVecMedidas;
}

}
