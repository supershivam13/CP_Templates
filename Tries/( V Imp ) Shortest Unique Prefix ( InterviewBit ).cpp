// TRIES

// a) efficient information retrieval data structure
// b) searchs in optimal time O( word.length() ), but takes extra space for storage


// IMPORTANT -

// A Normal Trie is also called a Prefix Trie because it contains all the prefixes of a word as well.
// A Suffix Trie is a Trie in which we insert all the sufffixes of the word along with the full word { as full word is also a suffix }.


// Insertion in Trie - O( word.length() );
// Searching in Trie - O( word.length() )


// **********************************************************************************


vector<string> ans;

// Node class { as per the requirements }
class node {
public:

    int count;
    node* a[26];

    // Constructor
    node() {
        count = 0;
        for (int i = 0; i < 26; i++)
            a[i] = NULL;
    }

    // Destructor
    ~node() {
        for (int i = 0; i < 26; i++) {
            if (a[i] != NULL)
                delete a[i];
        }
    }
};


// Function to insert word in Trie
void insert(node* root, string s) {

    node* temproot = root;

    for (int i = 0; i < s.length(); i++) {

        int index = s[i] - 'a';

        // create new node if already not present
        if (temproot->a[index] == NULL)
            temproot->a[index] = new node();

        // moving to the next node
        temproot = temproot->a[index];
        temproot->count++;
    }
}

void getAns(node* root, string s) {

    node* temproot = root;
    string out = "";

    for (int i = 0; i < s.length(); i++) {

        int index = s[i] - 'a';

        // moving to the next node
        temproot = temproot->a[index];

        out += s[i];

        // when the count of a node is 1, it means it is visited only one time, so upto this
        // it can be a unique prefix
        if (temproot->count == 1) {
            ans.push_back(out);
            return;
        }
    }

}


// Solution starts here
vector<string> Solution::prefix(vector<string> &A) {

    ans.clear();

    node* root = new node();

    // Inserting all the words in Trie
    for (int i = 0; i < A.size(); i++)
        insert(root, A[i]);

    // getting shortest uniue prefix for all words
    for (int i = 0; i < A.size(); i++)
        getAns(root, A[i]);

    // delete the dynamically allocated memory for root node
    delete root;

    return ans;
}
