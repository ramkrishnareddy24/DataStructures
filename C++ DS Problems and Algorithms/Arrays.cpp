#include<bits/stdc++.h>
using namespace std;

int insert(int arr[],int n,int pos,int x,int cap)
{
	if(n==cap) return n;
	int idx=pos-1;
	for(int i=n-1;i>=idx;i--)
		arr[i]=arr[i+1];
	arr[idx]=x;
	return n+1;
}

int Delete(int arr[],int n,int x)
{
	int i;
	for(int i=0;i<n;i++)
		if(arr[i]==x)
			break;
	if(i==n)
		return n;
	for(int j=i;j<n-1;j++)
		arr[j+1]=arr[j];
	return n-1;
}

int largest(int arr[],int n)
{
	int max=arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]>max)
			max=arr[i];
	return max;
}

int secondLargest(int arr[],int n)
{
	int largest=0,secondLargest=-1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[largest])
		{
			secondLargest=largest;
			largest=i;
		}
		else if(arr[i]!=arr[largest])
		{
			if(secondLargest==-1 || arr[i]>arr[secondLargest])
				secondLargest = i;
		}
	}
	return arr[secondLargest];
}

// second Largest Num in string
int secondHighest(string s) {
        int first=-1,second=-1;
        for(const auto& c:s)
        {
            if(!isdigit(c))
                continue;
        
        
	        int d = c-'0';
	        if(d>first)
	        {
	            second=first;
	            first=d;
	        }
	        else if(first > d && d>second)
	            second=d;
        }
        return second;
}


void moveZeroToEnd(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
		if(arr[i]!=0)
		{
			swap(arr[i],arr[count]);
			count++;
		}
}

void Reverse(int arr[],int n)
{
	int l=0,r=n-1;;
	while(r>l)
	{
		swap(arr[l],arr[r]);
		l++;
		r--;
	}
}

void reverse(int arr[],int l,int r)
{
	while(l<r)
	{
		swap(arr[l],arr[r]);
		l++;
		r--;
	}
}

void leftRotate(int arr[],int n)
{
	int temp=arr[0];
	for(int i=1;i<n;i++)
		arr[i-1]=arr[i];
	arr[n-1]=temp;
}

void rightRotate(int arr[],int n)
{
	int temp=arr[n-1];
	for(int i=n-2;i>=0;i--)
		arr[i+1]=arr[i];
	arr[0]=temp;	
}

// leftRotate by D places
// Naive
void leftRotateByD(int arr[],int n,int d)
{
	for(int i=0;i<d;i++)
		leftRotate(arr,n);
}
// optimal
void leftRotateByDp(int arr[],int n,int d)
{
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);
}

// Leaders in Array
// Naive
void leader(int arr[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=i+1;j<n-1;j++)
		{
			if(arr[i]<=arr[j])
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
			cout<<arr[i]<<" ";
	}
}
// Efficient
void leadersArray(int arr[],int n)
{
	vector<int> v;
	int currldr=arr[n-1];
	v.push_back(currldr);

	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>currldr)
		{
			currldr=arr[i];
			v.push_back(currldr);
		}
	}
	reverse(v.begin(),v.end());

	for(int x:v)
		cout<<x<<" ";
}

// Max Difference
// Naive
int maxDiff(int arr[],int n)
{
	int res=arr[1]-arr[0];
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			res=max(res,arr[j]-arr[i]);
	return res;
}
// Optimal
int MaxDiff(int arr[],int n)
{
	int res=arr[1]-arr[0];
	int minVal=arr[0];

	for(int i=1;i<n;i++)
	{
		res=max(res,arr[i]-minVal);
		minVal=min(minVal,arr[i]);
	}
	return res;
}

// Max Difference Alternative
int maxDifference(int arr[],int n)
{
	int small=arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]<small)
			small=arr[i];

	int max=arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]>max)
			max=arr[i];

	return max-small;
}

// Stock buy and sell problem
vector<vector<int>> stockBuySell(vector<vector<int>> arr[],int n)
{
	vector<vector<int>> ans;

	for(int i=1;i<n;i++)
	{
		vector<int> v;
		if(arr[i]>arr[i-1])
		{
			v.push_back(i-1);

			while(i<n && arr[i]>arr[i-1])
				i++;

			v.push_back(i-1);
		}
		ans.push_back(v);
	}
	return ans;
} 

// Trapping Rain water
int TrapppingRainwater(int arr[],int n)
{
	int res=0;
	int lmax[n];
	int rmax[n];

	lmax[0]=arr[0];
	for(int i=1;i<n;i++)
		lmax[i]=max(arr[i],lmax[i-1]);

	rmax[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
		rmax[i]=max(arr[i],rmax[i+1]);

	for(int i=1;i<n-1;i++)
		res+=min(lmax[i],rmax[i])-arr[i];

	return res;
}

// Maximum Consecutive Ones
int maxOnes(int arr[],int n)
{
	int res=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
			cnt=0;
		else
		{
			cnt++;
			res=max(res,cnt);
		}
	}
	return res;
}

