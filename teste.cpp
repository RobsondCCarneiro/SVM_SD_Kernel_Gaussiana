/*O código serve para calcular o tempo que o SVM, gasta para utilizar a maquina, 
assim como imprime os resultados para conferir se o código está certo
*/
#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

int main(){
    //Medindo o tempo a partir daqui 
    clock_t tempo;
    tempo = clock();


    //Implementacao do Kernel Gaussiana

    /*
    Tudo isso foi dado, porem foram apenas 15 elementos, como o algoritmo 
    forca a ter 16 para balancear com a outra opcao que tem 16 elementos,
    entao eu tive que colocar o ultimo elemento da entrada e do peso como zero
    */
    float C1[] = {4.6, 4.7, 3.3, 4.9, 4.9, 4.8, 4.7, 4.9, 5.1, 5.0, 4.9, 6.3, 6.9, 4.5, 5.0, 0.0};
    float C2[] = {1.5, 1.4, 1.0, 1.5, 1.5, 1.8, 1.6, 1.8, 1.9, 2.0, 2.0, 1.8, 2.3, 1.7, 1.5, 0.0};
    float w[] = {-1.000000000000000, -0.842166925518657, -0.905189126677198, -1.000000000000000, 
    -1.000000000000000, -1.000000000000000, -1.000000000000000, 1.000000000000000, 1.000000000000000, 
    0.876387674600306, 1.000000000000000, 0.143275875135736, 0.727692502459813, 1.000000000000000, 
    1.000000000000000, 0.0};
    float biasG = 0.131308149087384;
    float kernelG[16];
    float d, soma=0;

    float X1[] = {4.60, 4.10, 4.50, 4.00, 3.90, 4.70, 4.00, 4.20, 3.90, 4.70, 3.30, 4.50, 4.00, 4.50, 4.60,
 4.90, 4.50, 4.70, 3.50, 4.90, 4.80, 3.60, 4.30, 4.40, 4.70, 4.90, 5.50, 5.30, 5.70, 5.10,
  5.90, 5.10, 5.70, 6.00, 6.60, 5.00, 6.70, 5.80, 6.70, 5.80, 5.10, 4.90, 6.30, 5.60, 5.50,
   5.30, 6.90, 4.50, 6.10, 5.00};
   float X2[] = {1.50, 1.00, 1.50, 1.30, 1.40, 1.20, 1.30, 1.50, 1.10, 1.40, 1.00, 1.30, 1.00, 1.50, 1.30, 1.50, 
1.50, 1.40, 1.00, 1.50, 1.80, 1.30, 1.30, 1.40, 1.60, 1.80, 1.80, 2.30, 2.30, 1.90, 2.10, 2.00, 2.10, 2.50, 
2.10, 2.00, 2.00, 2.20, 2.20, 1.80, 2.40, 2.00, 1.80, 1.80, 2.10, 1.90, 2.30, 1.70, 2.50, 1.50};

    //Pegando o tamanho do vetor X1, sendo que o X2 e a saida irao ter os mesmos tamanhos
    int tam = sizeof(X1)/sizeof(X1[0]);
    float saida[tam];

    //Isso eh apenas para conferir se realmente o tamanho eh o que estah na tabela
   //cout << "O tamanho de X1 eh: " << sizeof(X1)/sizeof(X1[0]) << endl;
   //cout << "O tamanho de X2 eh: " << sizeof(X2)/sizeof(X2[0]);



    //Iteracao para calcular o kernel (laco i) e a saida (laco j)
    for(int j=0; j < tam; j++){
        for (int i=0; i< 16; i++){
            d = pow(X1[j] - C1[i], 2) + pow(X2[j] - C2[i], 2);
            //cout << "O valor de d na iteracao " << i << "/15 eh: " << d << endl;
            kernelG[i] = exp(-d);
            //cout << "O valor de KernelG eh" << kernelG[i] << endl;
            soma += kernelG[i]*w[i];
        }
        saida[j] = soma+biasG;
        soma = 0;
    }

    //imprimindo as saidas
    cout << "Agora vamos imprimir a saida: " << endl;
    cout << "{";
    for(int j=0; j < tam; j++){
        cout << saida[j] << ", " << endl;
    }
    cout << "}" << endl;

    //Imprimindo o Label de acordo com o hiperplano
    cout << "Agora ira imprimir o label: " << endl;
    for(int j=0; j < tam; j++){
        if(saida[j] < 0)
            cout << "versicolor, " << endl;
        else
            cout << "virginia, " << endl;
    }
    cout << "}" << endl;

    cout << "O tempo em segundos foi de: " << (clock() - tempo)/(double)CLOCKS_PER_SEC;

    return 0;

}
