#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, ans = 0;
	string a, b;
	cin>>n>>a>>b;

	
	for(int i = 0; i < n; i++){
		int num1 = a[i] - '0';
		int num2 = b[i] - '0';

		int aux1 = abs(num1 - num2);
		int aux2 = 1 + num2 + abs(9 - num1);
		int aux3 = 1 + num1 + abs(9 - num2);
		ans += min(aux1, min(aux2, aux3));
	}

	cout<<ans<<endl;
	return 0;
}
