#ifndef _TC
#define _TC

using namespace std;

template <typename T>
class TContainer {
private:
	int MaxSize;
	int step;
	int pos;
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
	TContainer() {
		MaxSize = 0;
		size = 0;
		step = 50;
		pos = 0;
		MaxSize += step;
		elements = new T[MaxSize];
		step = MaxSize * 0.1;
	}
	TContainer(int _MaxSize) {
		MaxSize = _MaxSize;
		step = 0.1 * MaxSize;
		size = 0;
		elements = new T[MaxSize];
	}
	~TContainer() { 
		delete[] elements;
	}
	
	// ----- перегрузки -----
	T& operator[](int ind) const { return elements[ind]; }
	bool operator == (const TContainer<T>& element) const {
		if (size != element.size) return false;
		for (int i = 0; i < size; i++) {
			if (elements[i] != element.elements[i]) return false;
		}
		return true;
	}
	friend istream& operator >> (istream& in, TContainer<T>& element) {
		in >> element;
		return in;
	}
	friend ostream& operator << (istream& out, const TContainer<T>& element) {
		out << element;
		return out;
	}

	// ----- геттеры/сеттеры -----
	int GetPos() const { return pos; }
	int GetSize() const { return size; }
	int GetMSize() const { return MaxSize; }
	void SetSize(int _size) { size = _size; }

	// ----- переход к следующему/передыдущему, сброс -----
	void next() { pos = (pos + 1) % MaxSize; }
	void back() { pos = (pos - 1) % MaxSize; }
	void reset() { pos = 0; }

	// ----- вставка/удаление перед/после текущего -----
	void PozIns(const T& element, int n = 0) { // n = 1 для вставки после
		int tmp = size - 1;
		if (size == MaxSize) realloc();
		for (int i = size - 1; i > pos - n; i--) {
			elements[i + 1] = elements[i];
			tmp = i;
		}
		pos = tmp;
		size += 1;
		elements[pos] = element;
	}
	void PozRem(int n = 1) { // n = -1 для удаления после
		for (int i = pos + n; i < size; i++) {
			elements[i] = elements[i + 1];
		}
		size -= 1;
	}

	// ----- вставка/удаление из любой позиции -----
	void insert(const T& element, int index) {
		if (size == MaxSize) realloc();
		for (int i = size - 1; i >= index; i--) {
			elements[i + 1] = elements[i];
		}
		pos = index;
		size += 1;
		elements[pos] = element;
	}
	void remove(int index) {
		for (int i = index; i < size; i++) {
			elements[i] = elements[i + 1];
		}
		size -= 1;
	}

	// ----- поиск -----
	long int id(const T& value) const  {
		for (int i = 0; i < size; i++) {
			if (elements[i] == value) return i;
		}
		return -1;
	}
}; 



#endif