#include <iostream>

using namespace std;

template<typename T, size_t S>
class Array{
public:
    constexpr int Size() const { return S; }

    T& operator[](int index) {
        
        if (!(index < 5)){
            __debugbreak();
        }
        
        return m_Data[index];
    }

    const T& operator[](size_t index) const { return m_Data[index]; }
private:
    T m_Data[S];
};

int main(){

    Array<int, 5> data{};

    for(int i=0; i<data.Size(); i++){
        data[i] = i;
        cout<<data[i]<<" ";
    }
}