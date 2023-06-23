#include<bits/stdc++.h>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool swapped = false;
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

// Naive Selection sort
void selectionSort(int arr[],int n)
{
	int temp[n];
	for(int i=0;i<n;i++)
	{
		int min_ind=0;
		for(int j=1;j<n;j++)
		{
			if(arr[j]<arr[min_ind])
				min_ind=j;
		}
		temp[i]=arr[min_ind];
		arr[min_ind]=INT_MAX;
	}
	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}

// Optimized Selection Sort
void SelectionSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int minInd = i;
		for(int j=i+1;j<n;j++)
			if(arr[j]<arr[minInd])
				minInd = j;
		swap(arr[minInd],arr[i]);
	}
}

// Insertion Sort
void insertionSort(int arr[],int n)
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

// Merge Two Sorted arrays
// Naive Solution
void mergeTwoSortedArrays(int a[],int b[],int m,int n)
{
	int c[m+n];
	for(int i=0;i<m;i++)
		c[i]=a[i];
	for(int i=0;i<n;i++)
		c[m+i]=b[i];

	sort(c,c+m+n);

	for(int i=0;i<m+n;i++)
		cout<<c[i]<<" ";
	cout<<endl;
}

// Merge Two Sorted arrays
// Optimized Solution
void MergeTwoSortedArrays(int a[],int b[],int m,int n)
{
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(a[i]<=b[j])
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
	int n1 = m-l+1,n2 = r-m;

	int left[n1],right[n2];

	for(int i=0;i<n1;i++)
		left[i] = arr[l+i];
	for(int j=0;j<n2;j++)
		right[j] = arr[m+1+j];

	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	while(i<n1) arr[k++] = left[i++];
	while(j<n2) arr[k++] = right[j++];
}

void mergeSort(int arr[],int l,int r)
{
	if(r>l)
	{
		int m = l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

// Quick Sort using Lomuto Partition
int lomutoPartition(int arr[],int l,int h)
{
	int pivot = arr[h];
	int i = l-1;

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

void quickSort(int arr[],int l,int h)
{
	if(h>l)
	{
		int pivot = lomutoPartition(arr,l,h);
		quickSort(arr,l,pivot-1);
		quickSort(arr,pivot+1,h);
	}
}

// Quick Sort using Hoare's Partition
int hoarePartition(int arr[],int l,int h)
{
	int p = arr[l];
	int i=l-1,j=h+1;

	while(true)
	{
		do
		{
			i++;
		}while(arr[i]<p);

		do
		{
			j--;
		}while(arr[j]>p);

		if(i>=j) return j;
		swap(arr[i],arr[j]);
	}
}

void QuickSort(int arr[],int l,int h)
{
	if(h>l)
	{
		int p = hoarePartition(arr,l,h);
		QuickSort(arr,l,p);
		QuickSort(arr,p+1,h);
	}
}

// Heap Sort
void maxHeapify(int arr[],int n,int i)
{
	int largest=i,left=2*i+1,right=2*i+2;

	if(left<n && arr[left]>arr[largest])
		largest = left;
	if(right<n && arr[right]>arr[largest])
		largest = right;

	if(largest!=i)
	{
		swap(arr[largest],arr[i]);
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
		swap(arr[0],arr[i]);
		maxHeapify(arr,i,0);
	}
}

// Intersection of two sorted arrays
int intersectionOfTwoArrays(int a[],int b[],int m,int n)
{
	unordered_set<int> s;
	for(int i=0;i<m;i++)
		s.insert(a[i]);

	int res=0;
	for(int j=0;j<n;j++)
	{
		if(s.find(b[j])!=s.end()){
			res++;
			s.erase(b[j]);
		}
	}
	return res;
}

// Union of two Sorted arrays
int unionOftwoSortedArrays(int a[],int b[],int m,int n)
{
	unordered_set<int> s;
	for(int i=0;i<m;i++)
		s.insert(a[i]);
	for(int j=0;j<n;j++)
		s.insert(b[j]);
	return s.size();
}

// Count Inversions in array :Naive
int countInversions(int arr[],int n)
{
	int res=0;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n;j++)
			if(arr[i]>arr[j])
				res++;
	return res;
}

// Count Inversions in array :Efficient
int countAndMerge(int arr[],int l,int m,int r)
{
	int n1 = m-l+1,n2 = r-m;
	int left[n1],right[n2];

	for(int i=0;i<n1;i++)
		left[i] = arr[l+i];
	for(int i=0;i<n2;i++)
		right[i] = arr[m+1+i];

	int i=0,j=0,k=l;
	int res=0;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
			arr[k++] = left[i++];
		else
		{
			arr[k++] = right[j++];
			res+=(n1-i);
		}
	}
	while(i<n1) arr[k++] = left[i++];
	while(j<n2) arr[k++] = right[j++];
	return res;
}

int countInversions(int arr[],int l,int r)
{
	int res=0;
	if(r>l)
	{
		int m = l+(r-l)/2;
		res+=countInversions(arr,l,m);
		res+=countInversions(arr,m+1,r);
		res+=countAndMerge(arr,l,m,r);
	}
	return res;
}

// Kth Smallest : Naive 
int kthSmallest(int arr[],int n,int k)
{
	sort(arr,arr+n);
	return arr[k-1];
}

// Kth SMallest :Efficient
int KthSmallest(int arr[],int n,int k)
{
	int l=0,r=n-1;

	while(l<=r)
	{
		int p = lomutoPartition(arr,l,r);

		if(p==k-1)
			return arr[p];

		if(p>k-1)
			r=p-1;
		else
			l=p+1;
	}
	return -1;
}

// Chocolate Distribution problem
int minDifference(int arr[],int n,int m)
{
	if(m>n) return -1;
	sort(arr,arr+n);

	int res=arr[m-1]-arr[0];
	for(int i=0;(i+m-1)<n;i++)
		res=min(res,arr[i+m-1]-arr[i]);
	return res;
}

// Sort two types of elements
// Segregate two types of elements
void SortTwo(int arr[],int n)
{
	int temp[n],i=0;
	for(int i=0;i<n;i++)
		if(arr[i]<0)
			temp[i]=arr[i];

	for(int j=0;j<n;j++)
		if(arr[j]>=0){
			temp[i]=arr[j];
			i++;
		}

	for(int i=0;i<n;i++)
		arr[i] = temp[i];
}

void SortTwoTypes(int arr[],int n)
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

		if(i>=j)
			return;
		swap(arr[i],arr[j]);
	}
}

