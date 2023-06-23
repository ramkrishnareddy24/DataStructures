bool valid(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int n=s.length();
            int l=0,h=n-1;
            while(l<h)
            {
                if(s[l]!=s[h]){
                   if(valid(s,l,h-1))
                           return true;
                    if(valid(s,l+1,h))
                        return true;
                 return false;   
                }
                else{
                    l++;
                    h--; 
                }
                       
            }
            return true;
    }