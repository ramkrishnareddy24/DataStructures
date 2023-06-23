// 6033. Minimum Bit Flips to Convert Number
int countSetBits(int n){
    int count=0;
        while(n>0)
        {
            count++;
            n=n&(n-1);
        }
        return count;
}
int minBitFlips(int start, int goal) {
    return countSetBits(start^goal);
}

