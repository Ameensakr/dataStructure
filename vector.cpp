#include <bits/stdc++.h>

using namespace std;


const long long MOD = 1e9 + 7;
//const long long MOD = 998244353;
const long long OO = 1e16, N = 3e5;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// #define int long long
#define ll long long

template<class  T>
class Vector{
private:
    T *arr = nullptr;
    int size = 0;
    int capacity;
public:
    Vector(int n)
    {
        size = n;
        if(size <= 0)size = 1;
        arr = new T [size] {};
        capacity = n;
    }
    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }

    T get(int idx)
    {
        assert(idx >= 0 && idx < size);
        return arr[idx];
    }

    void set(int idx , T value)
    {
        assert(idx >= 0 && idx < size);
        arr[idx] = value;
    }
    void print()
    {
        for(int i = 0 ; i < size ; i++)cout<<arr[i]<<" ";
            cout<<'\n';
    }

    int find(T num)
    {
        for (int i = 0; i < size; ++i)
        {
            if(arr[i] == num)return i;
        }
        return -1;
    }

    void push_back(T num)
    {
        if(size == capacity)expected_capacity();
        arr[size++] = num;
    }
    void expected_capacity()
    {
        capacity *= 2;
        T *temp = arr;
        arr = new T [capacity] {};
        for (int i = 0; i < size; ++i)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
    void insert(int idx , T num)
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
    T& operator [] (int idx)
    {
        return arr[idx];
    }

    int front()
    {
        assert( size > 0);
        return arr[0];
    }
    int back()
    {
        assert(size > 0);
        return arr[size - 1];
    }

    void right_rotate() // first homework
    {
        T lastElement = arr[size - 1];
        for (int i = size - 1; i >= 1 ;--i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = lastElement;
    }

    void left_rotate() // second homework
    {
        T firstElement = arr[0];
        for (int i = 0; i < size - 1 ; ++i) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = firstElement;
    }

    void right_rotate_with_steps(int num) // third homework
    {
        T *temp = new T [size] {};
        for (int i = 0; i < size; ++i) {
            temp[(i + num)%size] = arr[i];
        }
        arr = temp;
        delete[] temp;
    }

    T erase(int idx) // fourth homework
    {
        T num = arr[idx];
        for (int i = idx + 1; i < size; ++i) {
            arr[i - 1] = arr[i];
        }
        size--;
        return num;

    }

    int find_transposition(T value) // fifith homework
    {
        for (int i = 0; i < size; ++i) {
            if(arr[i] == value)
            {
                if(i != 0)
                {
                    swap(arr[i] , arr[i-1]);
                    return i-1;
                }
                return 0;
            }
        }
    }




};


signed main() {
    fast;



    int t = 1;
//    cin >> t;
    for (int tct = 1; tct <= t; tct++) {
        Vector<int> v1(10);
        v1.set(1 , 9);
        v1.set(0 , 19);
        v1[0] = 1;
        v1.print();
        cout<<v1.find(9)<<" "<<v1.find(66)<<'\n';
        v1.push_back(10);
        v1.insert(1 , 10);
        v1.print();
        v1.right_rotate();
        v1.print();
        v1.left_rotate();
        v1.print();
        cout<<v1.erase(1)<<endl;
        v1.print();
        cout<<v1.find_transposition(9)<<endl;
        v1.print();





    }
}