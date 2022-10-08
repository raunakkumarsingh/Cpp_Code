#include<bits/stdc++.h>
using namespace std;

//Euclidean algorithm to find Greatest common divisor between two number a and b
//recursive call is done over the basic euclid algorithm
//Basic Euclidean Algorithm with complexity O(log(min(a,b)))
int func(int a,int b){
    if(a==0)
        return b;
    return func(b%a,a);
}

int main(){
    int a,b;
    cin>>a>>b;
    int res = func(a,b);
    cout<<res<<endl;
    return 0;
}

//Extenden Euclidean Alogrithm

// it is special as it can also find the coefficient satisfying the equation ax + by = gcd(a,b) where gcd is greatest common
// divisor

#include <bits/stdc++.h>
using namespace std;
//function to extend euclid algorithm 
int funcext(int a, int b,int *x,int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = funcext(b % a, a, &x1, &y1);

    // Update x and y using results of
    // recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    int x, y, a, b;
    cin >> a >> b;
    int res = funcext(a, b, &x, &y);
    cout << res << endl;
    return 0;
}

//Complexity O(log N)
//you can input


//Else you can find the gcd of two number using the stl function in c++ i.e __gcd(a,b)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<__gcd(a,b)<<endl;   // the stl function __gcd(a,b) calculates the gcd between two number most efficiently
    return 0;
}
