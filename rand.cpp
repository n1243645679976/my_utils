#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<algorithm>
#include<stdlib.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::max;
using std::min;
int main(int argc, char* argv[]){
    string sArg;
    // initial
    int i = 0, n = 1;
    bool reverseFlag = false;
    srand(time(NULL));

    // parse Arguments
    while(i < argc){
        sArg = string(argv[i]);
        if(sArg == "--seed" || sArg == "-seed" || sArg == "-s"){
            int seed = std::stoi(string(argv[i+1]));
            i += 1;
            srand(seed);
        }
        if(sArg == "--n" || sArg == "-n"){
            n = std::stoi(string(argv[i+1]));
            i += 1;
        }
        if(sArg == "-r" || sArg == "--r" || sArg == "--reverse" || sArg == "-reverse"){
            reverseFlag = true;
        }
        i += 1;
    }

    string line;
    std::vector<string> lines;
    while(cin){
        getline(std::cin, line);
        lines.push_back(line);
    }
    std::random_shuffle(lines.begin(), lines.end());
    if(!reverseFlag){
        int end = min(n, int(lines.size()));
        for(int i=0;i<end;++i){
            cout<<lines[i]<<endl;
        }
    }
    else{
        int start = min(n, int(lines.size())), ll = lines.size();
        for(int i=n;i<ll;++i){
            cout<<lines[i]<<endl;
        }
    }
}
