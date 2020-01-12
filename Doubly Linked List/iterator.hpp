#ifndef ITERATOR_H
#define ITERATOR_H

#include "ring.hpp"

template <typename Key, typename Info>
class Ring<Key,Info>::Iterator
{
    private:
        Node *itr;
    public:
        Iterator()
        {
            itr = nullptr;
        }
        Iterator(Node* temp)
        {
            itr = temp;
        }        
        Iterator(const Iterator &x)
        {
            itr = x.itr;
        }
        Iterator &operator++()
        {
            itr = itr->next;
            return *this;
        }
        Iterator &operator++(int)
        {
            Iterator old = *this;
            itr = itr->next;
            return old;
        }        
        Iterator &operator+=(int x)
        {
            for(int i = 0; i < x; i++)
                itr = itr->next;
            return *this;
        }
        Iterator &operator--()
        {
            itr = itr->prev;
            return *this;
        }
        Iterator &operator--(int)
        {
            Iterator old = *this;
            itr = itr->prev;
            return old;
        }   
        Iterator &operator-=(int x)
        {
            for(int i = 0; i < x; i++)
                itr = itr->prev;
            return *this;
        }
        bool operator==(const Iterator &x) const
        {
            return (itr == x.itr);
        }
        bool operator!=(const Iterator &x) const
        {
            return (itr != x.itr);
        }  
        Node& operator*() const
        {
            return *itr;
        }
        Node* operator->() const
        {
            return itr;
        }
}; 
template <typename Key, typename Info>
class Ring<Key,Info>::ConstIterator
{
    private:
        Node *itr;
    public:
        ConstIterator()
        {
            itr = nullptr;
        }
        ConstIterator(Node* temp)
        {
            itr = temp;
        }
        ConstIterator(const ConstIterator &x)
        {
            itr = x.itr; 
        }
        ConstIterator operator++()
        {
            itr = itr->next;
            return *this;
        }
        ConstIterator operator+=(int x)
        {
            for(int i = 0; i < x; i++)
                itr = itr->next;
            return *this;
        }
        ConstIterator operator--()
        {
            itr = itr->prev;
            return *this;
        }
    
        ConstIterator operator-=(int x)
        {
            for(int i = 0; i < x; i++)
                itr = itr->prev;
            return *this;
        }
        bool operator==(const ConstIterator &x) const
        {
            return (itr == x.itr);
        }
        bool operator!=(const ConstIterator &x) const
        {
            return (itr != x.itr);
        }  
        Node& operator*() const
        {
            return *itr;
        }
        Node* operator->() const
        {
            return itr;
        }
};
#endif