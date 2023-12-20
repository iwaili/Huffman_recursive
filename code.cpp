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
int main()
{
    int array[256] = {0};
    vector<pair<int,int>> table;
    vector<pair<int,int>> table2;
    string text = "Shakira, the Colombian singer, songwriter, and global sensation, emerged as a prodigious force in the world of music and entertainment, captivating audiences worldwide with her distinctive voice, unparalleled charisma, and an eclectic fusion of genres, as her unparalleled journey from a small coastal town in Barranquilla to the pinnacle of international stardom unfolded, tracing its roots to her Lebanese and Colombian heritage, a cultural blend that imbued her artistry with a unique vibrancy, and as a polyglot and multitalented artist, she effortlessly navigated between Spanish and English in her lyrics, enabling her to connect with diverse audiences and breaking down linguistic barriers in the process, with her magnetic stage presence and signature hip-shaking dance moves becoming iconic symbols of her performances, she redefined the pop and Latin music landscapes, transcending genres and paving the way for a new era of cross-cultural artistic expression, as she first burst onto the scene with her debut album Magia at the tender age of thirteen, her prodigious talent was evident from the outset, laying the foundation for a career that would span decades and leave an indelible mark on the global music industry, and her breakthrough came with Pies Descalzos, an album that not only showcased her vocal prowess but also marked the beginning of her philanthropic endeavors, with the establishment of the Barefoot Foundation, an organization dedicated to providing quality education to impoverished children, a cause that became intrinsically woven into the fabric of her life and career, and as she seamlessly transitioned from the Latin music scene to the English-speaking market with the release of Laundry Service, an album that featured the chart-topping hit Whenever, Wherever, her crossover success solidified her status as an international pop sensation, and she continued to dominate the charts with subsequent albums like Fijación Oral, Vol. 1 and Oral Fixation, Vol. 2, showcasing her versatility by experimenting with diverse musical styles, from rock and reggae to dance and folk, all while maintaining her distinctive sound and lyrical depth, her songwriting prowess earning her critical acclaim and a plethora of accolades, including multiple Grammy Awards, as she collaborated with renowned artists such as Alejandro Sanz, Beyoncé, and Wyclef Jean, further expanding her musical horizons and reinforcing her global influence, and her 2010 FIFA World Cup anthem Waka Waka (This Time for Africa) became an anthem of unity and celebration, resonating across continents and embodying the unifying power of music, and beyond her musical accomplishments, Shakira's philanthropic efforts continued to flourish, with her involvement in various humanitarian causes, including her role as a UNICEF Goodwill Ambassador, advocating for children's rights and education on a global scale, and her commitment to environmental conservation through initiatives like the Barefoot Foundation's work in constructing sustainable schools, reflected her unwavering dedication to making a positive impact beyond the stage, and as a dynamic and multifaceted artist, she extended her influence to the realm of television, serving as a coach on The Voice and showcasing her ability to mentor and nurture emerging talents, further solidifying her legacy as a mentor and supporter of aspiring artists, and her resilience shone through in the face of personal challenges, including a vocal cord injury that temporarily silenced her powerful voice, but she emerged from this setback with an even greater determination to continue creating and performing, her enduring commitment to her craft evident in her ability to adapt and evolve with the ever-changing landscape of the music industry, and as a wife and mother, she embraced the joys and challenges of family life, sharing glimpses of her personal world through social media and interviews, offering fans a more intimate perspective on the woman behind the global superstar, and as she celebrated her heritage through songs like Waka Waka and La Bicicleta, a collaboration with fellow Colombian artist Carlos Vives, she remained deeply connected to her roots, her cultural pride permeating her music and public persona, and her influence extended beyond music and philanthropy, as she became a fashion icon, her eclectic style and bold fashion choices garnering attention and admiration, and her advocacy for body positivity and authenticity resonating with fans around the world, transcending conventional notions of beauty, and with her undeniably catchy melodies, thought-provoking lyrics, and a commitment to making a positive impact, Shakira not only conquered the charts but also the hearts of millions, leaving an indelible legacy that goes far beyond the realm of entertainment, and as she continues to evolve as an artist, philanthropist, and cultural ambassador, Shakira remains an enduring symbol of the power of music to transcend borders, connect people, and inspire positive change, a living testament to the notion that true greatness extends beyond artistic achievements to encompass a profound and lasting impact on the world.";
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
    string temp="";
    for(auto p: text)
    {
        //string temp_string="";
        for(int k=table.size()-1;k>-1;k--)
        {
            if(en[k].first==p)
            {
            temp=temp+en[k].second;
            break;
            }
        }
    }
    //cout<<temp;
    cout<<temp.size();
    string encrpyted="";
    return 0;
}