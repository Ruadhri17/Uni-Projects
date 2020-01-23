#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <string>

using std::endl;
using std::cout;

template <typename Key, typename Info>
class Sequence{
    public:
        struct Node
        {
        Key key_of_node;
        Info info_of_node;
        Node *next;
        Node(Key k, Info i)
            {
            key_of_node = k;
            info_of_node = i;
            }
        };
        Sequence(); // Constructor of Sequence
        ~Sequence(); // Destructor of Sequence
        Sequence(const Sequence<Key, Info> &x); // Copy constructor of sequence
        Sequence<Key, Info> &operator=(const Sequence<Key, Info> &x); // overloaded "=" operator to copy Sequence
        bool operator==(const Sequence<Key, Info> &x); // overloaded "==" operator for checking the equality of two sequences
        bool operator!=(const Sequence<Key, Info> &x); // overloaded "!=" operator for checking the inequality of two sequences
        bool pushFront(const Key& add_key, const Info& add_info); // function used to add node at the beginning of sequence 
        bool pushBack(const Key& add_key, const Info& add_info); // function used to add node at the end of sequence
        bool insert(const Key& add_key , const Info& add_info, int occurence); // function used to add node with the repeated key right behind the node with that key
        bool popFront(); // function used to remove node which is first at the sequence
        bool popBack(); // function used to remove node which is last at the sequence
        bool remove(const Key& remove_key, int occurence); // function used to remove one of the node with repeatable key (occurence says which repeated key we remove) 
        bool removeAllKey(const Key& remove_key); // function used to remove all nodes with depict key
        bool removeAll(); // function used to remove every element in sequence
        void print(); // printing sequence 
        void printReversed(); // printing sequence in reversed order
        bool isEmpty() const; // return true if function is empty
        int size() const; // return number of elements in sequences
        bool findElement(const Key& find_key, int occurence) const;
        Node* getHead() const; // function which return private element of sequence (precisely head to have access to all sequence in external function merge)
    private:
        Node *head; // head of node;
        void print(Node *node); // recursive function of printing
        void printReversed(Node *node); // recursive function of printing in reversed order
};
template <typename Key, typename Info>
Sequence<Key, Info> merge(const Sequence<Key, Info> s1, int start1, int len1, const Sequence<Key, Info> s2, int start2, int len2, int count) // function of merge described
{
    typename Sequence<Key, Info>::Node *temp1 = s1.getHead();
    typename Sequence<Key, Info>::Node *temp2 = s2.getHead();
    Sequence<Key, Info> NewSequence;
    if(temp1 != NULL)
        {
        for(int l = 0; l < start1; l++)
            temp1 = temp1->next;
        }
    if(temp2 != NULL)
        {
        for(int m = 0; m < start2; m++)
            temp2 = temp2->next;
        }
    for(int k = 0; k < count; k++)
        {
                    for(int i = 0; i < len1; i++)
                        { 
                            if(temp1 == NULL)
                                break;
                            NewSequence.pushBack(temp1->key_of_node, temp1->info_of_node);
                            temp1 = temp1->next;
                        }
                    for(int j = 0; j < len2; j++)
                        {
                            if(temp2 == NULL)
                                break;
                            NewSequence.pushBack(temp2->key_of_node, temp2->info_of_node);
                            temp2 = temp2->next;
                        }

        }   
    return NewSequence;
}
template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    head = NULL;

}
template <typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{
    Node *temp = head;
    while(head != NULL)
        {   
            temp = head->next;
            delete head;
            head = temp;
        }
}
template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence<Key, Info> &x)
{
    head = NULL;
    Node *temp =x.head;
    while(temp != NULL)
        {
            pushBack(temp->key_of_node, temp->info_of_node);
            temp = temp->next;
        }
}
template <typename Key, typename Info>
bool Sequence<Key,Info>::pushFront(const Key& add_key, const Info& add_info)
{
    if(head == NULL)
        {
            Node *add = new Node(add_key, add_info);
            head = add;
            head->next = NULL;
            return true;
        }
    else if(head != NULL)
        {
            Node *add = new Node(add_key, add_info);
            Node *temp = head;
            head = add;
            head->next = temp;
            return true;
        }    
    else 
        {
        return false;
        }
}
template <typename Key, typename Info>
bool Sequence<Key,Info>::pushBack(const Key& add_key, const Info& add_info)
{
    if(head == NULL)
        {
            Node *add = new Node(add_key, add_info);
            head = add;
            head->next = NULL;
            return true;
        }
    else if(head != NULL)
        {
            Node *add = new Node(add_key, add_info);
            Node *temp = head;
            while(temp->next != NULL)
                {
                    temp = temp->next;
                }
            temp->next = add;
            (temp->next)->next = NULL;
            return true;
        }
    else
        {
        return false;
        }
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::insert(const Key& add_key , const Info& add_info, int occurence)
{
    Node *temp = head;
    if(temp == NULL || occurence < 1)
        return false;
    while(temp != NULL)
        {
            if(temp->key_of_node == add_key)
                occurence--;
            if(occurence == 0)
                break;
            temp = temp->next;
        }
    if(occurence > 0)
        return false;
    else
    {
        Node *add = new Node(add_key, add_info);
        if(temp->next == NULL)
            {
                temp->next = add;
                (temp->next)->next = NULL;
                return true;
            }
        else
            {
                Node *temp2 = temp->next;
                temp->next = add;
                (temp->next)->next = temp2;
                return true;
            }    
    }
    
}
template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator=(const Sequence<Key, Info> &x)
{
if(&x != this)
    {
        if(this->head != NULL)
            {
                Node *temp = this->head;
                while(head != NULL)
                    {
                        temp = head->next;
                        delete head;
                        head = temp;
                    }
            }
    }
    Node *temp2 = x.head;
    while(temp2 != NULL)
        {
            pushBack(temp2->key_of_node, temp2->info_of_node);
            temp2 = temp2->next;        
        }
    return *this;
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::operator==(const Sequence<Key, Info> &x)
{
    Node *temp = this->head;
    Node *temp2 = x.head;
    if(this->size() != x.size())
        return false; 
    while(temp != NULL)
        {
            if(temp->key_of_node != temp2->key_of_node && temp->info_of_node != temp2->info_of_node)
                    return false;
            temp2 = temp2->next;
            temp = temp->next;
        }
    return true;
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::operator!=(const Sequence<Key, Info> &x)
{
    Node *temp = this->head;
    Node *temp2 = x.head;
    if(this->size() != x.size())
        return true; 
    while(temp != NULL)
        {
            if(temp->key_of_node != temp2->key_of_node && temp->info_of_node != temp2->info_of_node)
                    return true;
            temp2 = temp2->next;
            temp = temp->next;
        }
    return false;
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::popFront()
{
    if(head == NULL)
        return false;
    else if(head != NULL && head->next == NULL)
        {
            delete head;
            head = NULL;
            return true;
        }
    else if(head != NULL && head->next != NULL)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
            return true;
        }
    else
        {
            return false;
        }
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::popBack()
{
    if(head == NULL)
        return false;
    else if(head != NULL && head->next == NULL)
        {
            delete head;
            head = NULL;
            return true;
        }
    else if(head != NULL && head->next != NULL)
        {
            Node *temp = head;
            Node *temp2 = temp;
            while(temp->next != NULL)
                {
                    temp2 = temp;
                    temp = temp->next;
                }
            delete temp;
            temp2->next = NULL;
            return true;
        }
    else
        {
            return false;
        }
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::remove(const Key& remove_key, int occurence)
{
    Node *temp =head;
    Node *temp2 = temp;
    if(temp == NULL || occurence == 0)
        return false;
    while(temp != NULL)
        {
            if(temp->key_of_node == remove_key)
                occurence--;
            if(occurence == 0)
                break;
            temp2 = temp;
            temp = temp->next;
        }
    if(temp->next == NULL && occurence >0)
        return false;
    else
        {
        if(temp == head)
            {
                head = temp->next;
                delete temp;
                return true;
            }
        else if(temp->next == NULL)
            {
                delete temp;
                temp2->next = NULL;
                return true;
            }
        else if(temp->next != NULL)
            {
            temp2->next = temp->next;
            delete temp;
            return true;
            }
        }  
    return false; 
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::removeAllKey(const Key& remove_key)
{
    if(head == NULL)
        return false;
    Node *temp = head;
    Node *temp2 = temp;
    while(temp != NULL)
        {
            if(temp->key_of_node == remove_key)
                {     
                    if(temp == head && temp->next == NULL)
                        {
                            delete head;
                            head = NULL;
                            return true;
                        }
                    else if(temp == head && temp->next != NULL)
                        {
                            head = temp->next;
                            delete temp;
                            temp = head;
                            continue; 
                        }
                    else if(temp->next == NULL)
                        {
                            delete temp;
                            temp2->next = NULL;
                        }
                    else if(temp->next != NULL)
                        {
                            temp2->next = temp->next;
                            delete temp;
                            temp = temp2->next;
                            continue;
                        }
                }
            temp2 = temp;
            temp = temp->next;
        }
    return true;         
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::removeAll()
{
    if(head == NULL)
        return false;
    Node *temp = head;
    while(head != NULL)
        {   
            temp = head->next;
            delete head;
            head = temp;
        }
    return true;
}
template <typename Key, typename Info>
void Sequence<Key, Info>::print()
{
    if(head == NULL)
        return;
    print(head);
}
template <typename Key, typename Info>
void Sequence<Key, Info>::print(Node *node)
{
    if(node == NULL)
        {
            return;
        }
    cout<< node->key_of_node << " " << node->info_of_node << endl;
    print(node->next); 
}
template <typename Key, typename Info>
void Sequence<Key, Info>::printReversed()
{
    printReversed(head);
}
template <typename Key, typename Info>
void Sequence<Key, Info>::printReversed(Node *node)
{
    if(node == NULL)
        {
            return;
        }
    printReversed(node->next); 
    cout<< node->key_of_node << " " << node->info_of_node << endl;
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::isEmpty() const
{
    Node *temp = head;
    if(temp == NULL)
        return true;
    else
        return false; 
}
template <typename Key, typename Info>
int Sequence<Key, Info>::size() const
{
    int size = 0;
    Node *temp = head;
    while(temp != NULL)
        {
            size++;
            temp = temp->next;
        }
    return size;
}
template <typename Key, typename Info>
bool Sequence<Key, Info>::findElement(const Key& find_key, int occurence) const
{
    if(head == NULL)
        return false;
    Node* temp = head;
    while(temp != NULL)
        {
            if(temp->key_of_node == find_key)
                occurence--;
            if(occurence == 0)
                return true;
            temp = temp->next;
        }
    return false;
}
template <typename Key, typename Info>
typename Sequence<Key, Info>::Node* Sequence<Key, Info>::getHead() const 
{
    return head;
}
#endif