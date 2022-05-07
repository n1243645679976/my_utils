#include<iostream>
#include<cstdio>
#include<string>
using std::cout;
using std::cin;
using std::string;
int main(int argc, char* argv[]){
    string sArg;
    // initial
    int i = 1, p = 1;
    bool reverseFlag = false;
    srand(time(NULL));

    // parse Arguments
    while(i < argc){
        sArg = string(argv[i]);
        if(sArg == "--p" || sArg == "-p"){
            p = std::stoi(string(argv[i+1]));
            i += 1;
        }
        i += 1;
    }
    

    double d;
    while(cin >> d){
        printf("%.*f\n", p, d);
    }
}
