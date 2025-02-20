#include <dirent.h>
#include <cstdlib>
#include <string>
#include <fstream>

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
        std::cerr << "Diretório com as instâncias não foi informado." << std::endl;
        exit (1);
    }
    for(int i=0;i<argc; i++){
        std::cout << argv[i] << std::endl;
    }

	std::string nomeDir = argv[1];
	DIR *dir = 0;
    struct dirent *entrada = 0;
    unsigned char isFile = 0x8;

    dir = opendir (nomeDir.c_str());

    if (dir == 0) {
        std::cerr << "Nao foi possível abrir diretorio com as instâncias." << std::endl;
        exit (1);
    }
	// Pego todas as instâncias do diretório
	while ((entrada = readdir (dir))){
		if (entrada->d_type == isFile){
            std::stringstream convert;
            std::cout << " Padronizando: " << nomeDir+entrada->d_name << std::endl;
            std::string xF = nomeDir + "saida/"+entrada->d_name + convert.str();
            std::string cmd = "./main  <" + nomeDir+entrada->d_name + " > " + nomeDir + "saida/"+entrada->d_name  + convert.str();
            const char * c = cmd.c_str();
            int s = system(c);
		}
	}
    closedir (dir);
	return 0;
}

/**********************************************************************************************
 * Compile: g++ -O3 -march=native -std=c++11 -o run  run.cpp 
 * Run: ./run ./entrada/
 *  Após o nome do programa, informe o diretório com as instâncias como parâmetro de entrada.
**********************************************************************************************/
