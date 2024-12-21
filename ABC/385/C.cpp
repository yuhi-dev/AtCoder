#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int maxBuildings = 1;
    for (int d = 1; d < N; ++d) {
        unordered_map<int, int> count;
        for (int i =0;i + d < N; ++i) {
            if (H[i] == H[i + d]) {
                count[H[i]]++;
                maxBuildings = max(maxBuildings, count[H[i]]);
            }
            else if(H[i] == H[i + d] + 1) {
                count[H[i]]++;
                maxBuildings = max(maxBuildings, count[H[i]]);
            }
        }
    }

    cout << maxBuildings << endl;
    return 0;
}

//answer
/*#include <bits/stdc++.h>
using namespace std;
int n,a[3010],ans=0,mx=0;
int main(){
	cin>>n;
	if(n==1) {
		cout<<1<<endl;
		return 0;
	}
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n-i; ++j){
			int k=i;
			ans=1;
			while(k+j<=n){
				if(a[k+j]!=a[k]) break;
				k+=j,ans++; 
			}
			mx=max(ans,mx);
		}
	}
	cout<<mx<<endl;
	return 0;
}*/