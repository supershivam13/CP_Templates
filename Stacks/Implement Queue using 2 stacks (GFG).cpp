/* The structure of the class is
class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    int ans;
    if(!s2.empty()){
        ans=s2.top();
        s2.pop();
    }
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
            
        if(!s2.empty()){
        ans=s2.top();
        s2.pop();
        }
        else
            ans=-1;
    }
    return ans;       
}
