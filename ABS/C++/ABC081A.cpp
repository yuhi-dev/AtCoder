#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int count = 0;
    for (int i = 0; i < 3 ; i++){
        cin >> s[i];
        if (s[i] == '1'){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}