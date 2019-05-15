#ifndef CONTAINER2_H
#define CONTAINER2_H
#define MAX 20

template <typename T, int maxsize> 
class ContainerA
{
private:
	T** m;
	int s; 
public:
	ContainerA();
	ContainerA(int _s);
	ContainerA(const ContainerA& c);
	~ContainerA();

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
ContainerA <T, maxsize>::ContainerA <T,maxsize>()
{
	s = 0;
	m = new T*[MAX];
}

template <typename T, int maxsize>
ContainerA <T, maxsize>::ContainerA <T,maxsize>(int _s)
{
	s = _s;
	m = new T*[MAX];
	for(int i = 0; i < s; i++)
	{
	m = new T;
	}
}

template <typename T, int maxsize>
ContainerA <T, maxsize>::ContainerA < T, maxsize> (const ContainerA &c)
{
	s = c.s;
	m = new T*[MAX];
	for (int i = 0; i < s; i++)
	{
		m = new T;
		*(m[i]) = c.*m[i];
	}
}

template <typename T, int maxsize>
ContainerA <T, maxsize>::~ContainerA <T,maxsize>()
{
	for (int i = 0; i < s; i++)
		delete []m[i];
	delete []m;
	s = 0;
}

template <typename T, int maxsize>
bool ContainerA <T, maxsize>::IsFull() const
{
	if (s == MAX)
		return true;
	return false;
}

template <typename T, int maxsize>
bool ContainerA <T, maxsize>::IsEmpty() const
{
	if (s == 0)
		return true;
	return false;
}

template <typename T, int maxsize>
void ContainerA <T, maxsize>::Fill()
{
	cout << "Enter array elements" << endl;
	if(IsEmpty()) 
		throw "Array is empty";
	for (int i = 0; i < s; i++)
    {
        cin >> *m[i];
    }
}

template <typename T, int maxsize>
void ContainerA <T, maxsize>::Print() 
{
	cout << "Enter array elements" << endl;
	if(IsEmpty()) 
		throw "Array is empty";
	for (int i = 0; i < s; i++)
    {
        cout << *m[i] << " ";
    }
    cout << endl;
}

template <typename T, int maxsize>
int ContainerA <T, maxsize>::Find(T n) const
{
	for (int i = 0; i < n; i++)
        if (*m[i] == a)
            return i;
    throw "Item not found";
}

template <typename T, int maxsize>
void ContainerA <T, maxsize>::Add(T n)
{
	if (IsFull())
		throw "The array is full, you cannot add a new item";
	m[s] = new T;
	*m[s] = n;
	s++;
}

template <typename T, int maxsize>
void ContainerA <T, maxsize>::Delete(T n)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	int i;
	i = Find(n);
	*m[i] = *m[s - 1];
	delete *m[s - 1];
}

template <typename T, int maxsize>
T* ContainerA <T, maxsize>::operator[](int i) const
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= s))
		throw "Wrong index";
	return m[s];
}

#endif