#include <bits/stdc++.h>

using namespace std;


bool isvowel(char ch) { 
	return ((ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') || (ch == 'u') || (ch == 'y')); 
}


string to_lower(string line){
	string cadena = "";
	for(int i = 0; i < line.size(); i++){
		cadena = cadena + (char)tolower(line[i]);
	}
	return cadena;
}

pair < string, string > format_string(string line){
	vector < string > cadenas;
	for(int i = 0; i < line.size(); i++){
		string cadena = "";
		while(i < line.size() && (line[i] != ' ')){
			if(isvowel(line[i])){
				i = i + 1;
			} else {
				cadena = cadena + line[i];
				i = i + 1;
			}
		}
		sort(cadena.begin(), cadena.end());
		cadenas.push_back(cadena);
	}
	return (make_pair(cadenas[0], cadenas[1]));
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
		string cadena1 = fline.first;
		string cadena2 = fline.second;
		sort(cadena1.begin(),cadena1.end());
		sort(cadena2.begin(),cadena2.end());
		// get result
		string key = cadena1 + " " + cadena2;
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
