max_arguments=50
max_length=500

[ -f sscanf.cpp ] && rm sscanf.cpp

echo "
#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;

vector<char*> ssscanf(char* target, char* pattern){
    vector<char*> ans;
    for(int i=0;i<$max_arguments;i++) ans.push_back(new char[$max_length]);
" >> sscanf.cpp

printf "sscanf(target, pattern"  >> sscanf.cpp
for i in `seq 1 1 $max_arguments`; do printf ", ans[$((i-1))]" >> sscanf.cpp; done


echo ");
    return ans;

}

int main(int argc, char** argv){
    string pattern = string(argv[1]);
    string target = string(argv[2]);
    vector<char*> output;
    output = ssscanf(argv[2], argv[1]);
    int last_chars = 0;
    for(int i = 0;i < $max_arguments; i++){
        if(output[i][0] != '\0') last_chars = i;
    }
    for(int i = 0;i <= last_chars; i++){
        cout<<output[i]<<endl;
    }

    return 0;
}
" >> sscanf.cpp
