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
	if(i==n) return n;
	for(int j=i;j<n-1;j++)
		arr[j]=arr[j+1];
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
				secondLargest=i;
		}
	}
	return arr[secondLargest];
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

void reverse(int arr[],int n)
{
	int l=0,r=n-1;
	while(l<r)
	{
		swap(arr[l],arr[r]);
		l++; r--;
	}
}

void leftRotate(int arr[],int n)
{
	int temp = arr[0];
	for(int i=0;i<n;i++)
		arr[i]=arr[i+1];
	arr[n-1]=temp;
}

void rightRotate(int arr[],int n)
{
	int temp = arr[n-1];
	for(int i=n-1;i>=0;i--)
		arr[i]=arr[i-1];
	arr[0] = temp;
}

// left Rotate by D places : Naive
void leftRotateD(int arr[],int n,int d)
{
	for(int i=0;i<d;i++)
		leftRotate(arr,n);
}

int Reverse(int arr[],int l,int r)
{
	while(l<r)
	{
		swap(arr[l],arr[r]);
		l++; r--;
	}
}

// left Rotate by D places : Efficient 
void leftRotateDP(int arr[],int n,int d)
{
	Reverse(arr,0,d-1);
	Reverse(arr,d,n-1);
	Reverse(arr,0,n-1);
}

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

	for(auto x:v)
		cout<<x<<" ";
}

// maxDiff : Naive
int maxDiff(int arr[],int n)
{
	int res=arr[1]-arr[0];
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			res=max(res,arr[j]-arr[i]);
	return res;
} 

// maxDiff : Optimal
int maxDifference(int arr[],int n)
{
	int res = arr[1]-arr[0];
	int minVal = arr[0];

	for(int i=1;i<n;i++)
	{
		res=max(res,arr[i]-minVal);
		minVal=min(minVal,arr[i]);
	}
	return res;
}

// Max Difference : Alternate
int MaxDifference(int arr[],int n)
{
	int small = arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]<small)
			small=arr[i];

	int large = arr[0];
	for(int i=1;i<n;i++)
		if(arr[i]>large)
			large=arr[i];

	return (large-small);
}

// Stock Buy and Sell
vector<vector<int>> stockBuySell(vector<vector<int>> arr[],int n)
{
	vector<vector<int>> ans;

	for(int i=1;i<n;i++)
	{
		vector<int> v;

		if(arr[i]>arr[i-1])
		{

			v.push_back(i-1);

			while(i<n && arr[i]<arr[i-1])
			i++;

			v.push_back(i-1);
		}
		ans.push_back(v);

	}
	return ans;
}

int trappingRainwater(int arr[],int n)
{
	int res=0;
	int lmax[n],rmax[n];

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

int maxConsecutiveOnes(int arr[],int n)
{
	int cnt=0,res=0;
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

// maxSubArraySum: Kadane Algorithm
int maxSubArraySum(int arr[],int n)
{
	int res=arr[0];
	int maxEnd=arr[0];
	for(int i=1;i<n;i++)
	{
		maxEnd=max(maxEnd+arr[i],arr[i]);
		res=max(res,maxEnd);
	}
	return res;
}

int longestEvenOddSubArr(int arr[],int n)
{
	int res=1,curr=1;

	for(int i=1;i<n;i++)
	{
		if((arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i-1]%2==0 && arr[i]%2!=0))
		{
			curr++;
			res=max(res,curr);
		}
		else
			curr=1;
	}
	return res;
}

int maxCircularSubArrSum(int arr[],int n)
{
	int maxNormal = maxSubArraySum(arr,n);

	if(maxNormal<0)
		return maxNormal;

	int arrSum=0;
	for(int i=0;i<n;i++)
	{
		arrSum+=arr[i];
		arr[i]=-arr[i];
	}

	int maxCircular = arrSum+maxSubArraySum(arr,n);
	return max(maxNormal,maxCircular);
}

// Moore's Voting Algo
int majorityElement(int arr[],int n)
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

	return arr[res];
}

int minFlips(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			if(arr[i]!=arr[0])
				cout<<"from "<<i<<" ";
			else
				cout<<(i-1)<<endl;
		}
	}
	if(arr[n-1]!=arr[0])
		cout<<n-1<<endl;
}

