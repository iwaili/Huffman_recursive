//aloha
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int array[256] = {0};
    vector<pair<int,int>> table;
    string text = "Nestled on the western fringes of Europe, Ireland captivates with its emerald landscapes, where rolling hills and expansive fields adorned with ancient castles create a timeless tableau. The rich tapestry of Irish culture weaves together traditional music, dance, and folklore, echoing through lively pubs and quiet countryside alike. Dublin, the bustling capital, harmonizes modernity with historic charm, while the rugged Cliffs of Moher offer breathtaking views of the Atlantic's ceaseless embrace. Ireland's literary legacy, from Yeats to Joyce, echoes in the whispers of its windswept landscapes. Amidst the warmth of its people and the allure of its myths, Ireland beckons as a land of enduring enchantment. The mystical allure extends to its prehistoric sites, such as the hauntingly beautiful Newgrange, standing proudly as a testament to ancient ingenuity. The warmth of Irish hospitality, expressed in friendly conversations over a pint of Guinness, creates a sense of belonging that resonates far beyond the boundaries of this island nation. Exploring the Wild Atlantic Way unveils hidden gems, where craggy cliffs meet the crashing waves, and quaint villages invite travelers to step back in time. Ireland's blend of history, natural beauty, and cultural vibrancy crafts an immersive experience that lingers in the heart, inviting all who venture there to become part of its storied narrative.";
    for(auto f:text)
    {
        array[f]++;
    }
    int y=0;
    for(auto f:array)
    {
        if(f!=0)
        table.push_back({y,f});
        y++;
    }
    sort(table.begin(), table.end(),[](const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;});
    for (const auto& pair : table) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }
    cout<<"hey";
    return 0;
}