class Node{
    public:
    Node* children[26];
    bool end;

    Node(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        end=false;
    }

};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* cur=root;
        for(int i=0;i<word.length();i++){
            int x=word[i]-'a';
            if(cur->children[x]==nullptr)cur->children[x]= new Node();
            cur=cur->children[x];
        }
        cur->end=true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
private:
    bool dfs(string word,int j,Node* root){
        Node* cur=root;
        for(int i=j;i<word.size();i++){
            char c= word[i];
            if(c=='.'){
                for(Node* child : cur->children){
                    if(child != nullptr && dfs(word,i+1,child)){
                        return true;
                    }
                }
                return false;
            }else{
                if(cur->children[c-'a']==nullptr) return false;
                cur=cur->children[c-'a'];
            }
        }
        return cur->end;
    }
};
