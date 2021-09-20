#include "Sorts.h"
#include "lectorCSV.h"
#include "lab.h"
#include <iostream>

int main(){
	std::vector<Lab> readFile = csvReader();
	std::vector<Lab> vector;
	Sort<Lab> bubbleSort;
	std::cout << "Bienvenido a la base de datos del laboratorio.\n";
	std::cout << "Por el momento nuestra base solo admite ordenamiento de los datos.\n";
	std::cout << "Seleccione como quiere ordenar la base de datos.\n";
	std::cout << "1. Por nombre.\n";
	std::cout << "2. Por edad.\n";
	std::cout << "3. Por tiempo trabajado (años).\n";
	
	int opt = 0;
	while(opt > 3 || opt < 1){
		std::cin >> opt;
		switch(opt){
			case 1:
				bubbleSort.rangeBubbleSort(readFile);
				break;
				
			case 2:
				bubbleSort.ageBubbleSort(readFile);
				break;
				
			case 3:
				bubbleSort.timeBubbleSort(readFile);
				break;
			
			default:
				break;
			
		}
		
	}
	std::cout << "\n [";
	int k = 1;
	for(int i = 0; i < readFile.size(); i++){
		std::cout << " " << k << ". ";
		std::cout << readFile[i].getName() << std::endl;
		std::cout << readFile[i].getJob() << std::endl;
		k += 1;
		
	}
	std::cout << " ]" << std::endl;
	
}