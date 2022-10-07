#include <bits/stdc++.h>
#include <cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while(t--){
       int k;
        cin>>k;
        int a[k];
      if( k==2){
       cout<<-1<<endl;
      }
    else  if(k%2==1){
          int x=k;
          for(int i=0;i<k;i++,x--){
              cout<<x<<" ";
          }
          cout<<endl;
      }
      else{
      int x=1;
      for(int i=0;i<k;i++,x++){
          a[i]=x;
      }
      a[0]=2;
      a[1]=3;
      a[2]=1;
        for(int i=0;i<k;i++){
              cout<<a[i]<<" ";
          }
          cout<<endl;
      }
    }
    return 0;
}