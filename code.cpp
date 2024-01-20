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
    string inputString = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Sociis natoque penatibus et magnis dis. Quisque egestas diam in arcu cursus. Habitasse platea dictumst quisque sagittis purus sit amet. Elementum sagittis vitae et leo duis. Neque laoreet suspendisse interdum consectetur libero id faucibus nisl tincidunt. Lacus vestibulum sed arcu non. Massa enim nec dui nunc mattis enim ut tellus elementum. Id ornare arcu odio ut sem nulla pharetra diam. Velit dignissim sodales ut eu. Maecenas volutpat blandit aliquam etiam erat velit scelerisque in dictum. Auctor augue mauris augue neque. Ac turpis egestas sed tempus urna et pharetra pharetra. Congue quisque egestas diam in arcu cursus euismod.Praesent elementum facilisis leo vel fringilla est. Euismod elementum nisi quis eleifend quam adipiscing vitae proin. Diam volutpat commodo sed egestas egestas. Augue ut lectus arcu bibendum at varius vel. Ut tristique et egestas quis ipsum suspendisse ultrices gravida. Ut morbi tincidunt augue interdum velit euismod in. Praesent semper feugiat nibh sed pulvinar proin gravida. Eget mi proin sed libero enim sed. Fringilla est ullamcorper eget nulla facilisi. Quis commodo odio aenean sed adipiscing. Vestibulum morbi blandit cursus risus at ultrices mi tempus. Felis imperdiet proin fermentum leo vel orci porta non pulvinar. Nulla posuere sollicitudin aliquam ultrices. Nisi scelerisque eu ultrices vitae auctor. Tempor commodo ullamcorper a lacus vestibulum sed arcu. Faucibus interdum posuere lorem ipsum dolor sit. Sagittis orci a scelerisque purus semper eget duis at. Non tellus orci ac auctor augue mauris augue. Id consectetur purus ut faucibus pulvinar elementum. Massa sapien faucibus et molestie ac feugiat sed lectus.Senectus et netus et malesuada fames ac turpis egestas integer. Morbi tincidunt augue interdum velit euismod in. Nec ultrices dui sapien eget mi proin sed. Nisl pretium fusce id velit ut. Sed libero enim sed faucibus. Ipsum suspendisse ultrices gravida dictum fusce ut placerat. Purus viverra accumsan in nisl nisi scelerisque. Pellentesque eu tincidunt tortor aliquam nulla facilisi. Quam adipiscing vitae proin sagittis nisl rhoncus mattis rhoncus. Diam vel quam elementum pulvinar etiam non quam lacus suspendisse. A arcu cursus vitae congue mauris rhoncus aenean vel. Id aliquet lectus proin nibh.Feugiat vivamus at augue eget. Consectetur libero id faucibus nisl tincidunt eget nullam non. Amet mattis vulputate enim nulla aliquet. Vel facilisis volutpat est velit. Et netus et malesuada fames ac turpis egestas. Praesent tristique magna sit amet purus gravida quis blandit turpis. Non quam lacus suspendisse faucibus interdum posuere lorem. Tristique senectus et netus et malesuada fames ac turpis egestas. Etiam non quam lacus suspendisse faucibus interdum posuere lorem ipsum. Tincidunt eget nullam non nisi est sit amet facilisis. Eget lorem dolor sed viverra ipsum nunc aliquet bibendum enim. Volutpat lacus laoreet non curabitur. Nulla facilisi nullam vehicula ipsum a arcu cursus. Dolor magna eget est lorem. Venenatis lectus magna fringilla urna porttitor rhoncus dolor purus.Pellentesque dignissim enim sit amet venenatis urna cursus. Dolor morbi non arcu risus quis varius quam. Ut morbi tincidunt augue interdum velit. Fames ac turpis egestas sed tempus urna et pharetra. Consectetur libero id faucibus nisl tincidunt eget nullam. Sed egestas egestas fringilla phasellus faucibus scelerisque eleifend donec. Donec enim diam vulputate ut pharetra sit amet aliquam id. Sit amet volutpat consequat mauris nunc congue nisi vitae. Mauris nunc congue nisi vitae suscipit tellus mauris a. Volutpat odio facilisis mauris sit. Sit amet purus gravida quis blandit turpis cursus in hac. In hac habitasse platea dictumst vestibulum rhoncus est pellentesque. Vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras tincidunt lobortis. Orci ac auctor augue mauris augue neque.Tincidunt eget nullam non nisi est sit amet. Nisl tincidunt eget nullam non nisi est sit amet. Morbi leo urna molestie at. Dictum varius duis at consectetur lorem donec. Cras semper auctor neque vitae tempus. Tincidunt dui ut ornare lectus sit amet est placerat in. Adipiscing tristique risus nec feugiat in fermentum posuere urna nec. Sit amet aliquam id diam. Ac turpis egestas integer eget aliquet. Felis imperdiet proin fermentum leo vel orci porta. Tempus iaculis urna id volutpat lacus laoreet non. Sed tempus urna et pharetra pharetra massa. Egestas maecenas pharetra convallis posuere. Nam at lectus urna duis convallis convallis tellus id interdum. Viverra tellus in hac habitasse platea dictumst vestibulum. Sed cras ornare arcu dui vivamus arcu felis bibendum ut. Phasellus egestas tellus rutrum tellus pellentesque. At erat pellentesque adipiscing commodo. Aliquet risus feugiat in ante metus dictum at.Elementum facilisis leo vel fringilla. Gravida arcu ac tortor dignissim. Est ullamcorper eget nulla facilisi etiam. Euismod lacinia at quis risus sed vulputate odio ut. Ridiculus mus mauris vitae ultricies leo. Elementum nibh tellus molestie nunc non blandit massa. Sed turpis tincidunt id aliquet risus feugiat in ante metus. Senectus et netus et malesuada fames. Egestas purus viverra accumsan in nisl. Vitae aliquet nec ullamcorper sit amet risus. Velit aliquet sagittis id consectetur. Tempus imperdiet nulla malesuada pellentesque. Massa enim nec dui nunc mattis enim ut tellus. Pretium vulputate sapien nec sagittis aliquam malesuada bibendum arcu.Amet volutpat consequat mauris nunc congue nisi vitae. Molestie ac feugiat sed lectus vestibulum mattis ullamcorper velit. Nibh ipsum consequat nisl vel pretium lectus quam. Turpis massa sed elementum tempus egestas sed. At elementum eu facilisis sed odio morbi. Ultricies leo integer malesuada nunc vel risus commodo viverra maecenas. Id velit ut tortor pretium viverra suspendisse potenti nullam. Scelerisque fermentum dui faucibus in ornare quam. Ipsum nunc aliquet bibendum enim facilisis. Semper auctor neque vitae tempus quam pellentesque.Commodo elit at imperdiet dui accumsan. Viverra suspendisse potenti nullam ac tortor. Ante in nibh mauris cursus mattis. Vitae proin sagittis nisl rhoncus. Eget gravida cum sociis natoque penatibus. Vulputate ut pharetra sit amet aliquam id diam maecenas. Ornare suspendisse sed nisi lacus sed viverra tellus in. Adipiscing elit pellentesque habitant morbi. Eu augue ut lectus arcu bibendum at varius. Commodo odio aenean sed adipiscing diam donec adipiscing tristique risus. Sapien nec sagittis aliquam malesuada bibendum arcu vitae elementum. Ut ornare lectus sit amet est placerat in egestas erat. Venenatis urna cursus eget nunc scelerisque. Quam pellentesque nec nam aliquam sem et. Ultricies leo integer malesuada nunc. Tempor commodo ullamcorper a lacus. Faucibus nisl tincidunt eget nullam non nisi est. Ac turpis egestas sed tempus urna et pharetra. Urna neque viverra justo nec ultrices dui. Metus vulputate eu scelerisque felis imperdiet proin fermentum.Tortor dignissim convallis aenean et tortor at risus viverra. Euismod lacinia at quis risus. Mi tempus imperdiet nulla malesuada pellentesque. Sit amet nisl purus in. Lobortis scelerisque fermentum dui faucibus in ornare. Nunc consequat interdum varius sit amet mattis vulputate enim nulla. Facilisis mauris sit amet massa. Aliquet enim tortor at auctor urna nunc. In nisl nisi scelerisque eu. Justo laoreet sit amet cursus sit amet dictum sit amet.";
    huffmanEncode(inputString);
    string hi=h;
    huffmanEncode(hi);
    hi=h;
    huffmanEncode(hi);
    return 0;
}
