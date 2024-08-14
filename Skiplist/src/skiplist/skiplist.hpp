#ifndef Skiplist_Included
#define Skiplist_Included

#include "vector.hpp"
#include <cstddef> /* size_t */
#include <cstdlib> /* rand() */

template<typename T>
class Skiplist {
private:
    size_t allowedMaxLevel;    /* Inner class is a friend of the class it is defined within */
                                /* Outer::Inner class can access the (private) member variable of Outer */

    bool flipcoin();

public:

    class Node {
    private:
        Vector<Node *> listToNext;
        Skiplist& skiplist;

    public:
        Node(Skiplist& sk);
        Node(Skiplist& sk, size_t __levels);
        Node(Skiplist& sk, size_t __levels, T __key);
        /*
        Node(Node& n);
        Node& operator=(Node& n);
        */
        Node(Node&& n); /* want to use default move constructor */
        /*
        Node& operator=(Node&& n);
        */

        T key;

        /* void updateMaxNumOfLevels(); */
        const size_t levels();
        Node* & operator[](const size_t i);
        void addLevel(const size_t i);
    };
private:
    Node* pHeader;
    Node* pSentinel;

    /*void insertBetween(Node* pFrontNode, Node* pBackNode, Node* pNodeToInsert);
    void insertImpl(Node* pCurrNode, Node* pNodeToInsert, size_t topLevel);*/

    struct node_tuple_t {
        Node* front;
        Node* back;
    };
    
    void positionToInsert(Node* pCurrNode, size_t currLevel, Node* pNodeToInsert, Vector<node_tuple_t> & positionTupleVector);
    void insertToPosition(Node* pNodeToInsert, Vector<node_tuple_t> & positionTupleVector);

    void findPositionOfKeyVal(Node* pCurrNode, size_t currLevel, T keyVal, Vector<node_tuple_t> & positionTupleVector);


public:
    Skiplist();
    /* ~Skiplist(); */

    void print_keys();
    void print_Nodes();

    /* bool isNextNodeSentinel(Node* pCurrNode); */
    void insert(T __key);

    bool found(T keyVal);

    bool remove(T keyVal);
};

/*--------------------------------------------*/




/*--------------------------------------------*/
#include "skiplist.tpp"


#endif
