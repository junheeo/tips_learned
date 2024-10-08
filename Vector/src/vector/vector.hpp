#ifndef Vector_Included
#define Vector_Included

#include<cstdlib>  /* for size_t, memory alloc */
#include<iterator> /* for std::random_access_iterator_tag */
#include<cstddef>  /* for ptrdiff_t */

template<typename T>
class Vector {
    T * container;
    size_t vsize, vcapacity;
    /* size_t iter; */

    void set_appropriate_capacity();
    

public:
    /* Constructors */
    Vector();
    Vector(size_t size);
    Vector(size_t  size, const T& val);
    template<size_t N>
    Vector(const T(&arr)[N]);
    Vector& operator=(Vector& vec);
    Vector(Vector<T>&& vec);
    Vector& operator=(Vector&& vec);
    /* Destructor */
    ~Vector();

    T& operator[](size_t i);
    T& operator[](size_t i) const;
    T& at(size_t i);
    /* const T& at(size_t i) const; */
    T& front();
    T& back();
    void sort(size_t lo, size_t hi);
    
    

    const size_t& capacity();
    const size_t& size();
    void print_container();

    struct Iterator {
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(); /* default construct */
        Iterator(const Vector<T>* other_vp); /* construct */
        Iterator(const Vector<T>* other_vp, size_t other_inx); /* construct */
        Iterator(const Iterator & other_iter); /* copy construct */
        Iterator operator=(const Iterator & other_iter); /* copy assign */
        /* destruct - use default : declaring default destructor causes error */

        reference operator*(); /* dereference operator: *Iter */
        reference operator*() const; 
        pointer operator&(); /* address_of operator: &Iter */
        /* const pointer operator&() const; */
        reference operator[](difference_type n); /* dereference n index away from current */
        /* const reference operator[](difference_type n) const; */
        
        /* change inx value of *this iterator, return some iterator */
        Iterator& operator++(); /* prefix ++ on Iterator, return ++'d one */
        Iterator operator++(int); /* postfix ++ on Iterator, return non++'d one */
        Iterator& operator--(); /* prefix -- on Iterator, return --'d one */
        Iterator operator--(int); /* postfix -- on Iterator, return non--'d one*/


        Iterator& operator+=(const difference_type& n); /* shift *this iter, return *this */

        Iterator& operator-=(const difference_type& n); /* shift *this iter, return *this */
        Iterator operator+(const difference_type& n); /* return new shifted iter, *this no change */
        Iterator operator-(const difference_type& n); /* return new shifted iter, *this no change */

        /*---------------*/
        difference_type operator-(const Iterator& j); /* return difference between *this.inx and I2.inx */


        /* compare inx values between Iterators */
        bool operator==(const Iterator& j); /* *this.inx == j.inx */
        bool operator!=(const Iterator& j); /* *this.inx != j.inx */
        bool operator<(const Iterator& j); /* *this.inx < j.inx */
        bool operator>(const Iterator& j); /* *this.inx > j.inx */
        bool operator<=(const Iterator& j); /* *this.inx <= j.inx */
        bool operator>=(const Iterator& j); /* *this.inx >= j.inx */
        
        void turn_invalid();
        bool is_invalid();

    private:
        const Vector<T>* vp;
        size_t inx;
        bool is_valid;
        void try_throw_invalid_iter_error();
    };

    Iterator begin() const;
    Iterator end() const;

    Iterator insert(const Iterator & position_iter, size_t n, const T val);
    void pop_back();
    void push_back(const T& val);

};



template<typename T>
void swap(Vector<T>& v, const size_t i, const size_t j);

template<typename T>
size_t partition(Vector<T>& v, const size_t lo, const size_t pi, const size_t hi);

template<typename T>
void quicksort(Vector<T>& v, const size_t lo, const size_t hi);


/*---------------------------------------------------*/
#include"vector.tpp" 









#endif
