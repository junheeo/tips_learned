#include "vector.hpp"
#include <cstdlib> /* rand() srand() */
#include <cstddef> /* size_t */
#include <ctime> /* time() */
#include <stdexcept>

template<typename T>
Skiplist<T>::Node::Node(Skiplist<T>& sk) : skiplist(sk) {
    this->listToNext = Vector<typename Skiplist<T>::Node*>(1, nullptr);
    /*  this->skiplist = sk; */
    /* no val initialized */
}

template<typename T>
Skiplist<T>::Node::Node(Skiplist<T>& sk, size_t __levels) : skiplist(sk) {
    this->listToNext = Vector<Skiplist<T>::Node*>(__levels, nullptr);
    /* this->skiplist = sk; */
    /* no val initialized */
    if(skiplist.allowedMaxLevel < __levels){
        skiplist.allowedMaxLevel = __levels + 1;
    }   
}


template<typename T>
Skiplist<T>::Node::Node(Skiplist<T>& sk, size_t __levels, T __key) : skiplist(sk) {
    std::cout<<"Node(Skiplist<T>, size_T, T): enter"<<std::endl;
    this->listToNext = Vector<Skiplist<T>::Node*>(__levels, nullptr);
    std::cout<<"Node(Skiplist<T>, size_T, T): create listToNext for Node success"<<std::endl;
    /* this->skiplist = sk; */
    if((this->skiplist).allowedMaxLevel < __levels){
        (this->skiplist).allowedMaxLevel = __levels + 1;
    }
    this->key = __key;
}

/*
template<typename T>
Skiplist<T>::Node::Node(Skiplist<T>::Node& n) : listToNext(n.listToNext), key(n.key) {
    if(maxNumOfLevels <= n.levels()){
        maxNumOfLevels = n.levels() + 1;
    }      
}

template<typename T>
Skiplist<T>::Node Skiplist<T>::Node::operator=(Skiplist<T>::Node& n) {
    listToNext = n.listToNext;
    if(maxNumOfLevels <= n.levels()){
        maxNumOfLevels = n.levels() + 1;
    }
    key = n.key;
}
*/

/* want to use default move constructor */
template<typename T>
Skiplist<T>::Node::Node(Skiplist<T>::Node&& n) : listToNext(n.listToNext), key(n.key) {
    if(skiplist.allowedMaxLevel <= n.levels()){
        skiplist.allowedMaxLevel = n.levels() + 1;
    }      
}

/*
template<typename T>
Skiplist<T>::Node Skiplist<T>::Node::operator=(Skiplist<T>::Node&& n) {
    listToNext = n.listToNext;
    if(maxNumOfLevels <= n.levels()){
        maxNumOfLevels = n.levels() + 1;
    }
    key = n.key;
}
*/




/*---------------------------------*/


template<typename T>
const size_t Skiplist<T>::Node::levels() {
    return listToNext.size();
}

template<typename T>
Skiplist<T>::Node * & Skiplist<T>::Node::operator[](const size_t i) {
    return listToNext.at(i);    /* listToNext : Vector<Node*> */
}

template<typename T>
void Skiplist<T>::Node::addLevel(const size_t i) {
    listToNext.push_back(nullptr);
    size_t thisNodeLevels = this->levels();
    if(thisNodeLevels > this->skiplist.allowedMaxLevel) {
        this->skiplist.allowedMaxLevel = thisNodeLevels + 1;
    }
    return;
}

/*--------------------------------*/
template<typename T>
bool Skiplist<T>::flipcoin() {
    return bool (std::rand() % 2);
}
/*--------------------------------*/

template<typename T>
Skiplist<T>::Skiplist() {
    std::cout<<"entered Skiplist constructor"<<std::endl;
    using Node = typename Skiplist<T>::Node;
    /*typename Skiplist<T>::Node sentinel_Obj = typename Skiplist<T>::Node::Node(*this, 4);*/

    this->pSentinel = new Node(*this, 4);
    /*(typename Skiplist<T>::Node *) this->pSentinel = new Node(*this, 4);*/   /* Skiplist<T>::Node* sentinel  */
    std::cout<<"Skiplist: success creating pSentinel"<<std::endl;

    /*typename Skiplist<T>::Node header_Obj = typename Skiplist<T>::Node::Node(*this, 4);*/
    this->pHeader = new Node(*this, 4);
    /*(typename Skiplist<T>::Node *) this->pHeader = new Node(*this, 4);*/     /* Skiplist<T>::Node* header  */
    std::cout<<"Skiplist: success creating pHeader"<<std::endl;

    
    std::cout<<"Skiplist: pHeader()->levels() == "<<pHeader->levels()<<std::endl;
    int inx = this->pHeader->levels() - 1;
    for(; inx>=0; --inx) {
        (*pHeader)[inx] = pSentinel; /* typeof Node * */
    }

    this->allowedMaxLevel = 5;


    std::srand(std::time(0));   /* seeding std::rand() */
    std::cout<<"Skiplist: success constructing"<<std::endl;
}

/*
template<typename T>
Skiplist<T>::~Skiplist() {
    
}
*/

