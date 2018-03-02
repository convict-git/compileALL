/*
 ***************************************************************
 ||   Author                         {Priyanshu Shrivastav}   || 
 ||   email  {official[dot]mr[dot]convict[at]gmail[dot]com}   || 
 ***************************************************************
**_ __ ___    _ __    ___    ___    _ __   __   __ (_)   ___  | |_ 
 | '_ ` _ \  | '__|  / __|  / _ \  | '_ \  \ \ / / | |  / __| | __|
 | | | | | | | |    | (__  | (_) | | | | |  \ V /  | | | (__  | |_ 
 |_| |_| |_| |_|     \___|  \___/  |_| |_|   \_/   |_|  \___|  \__|
 ***************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

string strout(string strinp){//for converting main.cpp to main.out as a string
	unsigned int i = strinp.size() - 1;
	while(i >= strinp.size()-1){
		if (strinp[i] == '.'){
			strinp.erase(strinp.begin()+i,strinp.begin()+i+1);
			strinp.append(".out", 4);
			return strinp;
		}
		else strinp.erase(strinp.begin()+i,strinp.begin()+i+1);
		i--;
	} return "ERROR";
}

int main(){
	cout << "This program compiles all of your c files in one go!" << endl << endl;
	string strinp;
	system("ls *.c > ls");//creates a list of all c files and stores it into a file
	int DONE=0, lineN=1;
	ifstream read("ls");
	while( read >> strinp){//reads all your c file names from the file
		cout << lineN++ << "  Compiling " << strinp<< " gcc -lm -std=c99 -O2 " << strinp << " -o " << strout(strinp);
		ostringstream gcc;
		gcc << "gcc -lm -std=c99 -O2 "<< strinp << " -o " << strout(strinp);//compilation with optimisations
		system(gcc.str().c_str());
		cout << "____DONE" << endl;
		DONE= 1;
	} read.close(); cout << endl;
	if (DONE== 1) system("rm -rf ls && echo \"Compiled files are: \" && ls *.out");//removes the temp file containing the list of c files
	cout << endl << "Bugs and other issues can be reported on https://github.com/convict-git/compileALL/ (Priyanshu Shrivastav)" << endl << endl;
}
