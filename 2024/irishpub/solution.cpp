#include <bits/stdc++.h>

using namespace std;


bool isvowel(char ch) { 
	return ((ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') || (ch == 'u') || (ch == 'y')); 
}


string to_lower(string line){
	string cad = "";
	for(int i = 0; i < line.size(); i++){
		cad = cad + (char)tolower(line[i]);
	}
	return cad;
}

pair < string, string > format_string(string line){
	vector < string > cads;
	for(int i = 0;i < line.size();i++){
		string cad = "";
		while(i < line.size() && (line[i] != ' ')){
			if(isvowel(line[i])){
				i = i + 1;
			} else {
				cad = cad + line[i];
				i = i + 1;
			}
		}
		sort(cad.begin(), cad.end());
		cads.push_back(cad);
	}
	return (make_pair(cads[0], cads[1]));
}


int main(){
	srand(42);
	//
	vector < string > names;
	vector < pair < string, string > > fnames;
	map < string, vector < string > > Map;
	//
	string line;
	while(getline(cin,line)){
		if(line == "START"){
			break;
		}
		string lline = to_lower(line);
		pair < string, string > fline = format_string(lline);
		names.push_back(lline);
		fnames.push_back(fline);
		//
		string key = fline.first + " " + fline.second;
		Map[key].push_back(lline);
	}
	
	while(getline(cin,line)){
		// split
		pair < string, string > fline = format_string(line);
		string cad1 = fline.first;
		string cad2 = fline.second;
		sort(cad1.begin(),cad1.end());
		sort(cad2.begin(),cad2.end());
		// get result
		string key = cad1 + " " + cad2;
		vector < string > match = Map[key];
		cout << match[0];
		int i = 1;
		while(i < match.size()){
			cout << "," << match[i];
			i = i + 1;
		}
		cout << endl;
	}
	return 0;
}