template<typename T>
void Skiplist<T>::print_keys() {
    Skiplist<T>::Node * pNextNode = (*pHeader)[0];
    while(pNextNode != pSentinel) {
        std::cout<<(pNextNode->key)<<" ";
        pNextNode = (*pNextNode)[0];
    }
    std::cout<<std::endl;
}

template<typename T>
void Skiplist<T>::print_Nodes() {
    std::cout<<"Header: "<<pHeader->levels()<<" | "<<pHeader<<std::endl;
    for(int i=0; i<pHeader->levels(); ++i) {
        std::cout<<(*pHeader)[i]<<" ";
    }
        std::cout<<std::endl;
    Skiplist<T>::Node * pNextNode = (*pHeader)[0];
    while(pNextNode != pSentinel) {
        std::cout<<pNextNode->key<<" | "<<pNextNode->levels()<<" | "<<pNextNode<<std::endl;
        for(int i=0; i<pNextNode->levels(); ++i) {
            std::cout<<(*pNextNode)[i]<<" ";
        }
        std::cout<<std::endl;
        pNextNode = (*pNextNode)[0];
    }
    std::cout<<"Sentinel: "<<pSentinel->levels()<<" | "<<pSentinel<<std::endl;
    for(int i=0; i<pSentinel->levels(); ++i) {
        std::cout<<(*pSentinel)[i]<<" ";
    }
    std::cout<<std::endl;
}


template<typename T>
void Skiplist<T>::insertToPosition(Skiplist<T>::Node* pNodeToInsert, Vector<Skiplist<T>::node_tuple_t> & positionTupleVector) {
    for(size_t level = 0; level < pNodeToInsert->levels(); ++level) {
        Skiplist<T>::Node* pFront = (positionTupleVector[level]).front;
        Skiplist<T>::Node* pBack = (positionTupleVector[level]).back;
        (*pNodeToInsert)[level] = pBack;
        (*pFront)[level] = pNodeToInsert;
    }
}


template<typename T>
void Skiplist<T>::positionToInsert(Skiplist<T>::Node* pCurrNode, size_t currLevel, Skiplist<T>::Node* pNodeToInsert, Vector<Skiplist<T>::node_tuple_t> & positionTupleVector) {
    if(pCurrNode == pHeader || pCurrNode->key <= pNodeToInsert->key) {
        Skiplist<T>::Node* pNextNode = (*pCurrNode)[currLevel];
        if(pNextNode == pSentinel || pNodeToInsert->key < pNextNode->key) {
            positionTupleVector[currLevel] = {pCurrNode, pNextNode};
            if(currLevel == 0) {
                return;
            } else {
                Skiplist<T>::positionToInsert(pCurrNode, currLevel - 1, pNodeToInsert, positionTupleVector);
                return;
            }
        } else if(pNextNode->key <= pNodeToInsert->key) {
            Skiplist<T>::positionToInsert(pNextNode, currLevel, pNodeToInsert, positionTupleVector);
            return;
        } else {
            throw std::runtime_error("2");
        }
    } else {
        throw std::runtime_error("1");
    }
}


template<typename T>
void Skiplist<T>::insert(T __key) {
    /* REQUIRES: pHeader->levels() == allowedMaxLevel - 1; 
     *           pSentinel->levels() == allowedMaxLevel - 1; */

    /*std::cout<<"enter Skiplist<T>::insert()"<<std::endl;
    std::cout<<"allowedMaxLevel"<<allowedMaxLevel<<std::endl;*/


    size_t thisNodeLevels = 1;
    bool doContinue = true;
    while(doContinue) {
        /*std::cout<<"continuing to flip coins"<<std::endl;*/
        if(flipcoin()){
            ++thisNodeLevels;
        } else {
            doContinue = false;
        }
        if(thisNodeLevels == allowedMaxLevel) {
            ++allowedMaxLevel;
            doContinue = false;
        }
    }

    /*
    size_t thisNodeLevels = 5;
    allowedMaxLevel = 6;
    */
    
    /*std::cout<<"thisNodeLevels "<<thisNodeLevels<<std::endl;
    std::cout<<"insert(T): try Node() constructor"<<std::endl;*/
    Skiplist<T>::Node * pNode = new typename Skiplist<T>::Node::Node(*this, thisNodeLevels, __key);
    /*std::cout<<"insert(T): success creating new node to insert"<<std::endl;
    std::cout<<"node to insert info: "<<std::endl;
    std::cout<<"*   pNode->levels(): "<<pNode->levels()<<std::endl;
    std::cout<<"*   pHeader->levels(): "<<pHeader->levels()<<std::endl;*/

    /* finished creating the node to be inserted */
    
    const size_t targetHeaderMaxLevel = allowedMaxLevel;
    /*std::cout<<"targetHeaderMaxLevel "<<targetHeaderMaxLevel<<std::endl;*/

    /* pHeader->levels() == pSentinel->levels() by REQ */
    while(pHeader->levels() < targetHeaderMaxLevel-1) {
        /* loop_invariant pHeader->skiplist.allowedMaxLevel (constant) */
        std::cout<<"while(pHeader->levels() < targetHeaderMaxLevel)"<<std::endl;
        pHeader->addLevel(1);
        std::cout<<"*  pHeader->levels() "<<pHeader->levels()<<std::endl;
        std::cout<<"*  targetHeaderMaxLevel "<<targetHeaderMaxLevel<<std::endl;
        (*pHeader)[pHeader->levels() - 1] = pSentinel;
        pSentinel->addLevel(1);
        /* default values in listToNext by addLevel(): nullptr */
    }
    /* pHeader->levels() == targetHeaderMaxLevel */

    /*std::cout<<"exit while loop"<<std::endl;

    std::cout<<"allowedMaxLevel "<<allowedMaxLevel<<std::endl;
    std::cout<<"call: insertImpl(pHeader, pNode, allowedMaxLevel - 2)"<<std::endl;*/
    
    Vector<Skiplist<T>::node_tuple_t> positionTupleVector(allowedMaxLevel - 1);


    positionToInsert(pHeader, allowedMaxLevel - 2, pNode, positionTupleVector);
    insertToPosition(pNode, positionTupleVector);

    return;
}


