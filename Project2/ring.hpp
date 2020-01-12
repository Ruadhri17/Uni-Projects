#ifndef RING_HPP
#define RING_HPP

#include <iostream>
#include <string>

using namespace std;

template <typename Key, typename Info>
class Ring
{
private:
    struct Node
    {
        Key key_of_node;
        Info info_of_node;
        Node *next;
        Node *prev;
        Node(Key k, Info i)
        {
            key_of_node = k;
            info_of_node = i;
        }
    };
    Node *head;
    int size;

public:
    Ring(); //
    ~Ring(); //
    Ring(const Ring<Key,Info> &x); //
    Ring<Key,Info> &operator=(const Ring<Key,Info> &x); //
    bool operator==(const Ring<Key, Info> &x) const; //
    bool operator!=(const Ring<Key, Info> &x) const; //
    bool push_front(Key add_key, Info add_info); //
    bool push_back(Key add_key, Info add_info); //
    bool insert(Key add_key, Info add_info, int occurence); //
    bool pop_front(); //
    bool pop_back(); //
    bool remove(Key remove_key, int occurence); //
    bool remove_all(); //
    bool remove_all_occurences(Key remove_key);
    void print(); //
    bool is_empty() const; //

    class Iterator;
    Iterator begin()
    {
        return head;
    }
    Iterator end()
    {
        return head->prev;
    }
    class ConstIterator;
    ConstIterator cbegin() const
    {
        return head;
    }
    ConstIterator cend() const
    {
        return head->prev;
    }
};
template <typename Key, typename Info>
void split(const Ring<Key, Info> &Source, bool direction, Ring<Key, Info> &Result1, int sequence1, int rep1, Ring<Key, Info> &Result2, int sequence2, int rep2)
{
    if(Source.is_empty())
        return;
    if(!Result1.is_empty() ||!Result2.is_empty())
        {
            Result1.remove_all();
            Result2.remove_all();
        }
    if(rep1 < 0)
        rep1 = 0;
    if(rep2 < 0)
        rep2 = 0;
    if(sequence1 < 0)
        sequence1 = 0;
    if(sequence2 < 0)
        sequence2 = 0;
    typename Ring<Key,Info>::ConstIterator itr = Source.cbegin();
    if(direction == true)
        {
            while(rep1 + rep2 > 0)
                {
                    if(rep1 > 0)
                        {
                            for(int i = 0; i < sequence1; i++)
                                {
                                    Result1.push_back(itr->key_of_node,itr->info_of_node);
                                    ++itr;
                                }
                            rep1--;
                        }
                    if(rep2 > 0)
                        {
                            for(int i = 0; i < sequence2; i++)
                                {
                                    Result2.push_back(itr->key_of_node,itr->info_of_node);
                                    ++itr;
                                }
                            rep2--;
                        }
                }
        }
    else
        {
            while(rep1 + rep2 > 0)
                {
                    if(rep1 > 0)
                        {
                            for(int i = 0; i < sequence1; i++)
                                {
                                    Result1.push_back(itr->key_of_node, itr->info_of_node);
                                    --itr;
                                }
                            rep1--;
                        }
                    if(rep2 > 0)
                        {
                            for(int i = 0; i < sequence2; i++)
                                {
                                    Result2.push_back(itr->key_of_node, itr->info_of_node);
                                    --itr;
                                }
                            rep2--;      
                        }
                }
        }
}
template <typename Key, typename Info>
Ring<Key, Info>::Ring()
{
    head = nullptr;
    size = 0;
} 
template <typename Key, typename Info>
Ring<Key,Info>::~Ring()
{
    remove_all();
}
template <typename Key, typename Info>
Ring<Key,Info>::Ring(const Ring<Key,Info> &x)
{
    head = nullptr;
    size = 0;
    Ring<Key,Info>::ConstIterator itr = x.cbegin();
    for(int i = 0; i < x.size; i++)
        {
            push_back(itr->key_of_node, itr->info_of_node);
            ++itr;
        }
}
template <typename Key, typename Info>
Ring<Key,Info> &Ring<Key,Info>::operator=(const Ring<Key,Info> &x)
{
    if(&x != this)
        {
            Ring<Key,Info>::ConstIterator itr = x.cbegin();
            for(int i = 0; i < x.size; i++)
                {
                    push_back(itr->key_of_node, itr->info_of_node);
                    ++itr;
                }
            return *this;
        }
    else
        {
            return *this;
        }
    
}
template <typename Key, typename Info>
bool Ring<Key,Info>::operator==(const Ring<Key, Info> &x) const
{
    if(size != x.size)
        return false;
    else
    {
        Ring<Key,Info>::ConstIterator itr1 = x.cbegin();
        Ring<Key,Info>::ConstIterator itr2 = this->cbegin();
        for(int i = 0; i < size; i++)
            {
                if(itr1->key_of_node != itr2->key_of_node || itr1->info_of_node != itr2->info_of_node)
                    return false;
                ++itr1;
                ++itr2;
            }
        return true;
    }  
}
template <typename Key, typename Info>
bool Ring<Key,Info>::operator!=(const Ring<Key, Info> &x) const
{
    if(size != x.size)
        return true;
    else
    {
        Ring<Key,Info>::ConstIterator itr1 = x.cbegin();
        Ring<Key,Info>::ConstIterator itr2 = this->cbegin();
        for(int i = 0; i < size; i++)
            {
                if(itr1->key_of_node != itr2->key_of_node || itr1->info_of_node != itr2->info_of_node)
                    return true;
                ++itr1;
                ++itr2;
            }
        return false;
    }  
}
template <typename Key, typename Info>
bool Ring<Key,Info>::push_front(Key add_key, Info add_info)
{
    Node *add = new Node(add_key, add_info);
    if(head == nullptr)
        {
            add->next = add;
            add->prev = add;
            head = add;
            size++;
            return true;
        }
    else 
        {
            add->next = head;
            add->prev = head->prev;
            head->prev->next = add;
            head->prev = add;
            head = add;
            size++;
            return true;
        }
}
template <typename Key, typename Info>
bool Ring<Key,Info>::push_back(Key add_key, Info add_info)
{
    Node *add = new Node(add_key, add_info);
    if(head == nullptr)
        {
            add->next = add;
            add->prev = add;
            head = add;
            size++;
            return true;
        }
    else 
        {
            add->next = head;
            add->prev = head->prev;
            head->prev->next = add;
            head->prev = add;
            size++;
            return true;
        }   
}
template <typename Key, typename Info>
bool Ring<Key,Info>::insert(Key add_key, Info add_info, int occurence)
{
    Node *temp = head;
    Ring<Key,Info>::ConstIterator itr = this->cbegin();
    if(head == nullptr || occurence == 0 )
        return false;
    else if(head != nullptr)
        {
            for(int i = 0; i < size ; i++)
                {
                    if(itr->key_of_node == add_key)
                        occurence--;
                    if(occurence == 0)
                        break;
                    ++itr;
                }
            if(occurence > 0)
                return false;
            temp = &*itr;
            Node *add = new Node(add_key, add_info);
            add->next = temp->next;
            add->prev = temp;
            (temp->next)->prev = add;
            temp->next = add;
            size++;
            return true; 
        }
    else
        {
            return false;
        }
    
}
template <typename Key, typename Info>
bool Ring<Key,Info>::pop_front()
{
    if(head == nullptr)
        return false;
    else if(head->next == head)
        {
            delete head;
            head = nullptr;
            size--;
            return true;
        }
    else if(head->next != head)
        {
            Node *temp = head;
            (head->next)->prev = head->prev;
            (head->prev)->next = head->next;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
    else
        {
            return false;
        }
}
template <typename Key, typename Info>
bool Ring<Key,Info>::pop_back()
{
    if(head == nullptr)
        return false;
    else if(head->next == head)
        {
            delete head;
            head = nullptr;
            size--;
            return true;
        }
    else if(head->next != head)
        {
            Node *temp = head->prev;
            (temp->prev)->next = head;
            head->prev = temp->prev;
            delete temp;
            size--;
            return true;
        }
    else
        {
            return false;
        }
}
template <typename Key, typename Info>
bool Ring<Key,Info>::remove(Key remove_key, int occurence)
{
    Node *temp = head;
    Ring<Key,Info>::ConstIterator itr = this->cbegin();
    if(head == nullptr || occurence == 0 )
        return false;
    else if(head != nullptr && occurence > 0)
        {
            for(int i = 0; i < size ; i++)
                {
                    if(itr->key_of_node == remove_key)
                        occurence--;
                    if(occurence == 0)
                        break;
                    ++itr;
                }
            if(occurence > 0)
                return false;
            temp = &*itr;
            if(head->next == head)
                {
                pop_back();
                return true; 
                }
            else if(head->next != head)
                {
                (temp->next)->prev = temp->prev;
                (temp->prev)->next = temp->next;
                if(head == temp)
                    head = head->next;
                delete temp;
                temp = nullptr;
                size--;
                return true; 
                }
            else
                {
                    return false;
                }
        }
    else
        {
            return false;
        }
    
}
template <typename Key, typename Info>
bool Ring<Key,Info>::remove_all_occurences(Key remove_key)
{
    if(head == nullptr)
        return false;
    int occurances = 0;
    Ring<Key,Info>::ConstIterator itr = this->cbegin();    
    for(int i = 0; i < size; i++)
        {
            if(itr->key_of_node == remove_key)
                {
                occurances++;
                }
            ++itr;
        }
    for(int i = occurances; i > 0 ; i--)
        remove(remove_key, i);
    return true;
}
template <typename Key, typename Info>
bool Ring<Key,Info>::remove_all()
{
    if(head == nullptr)
        return false;
    Ring<Key,Info>::ConstIterator itr = this->cbegin();
    int num_of_nodes = size;
    for(int i = 0; i < num_of_nodes; i++)
        {
            pop_back();
        }
    return true;
}
template <typename Key, typename Info>
bool Ring<Key,Info>::is_empty() const
{
    if(head == nullptr)
        return true;
    else
        return false;
    
}
template <typename Key, typename Info>
void Ring<Key,Info>::print()
{
    
    Ring<Key,Info>::ConstIterator itr = this->cbegin();
    for(int i = 0; i < size; i++)
        {
            cout << itr->key_of_node << " " << itr->info_of_node << endl;
            ++itr;
        }
}
#include "iterator.hpp"

#endif