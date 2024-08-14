#include <cstddef>
#include <ctime>
#include <iostream>
#include <iterator>

template<typename T>
Vector<T>::Vector() {
    this->vsize = 0;
    set_appropriate_capacity();

    /*deprecated : this->container = (T *)std::malloc((this->vcapacity) * sizeof(T));*/
    this->container = new T[this->vcapacity];
}

template<typename T>
Vector<T>::Vector(size_t size) {
    this->vsize = size;
    set_appropriate_capacity();

    /*deprecated : this->container = (T *)std::malloc((this->vcapacity) * sizeof(T));*/

    this->container = new T[this->vcapacity];
}

template<typename T>
Vector<T>::Vector(size_t  size, const T& val) {
    this->vsize = size;
    set_appropriate_capacity();

    /*deprecated : this->container = (T *)std::malloc((this->vcapacity) * sizeof(T));*/

    this->container = new T[this->vcapacity];
    for(size_t i = 0; i < size; ++i) {
        container[i] = val;
    }
}

template<typename T>
template<std::size_t N>
Vector<T>::Vector(const T(&arr)[N]) {
    /*
    for(T val : arr){
        std::cout<<val;
    }
    std::cout<<std::endl;*/

    this->vsize = N;
    this->set_appropriate_capacity();

    std::cout<<"vsize: "<<this->vsize<<std::endl;
    std::cout<<"vcapacity: "<<this->vcapacity<<std::endl;

    /*
    malloc may return nullpinter when malloc(0).
    malloc will never return a null pointer:
        this->vcapacity >= 25
            due to set_appropriate_capacity()
    */
    this->container = (T *)std::malloc((this->vcapacity) * sizeof(T));
    for(int i=0; i<N; ++i){
        this->container[i] = arr[i];
    }

    print_container();

}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> & vec) {
    vsize = vec.vsize;
    vcapacity = vec.vcapacity;
    container = vec.container;

    container = (T *)std::malloc(vcapacity * sizeof(T));
    for(int i=0; i<vsize; ++i){
        this->container[i] = vec[i];
    }

    return *this;
}

template<typename T>
Vector<T>::Vector(Vector<T> && vec) : vsize(vec.vsize), vcapacity(vec.vcapacity), container(vec.container) {
    vec.vcapacity = nullptr;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> && vec) {
    vsize = vec.vsize;
    vcapacity = vec.vcapacity;
    container = vec.container;

    vec.container = nullptr;
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    this->vsize = 0;
    /*deprecated : std::free(this->container);*/
    delete [] this->container;
    this->vcapacity = 0;
}



/*------------------------------------------*/
template<typename T>
T& Vector<T>::operator[](size_t i) {
    return this->container[i];
}


template<typename T>
T& Vector<T>::operator[](size_t i) const {
    return this->container[i];
}


template<typename T>
T& Vector<T>::at(size_t i) {
    if(i>=this->vsize)
        throw("Vector::at() index out of bounds");
    return this->container[i];
}
/*
template<typename T>
const T& Vector<T>::at(size_t i) const {
    if(i>=this->vsize)
        throw("Vector::at index out of bounds");
    return this->container[i];
}
*/
template<typename T>
T& Vector<T>::front() {
    if(vsize==0)
        throw"front(): empty container";
    return this->container[0];
}

template<typename T>
T& Vector<T>::back() {
    if(vsize==0)
        throw"back(): empty container";
    return this->container[vsize - 1];
}

/* quicksort impl 
 * not stable sort */
template<typename T>
void Vector<T>::sort(size_t lo, size_t hi) {
    /* requires 0<=lo && lo<=hi && hi<=vsize;
     * ensures is_sorted(capacity[lo, hi)); */
    if(!(0<=lo && lo<=hi && hi<=vsize))
        throw("Vector<T>::sort() params out of range");
    std::srand(std::time(0));   /* seeding std::rand() */

    quicksort((*this), lo, hi);
    return;
}




/*--------------------------------------------*/
template<typename T>
const size_t& Vector<T>::size() {
    return this->vsize;
}

