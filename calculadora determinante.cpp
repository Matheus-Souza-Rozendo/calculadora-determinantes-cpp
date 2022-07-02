#include <bits/stdc++.h>


using namespace std;


//aloca memoria para uma matriz quadrada nxn
float **cria_matriz_quadrada(int tamanho){
    float **matriz;
    matriz = (float**) malloc(sizeof(float*)*tamanho);
    for(int i=0;i<tamanho;i++){
        matriz[i] = (float*) malloc(sizeof(float)*tamanho);
    }
    return matriz;
}

//Recebe um tamanho da matriz quadrado, ou seja se n = 2, lera 4 valores, dois em cada linha;
void ler_valores_matriz_quadrada(int tamanho, float **matriz){
    cout << "Digite os valores um em cada linha, (apenas numeros)" << endl << endl;
    for(int i = 0; i<tamanho; i++){
            for(int j=0; j<tamanho; j++){
                cout << "matriz["<<i+1<<"]["<<j+1<<"]: ";
                leitura:
                try{
                    cin >> matriz[i][j];
                }catch(exception& e){
                    cout << "valor invalido \n digite apenas numeros" << endl;
                    goto leitura;
            }
        }
    }
}

//calcula o determinante de uma matriz 2x2 ou 3x3
float calcular_determinante(int n, float **m){
        if(n==2){
            return (m[0][0]*m[1][1])-(m[0][1]*m[1][0]);
        }
        if(n==3){
            return ((m[0][0]*m[1][1]*m[2][2])+(m[0][1]*m[1][2]*m[2][0])+(m[1][0]*m[2][1]*m[0][2]))-((m[0][2]*m[1][1]*m[2][0])+(m[0][1]*m[1][0]*m[2][2])+(m[0][0]*m[1][2]*m[2][1]));
        }else{
            return NULL;
        }
}

int main(){
setlocale(LC_ALL, "Portuguese");
int n, teste;
float **m;
float det;
inicio:
system("cls");
cout << "Digite o tamanho da Matriz: ";
try{
    cin >> n;
}catch(exception& e){
    n = 0;
}

if((n==3)||(n==2)){
    m = cria_matriz_quadrada(n);
    ler_valores_matriz_quadrada(n,m);
    det = calcular_determinante(n,m);
    cout << endl << "Valor do determinante: " << det << endl;
    system("pause");
}else{
    cout << "Valor invalido !!"<<endl << "O programa aceita matriz de tamanho 2x2 e 3x3"<<endl;
    system("pause");
}
comando:
system("cls");
cout << "\n\nDigite 1 para continuar e 0 para sair\n";
try{
    cin >> teste;
}catch(exception& e){
    cout << "comando invalido";
    goto comando;
}


switch(teste){
    case 0:
        break;
    case 1:
        goto inicio;
        break;
    default:
        cout << "comando invalido" << endl;
        system("pause");
        goto comando;
        break;
}

return 0;

}