// Sort three types of elements
// Segregate tthree types of elements
void SortThree(int arr[],int n)
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

	for(int k=0;k<n;k++)
		if(arr[k]==2)
		{
			temp[i]=arr[k];
			i++;
		}

	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}

// Sort Three Types of elements
// dutch National Flag Problem
void SortThreeTypes(int arr[],int n)
{
	int low=0,mid=0,high=n-1;

	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 0:swap(arr[low],arr[mid]);
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

// Maximum Guests
int maxGuests(int arr[],int dep[],int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);

	int i=1,j=0,curr=1,res=1;
	while(i<n && j<n)
	{
		if(arr[i] <= dep[j])
		{
			curr++;
			i++;
		}
		else
		{
			curr--;
			j++;
		}
		res = max(res,curr);
	}
	return res;
}

int main()
{
	int arr[] = {10,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	bubbleSort(arr,n);
	cout<<"bubbleSort :"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	selectionSort(arr,n);
	cout<<"selectionSort :"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	SelectionSort(arr,n);
	cout<<"Optimized SelectionSort :"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	insertionSort(arr,n);
	cout<<"insertionSort :"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	int a[] = {10,15,20,40};
	int b[] = {5,6,6,10,15};
	int p = sizeof(a)/sizeof(a[0]);
	int q = sizeof(b)/sizeof(b[0]);
	cout<<"mergeTwoSortedArrays :"<<endl;
	mergeTwoSortedArrays(a,b,p,q);
	cout<<"MergeTwoSortedArrays :"<<endl;
	MergeTwoSortedArrays(a,b,p,q);

	int arr1[] = {20,10,5,80,50,70,60};
	int n1 = sizeof(arr1)/sizeof(int);
	int l=0,r=n1-1;
	cout<<"mergeSort :"<<endl;
	mergeSort(arr1,l,r);
	for(int x:arr1)
		cout<<x<<" ";
	cout<<endl;

	cout<<"lomutoPartition quickSort :"<<endl;
	quickSort(arr1,l,r);
	for(int x:arr1)
		cout<<x<<" ";
	cout<<endl;
	cout<<"hoarePartition QuickSort :"<<endl;
	QuickSort(arr1,l,r);
	for(int x:arr1)
		cout<<x<<" ";
	cout<<endl;

	cout<<"heapSort :"<<endl;
	heapSort(arr1,n1);
	for(auto x:arr1)
		cout<<x<<" ";
	cout<<endl;

	cout<<"intersectionOfTwoArrays :"<<intersectionOfTwoArrays(a,b,p,q)<<endl;
	cout<<"unionOftwoSortedArrays :"<<unionOftwoSortedArrays(a,b,p,q)<<endl;

	int arr2[] = {13,-12,8,-10};
	int n2 = sizeof(arr2)/sizeof(int);
	cout<<"SortTwo :"; SortTwo(arr2,n2);
	for(int x:arr2)
	cout<<x<<" ";
	cout<<endl;
	cout<<"SortTwoTypes :";
	SortTwoTypes(arr2,n2);
	for(int x:arr2)
	cout<<x<<" ";
	cout<<endl;

	int arr3[]={1,2,2,1,0,1,0,0,2,1};
	int n3 = sizeof(arr3)/sizeof(int);
	cout<<"SortThreeTypes :"; SortThreeTypes(arr3,n3);
	for(int x:arr3)
		cout<<x<<" ";
	cout<<endl;

	int arri[] = {900,600,700};
	int depa[] = {1000,800,730};
	int size = sizeof(arri)/sizeof(arri[0]);
	cout<<"maxGuests :"<<maxGuests(arri,depa,size)<<endl;

	return 0;
}