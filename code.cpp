//aloha
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,string>> make_tree(vector<pair<int,int>> table)
{
    int size = table.size();
    vector<pair<int,string>> ret;
    for(auto f:table)
    {
        ret.push_back({f.first,""});
    }
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            ret[j].second="0"+ret[j].second;
        }
        ret[i+1].second="1"+ret[i+1].second;
    }
    return ret;
}
/*
50 1
30 01
10 001
5  0001
3  00001
2  00000
*/
int main()
{
    int array[256] = {0};
    vector<pair<int,int>> table;
    vector<pair<int,int>> table2;
    string text = "Bats, nocturnal marvels of the sky, navigate the twilight realm with grace, their intricate echolocation guiding them through the darkness in search of prey, and as vital pollinators, they contribute to ecosystems by dispersing seeds and maintaining biodiversity; yet, these enigmatic creatures often face misconceptions and threats, from habitat loss to the risk of diseases like white-nose syndrome; their unique role in nature highlights the importance of conservation efforts, dispelling myths surrounding these winged wonders and fostering appreciation for their ecological significance, ensuring the survival of these silent guardians of the night.";
    cout<<text.size();
    for(auto f:text)
    {
        array[f]++;
    }
    int y=0;
    int y1=0;
    for(auto f:array)
    {
        if(f!=0)
        {
            table.push_back({y,f});
        }
        y++;
    }
    sort(table.begin(), table.end(),[](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});
    vector<pair<int,string>> en;
    en = make_tree(table);
    for(auto u:en)
    {
        cout<<char(u.first)<<" "<<u.second<<endl;
    }
    string temp="";
    int o=0;
    for(auto p: text)
    {
        //string temp_string="";
        for(int k=table.size()-1;k>-1;k--)
        {
            if(en[k].first==p)
            {
            temp=temp+en[k].second;
            if(o<10)
            {
            cout<<char(p)<<" "<<en[k].second<<endl;
            o++;
            }
            break;
            }
        }
    }
    //cout<<temp;
    cout<<temp.size();
    string encrpyted="";
    return 0;
}