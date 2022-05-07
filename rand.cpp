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
    int i = 1, n = 1;
    bool reverseFlag = false, sortFlag = false;
    srand(time(NULL));

    // parse Arguments
    while(i < argc){
        sArg = string(argv[i]);
        if(sArg == "--seed" || sArg == "-seed" || sArg == "-s"){
            int seed = std::stoi(string(argv[i+1]));
            i += 1;
            srand(seed);
        }
        else if(sArg == "--n" || sArg == "-n"){
            n = std::stoi(string(argv[i+1]));
            i += 1;
        }
        else if(sArg == "-r" || sArg == "--r" || sArg == "--reverse" || sArg == "-reverse"){
            reverseFlag = true;
        }
        else if(sArg == "--sort" || sArg == "--sorted" || sArg == "-S"){
            sortFlag = true;
        }
        else{
            cout << "unkown arg " << sArg << endl;
            return -1;
        }
        i += 1;
    }

    string line;
    std::vector<string> lines;
    while(getline(std::cin, line)){
//        getline(std::cin, line);
        lines.push_back(line);
    }
//    lines.pop_back(); // last empty line
    std::random_shuffle(lines.begin(), lines.end());
    if(!reverseFlag){
        int end = min(n, int(lines.size()));
        if(sortFlag) sort(lines.begin(), lines.begin()+end);
        for(int i=0;i<end;++i){
            cout<<lines[i]<<endl;
        }
    }
    else{
        int start = min(n, int(lines.size())), ll = lines.size();
        if(sortFlag) sort(lines.begin()+n, lines.end());
        for(int i=n;i<ll;++i){
            cout<<lines[i]<<endl;
        }
    }
}
