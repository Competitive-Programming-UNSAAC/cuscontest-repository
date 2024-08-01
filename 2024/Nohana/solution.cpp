#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; 
    cin >> t;
    for (int test = 0; test < t; test++){
        string s1, s2; 
        cin >> s1 >> s2;
        int len_s1 = s1.length();
        int len_s2 = s2.length();
        vector<string> array_s2;
        for (int i = 0; i < len_s2; i++){
        	for (int j = i; j < len_s2; j++){
        		array_s2.push_back(s2.substr(i, j - i + 1));
        	}
        }
        sort(array_s2.begin(), array_s2.end());
        int ans = 0;
        for (int i = 0; i < len_s1; i++){
        	for (int j = i; j < len_s1; j++){
        		string element = s1.substr(i, j - i + 1);
	        	int pos = lower_bound(array_s2.begin(), array_s2.end(), element) - array_s2.begin();
	        	ans += pos;
        	}
        }
        cout << ans << '\n';    
    }
    
}