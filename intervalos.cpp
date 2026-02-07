#include "funciones.h"
#include "intervalos.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int calcularClasesSturges(int n) {
    return static_cast<int>(1 + 3.322 * log10(n));
}

double calcularAmplitud(double rango, int clases) {

    return rango / clases;
}

vector <pair<double, double>> calcularIntervalos(const vector <double>&datos, double amplitud, int clases) {

vector <pair<double, double>> intervalos;

double  limInf = datos[0];

for(size_t i = 0; i < clases; i++) {

    double actualInf = limInf + i * amplitud;
    double actualSup = limInf + (i + 1) * amplitud;

    intervalos.push_back({actualInf, actualSup});
}

return intervalos;
}

void tablaDeFrecuenciasIntervalos(const vector <double>& datos,
                             const vector <pair<double, double>>& intervalos,
                             vector <int>& frecuencias,
                             vector <int> & frecuenciaAcumulada,
                             vector<double>& frecuenciaRelativa,
                             vector<double>& frecuenciaRP,
                             vector <double>& frecuenciaRA) {

    // Recorremos cada intervalo
for (size_t i = 0; i < intervalos.size(); i++) {

    double limInf = intervalos[i].first;
    double limSup = intervalos[i].second;
    int freq = 0;

    for (double dato : datos) {

       if (i == intervalos.size() - 1) {
    if (dato >= limInf && dato <= limSup)
        freq++;
} else {
    if (dato >= limInf && dato < limSup)
        freq++;
}

    }

    frecuencias.push_back(freq);
}

int acumulada = 0;

    for (size_t i = 0; i < frecuencias.size(); i++) {

        frecuenciaAcumulada.push_back(acumulada += frecuencias[i]);
}
    for(size_t i = 0; i < frecuencias.size(); i++){

        frecuenciaRelativa.push_back((double)frecuencias[i] / datos.size());

}
    for(size_t i = 0; i < frecuencias.size(); i++) {

        frecuenciaRP.push_back(frecuenciaRelativa[i] * 100);

        }

    frecuenciaRA.push_back(frecuenciaRelativa[0]);

    for(size_t i = 1; i < frecuenciaRelativa.size(); i++) {

         frecuenciaRA.push_back(frecuenciaRA[i - 1] + frecuenciaRelativa [i]);

         }


}


vector<double> calcularPuntosMedios(const vector<pair<double,double>>& intervalos) {
    vector<double> valores;

    for (const pair<double,double>& intervalo : intervalos) {
        double limInf = intervalo.first;
        double limSup = intervalo.second;

        double puntoMedio = (limInf + limSup) / 2.0;
        valores.push_back(puntoMedio);
    }

    return valores;
}

double clasesPorFrecuencias(const vector <double>& valores,
                            const vector <int>& frecuencias) {

 double clasesXFrecuencias = 0;

for (size_t i = 0; i < frecuencias.size(); i++) {

    clasesXFrecuencias +=  frecuencias [i] * valores[i];

}
return clasesXFrecuencias;
}


double mediaIntervalos (const vector <int> & frecuencias,
                        double clasesXfrecuencias) {
    int fTotales = 0;

    for (size_t i = 0; i < frecuencias.size(); i++) {

       fTotales += frecuencias [i];

    }
    return clasesXfrecuencias / fTotales;

}
double calcularMediaIntervalos (const vector <pair<double, double>>& intervalos,
                                const vector <int>& frecuencias){

            vector <double> puntosMedios = calcularPuntosMedios(intervalos);

            double suma = clasesPorFrecuencias(puntosMedios, frecuencias);

            return mediaIntervalos(frecuencias, suma);
            }

double calcularMedianaIntervalos(const vector <pair<double, double>>& intervalos,
                                const vector <int>& frecuencias,
                                const vector <int> & frecuenciaAcumulada,
                                double amplitud) {

double medianaIntervalos = 0;

double ultimaP = frecuenciaAcumulada.back() / 2;

for(size_t i = 0; i < frecuenciaAcumulada. size(); i++) {


if(ultimaP <= frecuenciaAcumulada[i]) {

    if(i > 0) {

    medianaIntervalos = intervalos[i].first + ((ultimaP - frecuenciaAcumulada[i-1]) / frecuencias[i]) * amplitud;

    }

    if(i == 0) {

      medianaIntervalos = intervalos[i].first + (ultimaP / frecuencias[i]) * amplitud;

    }

    break;
    }

}
return medianaIntervalos;
}

