#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

   int t;
   cin >> t;
   while (t--){
    ll x,y,a;
    cin >> x >> y >> a;
    if( a%(x+y) < x){
        cout << "No" <<endl;
    }
    else{
        cout << "Yes" << endl;
    }
   }

   return 0;

}
