#include <utility>

template <typename T>
void swap(T& one, T& two) {
    T temp = std::move(one);
    one = std::move(two);
    two = std::move(temp);
}

// must be a forward iterator
template <class Iterator, class T>
constexpr Iterator lower_bound(Iterator begin, Iterator end, const T& val);

// must be a forward iterator
template <class Iterator, class T>
constexpr Iterator uppper_bound(Iterator begin, Iterator end, const T& val);



template <class Iterator>
void insertion_sort(Iterator begin, Iterator end);

template <class Iterator>
void sort(Iterator begin, Iterator end);

template <class Iterator, class Compare>
void insertion_sort(Iterator begin, Iterator end, Compare comp);


template <class Iterator, class Compare>
void sort(Iterator begin, Iterator end, Compare comp);
