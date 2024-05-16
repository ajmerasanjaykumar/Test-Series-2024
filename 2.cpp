#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;

    int ans=1;
    for(int i=0;i<=n;i=i+a)
    {
        for(int j=0;i+j<=n;j=j+b)
        {
            if((n-(i+j))%c==0) ans=max(ans,(i/a)+(j/b)+((n-(i+j))/c));
        }
    }
    cout<<ans;

    

    
    return 0;
}
