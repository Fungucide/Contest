#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> dp[2];

string add(string s)
{
    int idx= s.size()-1;
    while(idx>=0)
    {
        if(s[idx]=='9')
        {
            s[idx]=='0';
            idx--;
        }
        else
        {
            s[idx]++;
            break;
        }
    }
    return s;
}

int f(string s,bool inc)
{
    if(s.size()==1)
    {
        return inc?10-(s[0]-'0'):0;
    }
    if(dp[inc].find(s)==dp[inc].end())
    {
        int res = 1<<30;
        int first = s[s.size()-1]-'0';
        int last = s[0]-'0';
        string adjust=add(s.substr(1,s.size()-2));

        //bring first to last
        if(first<last)
        {
            res = min(res,f(s.substr(1,s.size()-2),false)+last-first);
            res = min(res,f(s.substr(1,s.size()-2),true)+last-first-1);
            //Try looping last
            res = min(res,f(adjust,false)+10-last+first);
            res = min(res,f(adjust,true)+9-last+first);
        }
        //bring last to first
        if(last<first)
        {
            res = min(res,f(s.substr(1,s.size()-2),false)+first-last);
            res = min(res,f(s.substr(1,s.size()-2),true)+first-last-1);
        }
        //can increment
        if(inc)
        {
            //Bring first to last
            res = min(res,f(s.substr(1,s.size()-2),false)+10-first+last);
            res = min(res,f(s.substr(1,s.size()-2),true)+9-first+last);
            //Bring both to 0
            res = min(res,f(adjust,false)+20-first-last);
            res = min(res,f(adjust,true)+19-first-last);
        }
        dp[inc][s]=res;
    }
    return dp[inc][s];
}

int main()
{
    string s;
    cin>>s;
    cout<<min(f(s,true),f(s,false))<<"\n";
    return 0;
}
