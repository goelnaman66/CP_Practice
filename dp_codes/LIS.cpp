//given a sequence of numbers find the longest increasing subsequence
//O(n^2) solution


#include<bits/stdc++.h>
using namespace std;



int dp_i(int *arr, int n, int *dp1){

    dp1[1]=1;
    
    for(int i=2;i<=n;i++){
        dp1[i]=1;
        for(int j=i-1;j>=1;j--){
            if(arr[i]>=arr[j]){
                dp1[i]=max(dp1[i],1+dp1[j]);
            }
        }
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){ 
        cout<<dp1[i]<<" ";
        ans=max(ans,dp1[i]);
    }
    cout<<endl;
    cout<<ans<<endl;
    
    
}

int dps(int *arr, int n, int *dp, int level){
    if(level==0) return 0;

    if(dp[level]!=-1) return dp[level];

    int ans=1;
    for(int i=level-1;i>=1;i--){
         if(arr[level]>=arr[i]){
            ans=max(ans,1+dps(arr,n,dp,i));
        }
    }
    return dp[level]=ans;

}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int *dp1=new int[n+1];
    dp_i(arr,n,dp1);

    int *dp=new int[n+1];
    for(int i=0;i<=n;i++) dp[i]=-1;
    for(int i=n;i>=1;i--) dps(arr,n,dp,i);
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
    cout<<endl;
    cout<<ans<<endl;
}