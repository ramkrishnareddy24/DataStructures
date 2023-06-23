#include<bits/stdc++.h>
using namespace std;

int bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool swapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}
		if(swapped==false)
			break;
	}
}

int selectionSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int minInd=i;
		for(int j=i+1;j<n;j++)
			if(arr[j]<arr[minInd])
			{
				minInd=j;
				swap(arr[j],arr[minInd]);
			}
	}
}

int insertionSort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void mergeTwoSortedArrays(int a[],int m,int b[],int n)
{
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
			cout<<a[i++]<<" ";
		else
			cout<<b[j++]<<" ";
	}

	while(i<m) cout<<a[i++]<<" ";
	while(j<n) cout<<b[j++]<<" ";
	cout<<endl;
}

// Merge Sort
void merge(int arr[],int l,int m,int r)
{
	int n1=m-l+1,n2=r-m;
	int left[n1],right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		right[j]=arr[m+1+j];

	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
			arr[k++]=left[i++];
		else
			arr[k++]=right[j++];
	}

	while(i<n1) arr[k++]=left[i++];
	while(j<n2) arr[k++]=right[j++];
}

void mergeSort(int arr[],int l,int r)
{
	if(r>l)
	{
		int m=l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

// Quick Sort
int hoarePartition(int arr[],int l,int h)
{
	int p=arr[l];
	int i=l-1,j=h+1;

	while(true)
	{
		do{
			i++;
		}while(arr[i]<p);

		do{
			j--;
		}while(arr[j]>p);

		if(i>=j) return j;
		swap(arr[i],arr[j]);
	}
}

void quickSort(int arr[],int l,int h)
{
	if(h>l)
	{
		int p=hoarePartition(arr,l,h);
		quickSort(arr,l,p);
		quickSort(arr,p+1,h);
	}
}

// Heap Sort
void maxHeapify(int arr[],int n,int i)
{
	int largest=i,left=2*i+1,right=2*i+2;

	while(left<n && arr[left]>arr[largest])
		largest=left;
	while(right<n && arr[right]>arr[largest])
		largest=right;

	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		maxHeapify(arr,n,largest);
	}
}

void buildHeap(int arr[],int n)
{
	for(int i=(n-2)/2;i>=0;i--)
		maxHeapify(arr,n,i);
}

void heapSort(int arr[],int n)
{
	buildHeap(arr,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(arr[i],arr[0]);
		maxHeapify(arr,i,0);
	}
}

// intersection
int intersection(int a[],int m,int b[],int n)
{
	unordered_set<int> s;
	for(int i=0;i<m;i++)
		s.insert(a[i]);

	int res=0;
	for(int i=0;i<n;i++)
	{
		if(s.find(b[i])!=s.end())
			res++;
		s.erase(b[i]);
	}
	return res;
}

// Union
int Union(int a[],int m,int b[],int n)
{
	unordered_set<int> s;
	for(int i=0;i<m;i++)
		s.insert(a[i]);
	for(int i=0;i<n;i++)
		s.insert(b[i]);
	return s.size();
}

// Count Inversions
int countAndMerge(int arr[],int l,int m,int r)
{
	int n1=m-l+1,n2=r-m;
	int left[n1],right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(int i=0;i<n2;i++)
		right[i]=arr[m+1+i];

	int i=0;j=0,k=l;
	int res=0;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
			arr[k++]=left[i++];
		else
		{
			arr[k++]=right[j++];
			res+=(n1-i);
		}
	}

	while(i<n1) arr[k++]=left[i++];
	while(j<n2) arr[k++]=right[j++];

	return res;
}

int countInversions(int arr[],int l,int r)
{
	int res=0;
	if(r>l)
	{
		int m=r-(l+r)/2;
		res+=countAndMerge(arr,l,m);
		res+=countAndMerge(arr,m+1,r);
		res+=countInversions(arr,l,m,r);
	}
}

// Chocolate Distribution
int minDifference(int arr[],int n,int m)
{
	if(m>n) return -1;
	sort(arr,arr+n);

	int res=arr[m-1]-arr[0];
	for(int i=0;(i+m-1)<n;i++)
		res=min(res,arr[i+m-1]-arr[i]);
	return res;
}

// Sort two types
void sortTwoTypes(int arr[],int n)
{
	int temp[n],i=0;
	for(int i=0;i<n;i++)
		if(arr[i]<0)
			temp[i]=arr[i];

	for(int j=0;j<n;j++)
	{
		if(arr[j]>=0)
		{
			temp[i]=arr[j];
			i++;
		}
	}

	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}

int sortTwo(int arr[],int n)
{
	int i=-1,j=n;
	
	while(true)
	{
		do{
			i++;
		}while(arr[i]<0);

		do{
			j--;
		}while(arr[j]>=0);

		if(i>=j) return;
		swap(arr[i],arr[j]);
	}
}

// Sort Three Types
void sortThreeTypes(int arr[],int n)
{
	int temp[n],i=0;
	for(int i=0;i<n;i++)
		if(arr[i]==0)
			temp[i]=arr[i];
	for(int j=0;j<n;j++)
		if(arr[j]==1)
		{
			temp[i]=arr[j];
			i++;
		}

	for(int k=0;k<n;i++)
		if(arr[k]==2)
		{
			temp[i]=arr[k];
			i++;
		}

	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}

// Sort Three
// Dutch National Flag problem
void sortThree(int arr[],int n)
{
	int low=0,mid=0,high=n-1;

	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 0:swap(arr[mid],arr[low]);
				low++;
				mid++;
				break;
			case 1:mid++;
				break;
			case 2:swap(arr[mid],arr[high]);
				high--;
				break;
		}
	}
}

int lomutoPartition(int arr[],int l,int h)
{
	int i=l-1;
	int pivot=arr[h];

	for(int j=l;j<=h;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}

int kSmallest(int arr[],int n,int k)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int p=lomutoPartition(arr,l,r);

		if(p==k-1)
			return arr[p];

		if(k-1<p)
			r=p-1;
		else
			l=p+1;
	}
	return -1;
}

int main()
{
	int arr[] = {10,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	bubbleSort(arr,n);
	cout<<"bubbleSort :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	selectionSort(arr,n);
	cout<<"selectionSort :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	insertionSort(arr,n);
	cout<<"insertionSort :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	int a[] = {10,15,20,40};
	int b[] = {5,6,6,10,15};
	int p = sizeof(a)/sizeof(a[0]);
	int q = sizeof(b)/sizeof(b[0]);
	cout<<"mergeTwoSortedArrays :"<<endl;
	mergeTwoSortedArrays(a,p,b,q);

	int arr1[] = {20,10,5,80,50,70,60};
	int n1 = sizeof(arr1)/sizeof(int);
	int l=0,r=n1-1;
	cout<<"mergeSort :"<<endl;
	mergeSort(arr1,l,r);
	for(int x:arr1)
		cout<<x<<" ";
	cout<<endl;

	cout<<"hoarePartition QuickSort :"<<endl;
	quickSort(arr1,l,r);
	for(int x:arr1)
		cout<<x<<" ";
	cout<<endl;

	cout<<"heapSort :"<<endl;
	heapSort(arr1,n1);
	for(auto x:arr1)
		cout<<x<<" ";
	cout<<endl;

	cout<<"intersectionOfTwoArrays :"<<intersection(a,p,b,q)<<endl;
	cout<<"unionOftwoSortedArrays :"<<Union(a,p,b,q)<<endl;

}