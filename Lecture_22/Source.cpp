// Vectors

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	/*
	- A Vector is a type of array that allows for the size to be dynamically adjusted after being declared.
	- A vector is not created as a fixed size
	- Vectors are passed by value to functions rather than pass by reference such as arrays are. They can be handled by reference with '&' the same as normal variables
	- need #include<vector> header
	- declared as follows: vector<data_type> name(size optional);
	- elements are called in the same fashion as a standard array: vectorName[i]
	- Vectors are not as memory efficient as arrays but are useful when we are unsure of the exact size of the data that it will need to handle.
	*/
	vector<int> sampleVector; // size = 0
	vector<int> sizedVector(15); // size 15
	vector<int> initialVector(10, 0); // declares and initializes an integer vector with all elements initialized to 0

	cout << "Size of an uninitialized vector: " << sampleVector.size() << endl;
	cout << "Size of an uninitialized vector with an initial declared size: " << sizedVector.size() << endl;
	cout << "Size of an initialized vector with an initial declared size & state: " << initialVector.size() << endl;
	cout << "This vector has all elements initialized to 0, this is the sixth element: " << initialVector[5] << endl;

	// Vector size can be defined at run time based on input or other factors as needed.
	int vecSize;
	cout << "Enter the size of the vector you would like: " << endl;
	cin >> vecSize;
	vector<int> userVector(vecSize,0); // creates a vector with size equal to user requirement and initializes all elements as '0'

	// filling this vector using a basic function.
	vector<int> dataVec(10);
	for (int i = 0; i < dataVec.size(); i++) {
		dataVec[i] = i * i;
	}
	// There is a special case of the for loop meant to go through each element incrementing and storing the element at that index in the temp variable
	for (int temp : dataVec) {
		cout <<"Element: " << temp << " " << endl;
	}
	// appends the data in the brackets to the end of the vector by creating a new index location for the new element.
	dataVec.push_back(30);
	cout << dataVec[10] << " This is the 11th element, the size is now 11: " << dataVec.size() << endl; // this is the 11th element in what used to be a 10 element vector. It is now 11 elements and the last element is '30'
	// the pop_back command is the opposite of the push_back. it removes the last element and shrinks the size of the vector
	dataVec.pop_back(); // removes the last element in the vector
	cout << "The 11th element no longer exists. The size is now back to 10: " << dataVec.size() << endl;

	// Capacity vs size
	// Size is the max number of elements/spaces in the vector in memory. Capacity is how many spaces we have in that vector as it has been scaled by the push_back function to accomodate new values and represents the reserved space
	vector<int> capVector(10);
	capVector[0] = 1;

	cout << "Size: " << capVector.size() << " Capacity: " << capVector.capacity() << endl;
	capVector.push_back(10);
	cout << "Size: " << capVector.size() << " Capacity: " << capVector.capacity() << endl; // due to the pushback the compiler has build an extra capacity of 5 into the reserved space for the vector for future expansion

	capVector = dataVec; // This makes the two vectors exactly the same. Unlike arrays we can redefine the vector in this fashion.


	system("pause");
	return 0;
}