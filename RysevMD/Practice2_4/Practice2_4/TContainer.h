#ifndef _TC
#define _TC

using namespace std;

template <typename T>
class TContainer {
private:
	int MaxSize;
	int step;
	int poz = 0;
	int size;
	T* elements;
	
	void realloc() {
		MaxSize += step;
		T* tmp = new T[MaxSize];
		for (int i = 0; i < size; i++) {
			tmp[i] = elements[i];
		}
		delete[] elements;
		elements = tmp;
	}
public:
	TContainer(int _MaxSize) {
		MaxSize = _MaxSize;
		step = 0.1 * MaxSize;
		size = 0;
		elements = new T[MaxSize];
	}
	~TContainer() { delete[] elements; }

	T& operator[](int ind) { return elements[ind]; }

	int GetPoz() { return poz; }
	int GetSize() { return size; }
	int GetMSize() { return MaxSize; }

	// переход к следущему/передыдущему
	void next() { poz = (poz + 1) % MaxSize; }
	void back() { poz = (poz - 1) % MaxSize; }

	// -----вставка/удаление перед/после текущего-----
	void PozIns(const T& element, int n = 0) { // n = 1 для вставки после
		int tmp = size - 1;
		if (size == MaxSize) realloc();
		for (int i = size - 1; i > poz - n; i--) {
			elements[i + 1] = elements[i];
			tmp = i;
		}
		poz = tmp;
		size += 1;
		elements[poz] = element;
	}
	void PozRem(int n = 1) { // n = -1 для удаления после
		for (int i = poz + n; i < size; i++) {
			elements[i] = elements[i + 1];
		}
		size -= 1;
	}

	// -----вставка/удаление из любой позиции-----
	void insert(const T& element, int index) {
		if (size == MaxSize) realloc();
		for (int i = size - 1; i >= index; i--) {
			elements[i + 1] = elements[i];
		}
		poz = index;
		size += 1;
		elements[poz] = element;
	}
	void remove(int index) {
		for (int i = index; i < size; i++) {
			elements[i] = elements[i + 1];
		}
		size -= 1;
	}
};  

#endif