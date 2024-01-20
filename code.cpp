#include <iostream>
#include <queue>
#include <unordered_map>
#include <bitset>
using namespace std;
string h="";
class Node {
public:
    char data;
    unsigned freq;
    Node* left, *right;

    Node(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

Node* buildHuffmanTree(const unordered_map<char, unsigned>& freqTable) {
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

    for (const auto& entry : freqTable) {
        minHeap.push(new Node(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* internalNode = new Node('\0', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

void generateHuffmanCodes(Node* root, string currentCode, unordered_map<char, string>& codes) {
    if (root) {
        if (root->data != '\0') {
            codes[root->data] = currentCode;
        }
        generateHuffmanCodes(root->left, currentCode + "0", codes);
        generateHuffmanCodes(root->right, currentCode + "1", codes);
    }
}

void huffmanEncode(const string& input) {
    unordered_map<char, unsigned> freqTable;
    for (char c : input) {
        freqTable[c]++;
    }

    Node* root = buildHuffmanTree(freqTable);

    unordered_map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for (const auto& entry : codes) {
        cout << entry.first << ": " << entry.second << '\n';
    }

    cout << "Encoded String: ";
    cout<<codes.size()<<endl;
    /*
    int u=0;int lp=0;
    while(u==0)
    {
        int b=(b*10)+c[lp++];
        if(lp%8==0&&lp!=0)
        {
        char prin = char(b);
        cout<<prin;
        }
    }
    */
    string temp="";
    for (char c : input) {
        //cout << codes[c];
        temp+=codes[c];
    }
    //cout<<temp;
    string ultratemp="";
    int u=0;int lp=0;
    string b="";
    while(u!=temp.size()-1)
    {
        //cout<<b<<"  "<<endl;
        //cout<<temp[u];
        b=b+temp[u++];
        //cout<<b<<endl;
        if(u%8==0&&u!=0)
        {
        //if(b<0)
        //b=-b;
        //cout<<b<<" ";
        std::bitset<8> bits(b);
        char prin = static_cast<char>(bits.to_ulong());
        //cout<<prin<<" ";
        h+=prin;
        ultratemp+=prin;
        b="";
        }
        //if()
    }
    cout<<ultratemp.size();
    cout << '\n';
}

int main() {
    cout<<"..................................................................................................................";
    cout<<"..................................................................................................................";
    cout<<"..................................................................................................................";
    string inputString = "Born in Barranquilla, Colombia, on February 2, 1977, Shakira is an iconic artist celebrated globally for her genre-defying music that seamlessly weaves together Latin, pop, and rock influences. From her early years, she showcased remarkable musical talent and creativity, writing her first song at the age of eight. Her career trajectory shifted decisively in the late '90s with the release of albums like Pies Descalzos and ¿Dónde Están los Ladrones?, marking her emergence as a transformative force in the music industry. The release of her English-language debut, Laundry Service, in 2001, featuring the chart-topping single Whenever, Wherever, propelled her to international stardom, solidifying her status as a cross-cultural icon. Beyond her musical accomplishments, Shakira's dynamic stage presence, marked by her distinctive belly dancing and emotionally charged performances, sets her apart as one of the most captivating live artists of her generation. Her influence extends beyond the realm of entertainment, with a profound commitment to philanthropy evident in the establishment of the Pies Descalzos Foundation in 1997. This foundation reflects her dedication to providing education and nutrition to disadvantaged children in Colombia, showcasing Shakira's enduring impact as an artist and a humanitarian, transcending borders and leaving an indelible mark on the world stage";
    huffmanEncode(inputString);
    string hi=h;
    huffmanEncode(hi);
    hi=h;
    huffmanEncode(hi);
    return 0;
}