template<typename T>
const size_t& Vector<T>::capacity() {
    return this->vcapacity;
}

template<typename T>
void Vector<T>::set_appropriate_capacity() {
    size_t capacity_candidate = 25;

    
    /*
    prevent overflow
    REQUIRES: this->vsize is of type size_t (ensured by def)
              (probably also works when max_size is odd)
    */
    const size_t max_size = -1;   /*signed -1 is unsigned max*/
    if((max_size/2 - 10 < this->vsize) 
                        && (this->vsize <= max_size)){
        this->vcapacity = max_size;
    }

    while((capacity_candidate - 10) < this->vsize) {
        capacity_candidate *= 2;
    }
    this->vcapacity = capacity_candidate;
}

/* CAN THIS BE A NON MEMBER FUNCTION ??? */
template<typename T>
void Vector<T>::print_container() {
    std::cout<<"container: [";
    for(int i=0; i<this->vsize; ++i){
        std::cout<<" "<<this->container[i];
    }
    std::cout<<" ]"<<std::endl;
}




/*-----------------------------------------*/


/* default construct */ 
template<typename T>
Vector<T>::Iterator::Iterator() : vp(nullptr), inx(0), is_valid(true) {}

/* construct */
template<typename T>
Vector<T>::Iterator::Iterator(const Vector<T> * other_vp) : vp(other_vp), inx(0), is_valid(true) {}

/* construct */
template<typename T>
Vector<T>::Iterator::Iterator(const Vector<T> * other_vp, size_t other_inx) : vp(other_vp), inx(other_inx), is_valid(true) {}

/* copy construct */
template<typename T>
Vector<T>::Iterator::Iterator(const Vector<T>::Iterator & other_iter) : vp(other_iter.vp), inx(other_iter.inx), is_valid(true) {} 

/* copy assign */
template<typename T>
Vector<T>::Iterator Vector<T>::Iterator::operator=(const Vector<T>::Iterator & other_iter) {
    vp = other_iter.vp;
    inx = other_iter.inx;
    is_valid = true;
    return *this;} 

/* destruct - use default*/


/* dereference operator: *Iter */
template<typename T>
typename Vector<T>::Iterator::reference 
Vector<T>::Iterator::operator*() {
    return (*vp)[inx];
} 

template<typename T>
typename Vector<T>::Iterator::reference 
Vector<T>::Iterator::operator*() const {
    return (*vp)[inx];
}

/* address_of operator: &Iter */
template<typename T>
typename Vector<T>::Iterator::pointer 
Vector<T>::Iterator::operator&() {
    return *((*vp)[inx]);
} 

/*
template<typename T>
const typename Vector<T>::Iterator::pointer 
Vector<T>::Iterator::operator&() const {
    return *((*vp)[inx]);
}
*/

/* dereference n index away from current */
template<typename T>
typename Vector<T>::Iterator::reference 
Vector<T>::Iterator::operator[](typename Vector<T>::Iterator::difference_type n) {
    return (*vp)[inx + n];
}
        
/*
template<typename T>
const typename Vector<T>::Iterator::reference 
Vector<T>::Iterator::operator[](typename Vector<T>::Iterator::difference_type n) const{
    return (*vp)[inx + n];
}
*/

/* change inx value of *this iterator, return some iterator */
/* prefix ++ on Iterator, return ++'d one */
template<typename T>
typename Vector<T>::Iterator & 
Vector<T>::Iterator::operator++() {
    ++inx;
    return *this;
} 

/* postfix ++ on Iterator, return non++'d one */
template<typename T>
typename Vector<T>::Iterator 
Vector<T>::Iterator::operator++(int) {
    Iterator j(*this);
    ++this->inx;
    return j;
}

/* prefix -- on Iterator, return --'d one */
template<typename T>
typename Vector<T>::Iterator &
Vector<T>::Iterator::operator--() {
    --inx;
    return *this;
}

/* postfix -- on Iterator, return non--'d one*/
template<typename T>
typename Vector<T>::Iterator 
Vector<T>::Iterator::operator--(int) {
    Iterator j(*this);
    --inx;
    return j;
}

