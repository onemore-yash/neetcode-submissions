class Node{
    public:
    Node* children[26];
    bool end;

    Node(){
        for(int i=0;i<26;i++)children[i]=nullptr;
        end=false;
    }
};

class PrefixTree {
        Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(char c:word){
            if(node->children[c-'a']==nullptr) node->children[c-'a']=new Node();
            node=node->children[c-'a'];
        }
        node->end=true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(char c:word){
            if(node->children[c-'a']==nullptr) return false;
            node=node->children[c-'a'];
        }
        return node->end;
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(char c:word){
            if(node->children[c-'a']==nullptr) return false;
            node=node->children[c-'a'];
        }
        return true;
    }
};
