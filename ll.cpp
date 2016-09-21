#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <functional>


template <class T> 
class Node
{
    T _val;
    std::shared_ptr<Node<T>> _next;

public:

    Node(T val)
    {
        _val = val;
    }

    T getVal()
    {
        return _val;
    }

    void setVal(T val)
    {
        _val = val;
    }

    std::shared_ptr<Node<T>>& getNext()
    {
        return _next;
    }

    void setNext(std::shared_ptr<Node<T>> next)
    {
        _next = next;
    }
};

template <class T> 
class LinkedList
{
    std::shared_ptr<Node<T>> _head;
    std::shared_ptr<Node<T>> _tail;

public:

    LinkedList() = default;
    LinkedList(T val)
    {
        std::shared_ptr<Node<T>> tmpnode(new Node<T>(val));
        _head = tmpnode;
        _tail = tmpnode;
    }


    bool addNode(T val)
    {
        std::shared_ptr<Node<T>> tmpnode(new Node<T>(val));
        if(_tail)
        {
            _tail->setNext(tmpnode);
            _tail = tmpnode;
        }
        else
        {
            _head = tmpnode;
            _tail = tmpnode;
        }
        return true;
    }

    bool deleteNode(std::shared_ptr<Node<T>>& node)
    {
        if(node)
        {
            auto tmpnext = node->getNext();
            node->setVal(tmpnext->getVal());
            node->setNext(tmpnext->getNext());
            return true;
        }
        return false;
    }

    void removetoCmp(T val,std::function<bool(T,T)> cmp)
    {
        if(_head)
        {
            auto tmp = _head.get();
            auto tmphead = _head;
            while(cmp(val, tmphead->getVal()))
            {
                tmphead = tmphead->getNext();   
            }
            _head = tmphead;
            auto prev = tmphead;
            while(tmphead->getNext())
            {
                prev = tmphead;
                if(cmp(val, tmphead->getVal()))
                {
                    deleteNode(tmphead);
                }
                else
                {
                    tmphead = tmphead->getNext();
                }
                
            }
            if(cmp(val, tmphead->getVal()))
            {
                _tail = prev;
                _tail->getNext().reset();
            }
        }
    }

    void printList()
    {
       
        if(_head)
        {
            auto tmphead = _head;
            while(tmphead)
            {
                std::cout<<tmphead->getVal()<<",";
                tmphead = tmphead->getNext();
            }
            std::cout<<std::endl;
        }

    }


};

int main(int argc, char const *argv[])
{
    LinkedList<int> ll;
    for(int i = 1;i<argc;i++)
    {
        ll.addNode(std::atoi(argv[i]));
    }
    ll.printList();
    ll.removetoCmp(4, [](int x, int a){return(a>=x);});
    ll.printList();
    return 0;
}
