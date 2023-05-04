#ifndef _TC
#define _TC

using namespace std;

template <typename T>
class Tcontainer {
private:
	int max_size;
	int step = 10;
	int poz = 0;
	T* elements;
public:
	int size = 0;
	Tcontainer(int _max_size) {
		max_size = _max_size;
		elements = new T[max_size];
	}
	~Tcontainer() { delete[] elements; }

	T& operator[](int ind) { return elements[ind]; }

	void set_poz(int n) { poz = n; }
	int get_poz() { return poz; }

	// переход к следущему/передыдущему
	void next() { poz = (poz + 1) % max_size; }
	void back() { poz = (poz - 1) % max_size; }  

	 // -----вставка/удаление перед/после текущего-----
	void pozins(const T& element, int n = 0) { // n = 1 для вставки после
		int tmp = size - 1;
		for (int i = size - 1; i > poz - n; i--) {
			elements[i + 1] = elements[i];
			tmp = i;
		}
		poz = tmp;
		size += 1;
		elements[poz] = element;
	}
	void pozrem(int n = 1) { // n = -1 для удаления после
		for (int i = poz + n; i < size; i++) {
			elements[i] = elements[i + 1];
		}
		size -= 1;
	}

	// -----вставка/удаление из любой позиции-----
	void insert(const T& element, int index) {
		for (int i = size - 1; i >= index; i--) {
			elements[i + 1] = elements[i];
		}
		poz = index;
		size += 1;
		elements[poz] = element;
	}
	void remove(int index) {
		for (int i = 0; i < size; i++) {
			elements[i] = elements[i + 1];
		}
		size -= 1;
	}
};

#endif 

