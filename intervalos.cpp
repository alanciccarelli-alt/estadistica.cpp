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
    vector<double> marcasDeClase;

    for (const pair<double,double>& intervalo : intervalos) {
        double limInf = intervalo.first;
        double limSup = intervalo.second;

        double puntoMedio = (limInf + limSup) / 2.0;
        marcasDeClase.push_back(puntoMedio);
    }

    return marcasDeClase;
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

size_t indiceIntervaloMediana(const vector<int>& frecuenciaAcumulada) {
    double mitad = frecuenciaAcumulada.back() / 2;
    for(size_t i = 0; i < frecuenciaAcumulada.size(); i++) {
        if(mitad <= frecuenciaAcumulada[i]) return i;
    }
    return frecuenciaAcumulada.size() - 1; // fallback
}

double calcularMedianaIntervalos(
    const vector<pair<double, double>>& intervalos,
    const vector<int>& frecuencias,
    const vector<int>& frecuenciaAcumulada,
    double amplitud)
{
    size_t i = indiceIntervaloMediana(frecuenciaAcumulada);
    double ultimaP = frecuenciaAcumulada.back() / 2;

    if(i == 0) return intervalos[i].first + (ultimaP / frecuencias[i]) * amplitud;
    return intervalos[i].first + ((ultimaP - frecuenciaAcumulada[i-1]) / frecuencias[i]) * amplitud;
}


size_t encontrarIndiceModal(const vector<int>& frecuencias) {

    int indiceModa = 0;

    int frecuenciaMaxima = frecuencias[0];

    // Encontrar el índice del intervalo modal
    for (size_t i = 1; i < frecuencias.size(); i++) {
        if (frecuencias[i] > frecuenciaMaxima) {
            frecuenciaMaxima = frecuencias[i];
            indiceModa = i;
        }
    }
    return indiceModa;
}

double calcularProporcion(const vector<int>& frecuencias,
                          int indiceModa) {

    int subida = 0;

    int bajada = 0;

    double proporcion = 0;

    // Calcular subida y bajada según la posición
    if (indiceModa > 0 && indiceModa < frecuencias.size() - 1) {
        // intervalo modal en el medio
        subida = frecuencias[indiceModa] - frecuencias[indiceModa - 1];
        bajada = frecuencias[indiceModa] - frecuencias[indiceModa + 1];
    }
    else if (indiceModa == 0) {
        // primer intervalo → solo bajada
        subida = frecuencias[indiceModa];
        bajada = frecuencias[indiceModa] - frecuencias[indiceModa + 1];
    }
    else {
        // último intervalo → solo subida
        subida = frecuencias[indiceModa] - frecuencias[indiceModa - 1];
        bajada = frecuencias[indiceModa];
    }

    proporcion = subida / static_cast<double>(subida + bajada);


    return proporcion;
}

double calcularModaIntervalos (const vector <pair<double, double>>& intervalos,
                               const vector<int>& frecuencias,
                               double amplitud) {

    int indiceModa = encontrarIndiceModal(frecuencias);

    double proporcion = calcularProporcion(frecuencias, indiceModa);

    return intervalos[indiceModa].first + proporcion * amplitud;

}

//     RANGO (MEDIDA DE DISPERSION)
// -------------------------------------

double rangoDispersion(const vector<pair<double, double>>& intervalos) {

    if(intervalos.empty()) return 0.0; // chequeo de seguridad

    return intervalos.back().second - intervalos[0].first;
}


double calcularVarianzaPoblacionalIntervalos(const vector<double>& valores,
                                             const vector<int>& frecuencias,
                                             double media,
                                             const vector<int>& frecuenciaAcumulada) {

    double varianzaP = 0;

    double suma = 0;

    for (size_t i = 0; i < valores.size(); i++) {
        suma += pow(valores[i] - media, 2) * frecuencias[i];
    }

    return varianzaP = suma / frecuenciaAcumulada.back();

}

