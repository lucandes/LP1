#ifndef FILA_H
#define FILA_H

template <class T>
class Fila{
private:
	int capacity;
	int top;
	T* elements;
public:
	Fila(int size);
	T back();
	T front();
	bool empty();
	void pop();
	void pop(int index);
	void push(T element);
	int size();
	void resize(int new_size);
	~Fila();
};

#endif