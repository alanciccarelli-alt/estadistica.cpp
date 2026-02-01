#include <string>
#include <iostream>
#include <iomanip>

#include "funciones.h"
#include "intervalos.h"

using namespace std;

int main() {

    int opcion = 0;


    do {
        cout << "-------------------------CALCULADORA: ESTADISTICA DESCRIPTIVA---------------------\n\n";


        cout << "1 - Dato individuales\n\n";

        cout << "2 - Cálculo de intervalos\n\n";


        cout << "----------------------------------------------------------------------------------\n\n";

        cout << "3 - Salir\n";

        cout << "----------------------------------------------------------------------------------\n\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "\n";

        switch (opcion) {

        case 1: {


            int cantidad = totalDatos();


            vector <double> valores;
            vector <int> frecuencias;
            vector <double> frecuenciaAcumulada;
            vector <double> frecuenciaRelativa;
            vector <double> frecuenciaRP;
            vector <double> frecuenciaRA;
            vector <double> datos = ingresarDatos(cantidad);

            mostrarDecimales();

            tablaDeFrecuencias(
            datos,
            valores,
            frecuencias,
            frecuenciaAcumulada,
            frecuenciaRelativa,
            frecuenciaRP,
            frecuenciaRA);

            double media = calcularMedia(datos);
            double mediana = calcularMediana (datos);
            double moda = calcularModa(datos, frecuencias);

            double rango = calcularRango(datos);
            double varianzaP = calcularVarianzaPoblacional(datos);
            double varianzaM = calcularVarianzaMuestral(datos);
            double desvioP = calcularDesvioPoblacional(datos);
            double desvioM = calcularDesvioMuestral(datos);
            double cvP = CVpoblacional(datos);
            double cvM = CVmuestral(datos);

            string interpretacionCVp = interpretacionCV(cvP);
            string interpretacionCVm = interpretacionCV(cvM);


            mostrarResultados(
            interpretacionCVp,
            interpretacionCVm,
            cvP,
            cvM,
            desvioP,
            desvioM,
            varianzaP,
            varianzaM,
            rango,
            moda,
            media,
            mediana,
            datos,
            valores,
            frecuencias,
            frecuenciaAcumulada,
            frecuenciaRelativa,
            frecuenciaRP,
            frecuenciaRA);


            break;
        }
         case 2: {

            int cantidad = totalDatos();

            vector<double> datos = ingresarDatos(cantidad);
            vector<double> valores;
            vector <pair<double, double>> intervalos;
            vector<int> frecuencias;
            vector<int> frecuenciaAcumulada;
            vector<double> frecuenciaRelativa;
            vector<double> frecuenciaRP;
            vector<double> frecuenciaRA;

            double rango = calcularRango(datos);

            int clases = calcularClasesSturges(datos.size());

            double amplitud = calcularAmplitud(rango, clases);


            mostrarDecimales();

            intervalos = calcularIntervalos(
            datos,
            amplitud,
            clases);

            tablaDeFrecuenciasIntervalos(
            datos,
            intervalos,
            frecuencias,
            frecuenciaAcumulada,
            frecuenciaRelativa,
            frecuenciaRP,
            frecuenciaRA);

            double media = calcularMediaIntervalos(intervalos, frecuencias);
            double mediana = calcularMedianaIntervalos(intervalos, frecuencias, frecuenciaAcumulada, amplitud);
            double moda = calcularModaIntervalos(datos, frecuencias);

            valos(
            moda,
            mediana,
            media,
            intervalos,
            frecuencias,
            frecuenciaAcumulada,
            frecuenciaRelativa,
            frecuenciaRP,
            frecuenciaRA);


            break;
}

        case 3:

            cout << "Saliendo...";

            break;

        default:

            cout << "----------------------------------------------------------------------------------\n\n";

            cout << "Opcion no valida (" << opcion << ").\n\n";
        }

    } while (opcion != 3);

    return 0;
}
