// C++ STL tutorial

#include <utility> // utility class contains pair data type
#include <bits/stdc++.h> // This include all the classes like iostream, math.h, string, vector, list etc.
using namespace std;

// pairs
void explainPairs()
{
    pair<int, int> p = {4, 5};
    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> p1 = {4, {5, 6}}; // used to store three values => nested pair
    cout << p1.first << " " << p1.second.first << " " << p1.second.second;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}}; // This is an array of data type pair
    cout << arr[1].second; // output => 4
}


// vectors
void explainVectors()
{
    vector<int> v;

    v.push_back(4);
    v.emplace_back(5);

    v.size(); // size of the vector

    vector<pair<int, int>> v1; // vector of pair data type
    v1.push_back({4, 5});
    v1.emplace_back(4, 5); // emplace_back() has a little different syntax in case of pair and also this is a little faster than push_back()

    vector<int> v2(5, 100); // output => {100, 100, 100, 100, 100}
    v2.push_back(6); // output => {100, 100, 100, 100, 100, 6}

    /* acesssing the elements of a vector */
    vector<int> v3 {4, 5, 6, 7, 8, 9}; // v3 = {4, 5, 6, 7, 8, 9}

    cout<<v3[1]; // output => 5
    // cout<<v3.at(1);

    // iterator to acess the elements
    vector<int>::iterator it = v3.begin(); // it points to 4
    cout<<*it; // output => 4
    it++;
    cout<<*it; // output => 5

    vector<int>::iterator it1 = v3.end(); // it points after 9
    it1--; // now it will point to 9
    cout<<*it1; // output => 9

    /* printing the elements of a vector */
    for(int i = 0; i < v3.size(); i++){
        cout<<v[i]<<endl;
    }

    // using an iterator of type vector<int> to print the elements
    for(vector<int>::iterator it = v3.begin(); it < v3.end(); it++){
        cout<<*(it)<<endl;
    }

    // using auto to automatically assign the suitable data type to it
    for(auto it = v3.begin(); it < v3.end(); it++){
        cout<<*(it)<<endl;
    }

    // using for each loop
    for(auto it : v3){
        cout<<it<<endl;
    }

    /* erasing an element from the vector */
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vec.erase(vec.begin()); // output => {2, 3, 4, 5, 6, 7, 8, 9, 10}
    vec.erase(vec.begin() + 1); // output => {1, 3, 4, 5, 6, 7, 8, 9, 10}
    vec.erase(vec.begin() + 2, vec.begin() + 4); // output => {1, 2, 5, 6, 7, 8, 9, 10}

    /* inserting an element in the vector */
    vector<int> vec2{4, 5, 6, 7, 8, 9};

    vec2.insert(vec2.begin(), 10); // output => {10, 4, 5, 6, 7, 8, 9}
    vec2.insert(vec2.begin() + 2, 2, 86); // output => {10, 4, 86, 86, 5, 6, 7, 8, 9}

    /* pop_back() */
    vector<int> vec3{1, 4, 6, 8, 9};
    vec3.pop_back(); // output => {1, 4, 6, 8}

    /* swapping two vectors */
    // v1 = {4, 5}
    // v2 = {6, 7}
    // v1.swap(v2); // v1 = {6, 7} and v2 = {4, 5}

    v.clear(); // it clears all the elements of the vector

    v.empty(); // returns true if empty else returns false 
}

// lists
void explainList()
{
    list<int> l; // list<int> l is a doubly linked list where we can perform insertion and deletion from both sides


    l.push_back(4);
    l.emplace_back(5);
    l.push_front(6);
    l.emplace_front(7);
    l.pop_back();
    l.pop_front();

    // rest functions are same as vector
    // begin(), end(), size(), clear(), insert(), swap()
}

// dequeues
void explainDequeue()
{
    deque<int> dq; // dequeue<int> dq is a doubly ended queue

    dq.push_back(4);
    dq.emplace_back(5);
    dq.push_front(6);
    dq.emplace_front(7);
    dq.pop_back();
    dq.pop_front();

    // rest functions are same as vector
    // begin(), end(), size(), clear(), insert(), swap()
}


// stacks
void explainStack()
{
    stack<int> s; // stack follows lifo principle

    s.push(4); // {4}
    s.emplace(5); // {5, 4}
    s.emplace(6); // {6, 5, 4}
    s.emplace(7); // {7, 6, 5, 4}
    s.pop(); //{6, 5, 4}

    s.top(); // output => 6
    s.size(); // output => 3

    s.empty(); // output => false

    stack<int> s1, s2;
    s1.swap(s2);
}

void explainQueue()
{
    queue<int> q; // queue follows fifo principle

    q.push(4); // {4}
    q.emplace(5); // {4, 5}
    q.emplace(6); // {4, 5, 6}
    q.emplace(7); // {4, 5, 6, 7}

    cout<<q.back(); // output => 7

    q.back() += 5;
    cout<<q.back(); // {4, 5, 6, 12}

    q.pop(); //{5, 6, 12}
    q.pop(); //{6, 12}

    q.front(); // output => 6

    // rest functions are same as vector
    // size(), swap(), empty()
}

// priority queue
void explainPriorityQueue()
{
    priority_queue<int> pq; // priority queue follows fifo but the maximum element is always stored at the top

    pq.push(5); // {5}
    pq.emplace(2); // {5, 2}
    pq.emplace(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout<<pq.top(); // output => 10

    pq.pop(); // {8, 5, 2}

    /* minimum heap */
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.emplace(2); // {2, 5}
    pq.emplace(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout<<pq.top(); // output => 2

    // rest functions same as vector
    // size(), swap(), empty()
}

int main()
{

    return 0;
}
