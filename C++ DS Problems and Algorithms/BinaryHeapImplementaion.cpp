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
		arr=new int[c];
		size=0;
		capacity=c;
	}

	int left(int i)
	{
		return (2*i+1);
	}

	int right(int i)
	{
		return (2*i+2);
	}

	int parent(int i)
	{
		return (i-1)/2;
	}

	void insert(int x)
	{
		if(size==capacity)
			return;
		size++;
		arr[size-1]=x;

		for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];)
		{
			swap(arr[parent(i)],arr[i]);
			i=parent(i);
		}
	}

	int minHeapify(int i)
	{
		int left=2*i+1,right=2*i+2;
		int smallest=i;

		if(left<size && arr[left]<arr[i])
			smallest=left;
		if(right<size && arr[right]<arr[smallest])
			smallest=right;

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
	
	void Delete(int key)
	{
		decreaseKey(key,INT_MIN);
		extractMin();
	}

	void buildHeap()
	{
		for(int i=(size-2)/2;i>=0;i--)
			minHeapify(i);
	}	
};


//Heap Sort //nlogn
void maxHeapify(int arr[],int n,int i)
{
	int largest=i,left=2*i+1,right=2*i+2;

	if(left<n && arr[left]>arr[largest])
		largest=left;
	if(right<n && arr[right]>arr[largest])
		largest=right;

	if(largest!=i)
	{
		swap(arr[largest],arr[i]);
		maxHeapify(arr,n,largest);
	}
}

void BuildHeap(int arr[],int n)
{
	for(int i=(n-2)/2;i>=0;i--)
		maxHeapify(arr,n,i);
}

void heapSort(int arr[],int n)
{
	BuildHeap(arr,n);
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		maxHeapify(arr,i,0);
	}
}

// Purchasing Maximum Items //nlogn
//Sorting Solution //Method-1
int purchaseItems(int arr[],int n,int sum)
{
	sort(arr,arr+n);
	int res=0;

	for(int i=0;i<n;i++)
	{
		if(sum>=arr[i])
		{
			sum=sum-arr[i];
			res++;
		}
	}
	return res;
}

// Purchasing Maximum Items
// Method-2 using Heap
int PurchaseItems(int arr[],int n,int sum)
{
	priority_queue<int,vector<int>,greater<int>> pq;

	for(int i=0;i<n;i++)
		pq.push(arr[i]);

	int res=0;
	for(int i=0;i<n;i++)
	{
		if(sum>=pq.top())
		{
			sum=sum-pq.top();
			pq.pop();
			res++;
		}
	}

	return res;
}

// K-Largest Elements
void kLargest(int arr[],int n,int k)
{
	MinHeap *m = new MinHeap(k); //create minheap of K elements

	for(int i=k+1;i<n;i++) //traverse from k+1
	{
		if(arr[0]>arr[i]) // if top of heap is greater than current continue
			continue;
		else
		{
			arr[0]=arr[i];
			m->minHeapify(0);
		}
	}

	for(int i=0;i<k;i++)
		cout<<arr[i]<<" ";
}

// Sort K-Sorted Arrays
void SortKLargest(int arr[],int n,int k)
{
	priority_queue<int,vector<int>,greater<int>> pq;

	for(int i=0;i<=k;i++)
		pq.push(arr[i]);

	int index=0;
	for(int i=k+1;i<n;i++)
	{
		arr[index++]=pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while(!pq.empty())
	{
		arr[index++]=pq.top();
		pq.pop();
	}
}

// Merge K-Sorted Arrays
struct Triplet
{
	int value,aPos,vPos;
	Triplet(int v,int ap,int vp)
	{
		value=v;
		aPos=ap;
		vPos=vp;
	}
};
struct myCmp
{
	bool operator()(Triplet str1,Triplet str2)
	{
		return str1.value>str2.value;
	}
};
vector<int> mergeArr(vector<vector<int>> &arr)
{
	vector<int> res;
	priority_queue<Triplet,vector<Triplet>,myCmp> pq;
	for(int i=0;i<arr/size();i++)
	{
		Triplet t(arr[i][0],i,0);
		pq.push(t);
	}

	while(!pq.empty())
	{
		Triplet arr = pq.top(); pq.pop();
		res.push_back(curr.value);
		if(vp+1<arr[p].size())
		{
			Triplet t(arr[ab]+0,ap,vp+1);
			pq.push(t);
		}
	}
	return res;
}

int main()
{
	int arr[]={1,12,5,111,200};
	int n=sizeof(arr)/sizeof(arr[0]);

	// heapSort(arr,n);

	// for(int x:arr)
	// 	cout<<x<<" ";

	cout<<purchaseItems(arr,n,10)<<" ";
	cout<<PurchaseItems(arr,n,10);
	// kLargest(arr,n,2);

}