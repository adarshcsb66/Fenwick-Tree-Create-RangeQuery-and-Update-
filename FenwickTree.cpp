#include <bits/stdc++.h>
using namespace std;
int lsb(int index)
{
    for(int i=0;i<40;i++)
    {
        if(index>>i&1)
        {
            return pow(2,i);
        }
    }
    return -1;
}
int rangeQuery(int fen[],int index)
{
    if(index<=0)return 0;
    return fen[index]+rangeQuery(fen,index-lsb(index));
}
void update(int fen[],int index,int change,int n)
{
    while(index<=n)
    {
        fen[index]+=change;
        index+=lsb(index);
    }
}
int main(void){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int fen[n+1];
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            fen[i]=a[i];
        }
        else
        {
            fen[i]=a[i];
            int x=lsb(i);
            x--;
            int curr=i-1;
            while(x>0)
            {
                fen[i]+=fen[curr];
                x-=lsb(curr);
                curr-=lsb(curr);
            }
        }
    }
    int l,r;
    cin>>l>>r;
    cout<<rangeQuery(fen,r)-rangeQuery(fen,l-1)<<" ";
    update(fen,2,5,n);
    cout<<rangeQuery(fen,r)-rangeQuery(fen,l-1);
}
