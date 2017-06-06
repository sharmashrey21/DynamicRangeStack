/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  s276shar@uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter) 2016
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef DYNAMIC_STACK_AS_ARRAY_H
#define DYNAMIC_STACK_AS_ARRAY_H

#ifndef nullptr
#define nullptr 0
#endif

#include <algorithm>
#include "Exception.h"

class Dynamic_range_stack {
	private:
		int entry_count;
		int max_count;
		int min_count;
		int initial_capacity;
		int current_capacity;

		int *stack_array;
		int *maximum_array;
		int *minimum_array;

		// You may wish to include a number of helper functions
		// in order to abstract out some operations


	public:
		Dynamic_range_stack( int = 10 );
		Dynamic_range_stack( Dynamic_range_stack const & );
		~Dynamic_range_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		int maximum() const;
		int minimum() const;

		
		void push( int const & );
		int pop();
		void clear();


	// Friends

	friend std::ostream &operator<<( std::ostream &, Dynamic_range_stack const & );
};

Dynamic_range_stack::Dynamic_range_stack( int n ):
entry_count( 0 ),
min_count( 0 ),
max_count( 0 ),
initial_capacity( std::max( 1, n ) ),
current_capacity( initial_capacity ),
stack_array( new int[current_capacity] ),
maximum_array( new int[current_capacity] ),
minimum_array( new int[current_capacity] ) {
	// empty constructor
}

Dynamic_range_stack::~Dynamic_range_stack() {
	delete[] stack_array;
	delete[] maximum_array;
	delete[] minimum_array;	
}

int Dynamic_range_stack::top() const {
	if(entry_count < 1){
		throw underflow();
	}
	else{
		return stack_array[entry_count-1];
	}
}

int Dynamic_range_stack::maximum() const {
	int temp_max = 0;
	for(int i = 0; i < entry_count; i++){
		while(stack_array[i]>temp_max){
			temp_max = stack_array[i];
		}
	}
	return temp_max;
}

int Dynamic_range_stack::minimum() const {
	int temp_min = stack_array[0];
	for(int i = 0; i < entry_count; i++){
		if(stack_array[i]<temp_min){
			temp_min = stack_array[i];
		}
	}
	return temp_min;
}

int Dynamic_range_stack::size() const {
	return entry_count;
}

bool Dynamic_range_stack::empty() const {
	if(entry_count == 0){
		return true;
	}
	else {
		return false;
	}
 }

int Dynamic_range_stack::capacity() const {
	return current_capacity;
}

void Dynamic_range_stack::push( int const &obj ) {
	if(entry_count == current_capacity){
		current_capacity = 2*initial_capacity;
		int *new_stack_array = new int[current_capacity];
		int *new_maximum_array = new int[current_capacity];
		int *new_minimum_array = new int[current_capacity];

		for(int i=0; i<10; i++){
			for(int j=0; j<current_capacity; j++){
				new_stack_array[i] = stack_array[j];
			}
		new_stack_array[entry_count] = obj;
		}
		delete[] new_stack_array;
		delete[] new_maximum_array;
		delete[] new_minimum_array;
 	}	
	else{
		stack_array[entry_count] = obj;
		entry_count++;
	}
	return;
}

int Dynamic_range_stack::pop() {
	if(empty() == true){
		throw underflow();
	}
	entry_count = entry_count - 1;
	return stack_array[entry_count];
}
void Dynamic_range_stack::clear() {
	int counter = 0;
	for (int i=0; i < entry_count; i++){
		counter++;
		stack_array[i] = 0;
	}
	for (int i=0; i < counter; i++){
		entry_count--;
	}
	if(current_capacity != initial_capacity){
		current_capacity = initial_capacity;

		delete[] stack_array;
		delete[] maximum_array;
		delete[] minimum_array;

		int *stack_array = new int[initial_capacity];
		int *maximum_array = new int[initial_capacity];
		int *minimum_array = new int[initial_capacity];
	}
}

// You can modify this function however you want:  it will not be tested

std::ostream &operator<<( std::ostream &out, Dynamic_range_stack const &stack ) {

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif