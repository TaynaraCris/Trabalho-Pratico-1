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


string * get_tokens(string str){
     static string tokens[2000];
     string s_token;
     int cont = 0;
     const char* separator = " ";
 
     char *token = strtok(const_cast<char*>(str.c_str()), separator);
     while (token != nullptr)
     {
         s_token = string(token);
         if (s_token.size() > 3){
             tokens[cont] = s_token;
             cont++;
         }
 
         token = strtok(nullptr, separator);
     }
 
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
	    if(texto[i] == ',' || texto[i] == '.' || texto[i] == '-' || texto[i] == '_' || texto[i] == '!' || texto[i] == '?'){
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
            // Escreve o textoo no arquivo
            nota1 << texto; 
            // Escrevo uma quebra de line no arquivo
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

    //Reopen files
     ifstream read_nota1("Nota1.txt");
     ifstream read_nota2("Nota2.txt");
     ifstream read_nota3("Nota3.txt");
     ifstream read_nota4("Nota4.txt");
     ifstream read_nota5("Nota5.txt");

     string text_line;
     string * tokens_nota_1;
     string * tokens_nota_2;
     string * tokens_nota_3;
     string * tokens_nota_4;
     string * tokens_nota_5;

     int cont;
 
     while(getline(read_nota1, text_line)) {
         tokens_nota_1 = get_tokens(text_line);
     }

     for ( int i = 0; i < 10; i++ ) {
         cout << tokens_nota_1[i]<< endl;
     }

     while(getline(read_nota2, text_line)) {
         tokens_nota_2 = get_tokens(text_line);
     }

     for ( int i = 0; i < 10; i++ ) {
         cout << tokens_nota_2[i]<< endl;
     }

     while(getline(read_nota3, text_line)) {
         tokens_nota_3 = get_tokens(text_line);
     }

     for ( int i = 0; i < 10; i++ ) {
         cout << tokens_nota_3[i]<< endl;
     }
     
     while(getline(read_nota4, text_line)) {
         tokens_nota_4 = get_tokens(text_line);
     }

     for ( int i = 0; i < 10; i++ ) {
         cout << tokens_nota_4[i]<< endl;
     }
     while(getline(read_nota5, text_line)) {
         tokens_nota_5 = get_tokens(text_line);
     }

     for ( int i = 0; i < 10; i++ ) {
         cout << tokens_nota_5[i]<< endl;
     }
 
 
     read_nota1.close();
     read_nota2.close();
     read_nota3.close();
     read_nota4.close();
     read_nota5.close();

    return 0;
}
