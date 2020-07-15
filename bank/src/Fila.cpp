#include "Fila.hpp"


template <class  T>
Fila<T>::Fila(int size) : elements(nullptr), top(-1), capacity(size){
	this->elements = new T[this->capacity];
}

template <class  T>
T Fila<T>::back(){
	if (!this->empty()){
		return this->elements[this->top];
	}
}

template <class  T>
T Fila<T>::front(){
	if (!this->empty()){
		return this->elements[0];
	}
}

template <class  T>
bool Fila<T>::empty(){
	if (this->top == -1){
		return true;
	}
	return false;
}

template <class  T>
void Fila<T>::pop(){
	if (!this->empty()){
		this->top -= 1;
	}
}

template <class  T>
void Fila<T>::pop(int index){
	if (!this->empty()){
		if (index <= this->top && index >= 0){
			for (int i = index + 1; i < top; ++i){
				this->elements[i - 1] = this->elements[i];
			}
			this->top -= 1;
		}
	}
}

template <class  T>
void Fila<T>::push(T element){
	if (this->top < this->capacity - 1){
		this->top += 1;
		this->elements[this->top] = element; 
	}
}

template <class  T>
int Fila<T>::size(){
	return this->top + 1;
}

template <class  T>
void Fila<T>::resize(int new_size){
	T* temp = new T[new_size];
	int new_top = -1;
	for (int i = 0; i <= this->top && i < new_size; ++i){
		temp[i] = this->elements[i];
		new_top++;
	}
	delete[] this->elements;
	this->elements = temp;
	this->top = new_top;
}

template <class  T>
Fila<T>::~Fila(){
	delete[] this->elements;
}