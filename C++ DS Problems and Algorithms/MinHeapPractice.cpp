#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
	int *arr;
	int size;
	int capacity;
	MinHeap(int c)
	{
		arr = new int[c];
		size = 0;
		capacity = c;
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
		arr[size]=x;
		for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];)
		{
			swap(arr[parent(i)],arr[i]);
			i=parent(i);
		}
	}

	void minHeapify(int i)
	{
		int smallest=i,lt=left(i),rt=right(i);

		if(lt<size && arr[lt]<arr[i])
			smallest=lt;
		if(rt<size && arr[rt]<arr[smallest])
			smallest=rt;

		if(i!=smallest)
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
			swap(arr[i],arr[parent(i)]);
			i=parent(i);
		}
	}

	int buildHeap(int i)
	{
		for(int i=(size-2)/2;i>=0;i++)
			minHeapify(i);
	}

	int deletekey()
	{
		decreaseKey(i,INT_MIN);
		extractMin();
	}

	void display()
	{
		for(int i=0;i<size;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
};