#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;

    while(t--){
        int n,s=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if((arr[i]%7!=6) && (arr[i]%7!=0))
               s++;
        }
         cout<<8+s<<endl;
    }
    return 0;
}