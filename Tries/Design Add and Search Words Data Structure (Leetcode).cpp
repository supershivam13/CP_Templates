class WordDictionary {
public:
    // Structure for each Trie node
    struct TrieNode {
        bool endOfWord;
        TrieNode* children[26];
    };

    TrieNode* root;

    // Helper function to create a new Trie node
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->endOfWord = false;
        for (int i = 0; i < 26; ++i)
            newNode->children[i] = NULL;
        return newNode;
    }

    // Constructor to initialize the Trie root
    WordDictionary() {
        root = getNode();
    }

    // Adds a word to the dictionary
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';

            if (curr->children[index]==NULL)
                curr->children[index] = getNode();

            curr = curr->children[index];
        }
        curr->endOfWord = true;
    }

    // Helper recursive function for search with wildcard '.'
    bool searchUtil(TrieNode* node, const string& word, int pos) {
        if (!node) return false;

        for (int i = pos; i < word.length(); ++i) {
            char ch = word[i];

            if (ch == '.') {
                // Try all possible children
                for (int j = 0; j < 26; ++j) {
                    if (node->children[j] && searchUtil(node->children[j], word, i + 1))
                        return true;
                }
                return false;
            }
            else {
                int index = ch - 'a';
                if (node->children[index]==NULL)
                    return false;
                node = node->children[index];
            }
        }

        return node && node->endOfWord;
    }

    // Public search function
    bool search(string word) {
        return searchUtil(root, word, 0);
    }
};
