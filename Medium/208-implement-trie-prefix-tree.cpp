struct TrieNode
{
    bool isEndOfWord;
    TrieNode *child[26];

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (auto cha : word)
        {
            if (curr->child[cha - 'a'] == nullptr)
                curr->child[cha - 'a'] = new TrieNode();
            curr = curr->child[cha - 'a'];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (auto cha : word)
        {
            if (curr->child[cha - 'a'] == nullptr)
                return false;
            curr = curr->child[cha - 'a'];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (auto cha : prefix)
        {
            if (curr->child[cha - 'a'] == nullptr)
                return false;
            curr = curr->child[cha - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */