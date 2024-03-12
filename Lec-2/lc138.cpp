/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//! Following Program need to be done with the use of Hash maps and sets
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // step-1>>creating a node without random
        Node *dummy = new Node(10);
        Node *temp = dummy;
        Node *tempC = head;

        while (temp)
        {
            Node *actual = new Node(tempC->val);
            temp->next = actual;
            temp = temp->next;
            tempC = tempC->next;
        }

        Node *duplicate = dummy->next;

        // step-2>>merging the linked list
        Node *a = head;
        Node *b = duplicate;
        dummy = new Node(0);
        Node *tempD = dummy;

        while (a)
        {
            tempD->next = a;
             tempD = tempD->next;
            a = a->next;

            tempD->next = b;
            tempD = tempD->next;
            b = b->next;
        }
        dummy = dummy->next;

        // step-3>>assigning random pointers
        Node *t1 = dummy;
        Node *t2;
        while (t1)
        {
            t2 = t1->next;
            while (t1->random)
            {
                t2->random = t1->random->next;
                t1 = t1->next->next;
            }
        }

        // step-3>>deleting connections
        Node *t = dummy;
        Node *d1 = new Node(10);
        Node *d2 = new Node(20);
         t1 = d1;
         t2 = d2;

        while (t)
        {
            t1->next = t;
            t = t->next;
            t1 = t1->next;

            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;
    }
};