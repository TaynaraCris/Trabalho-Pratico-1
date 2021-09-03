#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int encontra(string avaliacao, string separator){
    
    int M = separator.length();
    int N = avaliacao.length();
    int j;

    for (int i = 0; i <= N - M; i++) {
        for (j = 0; j < M; j++)
            if (avaliacao[i + j] != separator[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
 string * get_tokens(string file_name){
      ifstream read_nota(file_name);
      string text_line;
  
      string* tokens = new string[800000];
      string s_token;
      int cont = 0;
      const char* separator = " ";
  
      while(getline(read_nota, text_line)) {
  
          char *token = strtok(const_cast<char*>(text_line.c_str()), separator);
          while (token != nullptr)
          {
              s_token = string(token);
              if (s_token.size() > 3){
                  tokens[cont] = s_token;
                  cont++;
              }
  
              token = strtok(nullptr, separator);
          }
  
      }
  
      read_nota.close();
  
      return tokens;
  }
 
string replace(string avaliacao){

    for(int i =  0; i < avaliacao.length(); i++){
	if(avaliacao[i] == '"'){
	   avaliacao[i] = ' ';
	}
    }
    return avaliacao;

}

int* get_idf(string *termos,int tamVetor, string *termosCompara, int tamVetorCompara){
    int* numDocsVetor = new int [tamVetor];

    for (int i = 0; i < tamVetor; i++)
    {
        numDocsVetor[i] = 0;
    }

    for (int i = 0; i < tamVetor; i++){
        for (int u = 0; u < tamVetorCompara; u++)
        {
            if(/*COMPARAÇÃO DE STRINGS AQUI*/){
                numDocsVetor[i]++;
                break;
            }
        }
        
    }

    return numDocsVetor;    
}


int main(){
    fstream file;
    file.open("tripadvisor_hotel_reviews.csv", ios::in);

    ofstream nota1;
    nota1.open("Nota1.txt");

    ofstream nota2;
    nota2.open("Nota2.txt");	

    ofstream nota3;
    nota3.open("Nota3.txt");

    ofstream nota4;
    nota4.open("Nota4.txt");

    ofstream nota5;
    nota5.open("Nota5.txt");

    string line;
    string texto = "", rate = "";
    string separator = ",   ,"; 

    int inicio_separator;

    string avaliacao;

    int total_tokens_rate_1 = 0;
    int total_tokens_rate_2 = 0;
    int total_tokens_rate_3 = 0;
    int total_tokens_rate_4 = 0;
    int total_tokens_rate_5 = 0;

    while( file.good() ) {
        rate = "";
	texto = "";

	// Pega uma line do arquivo
        getline(file, avaliacao);

        // Percorre a line inteira e troca as aspas por espaço em branco
      	avaliacao = replace(avaliacao);

	inicio_separator = encontra(avaliacao, separator);

	for(int i = 0; i < inicio_separator; i++){
	    texto += avaliacao[i];
	}
	for(int i = inicio_separator + separator.length(); i <= avaliacao.length(); i++){
	    rate += avaliacao[i];
	}


	for(int i = 0; i < texto.length(); i++){
	    if(texto[i] == ',' || texto[i] == '.' || texto[i] == '-' || texto[i] == '_' || texto[i] == '!' || texto[i] == '?' || texto[i] == ';'
	    || texto[i] == ':'){
	       
	    texto[i] = ' ';
	    }
	    else{
	       texto[i] = texto[i];
	    }
	}
	for(int i = 0; i < texto.length(); i++){
	    if(texto[i] == ' ' && texto[i+1] == ' '){
	       texto[i] = ' ';
	    }
	    else{
	       texto[i] = texto[i];
	    }
	}

        if(rate[0] == '1') {
            nota1 << texto; 
            nota1 << endl;
        }
	else if(rate[0] == '2'){
	    nota2 << texto;
	    nota2 << endl;
	}
	else if(rate[0] == '3'){
	    nota3 << texto;
	    nota3 << endl;
	}
	else if(rate[0] == '4'){
	    nota4 << texto;
	    nota4 << endl;
	}
	else if(rate[0] == '5'){
	    nota5 << texto;
	    nota5 << endl;
	}
    }
    file.close();

    nota1.close();
    nota2.close();
    nota3.close();
    nota4.close();
    nota5.close();

    string text_line;
    string * tokens_nota_1;
    string * tokens_nota_2;
    string * tokens_nota_3;
    string * tokens_nota_4;
    string * tokens_nota_5;
    int cont;
    
    tokens_nota_1 = get_tokens("Nota1.txt");
    tokens_nota_2 = get_tokens("Nota2.txt");
    tokens_nota_3 = get_tokens("Nota3.txt");
    tokens_nota_4 = get_tokens("Nota4.txt");
    tokens_nota_5 = get_tokens("Nota5.txt");


 
     bool achou_1 = 0;
     bool achou_2 = 0;
     bool achou_3 = 0;
     bool achou_4 = 0;
     bool achou_5 = 0;

     int num1;
     int num2;
     int num3;
     int num4;   
     int num5;
 
     for ( int i = 0; i < 800000; i++ ) {
         if(tokens_nota_1[i] == "" && achou_1 == 0) {
             //cout << "O ultimo token da nota 1 foi na posição: " << i << endl;
             achou_1 = 1;
             num1 = i;
         }
         if(tokens_nota_2[i] == "" && achou_2 == 0) {
             //cout << "O ultimo token da nota 2 foi na posição: " << i << endl;
             achou_2 = 1;
             num2 = i;
         }
         if(tokens_nota_3[i] == "" && achou_3 == 0) {
             //cout << "O ultimo token da nota 3 foi na posição: " << i << endl;
             achou_3 = 1;
             num3 = i;
         }
         if(tokens_nota_4[i] == "" && achou_4 == 0) {
             //cout << "O ultimo token da nota 4 foi na posição: " << i << endl;
             achou_4 = 1;
             num4 = i;
         }
         if(tokens_nota_5[i] == "" && achou_5 == 0) {
             //cout << "O ultimo token da nota 5 foi na posição: " << i << endl;
             achou_5 = 1;
             num5 = i;
         }
     }

     
    int * numDocsTermo1;

    numDocsTermo1 = get_idf(tokens_nota_1, num1 , tokens_nota_2,num2); 

    for (int i = 0; i < 10; i++)
    {
      cout << numDocsTermo1[i] << endl;
    }
    

    return 0;
}