class Solution{
public:
    
    bool detectLoop(Node* head)
    {
        set<Node*> s;
        
        while(head!=NULL){
            
            if(s.find(head)!=s.end())
                return true;
            
            s.insert(head);
            head=head->next;
        }
        
        return false;
    }
};
