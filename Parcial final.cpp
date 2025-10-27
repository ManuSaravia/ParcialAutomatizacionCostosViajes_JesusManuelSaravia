// Parcial final.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
using namespace std;

double verificarDatos(string mensaje) {
    double valor;
    do {
        cout << mensaje;
        cin >> valor;

        if (valor < 0) {
            cout << "No se aceptan números negativos. Error";
        }
    } while (valor < 0);

    return valor;
}

double CalculodeTotal(double distancias[], double costos[], int numeroViajes) {
    double total = 0;
    for (int i = 0; i < numeroViajes; i++) {
        total += distancias[i] * costos[i];
    }
    return total;
}

double Distanciapromedio(double distancias[], int numeroViajes) {
    double suma = 0;
    for (int i = 0; i < numeroViajes; i++) {
        suma += distancias[i];
    }
    return suma / numeroViajes;
}

int main() {
    int Conductores, numeroViajes;
    string nombres[10], conductormejor;
    double distancias[10], costos[10], totales[10], promedios[10];
    double ingresomayor;

    cout << "Ingrese la cantidad de conductores (Tope: 10): ";
    cin >> Conductores;

    if (Conductores > 10) {
        cout << "El numero maximo de conductores es 10. Error." << endl;
        return 0;
    }

    for (int i = 0; i < Conductores; i++) {
        cout << "\n=== CONDUCTOR #" << i + 1 << " ===" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];

        cout << "Ingrese el numero de viajes (Tope: 10): ";
        cin >> numeroViajes;

        if (numeroViajes > 10) {
            cout << "Error: El número máximo de viajes es 10." << endl;
            return 0;
        }

        for (int j = 0; j < numeroViajes; j++) {
            cout << "\n--- Viaje #" << j + 1 << " ---" << endl;
            distancias[j] = verificarDatos("Distancia en kilometros: ");
            costos[j] = verificarDatos("Costo por kilometro ($): ");
        }

        totales[i] = CalculodeTotal(distancias, costos, numeroViajes);
        promedios[i] = Distanciapromedio(distancias, numeroViajes);
    }


    cout << "\n========== RESUMEN DE VIAJES ==========\n";
    cout << "Conductor\tTotal Ganado ($)\tPromedio Distancia (km)\n";

    ingresomayor = totales[0];
    conductormejor = nombres[0];

    for (int i = 0; i < Conductores; i++) {
        cout << nombres[i] << "\t\t" << fixed << setprecision(2) << totales[i] << "\t\t" << fixed << setprecision(2) << promedios[i] << endl;

        if (totales[i] > ingresomayor) {
            ingresomayor = totales[i];
            conductormejor = nombres[i];
        }
    }

    cout << "\nEl conductor con mayor ingreso fue: "
        << conductormejor << " con $" << ingresomayor << endl;

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