double calcularVarianzaMuestralIntervalos(const vector<double>& valores,
                                             const vector<int>& frecuencias,
                                             double media,
                                             const vector<int>& frecuenciaAcumulada) {

    double varianzaM = 0;

    double suma = 0;

    for (size_t i = 0; i < valores.size(); i++) {
        suma += pow(valores[i] - media, 2) * frecuencias[i];
    }

    return varianzaM = suma / (frecuenciaAcumulada.back() - 1);

}

double calcularDesvioPoblacionalIntervalos(double varianzaP) {

    return sqrt(varianzaP);

}

double calcularDesvioMuestralIntervalos(double varianzaM) {

    return sqrt(varianzaM);

}

// COEFICIENTE DE VARIACION PONBLACIONAL
// -------------------------------------

double CVpoblacionalIntervalos(double desvioP, double media) {

double CV = desvioP / media;

return CV * 100;

}

// COEFICIENTE DE VARIACION MUESTRAL
// ---------------------------------

double CVmuestralIntervalos(double desvioM, double media) {

double CV = desvioM / media;

return CV * 100;

}

void valos (const resultadosEstadisticos& r) {

    cout << "--------------------------------------------------------------------------------\n";

    cout << "Rango (datos): " << r.rango << "\n";

    cout << "Clases: " << r.clases << "\n";

    cout << "Amplitud (Sturges): " << r.amplitud << "\n";

    cout << "\n";
    cout << "-------------------------------INTERVALOS----------------------------------------\n";

    cout << "\n";

    for(size_t i = 0; i < r.intervalos.size(); i++) {

    cout << "[" <<r.intervalos[i].first << ", " << r.intervalos[i].second << "]\n";

}
    cout << "\n";


    cout << "---------------------------TABLA DE FRECUENCIAS------------------------------------\n\n";

        cout << " marcas de clase | fi | fa | fr | fr% | fra\n\n";

        cout << r.marcasDeClase[0] << " | " << r.frecuencias[0] << " | "  << r.frecuenciaAcumulada[0] << " | ";
        cout << r.frecuenciaRelativa[0] << " | " << r.frecuenciaRP[0] << "%" << " | " << r.frecuenciaRA[0] << "\n";

        for(size_t i = 1; i < r.frecuencias.size(); i++) {

        cout << r.marcasDeClase[i] << " | " << r.frecuencias[i] << " | "  << r.frecuenciaAcumulada[i] << " | ";
        cout << r.frecuenciaRelativa[i] << " | " << r.frecuenciaRP[i]<< "%" << " | " << r.frecuenciaRA[i] << "\n\n";
        }

    cout << "------------------------------HISTOGRAMA---------------------------------------\n\n";

        for (size_t i = 0; i < r.clases; i++) {

    cout << "[" << r.intervalos[i].first << ", " << r.intervalos[i].second << "] ";

        for (int j = 0; j < r.frecuencias[j]; j++) {
            cout << ">";
        }

        cout << " (" << r.frecuencias[i] << ")\n";

}

cout << "\n\n";

    cout << "-------------------------MEDIDAS DE TENDENCIA------------------------------------\n";

    cout << "Media: "<< r.media << "\n";
    cout << "Mediana: " << r.mediana << "\n";
    cout << "Moda: " << r.moda << "\n";

    cout << "-------------------------MEDIDAS DE DISPERSION-----------------------------------\n";

    cout << "Rango: " << r.rango << "\n";
    cout << "Varianza Poblacional: "<< r.varianzaP << "\n";
    cout << "Varianza Muestral: " << r.varianzaM << "\n";
    cout << "Desvío Poblacional: " << r.desvioP << "\n";
    cout << "Desvío Muestral: " << r.desvioM << "\n";
    cout << "CV poblacional: " << r.cvP << "% : " << r.interpretacionCVp << "\n";
    cout << "CV muestral: " << r.cvM << "% : " << r.interpretacionCVm << "\n";

    cout << "-----------------------------------------------------------------------------------\n";
}



