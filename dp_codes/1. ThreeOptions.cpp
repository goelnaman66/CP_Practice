//given a no. n, you can perform one of the three operations
//1.divide a number by 3 if divisible
//2.divide a number by 2 if divisible
//3.Subtract 1 from the number

//Find minimum no. of steps to reach 1 from n


#include<bits/stdc++.h>
using namespace std;


int dp_i(int n, int *dp1){
    dp1[0]=0;
    dp1[1]=0;
    for(int i=2;i<n+1;i++){
        dp1[i]=1+dp1[i-1];
        if(i%2==0) dp1[i]=min(dp1[i],1+dp1[i/2]);
        if(i%3==0) dp1[i]=min(dp1[i],1+dp1[i/3]);
    }
    cout<<dp1[n]<<endl;
}



int dps(int n, int *dp){
    if(n==1) return 0;
    
    if(dp[n]!=-1) return dp[n];

    int ans1=INT_MAX;
    if(n%3==0){
        ans1=1+(dps(n/3,dp));
    }

    int ans2=INT_MAX;
    if(n%2==0){
        ans2=1+(dps(n/2,dp));
    }

    return dp[n]=min({ans1,ans2,dps(n-1,dp)+1});

}

int main(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    dps(n,dp);
    cout<<dp[n]<<endl;

    int dp1[n+1];
    for(int i=0;i<=n;i++){
        dp1[i]=-1;
    }
    dp_i(n,dp1);
    cout<<endl;
   
}