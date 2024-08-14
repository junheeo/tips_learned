#include <iostream>
#include "vector.hpp"
#include "skiplist.hpp"


int main() {
    /*
    std::cout<<"Test_Skiplist main() called"<<std::endl;
    int a[] = {3,2,4,1};
    Vector<int> v(a);
    v.print_container();
    */

    /*
    class A {
    
    public:
        class B{
            
        public:
            int val;
            B::B() : val(3) {};
        };
        Vector<B> vec;
        A::A() {

        }
    };
    */

    std::cout<<std::endl<<std::endl<<"testing skiplist"<<std::endl;
    Skiplist<int> sk1;
    std::cout<<"***success: testing skiplist"<<std::endl;

    /*
    std::cout<<std::endl<<"testing node creation"<<std::endl;
    std::cout<<"try creating Skiplist<int> testNodeCreation"<<std::endl;
    Skiplist<int> testNodeCreation;
    std::cout<<"created Skiplist<int>"<<std::endl;

    Skiplist<int>::Node * aNodeCreated = new typename Skiplist<int>::Node::Node(testNodeCreation);
    std::cout<<"created aNodeCreated"<<std::endl;
    std::cout<<"***success: testing node creation"<<std::endl<<std::endl;
    */
    
    std::cout<<std::endl<<std::endl;
    std::cout<<std::endl<<"enter sk1.insert(1)"<<std::endl;
    sk1.insert(1);
    
    sk1.print_keys();
    sk1.print_Nodes();
    std::cout<<std::endl;

    
    sk1.insert(4);
    sk1.print_keys();
    sk1.print_Nodes();
    std::cout<<std::endl;
    
    sk1.insert(5);
    sk1.print_keys();
    sk1.print_Nodes();


    sk1.insert(2);
    sk1.print_keys();
    sk1.print_Nodes();

    sk1.found(1);
    std::cout<<std::endl;
    sk1.found(2);
    std::cout<<std::endl;
    sk1.found(4);
    std::cout<<std::endl;
    sk1.found(5);
    std::cout<<std::endl;
    
    sk1.found(0);
    std::cout<<std::endl;
    sk1.found(3);
    std::cout<<std::endl;
    sk1.found(6);
    std::cout<<std::endl;

    std::cout<<std::endl<<std::endl;
    sk1.remove(4);
    sk1.print_keys();
    sk1.print_Nodes();

    std::cout<<std::endl<<std::endl;
    sk1.remove(1);
    sk1.print_keys();
    sk1.print_Nodes();

    std::cout<<std::endl<<std::endl;
    sk1.remove(5);
    sk1.print_keys();
    sk1.print_Nodes();

    std::cout<<std::endl<<std::endl;
    sk1.found(2);

    std::cout<<std::endl<<std::endl;
    sk1.found(0);

    std::cout<<std::endl<<std::endl;
    sk1.found(3);

    std::cout<<std::endl;
    sk1.insert(1);
    sk1.print_keys();
    sk1.print_Nodes();

    std::cout<<std::endl;
    sk1.insert(3);
    sk1.print_keys();
    sk1.print_Nodes();

    return 1;
}
