#ifndef CONTAINERA_H
#define CONTAINERA_H

template <typename T, int maxsize> 
class Container<T*, maxsize>
{
private:
	T** m;
	int s; 
public:
	Container();
	Container(int _s);
	Container(const Container& c);
	~Container();

	bool IsFull() const;
	bool IsEmpty() const;

	void Fill();
	void Print();
	int Find(T n) const;
	void Add(T n);
	void Delete(T n);
	T& operator[](int i);
	const T& operator[](int i) const;
	void Resize(int n);
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container()
{
	s = 0;
	m = new T*[MAX];
}

template <typename T, int maxsize>
Container <T*, maxsize>::Container(int _s)
{
	s = _s;
	m = new T*[maxsize];
	for(int i = 0; i < s; i++)
	{
	m[i] = new T;
	}
}

template <typename T, int maxsize>
Container <T*, maxsize>::Container(const Container &c)
{
	s = c.s;
	m = new T*[MAX];
	for (int i = 0; i < s; i++)
	{
		m = new T;
		m[i] = c->m[i];
	}
}

template <typename T, int maxsize>
Container <T*, maxsize>::~Container()
{
	for (int i = 0; i < s; i++)
		delete []m[i];
	delete []m;
	s = 0;
}

template <typename T, int maxsize>
bool Container <T*, maxsize>::IsFull() const
{
	if (s == maxsize)
		return true;
	return false;
}

template <typename T, int maxsize>
bool Container <T*, maxsize>::IsEmpty() const
{
	if (s == 0)
		return true;
	return false;
}

template <typename T, int maxsize>
void Container <T*, maxsize>::Fill()
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
void Container <T*, maxsize>::Print() 
{
	for (int i = 0; i < s; i++)
        cout << *m[i] << " ";
    cout << endl;
}

template <typename T, int maxsize>
int Container <T*, maxsize>::Find(T n) const
{
	for (int i = 0; i < s; i++)
        if (*m[i] == n)
            return i;
    throw "Item not found";
}

template <typename T, int maxsize>
void Container <T*, maxsize>::Add(T n)
{
	if (IsFull())
		this->Resize(1);
	m[s] = new T;
	*m[s] = n;
	s++;
}

template <typename T, int maxsize>
void Container <T*, maxsize>::Delete(T n)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	int i;
	i = Find(n);
	*m[i] = *m[s - 1];
	delete m[s - 1];
	s--;
}

template <typename T, int maxsize>
T& Container <T*, maxsize>::operator[](int i)
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= s))
		throw "Wrong index";
	return *m[s];
}

template <typename T, int maxsize>
const T& Container <T*, maxsize>::operator[](int i) const
{
	if(IsEmpty())
		throw "The array is empty, you can not delete item";
	if((i < 0) || (i >= s))
		throw "Wrong index";
	return *m[s];
}

template <typename T, int maxsize>
void Container <T*, maxsize>::Resize(int n = 1)
{
	T **tmp = new T*[s];
	for (int i = 0; i < s; i++)
		tmp[i] = m[i];
	delete m;
	m = new T*[s + n];
	for (int i = 0; i < s; i++)
		m[i] = tmp[i];
	delete []tmp;
}

#endif
