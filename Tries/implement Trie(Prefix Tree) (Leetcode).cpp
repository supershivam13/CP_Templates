// TRIES

// a) efficient information retrieval data structure
// b) searchs in optimal time O( word.length() ), but takes extra space for storage


// IMPORTANT -

// A Normal Trie is also called a Prefix Trie because it contains all the prefixes of a word as well.
// A Suffix Trie is a Trie in which we insert all the sufffixes of the word along with the full word { as full word is also a suffix }.


// INSERTION in Trie - O( word.length() );
// SEARCHING in Trie - O( word.length() )


// **********************************************************************************

class Trie {
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
        for (int i = 0; i < 26; i++)
            newNode->children[i] = NULL;
        
        return newNode;
    }

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
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
    
    // Checks if any word in the Trie starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';
            if (curr->children[index]==NULL)
                return false;
            
            curr = curr->children[index];
        }
        return true;
    }
};
