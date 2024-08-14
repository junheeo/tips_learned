#include<iostream>
#include"vector.hpp"

int main() {
    std::cout<<"main() is called"<<std::endl;
    int x[5] = {5,4,3,2,1};
    Vector<int> v1(x);

    std::cout<<"v1[2] = "<<v1[2]<<std::endl;
    v1[2] = 6;
    v1.print_container();
    std::cout<<"v1[2] = "<<v1.at(2)<<std::endl;
    v1.at(2) = 3;
    v1.print_container();

    try {
        v1.at(5);
    } 
    catch(...) {
        std::cout<<"raised error as expected"<<std::endl;
    }

    Vector<int> v2(41);
    std::cout<<"v2 set size 41 > 50-10"<<std::endl;
    std::cout<<"therefore v2 capacity must be 50*2"<<std::endl;
    std::cout<<"v2.capacity(): "<<v2.capacity()<<std::endl;

    std::cout<<"print v1 with iterator: ";

    auto __end=v1.end();
    for(auto __loop = v1.begin(); __loop!=__end; ++__loop) {
        std::cout<<*__loop;
    }
    std::cout<<std::endl;

    for(auto x : v1){
        std::cout<<x;
    }
    std::cout<<std::endl;

    std::cout<<std::endl<<std::endl;
    std::cout<<"insert a single 6 at v1[0]"<<std::endl;
    v1.insert(v1.begin(), 1, 6);

    std::cout<<std::endl<<std::endl;
    std::cout<<"insert a double 6 starting from v1[0]"<<std::endl;
    v1.insert(v1.begin(), 2, 6);

    std::cout<<std::endl<<std::endl;
    std::cout<<"insert a single 7 at v1[2]"<<std::endl;
    v1.insert(v1.begin()+=2, 1, 7);

    std::cout<<std::endl<<std::endl;
    std::cout<<"insert a single 0 at the end of v1"<<std::endl;
    v1.insert(v1.end(), 1, 0);

    std::cout<<std::endl<<std::endl;
    auto end_iter_insert(v1.end());
    v1.insert(end_iter_insert, 1, -1);

    /* This DOES work - doesn't work in std::vector<T> */
/*    std::cout<<std::endl<<std::endl;
    v1.insert(end_iter_insert, 1, -2); */


    std::cout<<std::endl<<std::endl;
    v1.pop_back();
    std::cout<<"pop_back(): ";
    v1.print_container();

    std::cout<<std::endl<<std::endl;
    v1.push_back(-1);
    std::cout<<"push_back(-1): ";
    v1.print_container();

    std::cout<<std::endl<<std::endl;
    v1.push_back(-2);
    std::cout<<"push_back(-2): ";
    v1.print_container();

    std::cout<<std::endl<<std::endl;
    v1.push_back(-3);
    v1.push_back(-4);
    v1.push_back(-5);
    v1.push_back(-6);
    v1.push_back(-7);
    v1.push_back(-8);
    v1.push_back(-9);
    v1.push_back(-10);
    v1.push_back(-11);
    v1.push_back(-12);
    v1.push_back(-13);
    v1.push_back(-14);
    v1.push_back(-15);
    v1.push_back(-16);
    v1.push_back(-17);
    v1.push_back(-18);
    v1.push_back(-19);
    v1.push_back(-20);
    v1.push_back(-21);
    v1.push_back(-22);
    v1.push_back(-23);
    v1.push_back(-24);
    v1.push_back(-25);
    v1.print_container();

   

    std::cout<<std::endl<<std::endl;
    char x2[] = {'t','e','s','t'};
    Vector<char> v3(x2);

    v3.push_back('i');
    v3.push_back('n');
    v3.push_back('g');
    v3.print_container();

    v3.pop_back();
    v3.print_container();
    v3.pop_back();
    v3.print_container();
    v3.back() = 's';
    v3.print_container();
    v3.pop_back();
    v3.at(0) = 'r';
    v3.print_container();

    std::cout<<std::endl<<std::endl;
    int x4[] = {4,5,3,6,2,7,9,2,1};
    Vector<int> v4(x4);
    v4.print_container();
    std::cout<<"call v4.sort(0, 9)"<<std::endl;
    v4.sort(0, v4.size());
    v4.print_container();

    Vector<int> v5(x4);
    v5.print_container();
    std::cout<<"call v5.sort(3, 8)"<<std::endl;
    v5.sort(3, 8);
    v5.print_container();
    std::cout<<"the correct result is: "<<std::endl;
    std::cout<<"           [ 4 5 3 2 2 6 7 9 1 ]"<<std::endl;

    std::cout<<std::endl<<std::endl;
    std::cout<<"expect: [ c c c c c ]"<<std::endl;
    Vector<char> v6(5, 'c');
    v6.print_container();

    std::cout<<std::endl<<std::endl;
    std::cout<<"expect: [ 7 7 7 ]"<<std::endl;
    Vector<int> v7 = Vector<int>(3, 7);
    v7.print_container();

    std::cout<<std::endl<<std::endl;
    std::cout<<"expect: [ 7 7 7 ]"<<std::endl;
    Vector<int> v8;
    Vector<int> v8prime = Vector<int>(3, 7);
    v8 = v8prime;
    v8.print_container();

    std::cout<<std::endl<<std::endl;
    struct tuple_t {
        int l;
        int r;
    };
    Vector<tuple_t> v9;
    v9.push_back({1,1});
    v9.push_back({2,2});
    std::cout<<v9[0].l<<" "<<v9[0].r<<std::endl;
    std::cout<<v9[1].l<<" "<<v9[1].r<<std::endl;



    return 0;
}
