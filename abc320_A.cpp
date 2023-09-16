#include <iostream>
#include <iomanip>

typedef long long int ll;

using namespace std;
double myPow(int x, int num) {
        if(num < 0) {
            x = 1 / x;
        } 
        int pow = 1;
        
        while(num){
            if(num & 1) { 
                pow *= x;
            }
            x *= x;
            num >>= 1;
        }
        return pow;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a , b;
    cin>>a >> b;
    cout<<fixed<<setprecision(0)<< myPow(a,b) + myPow(b,a);
   

    return 0;
}