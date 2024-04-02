#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct node{
    char data;
    unsigned frequency;
    node *left,*right;
    node(char data,unsigned frequency) : data(data),frequency(frequency),left(nullptr),right(nullptr){}
    node(){
        delete left;
        delete right;
    }
};
struct compare{
    bool operator()(node *left,node *right){
        return left->frequency > right->frequency;
    }
};
node *buildHuffmanTree(const unordered_map<char,unsigned>& freqMap){
    priority_queue<node* , vector<node*>,compare> pq;
    for(auto& pair : freqMap){
        pq.push(new node(pair.first,pair.second));
    }
    while(pq.size()!=1){
        node* left = pq.top();
        pq.pop();
        node* right = pq.top();
        pq.pop();
        node* internalnode = new node('$',left->frequency+right->frequency);
        internalnode->left = left;
        internalnode->right = right;
        pq.push(internalnode);
    }
    return pq.top();
}
void generatecodes(node* root, string code,unordered_map<char,string>& codes){
    if(root==nullptr) return;
    if(root->data!='$'){
        codes[root->data]=code;
    }
    generatecodes(root->left,code+"0",codes);
    generatecodes(root->right,code+"1",codes);
}
string compress(const string& data){
    unordered_map<char,unsigned> freqMap;
    for(char c : data){
        freqMap[c]++;
    }
    node* root = buildHuffmanTree(freqMap);
    unordered_map<char, string> codes;
    generatecodes(root,"",codes);
    string compressedData;
    for(char c : data){
        compressedData+=codes[c];
    }
    delete root;
    return compressedData;
}
int main(){
    string data = "huffman";
    string compressedData  = compress(data);
    cout<<"Original data : "<<data<<endl;
    cout<<"compressed data : "<<compressedData<<endl;
    return 0;
}