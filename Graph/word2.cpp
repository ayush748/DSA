#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
int solve(string &word1,string &word2,vector<string>&wordlenght){
    queue<pair<string,int>>q;
    q.push({word1,1});
    unordered_set<string>st(wordlenght.begin(),wordlenght.end());
    st.erase(word1);
    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==word2){
            return steps;
        }
        for(int i=0;i<word.size();i++){
            char orginal=word[i];
            for(char ch='a';ch<='z';ch++){
                st.erase(word);
                q.push({word,steps+1});
            }
            word[i]=orginal;
        }
    }
    return 0;
}

int main(){
    return 0;
}