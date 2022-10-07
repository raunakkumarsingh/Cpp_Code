#include<bits/stdc++.h>
using namespace std;

void bracket(string output,int n,int open,int close,int i){
     if(i==2*n){
            cout<<output<<endl;
          return;
     }


    
            if(open<n){
            //   output+='(';
              
          bracket(output+'(',n,open+1,close,i+1);
           output.pop_back();
            }
          
           if(close<open){
            //  output+=')';
       bracket(output+')',n,open,close+1,i+1);
       output.pop_back();
           }

}

int main()
{
    string output;
    int n;
    n=3;
    bracket(output,n,0,0,0);
    return 0;
}
