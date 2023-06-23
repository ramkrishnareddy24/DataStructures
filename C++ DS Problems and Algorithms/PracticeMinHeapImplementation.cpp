#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
	int *arr;
	int size;
	int capacity;
	MinHeap(int c)
	{
		arr = new int[c];
		size=0;
		capacity=c;
	}

	int left(int i){
		return 2*i+1;
	}

	int right(int i){
		return 2*i+2;
	}

	int parent(int i){
		return (i-1)/2;
	}

	void insert(int x)
	{
		if(size==capacity) return;

		size++;
		arr[size-1]=x;
		for(int i=size-1; i!=0 && arr[parent(i)]>arr[i];)
		{
			swap(arr[i],arr[parent(i)]);
			i=parent(i);
		}
	}

	void minHeapify(int i)
	{
		int lt=left(i),rt=right(i);
		int smallest=i;

		if(lt<size && arr[lt]<arr[i])
			smallest=lt;
		if(rt<size && arr[rt]<arr[smallest])
			smallest=rt;

		if(smallest!=i)
		{
			swap(arr[i],arr[smallest]);
			minHeapify(smallest);
		}
	}

	int extractMin()
	{
		if(size==0)
			return INT_MAX;
		if(size==1)
		{
			size--;
			return arr[0];
		}

		swap(arr[0],arr[size-1]);
		size--;
		minHeapify(0);
		return arr[size];
	}

	void decreaseKey(int i,int x)
	{
		arr[i]=x;
		while(i!=0 && arr[parent(i)]>arr[i])
		{
			swap(arr[parent(i)],arr[i]);
			i=parent(i);
		}
	}

	void buildHeap(int i)
	{
		for(int i=(size-2)/2;i>=0;i--)
			minHeapify(i);
	}

	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	int KthSmallest(MinHeap &m,int k)
	{
		for(int i=1;i<k;++i)
			extractMin();
		return extractMin();
	}

};

int main()
{
	MinHeap m(10);
	m.insert(5);
	m.insert(10);
	m.insert(15);
	m.insert(25);
	m.insert(35);
	m.insert(45);
	m.insert(55);
	m.insert(9);
	//cout<<m.extractMin()<<endl;
	m.display();
	int k=4;
	cout<<m.KthSmallest(m,k);
}