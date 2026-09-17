
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void leerArchivo(std::vector<std::string> &texto) {
    std::string line;
    std::ifstream archivo("bitacora.txt", std::ios::in);

    if (!archivo.is_open()) {
        std::cout << "Error no se encontro el archivo";
    }

    while (!archivo.eof()) {
        std::getline(archivo, line);
        texto.push_back(line);
    }
}

void GetFecha(std::vector<int> fechas, std::vector<std::string> archivo) {
    for (int i = 0; i < archivo.size(); i++) {
        std::stringstream t(archivo[i]);
        std::string s;


    }
}

int main()
{
    std::vector<std::string> text;
    leerArchivo(text);

    std::cout << text[2];
}
