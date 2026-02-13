#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>
using namespace std;

int leerEntero();

bool esValido(int n, int min, int max);

int totalDatos();

double leerDato(int i);

vector<double> ingresarDatos(int cantidad);

int pedirDecimales();

void aplicarDecimales(int decimales);

void tablaDeFrecuencias
(
 const vector<double>& datos,
 vector <double>& valores,
 vector <int>& frecuencias,
 vector <int>& frecuenciaAcumulada,
 vector <double>& frecuenciaRelativa,
 vector <double>& frecuenciaRP,
 vector <double>& frecuenciaRA
 );
//  MEDIDAS DE TENDENCIA
//-------------------------

double calcularMedia(const vector<double>& datos);

double calcularMediana(const vector<double>& datos);

double calcularModa(const vector<double>& datos, const vector<int>& frecuencias);

//  MEDIDAS DE VARIACIÓN
//-------------------------

double calcularRango(const vector<double>& datos);

double calcularVarianzaPoblacional(const vector<double>& datos);

double calcularVarianzaMuestral(const vector<double>& datos);

double calcularDesvioPoblacional(const vector<double>& datos);

double calcularDesvioMuestral(const vector<double>& datos);

double CVpoblacional (const vector <double>& datos);

double CVmuestral (const vector <double>& datos);

string interpretacionCV (double CV);

struct resultadosEstadisticos {
    double rangoDatos;
    double clases;
    double amplitud;
    string interpretacionCVp;
    string interpretacionCVm;
    double cvP;
    double cvM;
    double desvioP;
    double desvioM;
    double varianzaM;
    double varianzaP;
    double rango;
    double moda;
    double media;
    double mediana;
    vector <pair<double, double>> intervalos;
    vector<double> datos;
    vector<double> marcasDeClase;
    vector<int> frecuencias;
    vector<int> frecuenciaAcumulada;
    vector<double> frecuenciaRelativa;
    vector<double> frecuenciaRP;
    vector<double> frecuenciaRA;
};

//  MOSTRAR RESULTADOS
//-------------------------

void mostrarResultados(const resultadosEstadisticos& r);

#endif
