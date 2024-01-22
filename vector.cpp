#include <bits/stdc++.h>

using namespace std;


const long long MOD = 1e9 + 7;
//const long long MOD = 998244353;
const long long OO = 1e16, N = 3e5;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// #define int long long
#define ll long long


class Vector{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity;
public:
    Vector(int n)
    {
        size = n;
        if(size <= 0)size = 1;
        arr = new int [size] {};
        capacity = n;
    }
    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }

    int get(int idx)
    {
        assert(idx >= 0 && idx < size);
        return arr[idx];
    }

    void set(int idx , int value)
    {
        assert(idx >= 0 && idx < size);
        arr[idx] = value;
    }
    void print()
    {
        for(int i = 0 ; i < size ; i++)cout<<arr[i]<<" ";
            cout<<'\n';
    }

    int find(int num)
    {
        for (int i = 0; i < size; ++i)
        {
            if(arr[i] == num)return i;
        }
        return -1;
    }

    void push_back(int num)
    {
        if(size == capacity)expected_capacity();
        arr[size++] = num;
    }
    void expected_capacity()
    {
        capacity *= 2;
        int *temp = arr;
        arr = new int [capacity] {};
        for (int i = 0; i < size; ++i)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
    void insert(int idx , int num)
    {
        assert(idx >= 0 && idx < size);
        if(size == capacity)expected_capacity();
        for (int i = size; i > idx; --i)
        {
            arr[i] = arr[i-1];
        }
        arr[idx] = num;
        size++;
    }

};


signed main() {
    fast;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int t = 1;
    cin >> t;
    for (int tct = 1; tct <= t; tct++) {
        Vector v1(10);
        v1.set(1 , 9);
        v1.set(0 , 19);
        v1.print();
        cout<<v1.find(9)<<" "<<v1.find(66)<<'\n';
        v1.push_back(10);
        v1.insert(1 , 10);
        v1.print();




    }
}