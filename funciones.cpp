#include "funciones.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

//         TOTAL DATOS
// --------------------------

int totalDatos() {
    int n;

    do{

    cout << "----------------------------------------------------------------------------------\n";

    cout << "Ingrese la cantidad de datos: ";

    cin >> n;


    if(n < 0 || n > 6) {

    cout << "Opcion no valida (" << n << "), elija entre 0 y 20.\n";

    }

    }while(n > 20 || n < 0);
    return n;
}

//      INGRESAR DATOS
// --------------------------

vector<double> ingresarDatos(int cantidad) {

    vector<double> datos(cantidad);

    for (int i = 0; i < cantidad; i++) {
        cout << "----------------------------------------------------------------------------------\n\n";


        cout << "Dato " << i + 1 << ": ";

        cin >> datos[i];

    }
sort (datos.begin(), datos.end());

    return datos;
}

// MOSTRAR DECIMALES
// --------------------------

void mostrarDecimales(){


        int decimales;

    do{
        cout << "----------------------------------------------------------------------------------\n";

        cout << "Ingrese la cantidad de decimales a mostrar: ";

        cin >> decimales;

        cout << fixed << setprecision(decimales);

        if(decimales < 0 || decimales > 6) {

    cout << "Opcion no valida (" << decimales << "), elija entre 0 y 6.\n";


        }

    }while(decimales < 0 || decimales > 6);

}

//    TABLA DE FRECUENCIAS
// --------------------------

