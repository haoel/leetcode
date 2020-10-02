#include<bits/stdc++.h>
using namespace std;
string longestCommonSubstring(string &a, int n, string &b, int m){
	int dp[n+1][m+1];
	int len=0,row,col;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]) {
				dp[i][j]=dp[i-1][j-1]+1;
				if(dp[i][j]>len){
					len=dp[i][j];
					row=i;
					col=j;
				}
			}
			else dp[i][j]=0;
		}
	}
	if(len==0) { 
        return "No Common Substring";
    } 
    string ans="";
    while(dp[row][col]!=0){
    	ans=a[row-1]+ans;
    	row--;
    	col--;
    }
    return ans;
}
int main(){
	string a,b;
	cin>>a>>b;
	int n=a.length();
	int m=b.length();
	cout<<longestCommonSubstring(a,n,b,m);
    return 0; 
}
