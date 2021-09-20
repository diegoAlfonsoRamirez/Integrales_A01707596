#include <vector>
#include <iostream>
#include <list>

template <class T>
class Sort{
	public:
		void ageBubbleSort(std::vector<T>&);
		void rangeBubbleSort(std::vector<T>&);
		void timeBubbleSort(std::vector<T>&);
		void swap(std::vector<T>&, int, int);
		
};

template <class T>
void Sort<T>::swap(std::vector<T>&v, int i, int j){
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
	
}

template <class T>
void Sort<T>::ageBubbleSort(std::vector<T> &v){
	for(int i=v.size()-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(v[j].getAge()>v[j+1].getAge()){
				swap(v, j, j+1);
			}
		}	
	}
}

template <class T>
void Sort<T>::rangeBubbleSort(std::vector<T> &v){
	for(int i=v.size()-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(v[j].getRange()>v[j+1].getRange()){
				swap(v, j, j+1);
			}
		}	
	}
}

template <class T>
void Sort<T>::timeBubbleSort(std::vector<T> &v){
	for(int i=v.size()-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(v[j].getTimeY()>v[j+1].getRange()){
				swap(v, j, j+1);
			}
		}	
	}
}


