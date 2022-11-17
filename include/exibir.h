    #ifndef exibir_H
#define exibir_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
#include <fstream>
#include <string>
#include <iterator>
using namespace std;
#include "Base.h"
#include "DNA.h"
#include "Busca.h"

class exibir {
	private:
    Base basee;
    DNA dnaa;
    Busca buscaa;
    string usuario;
    int qAGAT,qAATG,qTATC,qTATCC; // Quantidade de x sequencia
  public:
    void welcome();
    void verificar(int argc, string csvdir, string txtseq);
    void diretiva(string d, string s);
    void match(string txtseq,string csvdir);
};

void exibir::verificar(int argc, string csvdir, string txtseq){
 if(argc < 5){ // Poucos argumentos
    cout << "O numero de argumentos está incorreto!" << endl;
    cout << "Exemplo: ./dna_profiler -d data/data.csv -s data/sequence_alice.txt" << endl;
    exit(1);
  } else {
   // Ler csv.
   cout << "[+] Preparing to read the DNA Database file [" << "\033[01;31m" << csvdir << "\033[01;m" << "]" << endl;
   basee.Leituracsv(csvdir);// chamada na funcao BASE

   // Ler .txt
  cout << "[+] Preparing to read the unknown DNA sequence file [" << "\033[01;31m" << txtseq << "\033[01;m" << "]" << endl;
   dnaa.Leituratxt(txtseq);// chamada na funcao DNA
  cout << "Processing data, please wait." << endl << endl;
   // sucesso. VOCE VC ADICIONAR UM IF CASO REALMENTE TEANHA SIDO SIDO.

   //PARA VERIFICAR SE FOI LIDO, RETORNA UM BOOL EM CADA LEITURA.
  cout << "Input files sucessfully read." << endl;
  cout << "Searching the database for a match... please wait." << endl << endl << endl;
  }
  
}

void exibir::diretiva(string d, string s){
 if(d != "-d" || s != "-s"){ // caso do usuario nao colocar o -d ou -s
    cout << "Não existe diretiva " << d << "e" << s << endl;
    exit(1);
  }
}

void exibir::welcome(){
  cout << endl << "=================================================================" << endl;
  cout << "                Welcome to the  DNA Profiler, v1.0" << endl;
  cout << "                Copyright (C) 2022, Allyson Gustavo" << endl;
  cout << "=================================================================" << endl << endl;

  cout << "\033[01;36m" << "This program loads a DNA database and an unknow " << endl;
  cout << "\033[01;36m" << "DNA sequence and tries to find a match between " << endl;
  cout << "\033[01;36m" << "The input DNA sequence and the DNA database " <<  "\033[01;m" << endl << endl;
}

void exibir::match(string txtseq,string csvdir){
  Busca Minhabusca;
  DNA buscaa;
  buscaa.Leituratxt(txtseq);
  qAGAT = buscaa.buscaqSTR("AGAT");
  qAATG = buscaa.buscaqSTR("AATG");
  qTATCC = buscaa.buscaqSTR("TATC");
  qTATC = qTATCC - 1;

  usuario = Minhabusca.antesmatch(csvdir,qAGAT,qAATG,qTATC);

  // Pegar oque tem no .txt
  ifstream file(txtseq);
  string txt;
  getline(file, txt);

  // Saida para usuario
  if(usuario == "no match"){
    cout << ">>>    Sorry, no match in our database." << endl;
  }
  else{
    cout << "Match ID (99.9%): " << usuario << endl;
    cout << "DNA profile:" << endl;
    cout << "AAGT[x" << qAGAT << "]          " << "AATG[x" << qAATG << "]          " << "TATC[x" << qTATC << "]" << endl;
    cout << "[" << txt << "]" << endl;
  }
}

#endif