double calcularModaIntervalos(const vector<double>& datos, const vector<int>& frecuencias) {

    int indiceModa = 0;

    int bajada = 0;

    int subida = 0;

    double proporcion = 0;



    int frecuenciaMaxima = frecuencias[0];

    for (size_t i = 1; i < frecuencias.size(); i++) {
        if (frecuencias[i] > frecuenciaMaxima) {
            frecuenciaMaxima = frecuencias[i];
            indiceModa = i;
        }
    }
    if (indiceModa > 0 && indiceModa < frecuencias.size() - 1) {
    // tiene subida y bajada
    }
    else if (indiceModa == 0) {
        // solo bajada

        bajada = frecuencias[indiceModa + 1] - frecuencias[indiceModa];

        proporcion = subida / (subida + bajada);

        modaIntervalos = intervalos[0].first + proporcion * amplitud;
    }
    else {
    // solo subids
        bajada = frecuencias[indiceModa - 1] - frecuencias[indiceModa];

            proporcion = subida / (subida + bajada);

        modaIntervalos = intervalos[0].first + proporcion * amplitud;
}

    return modaIntervalos;
}


void mostrarInfoIntervalos(double rango, int clases, double amplitud) {

    cout << "--------------------------------------------------------------------------------\n";

    cout << "Rango: " << rango << "\n";

    cout << "Clases: " << clases << "\n";

    cout << "Amplitud (Sturges): " << amplitud << "\n";
}

void valos (double moda,
            double mediana,
            double media,
const vector <pair<double, double>>& intervalos,
                             vector <int>& frecuencias,
                             vector <int> & frecuenciaAcumulada,
                             vector<double>& frecuenciaRelativa,
                             vector<double>& frecuenciaRP,
                             vector <double>& frecuenciaRA) {


    cout << "\n";
    cout << "-------------------------------INTERVALOS----------------------------------------\n";

    for(size_t i = 0; i < intervalos.size(); i++) {

    cout << "[" <<intervalos[i].first << ", " << intervalos[i].second << "]\n";

}
    cout << "\n\n";
    cout << "---------------------------TABLA DE FRECUENCIAS------------------------------------\n\n";

        cout << " x | fi | fa | fr | fr% | fra\n";


        cout << "[" <<intervalos[0].first << ", " << intervalos[0].second << "]" << " | " << frecuencias[0] << " | "  << frecuenciaAcumulada[0] << " | ";
        cout << frecuenciaRelativa[0] << " | " << frecuenciaRP[0] << "%" << " | " << frecuenciaRA[0] << "\n";

        for(size_t i = 1; i < frecuencias.size(); i++) {

        cout << "[" <<intervalos[i].first << ", " << intervalos[i].second << "]" << " | " << frecuencias[i] << " | "  << frecuenciaAcumulada[i] << " | ";
        cout << frecuenciaRelativa[i] << " | " << frecuenciaRP[i]<< "%" << " | " << frecuenciaRA[i] << "\n";
        }

    cout << "-------------------------MEDIDAS DE TENDENCIA------------------------------------\n";

    cout << "Media: "<< media << "\n";
    cout << "Mediana: " << mediana << "\n";
    cout << "Moda: " << moda << "\n";

    cout << "-------------------------MEDIDAS DE DISPERSION-----------------------------------\n";

    cout << "Rango: " << "\n";
    cout << "Varianza Poblacional: " << "\n";
    cout << "Varianza Muestral: " << "\n";
    cout << "Desvío Poblacional: " << "\n";
    cout << "Desvío Muestral: " << "\n";
    cout << "CV poblacional: " << "\n";
    cout << "CV muestral: " << "\n";

    cout << "-----------------------------------------------------------------------------------\n";
}



