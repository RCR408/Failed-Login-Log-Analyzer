#include "bitacora.h"

void bitacora::Set_Text() {
    std::string line;
    std::ifstream archivo(name_archive, std::ios::in);

    if (!archivo.is_open()) {
        return;
    }

    while (!archivo.eof()) {
        std::getline(archivo, line);
        Text.push_back(line);
    }

    archivo.close();
}

bitacora::bitacora() {
    name_archive = "bitacora.txt";
    mes = 0;
    dia = 0;
    hora = 0;
    mesDiccionario = {
    {"Jan",0},
    {"Feb",1},
    {"Mar",2},
    {"Apr",3},
    {"May",4},
    {"Jun",5},
    {"Jul",6},
    {"Aug",7},
    {"Sep",8},
    {"Oct",9},
    {"Nov",10},
    {"Dec",11}
    };
    Set_Text();
}

bitacora::bitacora(std::string name) {
    name_archive = name;
    mes = 0;
    dia = 0;
    hora = 0;
    mesDiccionario = {
    {"Jan",0},
    {"Feb",1},
    {"Mar",2},
    {"Apr",3},
    {"May",4},
    {"Jun",5},
    {"Jul",6},
    {"Aug",7},
    {"Sep",8},
    {"Oct",9},
    {"Nov",10},
    {"Dec",11}
    };
    Set_Text();
}

void bitacora::set_fecha() {
    int j = 0;
    std::string s;
    std::string temp[3];
    
    for (int i = 0; i < Text.size();i++) {
        j = 0;
        std::stringstream ss(Text[i]);
        while (ss >> s && j < 3) {
            temp[j] = s;
            j++;
        }

        mes = mesDiccionario[temp[0]]*100000000;
        dia = std::stoi(temp[1])*1000000;

        ss = std::stringstream(temp[2]);
        s = "";
        j = 0;

        while (std::getline(ss, s, ':') && j < 3) {
            temp[j] = s;
            j++;
        }

        hora = std::stoi(temp[0])*10000 + std::stoi(temp[1]) * 100 + std::stoi(temp[2]);

        times.push_back(mes + dia + hora);
    }
    return;
}

std::vector<int> bitacora::get_Fecha() {
    return times;
}

std::vector<std::string> bitacora::get_Text() {
    return Text;
}

void bitacora::buscar_fechas(std::string name, const std::vector<std::string>& text,int min, int max) {
    std::ofstream archivo;

    archivo.open(name, std::ofstream::out, std::ofstream::trunc);

    for (int i = min; i <= max; i++) {
        archivo << text[i] << std::endl;
    }

    archivo.close();
}