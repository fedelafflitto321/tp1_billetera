#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funci�n para leer el saldo actual desde el archivo
double leerSaldo() {
    double saldo = 0.0;
    ifstream archivo("billetera.txt");
    if (archivo.is_open()) {
        archivo >> saldo;
        archivo.close();
    }
    return saldo;
}

// Funci�n para escribir el saldo actual en el archivo
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

    cout << "Dep�sito realizado. Saldo actual: " << saldoActual << endl;
}

void extraccion() {
    double importe;
    cout << "Ingrese el importe a extraer: ";
    cin >> importe;

    double saldoActual = leerSaldo();
    if (importe <= saldoActual) {
        saldoActual -= importe;
        escribirSaldo(saldoActual);
        cout << "Extracci�n realizada. Saldo actual: " << saldoActual << endl;
    } else {
        cout << "Saldo insuficiente" << endl;
    }
}

void transferencia() {
    double importe;
    string numeroCelular;

    cout << "Ingrese el importe a transferir: ";
    cin >> importe;
    cout << "Ingrese el n�mero de celular del destinatario: ";
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
        cout << "Seleccione una opci�n: " << endl;
        cout << "D - Dep�sito" << endl;
        cout << "E - Extracci�n" << endl;
        cout << "T - Transferencia" << endl;
        cout << "Q - Salir" << endl;
        cout << "Opci�n: ";
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
                cout << "Opci�n no v�lida, intente de nuevo." << endl;
        }
    }

    return 0;
}
