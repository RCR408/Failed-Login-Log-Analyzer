
#include <iostream>
#include "bitacora.h"
#include "SortingA.h"
int main()
{
    std::unordered_map<std::string, int> mesDiccionario = {
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

    bitacora b = bitacora();
    b.set_fecha();

    std::vector<std::string> text = b.get_Text();
    std::vector<int> fecha = b.get_Fecha();

    SortingA::quickSort(fecha, text, 0, fecha.size()-1);

    std::vector<int> i = SortingA::busquedaBin(fecha, fecha.size(), mesDiccionario["Jul"], 2, mesDiccionario["Sep"], 3);
    bitacora::buscar_fechas("Result.txt", text, i[0], i[1]);

}
