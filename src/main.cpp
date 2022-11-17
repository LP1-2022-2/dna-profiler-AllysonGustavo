// Compilar
// make
// Executar
// ./dna_profiler -d data/data.csv -s data/sequence_alice.txt 
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
#include <sstream>
using std::ios;
using namespace std;
 
#include "../include/Base.h"
#include "../include/DNA.h"
#include "../include/exibir.h"
 
int main(int argc, char *argv[]) {
  string d = argv[1]; // O -d antes do diretorio
  string csvdir = argv[2]; // Diretorio da database de DNA
  string s = argv[3]; // O -s antes do diretorio
  string txtseq = argv[4]; // Diretorio do arquivo com a sequencia de DNA

  exibir tela;
  tela.welcome();
  tela.diretiva(d, s);
  tela.verificar(argc, csvdir, txtseq);
  tela.match(txtseq,csvdir);
  
  return 0;
}