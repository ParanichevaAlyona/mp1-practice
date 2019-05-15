#ifndef CONTAINER_H
#define CONTAINER_H
#define MAX 20

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
	T* operator[](int i) const;
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
	if (size == MAX)
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
	if(IsEmpty()) 
		throw "Array is empty";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <typename T, int maxsize>
int Container <T, maxsize>::Find(T n) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == n) return i;
	}
	throw "Item not found";
}

template <typename T, int maxsize>
void Container <T, maxsize>::Add(T n)
{
	if (IsFull())
		throw "The array is full, you cannot add a new item";
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
}

template <typename T, int maxsize>
T* Container <T, maxsize>::operator[](int i) const
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= size))
		throw "Wrong index";
	return &arr[i];
}

#endif