#include <bits/stdc++.h>
using namespace std;

long long absol(long long a){
    if(a<0) return -a;
    return a;
}

long long solve(long long x1,long long y1,long long x2,long long y2){
    return absol(x1-x2)+absol(y1-y2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        long long xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        vector<pair<long long,long long> > v(n+3);
        for(long long i=1;i<=n;i++) cin>>v[i].first>>v[i].second;
        long long dp[n+3][n+3];
        for(long long i=0;i<=n;i++)
        {
            for(long long j=0;j<=n;j++) dp[i][j]=1e18;
        }
        dp[0][0]=0;
        dp[1][0]=solve(xa,ya,v[1].first,v[1].second);
        dp[0][1]=solve(v[1].first,v[1].second,xb,yb);
        for(long long k=1;k<n;k++)
        {
            for(long long i=0;i<k;i++) 
            {
                // Alice at  (v[k].first , v[k].second ) , Bob at (v[i].first , v[i].second )
                dp[k+1][i]=min(dp[k+1][i],dp[k][i]+solve(v[k].first,v[k].second,v[k+1].first,v[k+1].second));
                if(i!=0) dp[k][k+1]=min(dp[k][k+1],dp[k][i]+solve(v[i].first,v[i].second,v[k+1].first,v[k+1].second));
                else dp[k][k+1]=min(dp[k][k+1],dp[k][0]+solve(xb,yb,v[k+1].first,v[k+1].second));
            }

            for(long long i=0;i<k;i++) 
            {
                // Alice at  (v[i].first , v[i].second ) , Bob at (v[k].first , v[k].second )
                if(i!=0) dp[k+1][k]=min(dp[k+1][k],dp[i][k]+solve(v[i].first,v[i].second,v[k+1].first,v[k+1].second));
                else dp[k+1][k]=min(dp[k+1][k],dp[0][k]+solve(xa,ya,v[k+1].first,v[k+1].second));
                dp[i][k+1]=min(dp[i][k+1],dp[i][k]+solve(v[k].first,v[k].second,v[k+1].first,v[k+1].second));
            }
        }
        long long ans=1e18;
        for(long long i=0;i<n;i++) ans=min(ans,dp[i][n]);
        for(long long i=0;i<n;i++) ans=min(ans,dp[n][i]);

        assert(ans!=1e18);
        cout<<ans<<"\n";
    }

    
    return 0;
}
