#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

class bitacora
{
private:
	std::vector<std::string> Text;
	std::string name_archive;
	int mes;
	int dia;
	int hora;
	std::vector<int> times;
	std::unordered_map<std::string, int> mesDiccionario;
public:
	bitacora();
	void Set_Text();
	bitacora(std::string);
	void set_fecha();
	std::vector<int> get_Fecha();
	std::vector<std::string> get_Text();
	static void buscar_fechas(std::string, const std::vector<std::string>&,int, int);
};