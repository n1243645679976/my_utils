
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
    for(int i=0;i<50;i++) ans.push_back(new char[500]);

sscanf(target, pattern, ans[0], ans[1], ans[2], ans[3], ans[4], ans[5], ans[6], ans[7], ans[8], ans[9], ans[10], ans[11], ans[12], ans[13], ans[14], ans[15], ans[16], ans[17], ans[18], ans[19], ans[20], ans[21], ans[22], ans[23], ans[24], ans[25], ans[26], ans[27], ans[28], ans[29], ans[30], ans[31], ans[32], ans[33], ans[34], ans[35], ans[36], ans[37], ans[38], ans[39], ans[40], ans[41], ans[42], ans[43], ans[44], ans[45], ans[46], ans[47], ans[48], ans[49]);
    return ans;

}

int main(int argc, char** argv){
    string pattern = string(argv[1]);
    string target = string(argv[2]);
    cout<<pattern<<endl<<target<<endl;
    vector<char*> output;
    output = ssscanf(argv[2], argv[1]);
    int last_chars = 0;
    for(int i = 0;i < 50; i++){
        if(output[i][0] != '\0') last_chars = i;
    }
    for(int i = 0;i <= last_chars; i++){
        cout<<output[i]<<endl;
    }

    return 0;
}

