#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función para leer el saldo actual desde el archivo
double leerSaldo() {
    double saldo = 0.0;
    ifstream archivo("billetera.txt");
    if (archivo.is_open()) {
        archivo >> saldo;
        archivo.close();
    }
    return saldo;
}

// Función para escribir el saldo actual en el archivo
void escribirSaldo(double saldo) {
    ofstream archivo("billetera.txt");
    if (archivo.is_open()) {
        archivo << saldo;
        archivo.close();
    }
}

void deposito() {
    double importe;
    cout << "Ingrese el importe a depositar: ";
    cin >> importe;

    double saldoActual = leerSaldo();
    saldoActual += importe;
    escribirSaldo(saldoActual);

    cout << "Depósito realizado. Saldo actual: " << saldoActual << endl;
}

void extraccion() {
    double importe;
    cout << "Ingrese el importe a extraer: ";
    cin >> importe;

    double saldoActual = leerSaldo();
    if (importe <= saldoActual) {
        saldoActual -= importe;
        escribirSaldo(saldoActual);
        cout << "Extracción realizada. Saldo actual: " << saldoActual << endl;
    } else {
        cout << "Saldo insuficiente" << endl;
    }
}

void transferencia() {
    double importe;
    string numeroCelular;

    cout << "Ingrese el importe a transferir: ";
    cin >> importe;
    cout << "Ingrese el número de celular del destinatario: ";
    cin >> numeroCelular;

    double saldoActual = leerSaldo();
    if (importe <= saldoActual) {
        saldoActual -= importe;
        escribirSaldo(saldoActual);
        cout << "Transferencia realizada a " << numeroCelular << ". Saldo actual: " << saldoActual << endl;
    } else {
        cout << "Saldo insuficiente" << endl;
    }
}

int main() {
    char opcion;

    while (true) {
        cout << "Seleccione una opción: " << endl;
        cout << "D - Depósito" << endl;
        cout << "E - Extracción" << endl;
        cout << "T - Transferencia" << endl;
        cout << "Q - Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 'D':
            case 'd':
                deposito();
                break;
            case 'E':
            case 'e':
                extraccion();
                break;
            case 'T':
            case 't':
                transferencia();
                break;
            case 'Q':
            case 'q':
                cout << "Saliendo..." << endl;
                return 0;
            default:
                cout << "Opción no válida, intente de nuevo." << endl;
        }
    }

    return 0;
}
