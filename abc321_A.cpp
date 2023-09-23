#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int x;
    cin >> x;
    int prev = x%10;
    x = x/10;
    int cur;
    while(x != 0){
        cur = x%10;
        if(prev >= cur){
            cout<<"No";
            return 0;
        }
        else{
            prev = cur;
            x = x/10;
        }
    }
    cout<<"Yes";
    return 0;
}