/* shift *this iter, return *this */
template<typename T>
typename Vector<T>::Iterator &
Vector<T>::Iterator::operator+=(const typename Vector<T>::Iterator::difference_type& n) {
    inx += n;
    return *this;
} 

/* shift *this iter, return *this */
template<typename T>
typename Vector<T>::Iterator &
Vector<T>::Iterator::operator-=(const typename Vector<T>::Iterator::difference_type& n) {
    inx -= n;
    return *this;
}

/* return new shifted iter, *this no change */
template<typename T>
typename Vector<T>::Iterator 
Vector<T>::Iterator::operator+(const typename Vector<T>::Iterator::difference_type& n) {
    Vector<T>::Iterator j(*this);
    j.inx += n;
    return j;
}

/* return new shifted iter, *this no change */
template<typename T>
typename Vector<T>::Iterator 
Vector<T>::Iterator::operator-(const typename Vector<T>::Iterator::difference_type& n) {
    Vector::Iterator j(*this);
    j.inx -= n;
    return j;
}


/*---------------*/
/* return difference between *this.inx and I2.inx */
template<typename T>
typename Vector<T>::Iterator::difference_type 
Vector<T>::Iterator::operator-(const Vector<T>::Iterator& j) {
    return inx - j.inx;
}


/* compare inx values between Iterators */

/* *this.inx == j.inx */
template<typename T>
bool Vector<T>::Iterator::operator==(const Vector<T>::Iterator& j) {
    return inx == j.inx;
}

/* *this.inx != j.inx */
template<typename T>
bool Vector<T>::Iterator::operator!=(const Vector<T>::Iterator& j) {
    return inx != j.inx;
}

/* *this.inx < j.inx */
template<typename T>
bool Vector<T>::Iterator::operator<(const Vector<T>::Iterator& j) {
    return inx < j.inx;
}

/* *this.inx > j.inx */
template<typename T>
bool Vector<T>::Iterator::operator>(const Vector<T>::Iterator& j) {
    return inx > j.inx;
}

/* *this.inx <= j.inx */
template<typename T>
bool Vector<T>::Iterator::operator<=(const Vector<T>::Iterator& j) {
    return inx <= j.inx;
}

/* *this.inx >= j.inx */
template<typename T>
bool Vector<T>::Iterator::operator>=(const Vector<T>::Iterator& j) {
    return inx >= j.inx;
}

template<typename T>
void Vector<T>::Iterator::turn_invalid() {
    this->is_valid = false;
}

template<typename T>
bool Vector<T>::Iterator::is_invalid() {
    return !(this->is_valid);
}

template<typename T>
void Vector<T>::Iterator::try_throw_invalid_iter_error() {
    if(is_invalid())
        throw "invalidated iterator";
}



/*------------------------------------*/


template<typename T>
Vector<T>::Iterator Vector<T>::begin() const{
    Vector<T>::Iterator i(this, 0);
    return i;
}

template<typename T>
Vector<T>::Iterator Vector<T>::end() const {
    Vector<T>::Iterator i(this, vsize);
    return i;
}

