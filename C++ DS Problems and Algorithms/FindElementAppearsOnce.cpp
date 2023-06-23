
//Efficient Solution
int search(int A[],int N)
{
		int res=A[0];
	    for(int i=1;i<N;i++)
	    res=res^A[i];
	    return res;
}