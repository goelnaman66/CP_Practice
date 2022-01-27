//given a no. n*m, You are on (1,1). Find the no of ways to reach (n,m) if you can take just right and down steps.



#include<bits/stdc++.h>
using namespace std;


int dp_i(int n, int m, int *dp1[]){

    //initialisation
    for(int i=1;i<=n;i++) dp1[i][1]=1;
    for(int i=1;i<=m;i++) dp1[1][i]=1;
    

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp1[i][j]=dp1[i-1][j]+dp1[i][j-1];
        }
    }
    return dp1[n][m];
}



int dps(int n, int m, int i, int j, int *dp[]){
    if(i<=0 || j<=0){
        return 0;
    }
    if(i==1 && j==1){
        return 1;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans= dps(n,m,i-1,j,dp)+dps(n,m,i,j-1,dp);
    return dp[i][j]=ans;


}

int main(){
    int n,m;
    cin>>n>>m;


    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    dps(n,m,n,m,dp);
    cout<<dp[n][m]<<endl;

    int **dp1=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp1[i]=new int[m+1];
    }
    cout<<dp_i(n,m,dp1)<<endl;
    

    
   
}