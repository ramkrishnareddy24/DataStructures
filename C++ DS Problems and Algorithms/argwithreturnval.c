#include<stdio.h>
void printline(char ch,int len);
value(float, float, int);
main()
{
    float principal,inrate,amount;
    int period;
    printf("enter the principal inrate period\n");
    scanf("%f %f %d",&principal,&inrate,&period);
    printline('*',50);
    amount=value(principal,inrate,period);
    printf("\t%f\t%f\t%d\t%f\n",principal,inrate,period,amount);
    printline('=',50);

}
void printline(char ch,int len)
{
    int i;
    for(i=1;i<len;i++)
        printf(" %c",ch);
    printf("\n");
}
value(float p,float r,int n)
{
    int year;
    float sum;
    sum=p; year=1;
    while(year<=n)
    {
      sum=sum*(1+r);
      year=year+1;
    }
    return(sum);
}
