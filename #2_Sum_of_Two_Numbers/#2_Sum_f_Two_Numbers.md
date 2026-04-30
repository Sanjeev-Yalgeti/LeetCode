# Sum Of Two Numbers (LeetCode 2)

## 🧾 Problem Statement

You are given two non-empty linked lists representing two non-negative integers.

Digits are stored in reverse order
Each node contains one digit

---
## 📌 Rules

Each node contains a single digit (0–9)
The result should also be in reverse order
You may assume no leading zeros (except the number 0 itself)

---

## 💡 Logic

* Used a dummy head and tail to create a Linked List.Dummy head
 is the start of the Linked List and Tail is used to add values to the Linked List. 

* Start by initializing head and tail as NULL; carry = 0.

* we run a loop to add sum of values to the dummy head LL.when L1,L2 and carry exists(!=NULL) the loop runs ,when all three are NULL/0 the loop terminates.This is to prevent Loop from terminating if only one of them becomes 0/NULL. 

* In the loop,check if values of current node of l1 and l2 exists,if they do they retain value else assiged as 0 to prevent errors.calculate sum of the values and carry .create a new Node and asign the value.If It is the first node (Head==NULL) then head=newNode & tail=head .
If 2nd or after nodes then next of tail becomes newNode and tail is incremented.l1 and l2 are checked to see if not Null and are incremented.  



---

## ⚙️ Code

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum;
        ListNode *tail=NULL;
        ListNode *head=NULL;
        while(l1!=NULL || l2!=NULL || carry)
        {   
            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;
            sum=x+y+carry;
            carry=sum/10;
            ListNode *newNode=new ListNode(sum%10);
            if( head==NULL)
            {
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }

            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return head;
    }
};

```

---

## ⏱️ Time Complexity

O(n)

## 🧠 Space Complexity

O(n)

---

## 📊 Performance

* Runtime: 0 ms (beats 100.00%)
* Memory: 72.28 MB (beats 11.77%)

---

## 🖼️ Proof

![alt text](image.png)