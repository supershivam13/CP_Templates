// TRIES
// a) efficient information retrieval data structure
// b) searchs in optimal time O( word.length() ), but takes extra space for storage

// IMPORTANT -
// A Normal Trie is also called a Prefix Trie because it contains all the prefixes of a word as well.
// A Suffix Trie is a Trie in which we insert all the sufffixes of the word along with the full word { as full word is also a suffix }.

// Insertion in Trie - O( word.length() );
// Searching in Trie - O( word.length() )

// **********************************************************************************

// Node class { as per the requirements }
class TrieNode {
public:
    int count;
    TrieNode* children[26];

    // Constructor initializes a Node
    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

void insert(TrieNode* root, string s) {

    TrieNode* curr = root;

    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';

        if (curr->children[idx] == NULL)                // create new node if already not present
            curr->children[idx] = new TrieNode();

        curr = curr->children[idx];                     // moving to the next node
        curr->count++;
    }
}

void getAns(TrieNode* root, string s, vector<string>& result) {

    TrieNode* curr = root;
    string out = "";

    for (int i = 0; i < s.length(); i++) {
            
        out += s[i];
        
        int idx = s[i] - 'a';
        curr = curr->children[idx];     // moving to the next node

        // when the count of a node is 1, it means it is visited only one time, so upto this
        // it can be the "Shortest Unique Prefix"
        if (curr->count == 1) {
            result.push_back(out);
            return;
        }
    }
}

// CODE starts here
vector<string> Solution::prefix(vector<string> &A) {
    
    vector<string> result;
    TrieNode* root = new TrieNode();

    for (int i = 0; i < A.size(); i++)      // Inserting all the words in Trie
        insert(root, A[i]);

    for (int i = 0; i < A.size(); i++)      // getting Shortest Uniue Prefix for all words
        getAns(root, A[i], result);

    return result;
}
