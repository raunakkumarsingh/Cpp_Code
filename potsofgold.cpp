#include <iostream>
#include <string>
using namespace std;
 

int findMaxCoins(int coin[], int d, int h)
{

    if (d == h) {
        return coin[d];
    }
 

    if (d + 1 == h) {
        return max(coin[d], coin[h]);
    }
 

    int start = coin[d] + min(findMaxCoins(coin, d + 2, h),
                            findMaxCoins(coin, d + 1, h - 1));
 
 
 
    int end = coin[h] + min(findMaxCoins(coin, d + 1, h - 1),
                    findMaxCoins(coin, d, h - 2));
 

    return max(start, end);
}
 

int main()
{
 
    int coin[] = { 1, 3, 9, 8 };
 

    int n = sizeof(coin) / sizeof(coin[0]);
 
    cout << "The Maximum coins collected by player is "
         << findMaxCoins(coin, 0, n - 1);
 
    return 0;
}
