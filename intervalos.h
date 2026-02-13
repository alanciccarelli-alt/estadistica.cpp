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

size_t encontrarIndiceMediana(const vector<int>& frecuenciaAcumulada);

double calcularMedianaIntervalos(
    const vector<pair<double, double>>& intervalos,
    const vector<int>& frecuencias,
    const vector<int>& frecuenciaAcumulada,
    double amplitud);


vector<pair<double, double>> calcularIntervalos(
    const vector<double>& datos,
    double amplitud,
    int clases
);

size_t encontrarIndiceModal(const vector<int>& frecuencias);

double calcularProporcion(const vector<int>& frecuencias,
                          int indiceModa);

double calcularModaIntervalos (const vector <pair<double, double>>& intervalos,
                               const vector<int>& frecuencias,
                               double amplitud);

double rangoDispersion(const vector<pair<double, double>>& intervalos);

double calcularVarianzaPoblacionalIntervalos(const vector<double>& valores,
                                             const vector<int>& frecuencias,
                                             double media,
                                             const vector<int>& frecuenciaAcumulada);

double calcularVarianzaMuestralIntervalos(const vector<double>& valores,
                                             const vector<int>& frecuencias,
                                             double media,
                                             const vector<int>& frecuenciaAcumulada);

double calcularDesvioPoblacionalIntervalos(double varianzaP);

double calcularDesvioMuestralIntervalos(double varianzaM);

double CVpoblacionalIntervalos(double desvioP, double media);

double CVmuestralIntervalos(double desvioM, double media);

void tablaDeFrecuenciasIntervalos(const vector <double>& datos,
                             const vector <pair<double, double>>& intervalos,
                             vector <int>& frecuencias,
                             vector <int> & frecuenciaAcumulada,
                             vector<double>& frecuenciaRelativa,
                             vector<double>& frecuenciaRP,
                             vector <double>& frecuenciaRA);


void valos(const resultadosEstadisticos& r);
#endif
