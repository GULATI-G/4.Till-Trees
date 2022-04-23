#include<iostream>
#include<vector>
using namespace std;

// a vector is just like a dynamic array. It's just that vector is inbuilt. It also doubles it size when it ran outs of space 
// just like a array. Except we don't have to tell its size
// we have to also mention its data type as it is made using template
// Although vector is stored on heap memory but it will go out of scope when the function returns.
// General information:- all dynamically allocated objects are stored in heap memory.


// v.capacity() will tell the memory currently allocated to vector
// v.max_size() will tell the number of elements vector can hold. That is limit to which vector can extend its size
// v.size() will tell the number of elements in the vector.
// sizeof(v) function 


int main()
{
    vector <int> v;

    // to create it dynamically
    // vector<int> *p = new vector<int>();
    // but remember to delete it yourselves 

    // To insert an element
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);


    // to access an element
    cout<<v[0]<<endl<<endl;

    // we can change element at index i by:-
    v[1]=50;
    
    // but inserting should not be done in same manner i.e v[i]=...
    // as first of all it will not increase size of the vector  and second
    // If we insert element via pushback after inserting via v[i]=... then the vector will insert the element in place of the element
    // that we have inserted using v[i]... as for the vector the index to be filled is i only not i+1;


    v[4]=60; // in this we are accessing memory that doesn't belong to us but it will still store the element. But it is still wrong
    cout<<v.size()<<endl<<endl;

    for(int i=0;i<5;i++)
    {cout<<v[i]<<endl;}

    cout<<endl<<v.size()<<endl<<endl; // see the size is still 4 not 5

    v.push_back(50);
    for(int i=0;i<5;i++)
    {cout<<v[i]<<endl;}

    // We can also access elements using 
    cout<<endl<<v.at(2)<<endl<<endl;
    // This is safer to use instead of v[i] as v[i] will read a element of index i even if i>= size of vector.
    // But v.at() will report an error out of range if we try to read v[i] in which i>= size of vector.
    // eg.

    // cout<<v.at(5)<<endl;

    // in below case both v.at() and v[i] will give same result
    for(int i=0;i<v.size();i++)
    {cout<<v.at(i)<<endl;}
    cout<<endl;

    // to delete last element:-
    v.pop_back();
    for(int i=0;i<v.size();i++)
    {cout<<v.at(i)<<endl;}

    cout<<endl<<endl;

    // to run below code you might have to comment the rest of above code
    vector <int> a;
    // let's see how the size of vector changes as we add elements
    for(int i=0;i<50;i++)
    {
        cout<<a.capacity()<<endl;
        a.push_back(i);
    }

    return 0;
}