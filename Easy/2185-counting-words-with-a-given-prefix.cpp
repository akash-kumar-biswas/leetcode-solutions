struct TrieNode
{
    bool isEndOfWord;
    TrieNode *child[26];
    int cnt;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        cnt = 0;
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
            curr->cnt++;
        }
        curr->isEndOfWord = true;
    }

    int startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (auto cha : prefix)
        {
            if (curr->child[cha - 'a'] == nullptr)
                return 0;
            curr = curr->child[cha - 'a'];
        }
        return curr->cnt;
    }
};

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        Trie *obj = new Trie();

        for (auto str : words)
            obj->insert(str);
        return obj->startsWith(pref);
    }
};