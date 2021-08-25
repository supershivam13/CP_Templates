vector<string> ans;

class node{
    public:

    int count;
    node* a[26];

    node(){
        count=0;
        for(int i=0;i<26;i++)
            a[i]=NULL;
    }

    ~node(){
        for(int i=0;i<26;i++){
            if(a[i]!=NULL)
                delete a[i];
        }
    }
};


void insert(node* root, string s){

    node* temproot = root;

    for(int i=0;i<s.length();i++){

        int index=s[i]-'a';
        
        if(temproot->a[index]==NULL)
            temproot->a[index]= new node();
        
        temproot = temproot->a[index];
        temproot->count++;
    }
}

void getAns(node* root,string s){

    node* temproot = root;
    string out="";

    for(int i=0;i<s.length();i++){

        int index= s[i]-'a';

        temproot=temproot->a[index];
        out+=s[i];

        if(temproot->count==1){
            ans.push_back(out);
            return;
        }
    }

}


// Solution Starts here
vector<string> Solution::prefix(vector<string> &A) {

    ans.clear();

    node* root = new node();

    for(int i=0;i<A.size();i++)
        insert(root,A[i]);
    
    for(int i=0;i<A.size();i++)
        getAns(root,A[i]);

    delete root;

    return ans;
}