// Sliding window
int maxSumK(int arr[],int n,int k)
{
	int curr_sum=0;
	for(int i=0;i<k;i++)
		curr_sum+=arr[i];

	int max_sum=curr_sum;
	for(int i=k;i<n;i++)
	{
		curr_sum+=(arr[i]-arr[i-k]);
		max_sum=max(curr_sum,max_sum);
	}
	return max_sum;
}

// Sliding Window : SubArray with given sum
int subArrGivenSum(int arr[],int n,int sum)
{
	int s=0;
	int curr_sum=arr[0];

	for(int e=1;e<n;e++)
	{

		while(curr_sum>sum && s<e-1)
		{
			curr_sum-=arr[s];
			s++;
		}

		if(curr_sum==sum)
			return true;

		if(e<n)
			curr_sum+=arr[e];
	}

	return (curr_sum==sum);
}

// Equilibrium Point : Prefix Sum
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

bool checkPrime(int n)
{
	if(n<=1)
		return false;

	for(int i=2;i<n;i++)
		if(n%i==0)
			return false;
	return true;
}

bool isPalindrome(int x) 
{
        long int y=0;
        int nums=x;
        
        while(nums>0)
        {
            y=(y*10)+(nums%10);
            nums=nums/10;
        }
        if(x==y)
            return true;
        else
            return false;
}

int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);

	int arr1[]={1,0,0,1,1,1};
	int n1 = sizeof(arr1)/sizeof(int);

	cout<<"Largest :"<<largest(arr,n)<<endl;
	cout<<"secondLargest :"<<secondLargest(arr,n)<<endl;
	cout<<"moveZeroToEnd :";moveZeroToEnd(arr1,n1);
	for(int i=0;i<n1;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;

	cout<<"Reverse :";reverse(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"leftRotate :";leftRotate(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"rightRotate :";rightRotate(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"leftRotate D :";leftRotateD(arr,n,2);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"leftRotate DP :";leftRotateDP(arr,n,2);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	int arr2[] = {16, 17, 4, 3, 5, 2};
	int n2 = sizeof(arr2)/sizeof(int);
	cout<<"leadersArray :"; leadersArray(arr2,n2);cout<<endl;

	int arr3[]={1, 2, 90, 10, 110};
	int n3 = sizeof(arr3)/sizeof(int);
	cout<<"maxDiff : "<<maxDiff(arr3,n3)<<endl;
	cout<<"maxDifference : "<<maxDifference(arr3,n3)<<endl;
	cout<<"MaxDifference : "<<MaxDifference(arr3,n3)<<endl;

	int arr4[]={2,1,3,2,3,1};
	int n4 = sizeof(arr4)/sizeof(int);
	cout<<"trappingRainwater :"<<trappingRainwater(arr4,n4)<<endl;

	int arr5[]={1,1,1,1,1,0,1,1};
	int n5=sizeof(arr5)/sizeof(int);
	cout<<"Max Cons Ones :"<<maxConsecutiveOnes(arr5,n5)<<endl;

	int arr6[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n6 = sizeof(arr6)/sizeof(int);
    cout<<"Max Sub Array Sum :"<<maxSubArraySum(arr6,n6)<<endl;

    int arr7[]={5,10,20,6,3,8};
    int n7=sizeof(arr7)/sizeof(int);
    cout<<"longestEvenOddSubArr :"<<longestEvenOddSubArr(arr7,n7)<<endl;

    int arr8[] = {-1, 40, -14, 7, 6, 5, -4, -1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    cout<<"maxCircularSubArraySum :"<<maxCircularSubArrSum(arr8,n8)<<endl;

    cout<<"Majority Element :"<<majorityElement(arr5,n5)<<endl;

    int arr9[]={0,0,1,1,0,0,1,1,0,1};
	int n9=sizeof(arr9)/sizeof(arr9[0]);
	cout<<"Min Flips :"<<endl;
	minFlips(arr9,n9); cout<<endl;

	int arr10[] = {3,4,8,-9,20,6};
	int n10 = sizeof(arr9)/sizeof(arr9[0]);
	cout<<"equilibriumPoint :"<<equilibriumPoint(arr9,n9)<<endl;

	cout<<"checkPrime :"<<checkPrime(22)<<endl;

	return 0;
}