// Maximum SubArray Sum : Kadane Algorithm
int maxSubArraySum(int arr[],int n)
{
	int res=arr[0];
	int maxEnd=arr[0];
	for(int i=1;i<n;i++)
	{
		maxEnd = max(maxEnd+arr[i],arr[i]);
		res = max(res,maxEnd);
	}
	return res;
}

// longest Even Odd SubArray length
int longEvenOddSubArray(int arr[],int n)
{
	int res=1;
	int curr=1;

	for(int i=1;i<n;i++)
	{
		if((arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i]%2!=0 && arr[i-1]%2==0))
		{
			curr++;
			res = max(curr,res);
		}
		else
			curr = 1;
	}
	return res;
}

// Max Circular Sub Array Sum
int MaxSubArraySum(int arr[],int n)
{
	int res=arr[0];
	int maxEnding=arr[0];

	for(int i=1;i<n;i++)
	{
		maxEnding=max(arr[i],maxEnding+arr[i]);
		res=max(res,maxEnding);
	}
	return res;
}

int maxCircularSubArraySum(int arr[],int n)
{
	int maxNormal = MaxSubArraySum(arr,n);

	if(maxNormal<0)
		return maxNormal;

	int arr_sum=0;
	for(int i=0;i<n;i++)
	{
		arr_sum+=arr[i];
		arr[i]=-arr[i];
	}

	int maxCircular = arr_sum+MaxSubArraySum(arr,n);

	return max(maxNormal,maxCircular);
}

// Majority Element : Moore's Voting Algo
int majority(int arr[],int n)
{
	int count=1;
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(arr[res]==arr[i])
			count++;
		else
			count--;

		if(count==0)
		{
			count=1;
			res=i;
		}
	}

	count=0;
	for(int i=0;i<n;i++)
		if(arr[res]==arr[i])
			count++;

	if(count<=n/2)
		res=-1;

	return res;
}

// Minimum Group Flips to make same
void minflips(bool arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			if(arr[i]!=arr[0])
				cout<<"from "<<i<<" to ";
			else
				cout<<i-1<<endl;
		}
	}
	if(arr[n-1]!=arr[0])
		cout<<n-1<<endl;
}

// Sliding Window : MaxSum of array of size K
int maxSumK(int arr[],int n,int k)
{
	int res=0;
	for(int i=0;i<k;i++)
		res+=arr[i];

	int curr=res;
	for(int i=k;i<n;i++)
	{
		curr+=(arr[i]-arr[i-k]);
		res = max(res,curr);
	}

	return res;
}

// Sliding Window : SubArray with given Sum
int subArraySum(int arr[],int n,int sum)
{
	int s=0;
	int currsum=arr[0];

	for(int e=1;e<n;e++)
	{
		while(currsum>sum && s<e-1)
		{
			currsum-=arr[s];
			s++;
		}

		if(currsum==sum)
			return true;

		if(e<n)
			currsum+=arr[e];
	}
	return (currsum==sum);
}

// Prefix Sum : Equilibrium Point
int equilibriumPoint(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];

	int l_sum=0;
	for(int i=0;i<n;i++)
	{
		if(l_sum==sum-arr[i])
			return true;

		l_sum+=arr[i];
		sum-=arr[i];
	}
	return false;
}

int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Leaders in Array :";
    leadersArray(arr, n);
    cout<<endl;

    int arr1[]={1, 2, 90, 10, 110};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "maximum difference is " << maxDiff(arr1, n1)<<endl;
    cout << "Maximum difference is " << MaxDiff(arr1, n1)<<endl;
    cout << "Maximum Difference :" << maxDifference(arr1,n1)<<endl;

    int buil[] = {2,0,2};
    int b = sizeof(buil)/sizeof(int);
    cout<<"Trapping Rainwater :"<<TrapppingRainwater(buil,b)<<endl;

    int binArr[]={1,1,1,0,1,1,1,1,1,0,1};
    int bin = sizeof(binArr)/sizeof(int);
    cout<<"Maximum Ones :"<<maxOnes(binArr,bin)<<endl;

    int arr2[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n2 = sizeof(arr2)/sizeof(int);
    cout<<"Max Sub Array Sum :"<<maxSubArraySum(arr2,n2)<<endl;

    int arr3[] = {-1, 40, -14, 7, 6, 5, -4, -1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"maxCircularSubArraySum :"<<maxCircularSubArraySum(arr3,n3)<<endl;

    bool arr4[]={0,0,1,1,0,0,1,1,0,1};
	int n4=sizeof(arr4)/sizeof(arr4[0]);
	minflips(arr4,n4);

	int arr5[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}; 
	int k = 4; 
	int n5 = sizeof(arr5)/sizeof(arr5[0]); 
	cout << "Sliding Window maxSumK :"<<maxSumK(arr5, n5, k)<<endl;

	int arr6[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
	int n6 = sizeof(arr6)/sizeof(arr6[0]); 
	int sum = 23; 
	cout<<"subArraySum :"<<subArraySum(arr6, n6, sum)<<endl;

	int arr7[] = {3,4,8,-9,20,6};
	int n7 = sizeof(arr7)/sizeof(arr7[0]);
	cout<<"equilibriumPoint :"<<equilibriumPoint(arr7,n7)<<endl;
    return 0;
}