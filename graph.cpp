#include <bits/stdc++.h>
#define TAMANHO_POPULACAO 10
#define DOMINIO 1000
#define TAXA_MUTACAO 3

using namespace std;

double bestResult;
double populacao[TAMANHO_POPULACAO];
double fit[TAMANHO_POPULACAO];
int geracao;

//Inicializa a populacao
void inicializaPopulacao(){
    bestResult = -999999999;
    for (int i=0;i<TAMANHO_POPULACAO;i++){
        populacao[i] = (double) (rand()%DOMINIO);
    } 
}

//Escolhe o melhor candidato da população e armazena
void escolheMelhor(){
    for(int i=0;i<TAMANHO_POPULACAO;i++){
        bestResult = max(bestResult, (populacao[i]>500)? 1000-populacao[i] : populacao[i]);
    }
}


//Mutação genetica
void crossover(){
    for(int i=0; i<TAMANHO_POPULACAO; i++){
        if(populacao[i] != bestResult){
            populacao[i] = (populacao[i] + bestResult)/2.0;
            populacao[i] += (double) ((rand()%DOMINIO)-(DOMINIO/2)) * ((double) TAXA_MUTACAO/100); 
        }
    }

}

void printPopulacao(){
    cout<<"População: ";
    for (int i=0;i<TAMANHO_POPULACAO;i++){
        cout<<populacao[i]<<" ";
    }
    cout<<"\n";
}



int main (){

    srand (time(NULL));

    inicializaPopulacao();

    while(getchar()!='e'){
        escolheMelhor();
        printPopulacao();
        cout<<"Geração: "<<geracao++<<" || Melhor: "<<bestResult<<endl;
        crossover();
    }

    return 0;
}