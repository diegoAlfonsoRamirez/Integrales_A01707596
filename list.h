#ifndef DLIST_H
#define DLIST_H
#include <string>
#include <sstream>

template <class T> class DList;

template <class T>
class DLink{
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);
	T		value;
	DLink<T> *previous;
	DLink<T> *next;
	
	friend class DList<T>;
	
};

template <class T>
DLink<T>::DLink(T val) : value(val), next(0), previous(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink *next){}

template <class T>
DLink<T>::DLink(const DLink<T> &source){}

template <class T>
class DList{
public:
	DList();

	int search(T);
	void update(int, T);
	void iFirst(T);
	void insertion(T);
	bool empty() const;
	void deleteAt(int);
	std::string toString() const;
	std::string toString_2() const;
	std::string toString_3() const;
	
private:
	DLink<T> *head;
	DLink<T> *tail;
	int size;
	
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}
	
template <class T>
int DList<T>::search(T val){
	DLink<T> *p;
	p = head;
	int b = 0;
	while(((p->value) != val) && (b != (size-1))){
		p = p->next;
		b++;
		
	}
	if((p->value) != val){
		b = -1;
	}
	return b;
	
}

template <class T>
void DList<T>::update(int a, T val){
	DLink<T> *p;
	if((a <= (size/2)) && (a >= 0)){
		int b = 0;
		p = head;
		while(b != a){
			p = p->next;
			b++;
			
		};
		p->value = val;
		
	}else if((a > (size/2)) && (a <= (size-1))){
		int b = size-1;
		p = tail;
		while(b != a){
			p = p->previous;
			b--;
			
		};
		p->value = val;
		
	}else{
		p->value = -1;
		
	}
	
}

template <class T>
void DList<T>::iFirst(T val){
	DLink<T> *newDLink;
	newDLink = new DLink<T>(val);
	tail = newDLink;
	head = newDLink;
	size++;
	
}

template <class T>
void DList<T>::insertion(T val){
	DLink<T> *newDLink, *p;
	newDLink = new DLink<T>(val);
	if(empty()){
		iFirst(val);
		return;
		
	}
	tail->next = newDLink;
	newDLink->previous = tail;
	tail = newDLink;
	size++;
	
}
	
template <class T>
bool DList<T>::empty() const{
	return (head == 0);
	
}

template <class T>
void DList<T>::deleteAt(int a){
	DLink<T> *p;
	int b = 0;
	p = head;
	head = p->next;
	head->previous = 0;
	delete p;
	size--;
	
}

template <class T>
std::string DList<T>::toString() const {
	std::stringstream aux;
	DLink<T> *p;
	p = head;
	aux << p->value;
	if (p->next != 0) {
		aux << ", ";
	}
	p = p->next;
	return aux.str();
}

template <class T>
std::string DList<T>::toString_2() const {
	std::stringstream aux;
	DLink<T> *p;
	p = head;
	aux << p->value;
	if (p->next != 0) {
		aux << ", ";
	}
	p = p->next;
	return aux.str();
}

template <class T>
std::string DList<T>::toString_3() const {
	std::stringstream aux;
	DLink<T> *p;
	p = head;
	aux << p->value;
	if (p->next != 0) {
		aux << ", ";
	}
	p = p->next;
	return aux.str();
}

#endif