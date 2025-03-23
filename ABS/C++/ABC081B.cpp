#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    while(true){
        bool exit_odd = false;
        for(int i = 0; i < N; i++){
            if (A[i] % 2 != 0){
                exit_odd = true;
            }
        }
        if(exit_odd){
            break;
        }
        for(int i = 0; i < N; i++){
            A[i] /= 2;
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}