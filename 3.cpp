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

    if(n==1 && a[0]==1)
    {
        cout<<"1";
        return 0;
    }
    if(n==1 && a[0]!=1)
    {
        cout<<"-1";
        return 0;
    }
    int f[200000]={0};
    for(int i=0;i<n;i++) f[a[i]]++;
    int ans=-1;
    for(int i=2;i<=n;i++)
    {
        int c=0;
        for(int j=i;j<=100000;j=j+i)
        {
            if(f[j]!=0) c+=f[j];
        }
        if(c==i) ans=max(ans,i);
    }

    cout<<ans;

    
    return 0;
}
