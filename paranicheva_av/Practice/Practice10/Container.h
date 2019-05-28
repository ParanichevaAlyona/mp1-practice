#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T, int maxsize> 
class Container
{
private:
	T* arr;
	int size; 
public:
	Container();
	Container(int _size);
	Container(const Container& c);
	~Container();

	bool IsFull() const;
	bool IsEmpty() const;

	void Fill();
	void Print();
	int Find(T n) const;
	void Add(T n);
	void Delete(T n);
	T operator[](int i);
	const T operator[](int i) const;
	void Resize(int n);
};

template <typename T, int maxsize>
Container <T, maxsize>::Container <T,maxsize>()
{
	size = 0;
	arr = new T*[MAX];

}

template <typename T, int maxsize>
Container <T, maxsize>::Container <T,maxsize>(int _size)
{
	size = _size;
	arr = new T[size];
}

template <typename T, int maxsize>
Container <T, maxsize>::Container < T, maxsize> (const Container &c)
{
	size = c.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = c.arr[i];
}

template <typename T, int maxsize>
Container <T, maxsize>::~Container <T,maxsize>()
{
	delete []arr;
	size = 0;
}

template <typename T, int maxsize>
bool Container <T, maxsize>::IsFull() const
{
	if (size == maxsize)
		return true;
	return false;
}

template <typename T, int maxsize>
bool Container <T, maxsize>::IsEmpty() const
{
	if (size == 0)
		return true;
	return false;
}


template <typename T, int maxsize>
void Container <T, maxsize>::Fill()
{
	cout << "Enter array elements" << endl;
	if(IsEmpty()) 
		throw "Array is empty";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}

template <typename T, int maxsize>
void Container <T, maxsize>::Print()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <typename T, int maxsize>
int Container <T, maxsize>::Find(T n) const
{
	for (int i = 0; i < size; i++)
		if (arr[i] == n) return i;
	throw "Item not found";
}

template <typename T, int maxsize>
void Container <T, maxsize>::Add(T n)
{
	if (IsFull())
		this->Resize(1);
	arr[size] = n;
	size++;
}

template <typename T, int maxsize>
void Container <T, maxsize>::Delete(T n)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	int i;
	i = Find(n);
	arr[i] = arr[size - 1];
	arr[size - 1] = 0;
	size--;
}

template <typename T, int maxsize>
T Container <T, maxsize>::operator[](int i)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= size))
		throw "Wrong index";
	return arr[i];
}

template <typename T, int maxsize>
const T Container <T, maxsize>::operator[](int i) const
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= size))
		throw "Wrong index";
	return arr[i];
}

template <typename T, int maxsize>
void Container <T, maxsize>::Resize(int n = 1)
{
	T *tmp = new T[size];
	for (int i = 0; i < size; i++)
		tmp[i] = arr[i];
	delete []arr;
	arr = new T[size + n];
	for (int i = 0; i < size; i++)
		arr[i] = tmp[i];
}

#endif
