#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    if(n==1) 
    {
        cout<<"1\n";
        return 0;
    }

    int c=0;
    for(int i=1;i<n-1;i++)
    {
        if(2*a[i]>a[i-1]+a[i+1]) c++;
    }
    if(2*a[0]>a[1]) c++;
    if(2*a[n-1]>a[n-2]) c++;

    cout<<c;

    return 0;
}
