*********************************************************  Question  *********************************************************************************
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104
*********************************************************  Solution  *********************************************************************************


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(node1 == NULL and node2==NULL) return NULL;
        if(node1==NULL)
        {
            Node *prv=nullptr , *curr=node2;
        while(curr)
        {
            Node*next = curr->next;
            curr->next=prv;
            prv=curr;
            curr=next;
        }
        return prv;
        }
        
        else if(node2==NULL)
        {
            Node *prv=nullptr , *curr=node1;
        while(curr)
        {
            Node*next = curr->next;
            curr->next=prv;
            prv=curr;
            curr=next;
            
        }
        return prv;
        }
        Node*ans = node1->data <= node2->data ? node1:node2;
        Node*head = ans;
        Node*curr1= ans==node1?node1->next:node1, *curr2=node2==ans?node2->next:node2;
        while(curr1 and curr2)
        {
            if(curr1->data <= curr2->data)
            {
                ans->next=curr1;
                curr1=curr1->next;
               
            }
            else{
                ans->next = curr2;
                curr2=curr2->next;
            }
            ans = ans->next;
            
        }
        
        ans->next =  curr1!=NULL?curr1:curr2;
        Node *prv=nullptr , *curr=head;
        while(curr)
        {
            Node*next = curr->next;
            curr->next=prv;
            prv=curr;
            curr=next;
            // cout<<curr->data<<" ";curr=curr->next;
        }
        //cout<<"hello\n";
        return prv;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends
