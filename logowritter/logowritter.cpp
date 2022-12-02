// logowritter.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <sstream>

using namespace std;

    void gotoxy(int x, int y) {
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon, dwPos);
    }
    void separar_entrada(string cadena) {
        stringstream input_stringstream(cadena);                      // Convertir la cadena a un stream

        string comando, numero;
        // Extraer
        char delimitador = ' ';
        getline(input_stringstream, comando, delimitador);
        getline(input_stringstream, numero, delimitador);
        // Imprimir
        cout << "Comando: " << comando << endl;
        cout << "Numero: " << numero << endl;

    }
    void Movl() {

    }

    
    int main() {
        cout << "Use:" << endl;
        cout << "Movl" << endl;
        cout << "Movr" << endl;
        cout << "Movu" << endl;
        cout << "Movd" << endl;
        string beffa;
        getline(cin, beffa);
        cout << beffa << endl;
        separar_entrada(beffa+" ");
        return 0;
    }








