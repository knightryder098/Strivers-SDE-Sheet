
//https://www.codingninjas.com/codestudio/problems/add-two-numbers-as-linked-lists_8230833?challengeSlug=striver-sde-challenge&leftPanelTab=0

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node * res=new Node(0);
    Node *curr=res;
    int c=0;
    while(num1!=NULL||num2!=NULL){
        int x=(num1)?num1->data:0;
        int y=(num2)?num2->data:0;
        int sum=x+y+c;
        c=sum/10;
        curr->next=new Node(sum%10);
        curr=curr->next;
        if(num1!=NULL)num1=num1->next;
        if(num2!=NULL)num2=num2->next;
    }
    if(c)curr->next=new Node(c);
    return res->next;
}
