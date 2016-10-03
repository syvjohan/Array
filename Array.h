#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

#include "Defs.h"

template <typename  T>
class Array {
public:
	Array();
	~Array();

	size_t Size() const;
	void Fill( const T & );
	T& At( const int );
	T* Data();
	T* Data() const;
	T& Back();
	T& Front();
	bool Empty();

	void PushBack( const T & );
	void PushFront( const T & );
	void PushAt( const T &, const int );

	void PopAll();
	void PopAt( const int );
	void PopFront();
	void PopBack();

	void Swap( Array<T> &, const int, const int, const int );

	T& operator[]( const int );
	T& operator[]( const int ) const;

private:
	void Insert( const T &, const int, bool );
	void Remove( const int );

	T *data;
	int length;
	int capacity;
};

template <typename  T>
Array<T>::Array() {
	length   = 0;
	capacity = 2;
	data     = DBG_NEW T[ sizeof( T ) * capacity ];
}

template <typename  T>
Array<T>::~Array() {
	if ( data ) {
		delete data;
		data = NULL;

		length   = 0;
		capacity = 0;
	}
}

template <typename  T>
void Array<T>::Insert(  const T &val, const int position, bool overwrite ) {
	if ( length == capacity ) {
		T *tmp   = data;
		capacity *= 2;
		data     = DBG_NEW T[ capacity ];
		memcpy( data, tmp, sizeof(T) * length );

		delete tmp;
		tmp = NULL;
	}
	
	if ( length == position && !overwrite ) {
		data[length++] = val;
	}
	else if (length != position && !overwrite) {
		memmove( data + position +1, data + position, sizeof(T) * (length - position) );
		data[position] = val;
		++length;
	} else {
		//overwrite
		data[position] = val;
	}
}

template <typename T>
void Array<T>::Remove( const int position ) {
	memmove( data + position, data + position +1, sizeof( T ) * ( length - 1 ) );
	--length;
}

template <typename  T>
void Array<T>::Fill( const T &value ) {
	assert( data ); 
	assert( capacity > 0 );
	for ( int i = 0; i != capacity; ++i ) {
		data[i] = value;
	}

	length = capacity;
}

template <typename  T>
size_t Array<T>::Size() const {
	return length;
}

template <typename  T>
T& Array<T>::At( const int index ) {
	assert( index <= length );
	return data[index];
}

template <typename  T>
T* Array<T>::Data() const {
	return data;
}

template <typename  T>
T* Array<T>::Data() {
	return data;
}

template <typename  T>
T& Array<T>::Back() {
	assert( length >= 1 );
	return data[length -1];
}

template <typename  T>
T& Array<T>::Front() {
	assert( length >= 1 );
	return *data;
}

template <typename  T>
bool Array<T>::Empty() {
	return length > 0;
}

template <typename  T>
void Array<T>::PopAll() {
	length = 0;
}

//******
//PopAt
//Start index is 1.
//******
template <typename  T>
void Array<T>::PopAt( const int index) {
	Remove( index -1 );
}

template <typename  T>
void Array<T>::PopBack() {
	assert(length >= 0);
	--length;
}

template <typename  T>
void Array<T>::PopFront() {
	assert( length > 0 );
	Remove( 0 );
}

template <typename  T>
void Array<T>::PushBack( const T &value ) {
	Insert( value, length, false );
}

template <typename  T>
void Array<T>::PushFront( const T &value ) {
	Insert( value, 0, false );
}

//******
//PushAt
//Start index is 1.
//DOES NOT OVERWRITE values in array.
//******
template <typename  T>
void Array<T>::PushAt( const T &value, const int position ) {
	Insert( value, position - 1, false );
}

//******
//Swap
//Start index is 1.
//******
template <typename  T>
void Array<T>::Swap( Array<T> &src, int srcStart, int numberOfElementsToSwap, int desStart ) {
	srcStart -= 1;
	desStart -= 1;

	assert( srcStart >= 0 );
	assert( desStart >= 0 );
	assert( desStart != (length + 1) );
	assert( length > 0 );
	assert( srcStart + numberOfElementsToSwap < length );
	T tmp;
	for ( int i = 0; i != numberOfElementsToSwap; ++i ) {
		tmp = src[srcStart];
		
		src[srcStart] = data[srcStart];
		++srcStart;

		Insert( tmp, desStart + i, true );
	}
}

template <typename  T>
T& Array<T>::operator[] ( const int index ) {
	assert( length > 0 );
	assert( index >= 0 );
	return data[index];
}

template <typename  T>
T& Array<T>::operator[] ( const int index ) const {
	assert( length > 0 );
	assert( index >= 0 );
	return data[index];
}

#endif //!ARRAY_H