#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

int color;


using namespace std;
static int varX, varY = 10;
void cambiar_color()
{
    switch (color)
    {
    case 1:
        printf("\33[0;34m"); break;
    case 2:
        printf("\33[0;31m"); break;
    case 3:
        printf("\33[0;33m"); break;
    case 4:
        printf("\33[0;32m"); break;
    }
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void coordenadas(int& varX, int& varY) {
    gotoxy(100, 0);
    cout << "                    " << endl;
    gotoxy(100, 0);
    cout << "Coordenadas: " << varX << "," << varY << endl;
}

void comparar_seleccion(string comando, int num) {
    int res;
    res = toupper(comando.compare("MOVR"));
    if (res == 0) {
        int var;

        _asm
        {
            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx

            mov eax, varX
            mov ebx, num

            add ecx, eax
            add ecx, ebx
            mov edx, ecx
            mov var, edx

            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx
        }

        int verificador = 0;

        _asm
        {
            cmp var, 112
            ja nmayor
            jmp nmenor

            nmayor :
            xor eax, eax
                add eax, 01
                mov verificador, eax
                xor eax, eax
                jmp nextt

                nmenor :
            xor eax, eax
                mov verificador, eax
                jmp nextt


                nextt :
            cmp num, 3
                jb azul

                cmp num, 6
                jb rojo

                cmp num, 9
                jb amarillo

                cmp num, 10
                jae verde

                azul :
            mov color, 1
                jmp continuar

                rojo :
            mov color, 2
                jmp continuar

                amarillo :
            mov color, 3
                jmp continuar

                verde :
            mov color, 4
                jmp continuar

                continuar :
        }


        cambiar_color();
        /*cout << verificador << endl;
        cout << var << endl;*/
        system("pause");
        if (verificador > 0) {
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
        int var; //varY + num;


        _asm
        {
            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx

            mov eax, varY
            mov ebx, num

            add ecx, eax
            add ecx, ebx
            mov edx, ecx
            mov var, edx

            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx
        }

        int verificador = 0;

        _asm
        {
            cmp var, 28
            ja nmayor2
            jmp nmenor2

            nmayor2 :
            xor eax, eax
                add eax, 01
                mov verificador, eax
                xor eax, eax
                jmp nextt2
                
                nmenor2 :
            xor eax, eax
                mov verificador, eax
                jmp nextt2
                
                nextt2 :
                cmp num, 3
                jb azul2

                cmp num, 6
                jb rojo2

                cmp num, 9
                jb amarillo2

                cmp num, 10
                jae verde2

                azul2 :
            mov color, 1
                jmp continuar2

                rojo2 :
            mov color, 2
                jmp continuar2

                amarillo2 :
            mov color, 3
                jmp continuar2

                verde2 :
            mov color, 4
                jmp continuar2

                continuar2 :
        }


        cambiar_color();

        if (verificador > 0) {
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
        int var; //= varX - num;


        _asm
        {
            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx

            mov eax, varX
            mov ebx, num

            add ecx, eax
            add ecx, ebx
            mov edx, ecx
            mov var, edx

            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx
        }

        int verificador = 0;

        _asm
        {
            cmp var, 10
            ja nmayor3
            jmp nmenor3

            nmayor3 :
            xor eax, eax
                add eax, 01
                mov verificador, eax
                xor eax, eax
                jmp nextt3

                nmenor3 :
            xor eax, eax
                mov verificador, eax
                jmp nextt3

                nextt3:
                cmp num, 3
                jb azul3

                cmp num, 6
                jb rojo3

                cmp num, 9
                jb amarillo3

                cmp num, 10
                jae verde3

                azul3 :
            mov color, 1
                jmp continuar3

                rojo3 :
            mov color, 2
                jmp continuar3

                amarillo3 :
            mov color, 3
                jmp continuar3

                verde3 :
            mov color, 4
                jmp continuar3

                continuar3 :
        }

        cambiar_color();

        if (verificador > 0) {
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
        int var; //= varY - num;





        _asm
        {
            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx

            mov eax, varY
            mov ebx, num

            add ecx, eax
            add ecx, ebx
            mov edx, ecx
            mov var, edx

            xor eax, eax
            xor ebx, ebx
            xor ecx, ecx
            xor edx, edx
        }

        int verificador = 0;

        _asm
        {
            cmp var, 10
            ja nmayor4
            jmp nmenor4

            nmayor4 :
            xor eax, eax
                add eax, 01
                mov verificador, eax
                xor eax, eax
                jmp nextt4
                
                nmenor4 :
            xor eax, eax
                mov verificador, eax
                jmp nextt4

                nextt4 :
                cmp num, 3
                jb azul4

                cmp num, 6
                jb rojo4

                cmp num, 9
                jb amarillo4

                cmp num, 10
                jae verde4

                azul4 :
            mov color, 1
                jmp continuar4

                rojo4 :
            mov color, 2
                jmp continuar4

                amarillo4 :
            mov color, 3
                jmp continuar4

                verde4 :
            mov color, 4
                jmp continuar4

                continuar4 :
        }




        cambiar_color();

        if (verificador > 0) {
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
    bool com = true;
    if (res == 0 || res2 == 0) {
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
    system("cls");
    Menu();
    string beffa;
    bool res;
    int resu = 1;
    do {
        coordenadas(varX, varY);
        gotoxy(0, 9);
        cout << "                                                    " << endl;
        gotoxy(0, 8);
        getline(cin, beffa);
        resu = toupper(beffa.compare("q"));
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