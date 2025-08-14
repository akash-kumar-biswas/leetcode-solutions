struct TrieNode{
    bool isEndOfWord;
    TrieNode* child[10];

    TrieNode(){
        isEndOfWord = false;
        for(int i = 0; i < 10; i++){
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto cha: word){
            if(curr->child[cha - '0'] == nullptr)
                curr->child[cha - '0'] = new TrieNode();
            curr = curr->child[cha - '0'];
        }
        curr->isEndOfWord = true;
    }
    
    int startsWith(string prefix) {
        TrieNode* curr = root;
        int len = 0;
        for(auto cha: prefix){
            if(curr->child[cha - '0'] == nullptr)
                return len;
            curr = curr->child[cha - '0'];
            len++;
        }
        return len;
    }
};

class Solution {
public:
    Trie* obj = new Trie();

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto it: arr1){
            obj->insert(to_string(it));
        }

        int maxLen = 0;
        for(auto it: arr2){
            maxLen = max(maxLen, obj->startsWith(to_string(it)));
        }
        return maxLen;
    }
};