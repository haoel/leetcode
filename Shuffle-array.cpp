#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define whln(t) while(t--)
#define whlp(t) while(t++)
int i ;
int main(){
  #ifndef ONLINE_JUDGEz
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
  #endif
    int n ;
    cin>>n;
    vector<ll>v(n),x(n/2),y(n/2);
    rep(i,n){
      int a ;
      cin>>a;
      if(i<n/2)
        x.push_back(a);
      else
        y.push_back(a);    
    }
    int cnt,i=0,j=0;
    rep(cnt,n){
      if(cnt%2==0){
        cout<<x[i];
        i++;
      }
      else{
       cout<<y[i];
        j++;
      }
    }
    //your code here
    return 0;
}