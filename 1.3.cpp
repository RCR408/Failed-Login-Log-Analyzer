
#include <iostream>
#include "bitacora.h"
#include "SortingA.h"
int main()
{

    bitacora b = bitacora();
    b.set_fecha();

    std::vector<std::string> text = b.get_Text();
    std::vector<int> fecha = b.get_Fecha();

    SortingA::quickSort(fecha, text, 0, fecha.size()-1);

}
