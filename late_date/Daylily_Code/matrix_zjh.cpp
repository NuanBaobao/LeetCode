//
// Created by 张进华 on 2022/5/10.
//
# include <iostream>
# include <cstring>

using namespace std;

template<class T>
class Matrix{
public:
    int number_rows;
    int number_column;
    T ** element;
    T original_array_2d[3][5];

    bool make_2d_array(){
        // 创建二维数组
        try {
            // 创建行指针
            element = new T * [number_rows];
            // 为每行分配空间
            for(int i = 0; i < number_column; i++){
                element[i] = new int [number_column];
            }
            return true;
        }
        catch(bad_alloc) {return false;}
    }
};

int main(void)
{
//    Matrix<int> res;
//    cin >> res.number_rows >> res.number_column;
//    res.make_2d_array();
//
//    cout << sizeof(res.element) << endl;
//    cout << sizeof(res.original_array_2d[0]) << endl;

    int u1, u2, u3, u4;
    cin >> u1 >> u2 >> u3 >> u4;

    int k_array[u1][u2][u3][u4];

    cout << sizeof(k_array) << endl;


    return 0;
}