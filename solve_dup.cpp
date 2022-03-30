#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<sstream>
#include <iterator>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::unordered_map;
std::vector<std::string> split(std::string const &input) { 
    std::istringstream buffer(input);
    std::vector<std::string> ret((std::istream_iterator<std::string>(buffer)), 
                                 std::istream_iterator<std::string>());
    return ret;
}
int main(int argc, char* argv[]){
    string sArg;
    int i = 0, n = 5;
    string spliter = "#";
    while(i < argc){
        sArg = string(argv[i]);
        if(sArg == "--n" || sArg == "-n"){
            n = std::stoi(string(argv[i+1]));
            i += 1;
        }
        if(sArg == "--d" || sArg == "-d"){
            spliter = string(argv[i+1]);
            i += 1;
        }
        i += 1;
    }
    vector<string> lines;
    unordered_map<string, int> key_set;
    string line;
    while(cin){
        getline(cin, line);
        if(line == "") continue;
        lines.push_back(line);
    }
    
    sort(lines.begin(), lines.end());
    int lv;
    vector<string> splits;
    for(string s: lines){
        splits = split(s);
        if(splits.size() == 0) continue;
        key_set[splits[0]]++;
        cout<<splits[0]<<spliter;
        printf("%0*d", n, key_set[splits[0]]);
        lv = splits.size();
        for(int i=1;i<lv;++i){
            cout<<" "<<splits[i];
        }
        cout<<endl;
    }
}
