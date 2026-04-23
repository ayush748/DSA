#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

int solve(string &word1,string &endword,vector<string>&wordlength)
{
    queue<pair<string,int>>q;
    q.push({word1,1});

    unordered_set<string>st(wordlength.begin(),wordlength.end());
    st.erase(word1);

    while(!q.empty())
    {
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();

        if(word==endword)
        {
            return steps;
        }

        for(int i=0;i<word.size();i++)
        {
            char original=word[i];

            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;

                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }

            word[i]=original;
        }
    }

    return 0;
}

int main()
{
    string start="hit";
    string end="cog";

    vector<string>arr={"hot","dot","dog","lot","log","cog"};

    int ans=solve(start,end,arr);

    cout<<ans;

    return 0;
}