template<typename T>
void Skiplist<T>::findPositionOfKeyVal(Skiplist<T>::Node* pCurrNode, size_t currLevel, T keyVal, Vector<Skiplist<T>::node_tuple_t> & positionTupleVector) {
    /*std::cout<<"*"<<std::endl;*/
    Node* pNextNode = (*pCurrNode)[currLevel];
    /*if(pCurrNode==pHeader){
        std::cout<<"pCurrNode Header"<<std::endl;
    } else {
        std::cout<<"pCurrNode->key "<<pCurrNode->key<<std::endl;
    }
    if(pNextNode==pSentinel){
        std::cout<<"pNextNode Sentinel"<<std::endl;
    } else {
        std::cout<<"pNextNode->key "<<pNextNode->key<<std::endl;
    }
    std::cout<<"keyVal "<<keyVal<<std::endl;
    std::cout<<"currLevel "<<currLevel<<std::endl;*/
    if(currLevel == 0) {
        if((pCurrNode == pHeader && pNextNode == pSentinel) ||
           (pCurrNode == pHeader && keyVal < pNextNode->key) ||
           (pCurrNode->key < keyVal && pNextNode == pSentinel) ||
           (pCurrNode->key < keyVal && keyVal < pNextNode->key)) {
            /*std::cout<<"    1"<<std::endl;*/
            throw std::runtime_error("1");
        } else if(keyVal == pNextNode->key) {
            /*std::cout<<"    2"<<std::endl;*/
            positionTupleVector[currLevel] = {pCurrNode, pNextNode};
            return;
        } else if(keyVal > pNextNode->key) {
            /*std::cout<<"    3"<<std::endl;*/
            findPositionOfKeyVal(pNextNode, currLevel, keyVal, positionTupleVector);
            return;
        } else {
            /*std::cout<<"    4"<<std::endl;*/
            throw std::runtime_error("2");
        }
    } else {
        if(pNextNode == pSentinel || keyVal <= pNextNode->key) {
            /*std::cout<<"    5"<<std::endl;*/
            positionTupleVector[currLevel] = {pCurrNode, pNextNode};
            findPositionOfKeyVal(pCurrNode, currLevel - 1, keyVal, positionTupleVector);
            return;
        } else {
        /* pNextNode->key < keyVal */
            /*std::cout<<"    6"<<std::endl;*/
            findPositionOfKeyVal(pNextNode, currLevel, keyVal, positionTupleVector);
            return;
        }
    }
}


template<typename T>
bool Skiplist<T>::found(T keyVal) {
    Vector<Skiplist<T>::node_tuple_t> positionTupleVector(allowedMaxLevel - 1);
    try{
        findPositionOfKeyVal(pHeader, allowedMaxLevel - 2, keyVal, positionTupleVector);
    } catch (std::runtime_error const & e) {
        std::cout<<keyVal<<" : not found"<<std::endl;
        return false;
    }
    std::cout<<keyVal<<" : found"<<std::endl;
    return true;
}


template<typename T>
bool Skiplist<T>::remove(T keyVal) {
    Vector<Skiplist<T>::node_tuple_t> positionTupleVector(allowedMaxLevel - 1);
    try{
        findPositionOfKeyVal(pHeader, allowedMaxLevel - 2, keyVal, positionTupleVector);
    } catch (std::runtime_error const & e) {
        std::cout<<keyVal<<" : not found"<<std::endl;
        return false;
    }
    std::cout<<keyVal<<" : found"<<std::endl;

    Skiplist<T>::Node* pNodeToRemove = (positionTupleVector[0]).back;
    for(size_t level = 0; level < pNodeToRemove->levels(); ++level) {
        Skiplist<T>::Node* pFrontOfDeleteNode = (positionTupleVector[level]).front;
        Skiplist<T>::Node* pDeleteNode = (positionTupleVector[level]).back;
        Skiplist<T>::Node* pBackOfDeleteNode = (*pDeleteNode)[level];
        (*pFrontOfDeleteNode)[level] = pBackOfDeleteNode;
    }
    return true;
}


/*------------------------------------------*/

