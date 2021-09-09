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

    ofstream todos_tokens;
    if (file_name == "Nota1.txt") {
        todos_tokens.open("todos_tokens.txt");
    } else {
        todos_tokens.open("todos_tokens.txt", std::ios_base::app);
    }

    string* tokens = new string[800000];
    string s_token;
    int cont = 0;
    const char* separator = " ";
    bool ja_existe;

    while(getline(read_nota, text_line)) {

        char *token = strtok(const_cast<char*>(text_line.c_str()), separator);
        while (token != nullptr)
        {
            s_token = string(token);
            if (s_token.size() > 3){
                todos_tokens << s_token << endl;
                tokens[cont] = s_token;
                cont++;
            }

            token = strtok(nullptr, separator);
        }

    }

    read_nota.close();
    todos_tokens.close();

    return tokens;
}

map<string, int> get_alltokens(){
    ifstream todos_tokens("todos_tokens.txt");
    string token;
    map<string, int> dicionario;

    while(getline(todos_tokens, token)) {
        if (dicionario[token]){
            dicionario[token]++;
        } else {
            dicionario[token] = 1;
        }
    }

    todos_tokens.close();

    return dicionario;
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

    int total_tokens_rate_1 = 0;
    int total_tokens_rate_2 = 0;
    int total_tokens_rate_3 = 0;
    int total_tokens_rate_4 = 0;
    int total_tokens_rate_5 = 0;

    while( file.good() ) {
        rate = "";
        texto = "";

        // Pega uma linha do arquivo
        getline(file, avaliacao);

        // Percorre a linha inteira e troca as aspas por espaço em branco
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
    string * tokens_inteiro;
    int cont;
    
    tokens_nota_1 = get_tokens("Nota1.txt");
    tokens_nota_2 = get_tokens("Nota2.txt");
    tokens_nota_3 = get_tokens("Nota3.txt");
    tokens_nota_4 = get_tokens("Nota4.txt");
    tokens_nota_5 = get_tokens("Nota5.txt");
    map<string, int> dicionario = get_alltokens();

    // PARA PRINTAR O DICIONARIO
    for (auto elemento : dicionario){
        cout << elemento.first << " " << elemento.second << endl;
    }
    
    // PARA ACESSAR O VALOR DA PALAVRA(A QUANTIDADE DE VEZES QUE ELA APARECEU)
    // cout << dicionario['palavra'] << endl;
    // int qt_palavra = dicionario['palavra'];
    

// TESTEEEEEEE
 
     //bool achou_1 = 0;
     //bool achou_2 = 0;
     //bool achou_3 = 0;
     //bool achou_4 = 0;
     //bool achou_5 = 0;
     //bool achou_6 = 0;

     //for ( int i = 0; i < 800000; i++ ) {
     //    if(tokens_nota_1[i] == "" && achou_1 == 0) {
     //        cout << "O ultimo token da nota 1 foi na posição: " << i << endl;
     //        achou_1 = 1;
     //    }
     //    if(tokens_nota_2[i] == "" && achou_2 == 0) {
     //        cout << "O ultimo token da nota 2 foi na posição: " << i << endl;
     //        achou_2 = 1;
     //    }
     //    if(tokens_nota_3[i] == "" && achou_3 == 0) {
     //        cout << "O ultimo token da nota 3 foi na posição: " << i << endl;
     //        achou_3 = 1;
     //    }
     //    if(tokens_nota_4[i] == "" && achou_4 == 0) {
     //        cout << "O ultimo token da nota 4 foi na posição: " << i << endl;
     //        achou_4 = 1;
     //    }
     //    if(tokens_nota_5[i] == "" && achou_5 == 0) {
     //        cout << "O ultimo token da nota 5 foi na posição: " << i << endl;
     //        achou_5 = 1;
     //    }
     //}
 
     //for(int j = 0; j < 1872600; j++){
     //    if(tokens_inteiro[j] == "" && achou_6 == 0) {
     //        cout << "O último token do texto foi na posição: " << j << endl;
     //        achou_6 = 1;
     //    }
     //}

     // TESTEEEEEEE
 
    return 0;
}