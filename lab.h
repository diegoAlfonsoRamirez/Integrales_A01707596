#ifndef LAB_H
#define LAB_H
#include <string>

class Lab{
	private:
		std::string name, job;
		int age, range, time_y;
		
	public:
		Lab();
		Lab(std::string name, int range, int age, std::string job, int time_y);
		
		std::string getName();
		std::string getJob();
		int getRange();
		int getAge();
		int getTimeY();
		
};

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
	return time_y;
}

#endif