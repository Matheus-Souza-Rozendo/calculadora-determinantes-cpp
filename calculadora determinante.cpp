#include <bits/stdc++.h>


using namespace std;

//função que retorna true se a string passada for um numero e false caso contrario
bool valida_apenas_numeros(string entrada){
    for(int i=0;i<entrada.size();i++){
        if((!isdigit(entrada[i]))&&(entrada[i]!='.')){
            return false;
        }
    }
    return true;
}


//função para a leitura de apenas numeros reais, caso ocorra um outro tipo de dado, a funçao acusa um erro
float ler_numeros_reais(){
    string entrada;
    leitura:
    try{
        cin >> entrada;
        if(!valida_apenas_numeros(entrada)){
            throw(entrada);
        }
    }catch(string msg){
        cout << msg << " Não é um valor valido " <<endl;
        system("pause");
        goto leitura;
        cout << endl << endl;
    }
    return stof(entrada);
}

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
    string entrada;
    cout << "Digite os valores um em cada linha, (apenas numeros)" << endl << endl;
    for(int i = 0; i<tamanho; i++){
            for(int j=0; j<tamanho; j++){
                leitura:
                cout << "matriz["<<i+1<<"]["<<j+1<<"]: ";
                matriz[i][j]= ler_numeros_reais();
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
int n,teste;
float **m;
float det;
string entrada;

inicio:
system("cls");
cout << "Digite o tamanho da Matriz: ";
n = ler_numeros_reais();
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
cout << "Digite 0 para Sair e 1 para continuar\n";
teste = ler_numeros_reais();
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
