
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>


int sum = 0;
int j = 0;
std::string s;
std::string temp[3]; 

std::unordered_map<std::string, int> values = {
    {"Jan",10000},
    {"Feb",20000},
    {"Mar",30000},
    {"Apr",40000},
    {"May",50000},
    {"Jun",60000},
    {"Jul",70000},
    {"Aug",80000},
    {"Sep",90000},
    {"Oct",100000},
    {"Nov",110000},
    {"Dec",120000}
};

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

    archivo.close();
}

void GetFecha(std::vector<int>& fechas, std::vector<std::string> archivo, int size) {

    if (size >= 0) {
        sum = 0;
        j = 0;
        std::stringstream ss(archivo[size]);
        while (ss >> s && j < 3) {
            temp[j] = s;
            j++;
        }

        sum += values[temp[0]];
        sum += std::stoi(temp[1]) * 1000;
        
        ss = std::stringstream(temp[2]);
        s = "";
        j = 0;

        while (std::getline(ss,s,':')&&j<3) {
            temp[j] = s;
            j++;
        }

        sum += std::stoi(temp[0]) * 100;
        sum += std::stoi(temp[1]) * 10;
        sum += std::stoi(temp[2]);


        fechas.push_back(sum);
        GetFecha(fechas, archivo,size-1);
    }
}
 
int main()
{
    std::vector<std::string> text;
    std::vector<int> compare;
    leerArchivo(text);

    GetFecha(compare, text,text.size()-1);
   
}
