/* Rat can only move on 1's not on 0's as 0's are blocked
and rat can move in four direction Up, Down, Left, Right
the rat is initially placed at (0,0) in a rectangular grid
can the rat go to (N-1,M-1) and
Print the path covered by rat using Abbreviations
U for Up
D for Down
L for Left
R for Right
*/
#include <bits/stdc++.h>
using namespace std;

void solve (int i,int j,vector <vector <int>> &grid,int n,int m,vector <string> &ans,string move,vector <vector <int>> &vis) {
  //if the base case is satisfied and the rat reaches its destination
  if(i==n-1 && j==m-1) {
    ans.push_back(move);
    return;
  }
  //if the Down path is 1 i.e rat can move down it will move to down
  if(i+1<n &&!vis[i+1][j] && grid[i+1][j]==1) {
    vis[i][j]=1;
    solve(i+1,j,grid,n,m,ans,move+'D',vis);
    vis[i][j]=0;
  }
  //if the left path is 1 i.e rat can move left it will move to left
  if(j-1>=0 &&!vis[i][j-1] && grid[i][j-1]==1) {
    vis[i][j]=1;
    solve(i,j-1,grid,n,m,ans,move+'L',vis);
    vis[i][j]=0;
  }
  //if the right path is 1 i.e rat can move right it will move to right
  if(j+1<m &&!vis[i][j+1] && grid[i][j+1]==1) {
    vis[i][j]=1;
    solve(i,j+1,grid,n,m,ans,move+'R',vis);
    vis[i][j]=0;
  }
  //if the up path is 1 i.e rat can move up it will move to up
  if(i-1>=0 &&!vis[i-1][j] && grid[i-1][j]==1) {
    vis[i][j]=1;
    solve(i-1,j,grid,n,m,ans,move+'U',vis);
    vis[i][j]=0;
  }
}

vector <string> findPath(vector <vector <int>> &grid,int n,int m) {
  vector <string> ans;
  vector <vector <int>> vis(n , vector <int> (m,0));
  if(grid[0][0]==1) {
    solve(0,0,grid,n,m,ans,"",vis);
  }
  return ans;
}

int main () {
  int n,m;
  cin >> n>>m ; // Enter the row and column of the grid
  vector <vector <int> > grid(n,vector <int> (m,0));
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < m ; j++) {
      cin >> grid[i][j] ; // Enter the values of the grid
    }
  }
  vector <string> ans;
  ans = findPath(grid,n,m);
  if(ans.size()==0) {
    cout << "Rat cannot Reach the Destination" <<endl;
  } else {
    cout << "the path rat could use to reach the destination are" << endl ;
    for ( auto it : ans ) {
      cout << it <<endl;
    }
  }
  return 0;
}
