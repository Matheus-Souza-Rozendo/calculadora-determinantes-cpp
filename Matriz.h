#ifndef MATRIZ_H
#define MATRIZ_H
#include <bits/stdc++.h>


using namespace std;

class Matriz{
    public:
        Matriz();
        float calcular_determinante();
        void set_dados(float **dado);
        bool set_tamanho(int tam);
    private:
        float calcular_determinante();
        float **dados = NULL;;
        int tamanho = 0;
};
Matriz::Matriz(){}

float Matriz::calcular_determinante(){
     if(tamanho==2){
        return (dados[0][0]*dados[1][1])-(dados[0][1]*dados[1][0]);
    }
    if(tamanho==3){
        return ((dados[0][0]*dados[1][1]*dados[2][2])+(dados[0][1]*dados[1][2]*dados[2][0])+(dados[1][0]*dados[2][1]*dados[0][2]))-((dados[0][2]*dados[1][1]*dados[2][0])+(dados[0][1]*dados[1][0]*dados[2][2])+(dados[0][0]*dados[1][2]*dados[2][1]));
    }else{

    }
}

void Matriz::set_dados(float **dado){
    dados=dado;
}

bool Matriz::set_tamanho(int tam){
    if(tam==2 || tam==3){
        tamanho = tam;
        return true;
    }else{
        return false;
    }
}

#endif // MATRIZ_H
