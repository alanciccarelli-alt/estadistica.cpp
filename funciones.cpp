#include "funciones.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

//         TOTAL DATOS
// --------------------------

int leerEntero() {
    int n;
    cin >> n;
    return n;
}

bool esValido(int n, int min, int max) {
    return n >= min && n <= max;
}

int totalDatos() {
    int n;

    cout << "----------------------------------------------------------------------------------\n";

    do {
        cout << "Ingrese la cantidad de datos: ";
        n = leerEntero();
        if (!esValido(n, 0, 20)) {
            cout << "Opción no válida (" << n << ").\n";
        }

    cout << "----------------------------------------------------------------------------------\n";

    } while (!esValido(n, 0, 20));
    return n;
}

//      INGRESAR DATOS
// --------------------------

double leerDato(int i) {

    double valor;

    cout << "Dato " << i + 1 << ": ";

    cin >> valor;

    return valor;
}

vector<double> ingresarDatos(int cantidad) {

    vector<double> datos(cantidad);

    for (size_t i = 0; i < cantidad; i++) {

        datos[i] = leerDato(i);
    }
    sort(datos.begin(), datos.end());
    return datos;
}


// MOSTRAR DECIMALES
// --------------------------

int pedirDecimales() {

    int dec;

    cout << "----------------------------------------------------------------------------------\n";

    do {
        cout << "Ingrese la cantidad de decimales a mostrar: ";
        cin >> dec;
        if (dec < 0 || dec > 6) {
            cout << "Opción no válida (" << dec << ").\n";
        }

    cout << "----------------------------------------------------------------------------------\n";

    } while (dec < 0 || dec > 6);
    return dec;
}

void aplicarDecimales(int decimales) {
    cout << fixed << setprecision(decimales);
}


//    TABLA DE FRECUENCIAS
// --------------------------

void tablaDeFrecuencias(const vector<double>& datos,
            vector <double>& marcasDeClase,
            vector <int>& frecuencias,
            vector <int>& frecuenciaAcumulada,
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

void mostrarResultados(const resultadosEstadisticos& r)

 {

    cout << "--------------------------------DATOS ORDENADOS-----------------------------------\n\n";

    for (size_t i = 0; i < r.datos.size(); i++) {

    cout << "- " << r.datos[i] << " ";

}

    cout << "\n\n";
    cout << "---------------------------TABLA DE FRECUENCIAS------------------------------------\n\n";

        cout << " x | fi | fa | fr | fr% | fra\n\n";

        cout << " " << r.marcasDeClase [0] << " | " << r.frecuencias[0] << " | "  << r.frecuenciaAcumulada[0] << " | ";
        cout << r.frecuenciaRelativa[0] << " | " << r.frecuenciaRP[0] << "%" << " | " << r.frecuenciaRA[0] << "\n";

        for(size_t i = 1; i < r.marcasDeClase.size(); i++) {

        cout << " " << r.marcasDeClase [i] << " | " << r.frecuencias[i] << " | "  << r.frecuenciaAcumulada[i] << " | ";
        cout << r.frecuenciaRelativa[i] << " | " << r.frecuenciaRP[i]<< "%" << " | " << r.frecuenciaRA[i] << "\n";

    }

    cout << "\n";

    cout << "---------------------------DIAGRAMA DE BARRAS------------------------------------\n\n";

        for (size_t i = 0; i < r.frecuencias.size(); i++) {

        cout << r.marcasDeClase[i] << " ";

        for (int j = 0; j < r.frecuencias[i]; j++) {
            cout << ">";
        }

        cout << " (" << r.frecuencias[i] << ")\n";

}


    cout << "\n\n";

    cout << "-------------------------MEDIDAS DE TENDENCIA------------------------------------\n";

    cout << "Media: " << r.media << "\n";
    cout << "Mediana: " << r.mediana << "\n";
    cout << "Moda: " << r.moda << "\n";

    cout << "-------------------------MEDIDAS DE DISPERSION-----------------------------------\n";

    cout << "Rango: " << r.rango << "\n";
    cout << "Varianza Poblacional: " << r.varianzaP << "\n";
    cout << "Varianza Muestral: " << r.varianzaM << "\n";
    cout << "Desvío Poblacional: " << r.desvioP << "\n";
    cout << "Desvío Muestral: " << r.desvioM << "\n";
    cout << "CV poblacional: " << r.cvP << "% : " << r.interpretacionCVp << "\n";
    cout << "CV muestral: " << r.cvM << "% : " << r.interpretacionCVm << "\n";

    cout << "-----------------------------------------------------------------------------------\n";
}
