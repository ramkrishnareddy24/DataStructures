#include<bits/stdc++.h>
using namespace std;

bool WinnerOfGame(string str)
{
	int n = str.length();
	int winner = 0;

	for(int i=1;i<n-2;i++)
	{
		if(str[i-1]=='A' && str[i+1]=='A' && str[i]=='A')
		{
			winner = 1;
			for(int j=i;j<n;j++)
				str[j] = str[i+1];
		}
		else if(!(str[i-1]=='A' && str[i+1]=='A' && str[i]=='A'))
		{
			winner = 0;
		}
		else if(str[i-1]=='B' && str[i+1]=='B' && str[i]=='B')
		{
			winner = 0;
			for(int j=i;j<n;j++)
				str[j] = str[i+1];
		}
		else if(!(str[i-1]=='B' && str[i+1]=='B' && str[i]=='B'))
		{
			winner = 1;
		}
	}
	if(winner)
		return true;
	return false;
}

bool winnerOfGame(string colors)
{
	int countA = 0, countB = 0;
        int n = colors.length();
        for (int i = 0; i < n - 2; i++) {
            if (colors[i] == 'A' && colors[i + 1] == 'A' && colors[i + 2] == 'A') {
                countA++;
            }
            if (colors[i] == 'B' && colors[i + 1] == 'B' && colors[i + 2] == 'B') {
                countB++;
            }
        }
        return countA > countB;
}

int main()
{
	string colors = "AAAABBBB";
	// colors.erase(colors.begin()+1);
	// cout<<colors;
	bool ans = winnerOfGame(colors);
	cout<<ans;

	return 0;
}