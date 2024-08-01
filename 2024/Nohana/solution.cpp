#include<bits/stdc++.h>

using namespace std;

int main(){
    int tt; cin>>tt;
    while(tt--){
        string s1, s2; cin>>s1>>s2;
        int a = s1.length();
        int b = s2.length();
        vector<string> sb;
        for (int i = 0; i < b; i++) for (int j = i; j< b; j++){
            sb.push_back(s2.substr(i,j-i+1));
        }
        sort(sb.begin(), sb.end());
        //db(sb);
        int ans = 0;
        for (int i = 0; i < a; i++) for (int j = i; j< a; j++){
        	string element = s1.substr(i, j-i+1);
        	int pos = lower_bound(sb.begin(),sb.end(), element) - sb.begin();
        	ans += pos;
        }
        cout<<ans<<endl;    
    }
    
}