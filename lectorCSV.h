#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "lab.h"
#define ARCHIVO_CSV "lista_laboratorio.csv"

std::vector<Lab> csvReader(){
	std::vector<Lab> lab;
	int i = 1;
	std::ifstream file(ARCHIVO_CSV);
	std::string line;
	char delimitator = ',';
	getline(file, line);
	while(getline(file, line)){
		std::stringstream stream(line);
		std::string name, range, age, job, timeY;
		getline(stream, name, delimitator);
		getline(stream, range, delimitator);
		getline(stream, age, delimitator);
		getline(stream, job, delimitator);
		getline(stream, timeY, delimitator);
		
		Lab *c1 = new Lab(name, std::stoi(range), std::stoi(age), job, std::stoi(timeY));
		lab.push_back(*c1);
		
	}
	return lab;
	
}