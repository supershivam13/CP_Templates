// TRIES

// a) efficient information retrieval data structure
// b) searchs in optimal time O( word.length() ), but takes extra space for storage



// Insertion in Trie - O( word.length() );
// Searching in Trie - O( word.length() )


// **********************************************************************************


// structure of TrieNode ( as given )

// struct TrieNode {
//     bool isLeaf;
//     TrieNode* childern[SIZE];
// };


// Function to create a new node and return back its address

// TrieNode* getNode()
// {
//     // creating a dynamically allocated new node
//     TrieNode* n = new TrieNode;
// 
//     n->isLeaf = false;
// 
//     // initialising all the addresses in the arr array as NULL
//     for (int i = 0; i < SIZE; i++)
//         n->childern[i] = NULL;
// 
//     return n;
// }


//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // creating a copy of the main root node (as root node is the most important node of Trie)
    TrieNode* temproot = root;

    // inserting word character by character in Trie
    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        // create new node if already not present
        if (temproot->children[index] == NULL)
            temproot->children[index] = getNode();

        // moving to the next node
        temproot = temproot->children[index];

        // only marking the node with end of the word as true
        if (i == key.length() - 1)
            temproot->isLeaf = true;

    }
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key)
{
    // creating a copy of the main root node (as root node is the most important node of Trie)
    TrieNode* temproot = root;

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        // if word is not present, simply return false
        if (temproot->children[index] == NULL)
            return false;

        // moving to the next node
        temproot = temproot->children[index];
    }

    return temproot->isLeaf;
}
