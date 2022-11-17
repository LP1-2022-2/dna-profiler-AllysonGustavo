#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>
#include <fstream>
#include <string>
#include <iterator> 
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //./dna_profiler -d data/data.csv -s data/sequence_alice.txt
using namespace std;

class Base{
  private:
    // Arquivo .csv
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
  public:
    vector<vector<string>> Leituracsv(string csvdir);
};

vector<vector<string>> Base::Leituracsv(string csvdir){ // Lê o arquivo .csv e .txt
// Ler o .csv
fstream file (csvdir, std::ios::in);
if(file.is_open()){
  while(getline(file, line)){
  row.clear();
  stringstream str(line);
  while(getline(str, word, ','))
  row.push_back(word);
  content.push_back(row);
    }
  }
  return content;
}

#endif