template<typename T>
Vector<T>::Iterator Vector<T>::insert(const Iterator & position_iter, size_t n, const T val) {
    /* position_iter : starting position for insertion; n : number of values to insert; val : value to insert;*/
    /*
    this->try_throw_invalid_iter_error();
    */

    /*std::cout<<"Vector<T>::insert() print container: ";
    print_container();
    std::cout<<"this->container mem addr: "<<this->container<<std::endl;*/

    Vector<T>::Iterator pre_stretch_container_end_iter = Vector::end();
    pre_stretch_container_end_iter-=1;

    const size_t previous_vsize = this->vsize;
    this->vsize+= n;
    const size_t previous_vcapacity = this->vcapacity;
    set_appropriate_capacity();
/*
    if(realloc(container, vcapacity * sizeof(T))==NULL) {
        std::cout<<
        throw("Vector<T>::insert() : realloc failed");
    }
*/
    /*std::cout<<"Vector<T>::insert() print container: ";
    print_container();
    std::cout<<"this->container mem addr: "<<this->container<<std::endl;
    std::cout<<"this->vsize: "<<this->vsize<<std::endl;
    std::cout<<"this->vcapacity: "<<this->vcapacity<<std::endl;*/
    /*deprecated : std::cout<< realloc(this->container, vcapacity * sizeof(T))<< std::endl;*/
    if(this->vcapacity != previous_vcapacity) {
        T * p_new_container = new T [this->vcapacity];
        for(size_t inx=0; inx<previous_vsize; ++inx) {
            p_new_container[inx] = this->container[inx];
        }
        delete [] this->container;
        this->container = p_new_container;
    }
    /* recede values in container */
    size_t insert_at = (this->vsize) - 1;
    Vector<T>::Iterator reverse_end_iter(position_iter);
    reverse_end_iter-=1;
    for(; pre_stretch_container_end_iter!=reverse_end_iter; --pre_stretch_container_end_iter) {
        T val_to_recede = *pre_stretch_container_end_iter;
        /*std::cout<<"val_to_recede: "<<val_to_recede<<std::endl;*/
        (*this)[insert_at] = val_to_recede;
        /*std::cout<<"insert_at: "<<insert_at<<std::endl;*/
        --insert_at;
    }
    /* place values to empty position */
    for(; n!=0; --n) {
        (*this)[insert_at] = val;
    }
  
    /*std::cout<<"Vector<T>::insert() print container: ";
    print_container();*/

    /*
    position_iter.turn_invalid();
    */
    /*
    position_iter.Vector<T>::Iterator::~Iterator();
    */
    
    return position_iter;
}

template<typename T>
void Vector<T>::pop_back() {
    if(vsize==0)
        throw"pop_back(): empty container";
/* WHY NOT WORK? <-- we probably need it in case there are members of T val that need to be freed.*/
    /* (*this).back().(~T()); */
    --vsize;
}

template<typename T>
void Vector<T>::push_back(const T& val) {
    insert((*this).end(), 1, val);
}





/*---------------------------------------*/
/* non-member functions */

template<typename T>
void swap(Vector<T>& v, const size_t i, const size_t j) {
    T temp = v.at(i);
    v.at(i) = v.at(j);
    v.at(j) = temp;
    return;
}

template<typename T>
size_t partition(Vector<T>& v, const size_t lo, const size_t pi, const size_t hi) {
    /* requires: 0<=lo && lo<hi && hi<=vsize;
     * ensures: le_seg(v[\result], v(lo, \result]); 
     * ensures: ge_seg(v[\result], v(\result + 1, hi]; */
    T p = v[pi];

    swap(v, lo, pi);
    
    size_t left = lo+1;
    size_t right = hi;
    while(left < right) {
        /* loop_invariant: lo+1 <= left && left<= right && right<= hi; 
         * loop_invariant: le_seg(p, v[lo+1, left)); 
         * loop_invariant: ge_seg(p, v[right, hi)); */

        if(v[left] <= p) {
            ++left;
        } else {
            /* assert v[left] > v; */
            swap(v, left, right-1); /* v[lo, left) <= p <= v[right, hi) guaranteed */
            --right;                /* therefore swap v[left] and v[right-1] */
        }
    }
    
    /* assert: p < v[left] */
    swap(v, lo, left-1);            /* v[left-1] <= p < v[left]*/
    return left-1;
}

template<typename T>
void quicksort(Vector<T>& v, const size_t lo, const size_t hi) {
    /* requires: 0<=lo && lo<=hi && hi<=vsize; 
     * ensures: is_sorted(v[lo, hi)); */

    if(hi-lo<=1)    /* there is 1 or 0 elements in container hence sorted */
        return;
    /* assert lo < hi; */
    size_t partition_inx = lo + (std::rand() % (hi-lo));
    size_t mid = partition(v, lo, partition_inx, hi);
    quicksort(v, lo, mid);  /* sort v[lo, mid) */
    quicksort(v, mid+1, hi);/* sort v[mid+1, hi) */
    return;
}
