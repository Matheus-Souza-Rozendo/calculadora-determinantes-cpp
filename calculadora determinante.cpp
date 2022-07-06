#include <bits/stdc++.h>
#include "Matriz.h"
#include "leitura_dados.h"

using namespace std;



int main(){
//setar localidade
setlocale(LC_ALL, "Portuguese");

//declaração de variaveis
Matriz *M = new Matriz();
int op,tamanho;
float **matriz;


leitura_tamanho: // ler o tamanho da matriz
system("cls");
cout << "Digite o tamanho da Matriz\nO programa aceita apenas matrizes 2x2 e 3x3\n tamanho: ";
tamanho =  ler_numeros_reais();
cout << endl;
if(M->set_tamanho(tamanho)){

    //lendo a matriz passada pelo usuario
    cout << "Digite os valores da matriz, um em cada linha\n Aceita apenas valores numericos\n\n";
    matriz = ler_matriz_numeros_reais(tamanho,tamanho);
    M->set_dados(matriz);
    cout << endl << endl<< endl;
    cout << "Determinante: " << M->calcular_determinante() << endl;
    system("pause");

    //rotina de menu
    menu:
    system("cls");
    cout << endl << endl << endl;
    cout << "Digite 1 para continuar\nDigite 0 para sair\nopção: ";
    op = ler_numeros_reais();
    cout << endl;
    switch(op){
        case 1:
            goto leitura_tamanho;
            break;
        case 0:
            break;
        default:
            cout << "Comando invalido\n";
            system("pause");
            goto menu;
            break;
    }

}else{
    cout << "tamanho invalido" << endl;
    system("pause");
    goto leitura_tamanho;
}


return 0;

}
