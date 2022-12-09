#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>


using namespace std;
static int varX, varY = 10;
    void gotoxy(int x, int y) {
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon, dwPos);
    }
    void coordenadas(int &varX, int &varY) {
        gotoxy(100, 0);
        cout << "                    " << endl;
        gotoxy(100, 0);
        cout << "Coordenadas: " << varX << "," << varY<<endl;
    }
    void comparar_seleccion(string comando, int num) {
        int res;
        res = toupper(comando.compare("MOVR"));
        if (res == 0) {
            int var = varX + num;
            if (var > 112) {
                gotoxy(0, 8);
                cout << "Numero fuera de rango" << endl;
                system("pause");
            }
            else {
            for (int i = 0; i < num; i++) {

                coordenadas(varX, varY);
                gotoxy(varX, varY);
                cout << "*";
                varX++;
            }
        }
        }
        res = toupper(comando.compare("MOVD"));
        if (res == 0) {
            int var = varY + num;
            if (var > 28) {
                gotoxy(0, 8);
                cout << "Numero fuera de rango" << endl;
                system("pause");
            }
            else {
            for (int i = 0; i < num; i++) {
                coordenadas(varX, varY);
                gotoxy(varX, varY);
                cout << "*";
                varY++;
            }
        }
        }
        res = toupper(comando.compare("MOVL"));
        if (res == 0) {
            int var = varX - num;
            if (var < 10) {
                gotoxy(0, 8);
                cout << "Numero fuera de rango" << endl;
                system("pause");
            }
            else {
                for (int i = 0; i < num; i++) {
                    coordenadas(varX, varY);
                    gotoxy(varX, varY);
                    cout << "*";
                    varX--;
                }
            }
        }
        res = toupper(comando.compare("MOVU"));
        if (res == 0) {
            int var = varY - num;
            if (var < 10) {
                gotoxy(0, 8);
                cout << "Numero fuera de rango" << endl;
                system("pause");
            }
            else {
                for (int i = 0; i < num; i++) {
                    coordenadas(varX, varY);
                    gotoxy(varX, varY);
                    cout << "*";
                    varY--;
                }
            }
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
            int num = stoi(numero);
            comparar_seleccion(comando, num);
        }
        return com;
    }

    void Menu() {
        cout << "Comandos:" << endl;
        cout << "Movl" << endl;
        cout << "Movr" << endl;
        cout << "Movu" << endl;
        cout << "Movd" << endl;
        cout << "q Para salir" << endl;
        cout << "Utilice la siguiente estructura <comando>, <num>." << endl;
    }
    
    int main() {
        Menu();
        string beffa;
        bool res;
        int resu=1;
        do {
            coordenadas(varX, varY);
            gotoxy(0, 9);
            cout << "                                                    " << endl;
            gotoxy(0, 8);
            getline(cin, beffa);
             resu= toupper(beffa.compare("q"));
            if (resu == 0) {
            }
            else {

                do {
                    res = separar_entrada(beffa);
                } while (res == false);
            }
            gotoxy(0, 8);
            cout << "                       " << endl;
            } while (resu != 0);
            
    return 0;
    }