class TrieNode {
public:
    TrieNode* children[26];
    int idx;
    int refs;

    TrieNode() {
        for(int i=0;i<26;i++)children[i]=nullptr;
        idx = -1;
        refs = 0;
    }

    void addWord(const string& word, int id) {
        TrieNode* cur = this;
        cur->refs++;
        for (char c : word) {
            int x = c - 'a';
            if (!cur->children[x])
                cur->children[x] = new TrieNode();
            cur = cur->children[x];
            cur->refs++;
        }
        cur->idx = id;
    }
};

class Solution {
public:
    vector<string> ans;

    void removeWord(TrieNode* root, const string& word) {
        TrieNode* cur = root;
        cur->refs--;

        for (char c : word) {
            cur = cur->children[c - 'a'];
            cur->refs--;
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, TrieNode* root,
             vector<string>& words) {

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            return;

        char ch = board[r][c];

        if (ch == '#')
            return;

        TrieNode* child = node->children[ch - 'a'];

        if (!child || child->refs == 0)
            return;

        if (child->idx != -1) {
            int id = child->idx;
            ans.push_back(words[id]);
            child->idx = -1;
            removeWord(root, words[id]);   
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, child, root, words);
        dfs(board, r - 1, c, child, root, words);
        dfs(board, r, c + 1, child, root, words);
        dfs(board, r, c - 1, child, root, words);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        for (int i = 0; i < words.size(); i++)
            root->addWord(words[i], i);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, root, words);
            }
        }

        return ans;
    }
};