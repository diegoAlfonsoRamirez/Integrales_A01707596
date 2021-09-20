#ifndef LAB_H
#define LAB_H
#include <string>

class Lab{
	private:
		std::string name, job;
		int age, range, timeY;
		
	public:
		Lab();
		Lab(std::string n, int r, int a, std::string j, int t);
		
		std::string getName();
		std::string getJob();
		int getRange();
		int getAge();
		int getTimeY();
		
};

Lab::Lab(std::string n, int r, int a, std::string j, int t){
	name = n;
	range = r;
	age = a;
	job = j;
	timeY = t;
	
}

std::string Lab::getName(){
	return name;
}

std::string Lab::getJob(){
	return job;
}

int Lab::getAge(){
	return age;
}

int Lab::getRange(){
	return range;
}

int Lab::getTimeY(){
	return timeY;
}

#endif