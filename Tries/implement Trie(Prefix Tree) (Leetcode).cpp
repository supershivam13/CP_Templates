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
private:
    // Each TrieNode represents one character in the Trie
    struct TrieNode {
        bool isEnd;                         // Marks end of a complete word
        TrieNode* children[26];             // Pointers to next characters (a–z)

        // Constructor initializes a Node
        TrieNode() {
            this->isEnd = false;
            for(int i = 0; i < 26; i++)      // Initialize all children as null
                children[i] = NULL;
        }
    };

    TrieNode* root;  // Root of the Trie (empty node)

    // Helper DFS function to search a word
    bool searchDFS(TrieNode* node, const string& word, int pos) {
    
        if (node == NULL) 
            return false;

        // If we have processed all characters, check whether current node marks end of a word
        if (pos == word.size())
            return node->isEnd;

        char ch = word[pos];                                                 
        int idx = ch - 'a';

        return searchDFS(node->children[idx], word, pos + 1);
    }

public:
    // Constructor initializes the Trie with an empty root
    Trie() {
        root = new TrieNode();
    }

    // Time Complexity: O(L), where L = word length
    void insert(const string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx]==NULL)                  // Create new node if path does not exist
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }


    // Searches a word in the Trie (Supports wildcard '.')
    bool search(const string& word) {
        return searchDFS(root, word, 0);
    }

    // Checks if any word in the Trie starts with the given prefix - Time Complexity: O(L)
    bool startsWith(const string& prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (curr->children[idx] == NULL)
                return false;                       // Prefix path breaks
            
            curr = curr->children[idx];
        }
        return true;                                // All prefix characters matched
    }
};
