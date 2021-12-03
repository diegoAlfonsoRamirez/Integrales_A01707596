#include "Sorts.h"
#include "list.h"
#include "lab.h"
#include "heap.h"
#include "quadratic.h"
#include "graph.h"
#include "lectorCSV.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

unsigned int myHash(const std::string s) {
	unsigned int acum = 0;
	for(unsigned int i = 0; i < s.size(); i++){
		acum += (int) s[i];
	}
	return acum;
}

int main(int argc, char* argv[]){
	std::vector<Lab> readFile = csvReader();
	std::vector<Lab> vector;
	Sort<Lab> bubbleSort;
	int aux = 0;
	int opt = 0;
	int a, b = 0;
	DList<int> e;
	DList<int> r;
	DList<int> t;
	Heap<float> heap(readFile.size());
	Quadratic <std::string, int> quad_hash(readFile.size(), std::string("empty"), myHash);
	
	for(int i = 0; i < readFile.size(); i++){
		quad_hash.put(readFile[i].getName() + "_" + readFile[i].getJob() + "_" + std::to_string(readFile[i].getAge()) + "_" + std::to_string(readFile[i].getTimeY()), readFile[i].getRange());
		
	}
	
	
	
	for(int i = 0; i < readFile.size(); i++){
		e.insertion(readFile[i].getAge());
		
	}
	
	for(int i = 0; i < readFile.size(); i++){
		r.insertion(readFile[i].getRange());
		
	}
	
	for(int i = 0; i < readFile.size(); i++){
		t.insertion(readFile[i].getTimeY());
		
	}	
	
	std::cout << "Bienvenido a la base de datos del laboratorio.\n";
	std::cout << "Seleccione que desea hacer.\n";
	std::cout << "1. Ordenar la base de datos.\n";
	std::cout << "2. Buscar o actualizar un dato.\n";
	std::cout << "3. Agregar un nuevo empleado a la base.\n";
	std::cout << "4. Consulta de personal en plantilla.\n";
	std::cout << "5. Consulta del elemento mas antiguo.\n";
	std::cout << "6. Conocer ruta de comunicacion entre personal.\n";
	std::cout << "Pulse cualquier otra tecla para salir.\n";
	
	std::cin >> opt;
	switch(opt){
		case 1:
		{
			aux = 1;
			std::cout << "Seleccione como quiere ordenar la base de datos.\n";
			std::cout << "1. Por rango.\n";
			std::cout << "2. Por edad.\n";
			std::cout << "3. Por tiempo trabajado.\n";
			std::cout << "Pulse cualquier otra tecla para salir.\n";
			
			opt = 0;
			std::cin >> opt;
			switch(opt){
				case 1:
				{
					bubbleSort.rangeBubbleSort(readFile);
					break;
				}
				
				case 2:
				{
					bubbleSort.ageBubbleSort(readFile);
					break;
				}
					
				case 3:
				{
					bubbleSort.timeBubbleSort(readFile);
					break;
				}
				
				default:
					break;
				
			}
			break;
		}
		
		case 2:
		{
			aux = 2;
			std::cout << "Seleccione que tipo de dato desea manejar.\n";
			std::cout << "1. Rango.\n";
			std::cout << "2. Edad.\n";
			std::cout << "3. Tiempo trabajado.\n";
			std::cout << "Pulse cualquier otra tecla para salir.\n";
			
			opt = 0;
			std::cin >> opt;
			switch(opt){
				case 1:
				{
					std::cout << "Desea actualizar o buscar datos?.\n";
					std::cout << "1. Actualizar.\n";
					std::cout << "2. Buscar.\n";
					std::cout << "Pulse cualquier otra tecla para salir.\n";
					a, b = 0;
					opt = 0;
					std::cin >> opt;
					switch(opt){
						case 1:
						{
							std::cout << "Introduzca la posicion del dato a reemplazar.\n";
							std::cin >> a;
							std::cout << "Introduzca el valor del dato a reemplazar.\n";
							std::cin >> b;
							r.update(a, b);
							break;
						}
						
						case 2:
						{
							std::cout << "Introduzca el valor a encontrar.\n";
							std::cin >> b;
							std::cout << r.search(b) << std::endl;
							break;
						}
						
						default:
							break;
							
					}
				}
				
				case 2:
				{
					std::cout << "Desea actualizar o buscar datos?.\n";
					std::cout << "1. Actualizar.\n";
					std::cout << "2. Buscar.\n";
					std::cout << "Pulse cualquier otra tecla para salir.\n";
					a, b = 0;
					opt = 0;
					std::cin >> opt;
					switch(opt){
						case 1:
						{
							std::cout << "Introduzca la posicion del dato a reemplazar.\n";
							std::cin >> a;
							std::cout << "Introduzca el valor del dato a reemplazar.\n";
							std::cin >> b;
							e.update(a, b);
							break;
						}
						
						case 2:
						{
							std::cout << "Introduzca el valor a encontrar.\n";
							std::cin >> b;
							std::cout << e.search(b) << std::endl;
							break;
						}
						
						default:
							break;
							
					}
				}
				
				case 3:
				{
					std::cout << "Desea actualizar o buscar datos?.\n";
					std::cout << "1. Actualizar.\n";
					std::cout << "2. Buscar.\n";
					std::cout << "Pulse cualquier otra tecla para salir.\n";
					a, b = 0;
					opt = 0;
					std::cin >> opt;
					switch(opt){
						case 1:
						{
							std::cout << "Introduzca la posicion del dato a reemplazar.\n";
							std::cin >> a;
							std::cout << "Introduzca el valor del dato a reemplazar.\n";
							std::cin >> b;
							t.update(a, b);
							break;
						}
						
						case 2:
						{
							std::cout << "Introduzca el valor a encontrar.\n";
							std::cin >> b;
							std::cout << t.search(b) << std::endl;
							break;
						}
						
						default:
							break;
							
					}

				}
				default:
					break;
			}
			break;
				
		}
		
		case 3:
		{
			std::ofstream lab;
			lab.open("lista_laboratorio.csv");
			lab << "name,range,age,job,time_y,\n";
			for(int i = 0; i < readFile.size(); i++){
				std::string b;
				b = readFile[i].getName() + "," + std::to_string(readFile[i].getRange()) + "," + std::to_string(readFile[i].getAge()) + "," + readFile[i].getJob() + "," + std::to_string(readFile[i].getTimeY()) + std::string("\n");
				lab << b;
				
			}
			std::string a;
			std::cout << "Introduzca el nombre, rango, edad, trabajo y tiempo trabajado del nuevo empleado, separado por una coma (,).\n";
			std::cin >> a;
			lab << a;
			lab.close();
			break;
			
		}
		
		case 4:
		{
			std::string a;
			std::cout << "Introduzca el nombre, trabajo, edad y tiempo trabajado, separados por un (_) sin espacios.\n";
			std::cin >> a;
			if(quad_hash.contains(a) == 1){
				std::cout << "El empleado se encuentra en la base de datos.";
				
			}else{
				std::cout << "El empleado no se encuentra en la base de datos.";
				
			}
			
			break;
			
		}
		
		case 5:
		{
			for(int i = 0; i < readFile.size(); i++){
				heap.push(readFile[i].getTimeY());
				
			}
			std::cout << "El empleado que menos tiempo ha trabajado, trabajo: " << heap.top() << " años.\n";
		}
		
		default:
			break;
			
	}
	
	if(aux == 1){
		std::cout << "\n";
		int k = 1;
		for(int i = 0; i < readFile.size(); i++){
			std::cout << " " << k << ". ";
			std::cout << readFile[i].getName() << " - " << readFile[i].getRange() << " - " << readFile[i].getAge() << " - " << readFile[i].getJob() << " - " << readFile[i].getTimeY() << std::endl;
			k += 1;
			
		}
		
	}else if(aux == 2){
		std::cout << "\n";
		int k = 1;
		for(int i = 0; i < readFile.size(); i++){
			std::cout << " " << k << ". ";
			std::cout << readFile[i].getName() << " - " << r.toString() << " - " << e.toString_2() << " - " << readFile[i].getJob() << " - " << t.toString_3() << std::endl;
			r.deleteAt(0);
			e.deleteAt(0);
			t.deleteAt(0);
			k += 1;
			
		}
		
	}else{
		aux = 0;
		
	}
	
}