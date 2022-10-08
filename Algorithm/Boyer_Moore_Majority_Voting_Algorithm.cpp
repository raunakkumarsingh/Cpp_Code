//Boyer-Moore voting algorithm is used to optimally find the majority element amongst the given elements. 

//This algorithm is based the fact that the majority element appears more than N/2 times and the remaining appears less than N/2.

//Idea of algorithm is to choose an element from the given set and if it is same as the candidate element we increase it's votes. Or else we decrease the votes and if the votes of the candidate element becomes zero, it no longer remains our candidate element hence we select another element as the new candidate element

//Implementing the Bouyer-Moore Voting Algorithm

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> &array)
{
    int candidate,votes;
    candidate=-1,votes=0;
    for(auto &currentElement:array)
    {
        // Changing our candidate element, and assigning vote=1 to it as it is encountered for the first time here
        if(votes==0)
        {
            candidate=currentElement;
            votes=1;
        }
        else
        {
            //Increasing votes if candidate element found in array
            if(currentElement==candidate)
            ++votes;
            //Decreasing votes if candidate element not equal to current element
            else
            --votes;
        }
    }
    //Now we will check for the base constraint that the majority element must occur more than N/2 times
    int occurences=0;
    for(auto &element:array)
        if(element==candidate)
        occurences++;
    if(occurences>array.size()/2)return candidate;
    else return -1;
}

int main()
{
    vector<int>array={2,2,2,2,1,4,3};
    //For taking user input
    /*
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    int value;
    for(int i=0;i<n;i++)
    cin>>value, array.push_back(value);
    */
    int majority_element = majorityElement(array);
    if(majority_element==-1)
    cout<<"No majority element in the given array."<<endl;
    else
    cout<<"Majority Element found by Boyer-Moore Voting Algorithm is: "<<majority_element;
    return 0;
}