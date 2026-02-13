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


        cout << "1 - Datos individuales\n\n";

        cout << "2 - Calculo de intervalos\n\n";


        cout << "----------------------------------------------------------------------------------\n\n";

        cout << "3 - Salir\n";

        cout << "----------------------------------------------------------------------------------\n\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "\n";

        switch (opcion) {

case 1: {
    resultadosEstadisticos r;

    int cantidad = totalDatos();
    r.datos = ingresarDatos(cantidad);

    int dec = pedirDecimales();
    aplicarDecimales(dec);

    // Llenamos directamente los vectores dentro del struct
    tablaDeFrecuencias(
        r.datos,
        r.marcasDeClase,             // se llena dentro de la función
        r.frecuencias,
        r.frecuenciaAcumulada,
        r.frecuenciaRelativa,
        r.frecuenciaRP,
        r.frecuenciaRA
    );

    r.media = calcularMedia(r.datos);
    r.mediana = calcularMediana(r.datos);
    r.moda = calcularModa(r.datos, r.frecuencias);

    r.rango = calcularRango(r.datos);
    r.varianzaP = calcularVarianzaPoblacional(r.datos);
    r.varianzaM = calcularVarianzaMuestral(r.datos);
    r.desvioP = calcularDesvioPoblacional(r.datos);
    r.desvioM = calcularDesvioMuestral(r.datos);
    r.cvP = CVpoblacional(r.datos);
    r.cvM = CVmuestral(r.datos);

    r.interpretacionCVp = interpretacionCV(r.cvP);
    r.interpretacionCVm = interpretacionCV(r.cvM);

    mostrarResultados(r);

    break;
}

case 2: {

    resultadosEstadisticos r;

    // 1. Ingresar datos
    int cantidad = totalDatos();
    r.datos = ingresarDatos(cantidad);

    // 2. Pedir decimales
    int dec = pedirDecimales();
    aplicarDecimales(dec);

    // 3. Calcular rango, clases y amplitud
    r.rangoDatos = calcularRango(r.datos);
    r.clases = calcularClasesSturges(r.datos.size());
    r.amplitud = calcularAmplitud(r.rangoDatos, r.clases);

    // 4. Calcular intervalos
    r.intervalos = calcularIntervalos(r.datos, r.amplitud, r.clases);

    // 5. Calcular marcas de clase
    r.marcasDeClase = calcularPuntosMedios(r.intervalos);

    // 6. Tabla de frecuencias
    tablaDeFrecuenciasIntervalos(
        r.datos,
        r.intervalos,
        r.frecuencias,
        r.frecuenciaAcumulada,
        r.frecuenciaRelativa,
        r.frecuenciaRP,
        r.frecuenciaRA
    );

    // 7. Medidas estadísticas
    r.media = calcularMediaIntervalos(r.intervalos, r.frecuencias);
    r.mediana = calcularMedianaIntervalos(r.intervalos, r.frecuencias, r.frecuenciaAcumulada, r.amplitud);
    r.moda = calcularModaIntervalos(r.intervalos, r.frecuencias, r.amplitud);

    r.rango = rangoDispersion(r.intervalos);
    r.varianzaP = calcularVarianzaPoblacionalIntervalos(r.marcasDeClase, r.frecuencias, r.media, r.frecuenciaAcumulada);
    r.varianzaM = calcularVarianzaMuestralIntervalos(r.marcasDeClase, r.frecuencias, r.media, r.frecuenciaAcumulada);
    r.desvioP = calcularDesvioPoblacionalIntervalos(r.varianzaP);
    r.desvioM = calcularDesvioMuestralIntervalos(r.varianzaM);
    r.cvP = CVpoblacionalIntervalos(r.desvioP, r.media);
    r.cvM = CVmuestralIntervalos(r.desvioM, r.media);

    r.interpretacionCVp = interpretacionCV(r.cvP);
    r.interpretacionCVm = interpretacionCV(r.cvM);

    // 8. Mostrar resultados
    valos(r);

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
