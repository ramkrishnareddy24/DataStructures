#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class minHeap
{
public:
	int *arr;
	int size;
	int capacity;
	minHeap(int c)
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

	void printHeap()
	{
		for(int i=0;i<size;i++)
			cout<<arr[i]<<" ";
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
};

int main()
{
	minHeap m(15);
	m.insert(40);
	m.insert(20);
	m.insert(15);
	m.insert(40);
	m.insert(50);
	m.insert(100);
	m.insert(25);
	m.insert(45);
	m.insert(12);
	m.printHeap(); cout<<endl;
	m.minHeapify(0);
	m.printHeap(); cout<<endl;
	cout<<m.extractMin()<<endl;
	m.printHeap();

}