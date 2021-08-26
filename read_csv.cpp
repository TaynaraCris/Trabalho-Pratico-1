#include <bits/stdc++.h>

using namespace std;

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

    string linha;
    string texto, rate;
    string separator = ",   ,"; 

    int inicio_separator;

    string avaliacao;

    while( file.good() ) {
        // Pega uma linha do arquivo
        getlinha(file, avaliacao);

        // Percorre a linha inteira e troca as aspas por espaço em branco
        replace(avaliacao.begin(), avaliacao.end(), '"', ' ');

        inicio_separator = avaliacao.find(separator);
        // Pegar uma substring de 0 até onde começa o separador
        texto = avaliacao.substr(0, inicio_separator);
        // Apaga de 0 até onde termina o separador
        avaliacao.erase(0, avaliacao.find(separator) + separator.length());
        // Pega o que sobrou que é a nota e guarda no rate
        rate = avaliacao;

        if(rate == "1") {
            // Escreve o textoo no arquivo
            nota1 << texto; 
            // Escrevo uma quebra de linha no arquivo
            nota1 << endl;
        }
	else if(rate == "2"){
	    nota2 << texto;
	    nota2 << endl;
	}
	else if(rate == "3"){
	    nota3 << texto;
	    nota3 << endl;
	}
	else if(rate == "4"){
	    nota4 << texto;
	    nota4 << endl;
	}
	else if(rate == "5"){
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

    return 0;
}
