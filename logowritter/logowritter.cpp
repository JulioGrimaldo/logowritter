#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>


using namespace std;

    void gotoxy(int x, int y) {
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon, dwPos);
    }
    void comparar_seleccion(string comando, string numero) {
        int res = toupper(comando.compare("movr"));
        if (res == 0) {
            int num = stoi(numero); //String to int 
            cout << "movr seleccionado"<<endl;
        }


    }
    bool separar_entrada(string cadena) {
        stringstream input_stringstream(cadena);                      

        string comando, numero;
        // Extraer
        char delimitador = ' ';
        getline(input_stringstream, comando, delimitador);
        getline(input_stringstream, numero, delimitador);
        // Imprimir
        int res = comando.compare("");
        int res2 = numero.compare("");
        bool com=true;
        if (res==0 || res2==0) {
            cout << "Formato incorrecto!!" << endl;
            com = false;
        }
        else {
            transform(comando.begin(), comando.end(), comando.begin(), ::toupper);
            comparar_seleccion(comando, numero);
            cout << "Comando: " << comando << endl;
            cout << "Numero: " << numero << endl;
        }
        
        return com;
    }
    void Menu() {
        cout << "Use:" << endl;
        cout << "Movl" << endl;
        cout << "Movr" << endl;
        cout << "Movu" << endl;
        cout << "Movd" << endl;
    }
    
    int main() {
        Menu();
        string beffa;
        
        bool res;
        do {
            getline(cin, beffa);
            res=separar_entrada(beffa);
        } while (res ==false);

        
        return 0;
    }








