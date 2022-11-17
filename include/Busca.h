#ifndef BUSCA_H
#define BUSCA_H

#include <iostream>
#include <vector>

using namespace std;

#include "Base.h"

class Busca{
  private:
    vector<vector<string>> content; // Vetor com os dados
    Base basee;
  public:
    string antesmatch(string csvdir,int qAGAT,int qAATG,int qTATC);
};

// Busca de numeros iguais
string Busca::antesmatch(string csvdir, int qAGAT,int qAATG,int qTATC){
  Base basee;
  int matchcontador = 0;
  content = basee.Leituracsv(csvdir);
  for(int i = 1; i<=3; i++){
    for(int j = 1; j<=3; j++){
      if(qAGAT == stoi(content[i][j])){ // Converte pq o content é uma string e qAGAT é um int
        matchcontador++;
      }
      if(qAATG == stoi(content[i][j])){
        matchcontador++;
      }
      if(qTATC == stoi(content[i][j])){
        matchcontador++;
      }
      if(matchcontador == 3){
        return content[i][0]; // Encontrou o DNA
      }
    }
    matchcontador = 0; // Zerar o contador depois de percorrer a linha
  }
  return "no match"; // Não encontrou o DNA
}
    
#endif