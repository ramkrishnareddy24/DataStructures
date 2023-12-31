template<typename T>
class vector
{
    int cs;
    int ms;
    T *arr;

public:
	vector()
	{
		cs=0;
		ms=1;
		arr=new T[ms];
	}
	void push_back(const T d)
	{
       if(cs==ms)
       {
       	T *oldArr=arr;
       	arr=new T[2*ms];
       	ms=2*ms;
       	for(int i=0;i<cs;i++)
       	{
       		arr[i]=oldArr[i];
       	}
       	delete [] oldArr;
       } 
       arr[cs]=d;
       cs++;
	}
	void pop_back()
	{
		cs--;
	}
	T front() const
	{
		return arr[0];
	}
	T back() const
	{
		return arr[cs-1];
	}
	bool empty() const
	{
		return cs==0;
	}
	bool capacity()
	{
		return ms;
	}
	T at(const int i)
	{
		return arr[i];
	}
	int size()
	{
		return cs;
	}

	T operator[](const int i)
	{
		return arr[i];
	}
};