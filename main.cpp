#include <iostream>
#include <cassert>

#include "Array.h"

int main() {
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Array<int> arr;

	arr.PushAt( 4, 1 );
	arr.PushAt( 5, 2 );
	arr.PushAt( 6, 3 );

	arr.PushAt( 1, 1 );
	arr.PushAt( 2, 2 );
	arr.PushAt( 3, 3 );

	arr.PushFront( 3 );
	arr.PushFront( 2 );
	arr.PushFront( 1 );

	arr.PushBack( 1 );
	arr.PushBack( 2 );
	arr.PushBack( 3 );

	arr.PushFront( 3 );
	arr.PushFront( 2 );
	arr.PushFront( 1 );

	arr.PushAt( 0, 1 );
	arr.PushAt( 0, 5 );
	arr.PushAt( 0, 9 );

	arr.PushBack( 1 );
	arr.PushBack( 2 );
	arr.PushBack( 3 );

	arr.PushAt( 0, 16 );
	arr.PushAt( 0, 20 );

	Array<int> arr2;
	arr2.PushBack( 1 );
	arr2.PushBack( 2 );
	arr2.PushBack( 3 );

	arr.Swap( arr2, 1, arr2.Size(), 2 );

	arr2.PushBack( 3 );
	//arr.Swap( arr2, 1, arr2.Size(), 9 );

	for ( int i = 0; i != arr.Size(); ++i ) {
		if ( arr[i] == 0 ) { printf( "-------\n" ); }
		std::cout << arr[i] << std::endl;
	}

	printf( "\n-----\nArray 2: \n-----\n" );
	for ( int i = 0; i != arr2.Size(); ++i ) {
		std::cout << arr2[i] << std::endl;
	}
	printf( "\n" );

	arr2.PopFront();
	assert( *arr2.Data() == 1 );

	arr2.PopBack();
	assert( arr2.Back() == 2 );

	arr2.PopAt( 1 );
	assert( arr2.Front() == 2 );

	arr2.PopAll();
	assert( arr2.Size() == 0 );
	printf( "Erased all elements in array 2\n" );

	arr2.Fill( 5 );
	printf( "\n-----\n" );
	for ( int i = 0; i != arr2.Size(); ++i ) {
		std::cout << arr2[i] << std::endl;
	}


	printf( "\nEND\n" );

	system( "pause" );
	return 0;
}