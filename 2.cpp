#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[3]={0};
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    int b[3];
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    int ans=0;
    ans+=a[0];
    a[1]=a[1]-a[0];
    a[2]=a[2]-a[0];
    ans+=a[1]/3;
    ans+=a[2]/3;

    int ans1=0;
    ans1+=b[0]/3;
    ans1+=b[1]/3;
    ans1+=b[2]/3;
    ans1+=min(min(b[0]%3,b[1]%3),b[2]%3);

    cout<<max(ans,ans1);
    return 0;
}
