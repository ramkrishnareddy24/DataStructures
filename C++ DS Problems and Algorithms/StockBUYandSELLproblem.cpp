// The cost of stock on each day is given in an array A[]
//of size N. Find all the days on which you buy and sell
//the stock so that in between those days your profit is
//maximum.
// Note: There may be multiple possible solutions.
//Return any one of them. Any correct solution will result
//in an output of 1, whereas wrong solutions will result in
//an output of 0.

//The Number of days to make Profit
vector<vector<int>> stockBuyAndSell(vector<vector<int>> arr[],int n)
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

