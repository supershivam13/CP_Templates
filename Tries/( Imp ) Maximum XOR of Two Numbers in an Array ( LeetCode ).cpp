// TRIES

// a) efficient information retrieval data structure
// b) searchs in optimal time O( word.length() ), but takes extra space for storage


// IMPORTANT -

// A Normal Trie is also called a Prefix Trie because it contains all the prefixes of a word as well.
// A Suffix Trie is a Trie in which we insert all the sufffixes of the word along with the full word { as full word is also a suffix }.


// Insertion in Trie - O( word.length() );
// Searching in Trie - O( word.length() )


// **********************************************************************************


// Time Complexity - O( N*log(a[i]) ) = O( N*32 ) = O(N)


// Node class { as per the requirements }
class node {
public:

    node* a[2];

    // Constructor
    node() {
        for (int i = 0; i < 2; i++)
            a[i] = NULL;
    }

    // Destructor
    ~node() {
        for (int i = 0; i < 2; i++) {
            if (a[i] != NULL)
                delete a[i];
        }
    }
};

// Function to insert the number 'i' in Trie with MSB attached to root and LSB as leaf node.
void insert(node *root, int x) {

    node* temproot = root;

    for (int i = 31; i >= 0; i--) {

        int bit = (x >> i) & 1;

        if (temproot->a[bit] == NULL)
            temproot->a[bit] = new node();

        temproot = temproot->a[bit];
    }
}


// getAns return the value of the maximum XOR possible using one element as x
int getAns(node *root, int x) {

    node* temproot = root;
    int ans = 0;

    for (int i = 31; i >= 0; i--) {

        // getting the i-th bit of x
        int bit = (x >> i) & 1;

        if (bit == 0) {

            // if bit = 0, then look for 1 { opposite bit to maximise XOR }
            // else have to go with 0
            if (temproot->a[1] != NULL) {
                temproot = temproot->a[1];

                // if opposite bit is found, then it contributes in the XOR
                ans += (1 << i);
            }
            else
                temproot = temproot->a[0];
        }

        else {

            // if bit = 1, then look for 0 { opposite bit to maximise XOR }
            // else have to go with 1
            if (temproot->a[0] != NULL) {
                temproot = temproot->a[0];

                // if opposite bit is found, then it contributes in the XOR
                ans += (1 << i);
            }
            else
                temproot = temproot->a[1];
        }

    }
    return ans;
}


// Solution starts here
class Solution {
public:
    int findMaximumXOR(vector<int>& a) {

        node* root = new node();
        int size = a.size();

        // Inserting all the numbers in Trie with MSB attached to root and LSB as leaf node.
        for (int i = 0; i < size; i++)
            insert(root, a[i]);

        int ans = 0;

        for (int i = 0; i < size; i++) {

            // getAns return the value of the maximum XOR possible using one element as a[i]
            int temp = getAns(root, a[i]);
            ans = max(temp, ans);
        }

        return ans;
    }
};
