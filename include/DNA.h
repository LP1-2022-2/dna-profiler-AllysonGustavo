#ifndef DNA_H
#define DNA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
#include <fstream>
#include <string>
#include <iterator>

#include "Base.h"

using namespace std;

class DNA{
  private:
    string DNAseq;
    
  public:
    void Leituratxt(string txtdir);
    string get_DNAseq();
    int buscaqSTR(string STR);
};

void DNA::Leituratxt(string txtdir){
  // Ler .txt
  ifstream file(txtdir);
  getline(file, DNAseq, ' ');
}

string DNA::get_DNAseq(){
  return DNAseq;
}

int DNA::buscaqSTR(string STR){
  int contador = 0;
  int foundAtual;
  // O primeiro found, já que ele n é found+1
  foundAtual = DNAseq.find(STR);

  for(int i = 0; i < DNAseq.length(); i++){
    if (foundAtual != string::npos){
      foundAtual = DNAseq.find(STR, foundAtual+1);
      contador++;
    }
  }
  return contador;
}

#endif