void tablaDeFrecuencias(const vector<double>& datos,
            vector <double>& marcasDeClase,
            vector <int>& frecuencias,
            vector <double>& frecuenciaAcumulada,
            vector <double>& frecuenciaRelativa,
            vector <double>& frecuenciaRP,
            vector <double>& frecuenciaRA) {

    double valorActual = datos[0];
    int frecuenciaActual = 1;



        for (int i = 1; i < datos.size(); i++) {

            double dato = datos[i];

            if (dato == valorActual) {
                frecuenciaActual++;
            } else {
                marcasDeClase.push_back(valorActual);
                frecuencias.push_back(frecuenciaActual);

                valorActual = dato;
                frecuenciaActual = 1;
            }
        }
        marcasDeClase.push_back(valorActual);
        frecuencias.push_back(frecuenciaActual);

        frecuenciaAcumulada.push_back(frecuencias[0]);

        for(size_t i = 1; i < frecuencias.size(); i++) {

        frecuenciaAcumulada.push_back(frecuenciaAcumulada[i - 1] + frecuencias [i]);

        }
        for(size_t i = 0; i < frecuencias.size(); i ++) {

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

//          MEDIA
// --------------------------

    double calcularMedia(const vector<double>& datos) {

    double suma = 0;

    for (double x : datos){suma += x;

    }

        return suma / datos.size();
    }


//          MEDIANA
// --------------------------

double calcularMediana(const vector<double>& datos) {

    int n = datos.size();
    int mid = n / 2;

    if (n % 2 == 0) {
        return (datos[mid - 1] + datos[mid]) / 2;
    } else {
        return datos[mid];
    }
}

//          MODA
// --------------------------

double calcularModa(const vector<double>& datos, const vector<int>& frecuencias) {
    int indiceModa = 0;
    int frecuenciaMaxima = frecuencias[0];

    for (size_t i = 1; i < frecuencias.size(); i++) {
        if (frecuencias[i] > frecuenciaMaxima) {
            frecuenciaMaxima = frecuencias[i];
            indiceModa = i;
        }
    }
    return datos[indiceModa];
}

//          RANGO
// --------------------------

double calcularRango(const vector<double>& datos) {
    double minimo = *min_element(datos.begin(), datos.end());
    double maximo = *max_element(datos.begin(), datos.end());
    return maximo - minimo;
}

//   VARIANZA POBLACIONAL
// --------------------------

double calcularVarianzaPoblacional(const vector <double>& datos) {

    vector <double> cuadrados;
    double media = calcularMedia(datos);
    double sumaCuadrados = 0;

    for(size_t i = 0; i < datos.size(); i++) {

    cuadrados.push_back((datos[i] - media) * (datos[i] - media));;

    }
    for(size_t i = 0; i < datos.size(); i++) {

    sumaCuadrados += cuadrados[i];

    }

    return sumaCuadrados / datos.size();

}

//   VARIANZA MUESTRAL
// --------------------------
double calcularVarianzaMuestral(const vector <double>& datos) {

    vector <double> cuadrados;
    double media = calcularMedia(datos);
    double sumaCuadrados = 0;

    for(size_t i = 0; i < datos.size(); i++) {

    cuadrados.push_back((datos[i] - media) * (datos[i] - media));;

    }
    for(size_t i = 0; i < datos.size(); i++) {

    sumaCuadrados += cuadrados[i];

    }

    return sumaCuadrados / (datos.size() -  1);

}


// DESVIO POBLACIONAL
// --------------------------
double calcularDesvioPoblacional(const vector<double>& datos) {

        double varianza = calcularVarianzaPoblacional(datos);

return sqrt(varianza);
}

// DESVIO MUESTRAL
// --------------------------

double calcularDesvioMuestral(const vector<double>& datos) {

double varianza = calcularVarianzaMuestral (datos);

return sqrt(varianza);
}

// COEFICIENTE DE VARIACION PONBLACIONAL
// -------------------------------------

double CVpoblacional (const vector <double>& datos) {

double CV = calcularDesvioPoblacional(datos) / calcularMedia(datos);

return CV * 100;

}

// COEFICIENTE DE VARIACION MUESTRAL
// ---------------------------------

double CVmuestral (const vector <double>& datos) {

double CV = calcularDesvioMuestral(datos) / calcularMedia(datos);

return CV * 100;

}

//
// ----------------------------------

string interpretacionCV (double CV) {

if (CV < 10) return "Muy representativo (menor al 10% - baja variabilidad)";
else if (CV < 20) return "Representativo aceptable (menor al 20% - variabilidad moderada)";
else if (CV < 30) return "Media poco representativa (menor al 30% - alta variabilidad)";
else return "No representativo (variabilidad muy alta)";

}

//        MOSTRAR RESULTADOS
// ----------------------------------
void mostrarResultados(
                       string interpretacionCVp,
                       string interpretacionCVm,
                       double cvP,
                       double cvM,
                    double desvioP,
                    double desvioM,
                    double varianzaM,
                    double varianzaP,
                       double rango,
                       double moda,
                       double media,
                      double mediana,
                      const vector<double>& datos,
                      vector<double>& marcasDeClase,
                      vector<int>& frecuencias,
                      vector<double>& frecuenciaAcumulada,
                      vector<double>& frecuenciaRelativa,
                      vector<double>& frecuenciaRP,
                      vector<double>& frecuenciaRA) {

    cout << "--------------------------------DATOS ORDENADOS-----------------------------------\n\n";

for (double x : datos) {
    cout << "- " << x << " ";

}

    cout << "\n\n";
    cout << "---------------------------TABLA DE FRECUENCIAS------------------------------------\n\n";

        cout << " x | fi | fa | fr | fr% | fra\n\n";

        cout << " " << marcasDeClase [0] << " | " << frecuencias[0] << " | "  << frecuenciaAcumulada[0] << " | ";
        cout << frecuenciaRelativa[0] << " | " << frecuenciaRP[0] << "%" << " | " << frecuenciaRA[0] << "\n";

        for(size_t i = 1; i < marcasDeClase.size(); i++) {

        cout << " " << marcasDeClase [i] << " | " << frecuencias[i] << " | "  << frecuenciaAcumulada[i] << " | ";
        cout << frecuenciaRelativa[i] << " | " << frecuenciaRP[i]<< "%" << " | " << frecuenciaRA[i] << "\n";

    }

    cout << "\n";

    cout << "---------------------------DIAGRAMA DE BARRAS------------------------------------\n\n";

int maxNivel = frecuencias[0];
for (int f : frecuencias) {
    if (f > maxNivel)
        maxNivel = f;
}

  for (int nivel = maxNivel; nivel >= 1; nivel--) {
    for (size_t i = 0; i < frecuencias.size(); i++) {
        if (frecuencias[i] >= nivel)
            cout << " O ";
        else
            cout << "   ";
    }

    cout << "\n";
}

    for(size_t i = 0; i < marcasDeClase.size(); i++) {

        cout << " " << marcasDeClase [i] <<  " ";

    }

    cout << "\n\n";

    cout << "-------------------------MEDIDAS DE TENDENCIA------------------------------------\n";

    cout << "Media: " << media << "\n";
    cout << "Mediana: " << mediana << "\n";
    cout << "Moda: " << moda << "\n";

    cout << "-------------------------MEDIDAS DE DISPERSION-----------------------------------\n";

    cout << "Rango: " << rango << "\n";
    cout << "Varianza Poblacional: " << varianzaP << "\n";
    cout << "Varianza Muestral: " << varianzaM << "\n";
    cout << "Desvío Poblacional: " << desvioP << "\n";
    cout << "Desvío Muestral: " << desvioM << "\n";
    cout << "CV poblacional: " << cvP << "% : " << interpretacionCVp << "\n";
    cout << "CV muestral: " << cvM << "% : " << interpretacionCVm << "\n";

    cout << "-----------------------------------------------------------------------------------\n";
}
