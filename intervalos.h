#ifndef INTERVALOS_H
#define INTERVALOS_H

#include <vector>
#include <utility>

using namespace std;

int calcularClasesSturges(int n);
double calcularAmplitud(double rango, int clases);

vector<double> calcularPuntosMedios(const vector<pair<double,double>>& intervalos);
double clasesPorFrecuencias(const vector <double>& valores,
                            const vector <int>& frecuencias);
double mediaIntervalos (const vector <int> & frecuencias,
                        double clasesXfrecuencias);
double calcularMediaIntervalos (const vector <pair<double, double>>& intervalos,
                                const vector <int>& frecuencias);

double calcularMedianaIntervalos(const vector <pair<double, double>>& intervalos,
                                const vector <int>& frecuencias,
                                const vector <int> & frecuenciaAcumulada,
                                double amplitud);

double calcularModaIntervalos(
    const vector<pair<double, double>>& intervalos,
    const vector<int>& frecuencias,
    double amplitud);

vector<pair<double, double>> calcularIntervalos(
    const vector<double>& datos,
    double amplitud,
    int clases
);

double calcularVarianzaPoblacionalIntervalos(const vector<double>& valores,
                                             const vector<int>& frecuencias,
                                             double media,
                                             const vector<int>& frecuenciaAcumulada);

void tablaDeFrecuenciasIntervalos(const vector <double>& datos,
                             const vector <pair<double, double>>& intervalos,
                             vector <int>& frecuencias,
                             vector <int> & frecuenciaAcumulada,
                             vector<double>& frecuenciaRelativa,
                             vector<double>& frecuenciaRP,
                             vector <double>& frecuenciaRA);


void valos(double varianzaP,
           double moda,
           double mediana,
           double media,
           const vector<double>& marcasDeClase,
const vector <pair<double, double>>& intervalos,
                             vector <int>& frecuencias,
                             vector <int> & frecuenciaAcumulada,
                             vector<double>& frecuenciaRelativa,
                             vector<double>& frecuenciaRP,
                             vector <double>& frecuenciaRA);
#endif
