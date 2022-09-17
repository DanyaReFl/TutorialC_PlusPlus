#include <iostream>
#include <cmath>

struct vector
{
    float vec_x , vec_y;
};

void function_add()
{
    vector add_vec1 , add_vec2;
    std::cout << "Enter the values of the two vectors."<<std::endl;
    std::cout << "X_1=";
    std::cin >> add_vec1.vec_x;
    std::cout << "Y_1=";
    std::cin >> add_vec1.vec_y;
    std::cout << "X_2=";
    std::cin >> add_vec2.vec_x;
    std::cout << "Y_2=";
    std::cin >> add_vec2.vec_y;
    std::cout << "The sum of two vectors is equal Sum( "<<add_vec1.vec_x+add_vec2.vec_x<<" , "<<add_vec1.vec_y+add_vec2.vec_y<<" ).";
}

void function_subtract()
{
    vector sub_vec1 , sub_vec2;
    std::cout << "Enter the values of the two vectors."<<std::endl;
    std::cout << "X_1=";
    std::cin >> sub_vec1.vec_x;
    std::cout << "Y_1=";
    std::cin >> sub_vec1.vec_y;
    std::cout << "X_2=";
    std::cin >> sub_vec2.vec_x;
    std::cout << "Y_2=";
    std::cin >> sub_vec2.vec_y;
    std::cout << "The difference of two vectors is equal Sub( "<<sub_vec1.vec_x-sub_vec2.vec_x<<" , "<<sub_vec1.vec_y-sub_vec2.vec_y<<" ).";
}

void function_scale()
{
    vector scale_vec1 ;
    float value;
    std::cout << "Enter a vector and a scalar value."<<std::endl;
    std::cout << "X_1=";
    std::cin >> scale_vec1.vec_x;
    std::cout << "Y_1=";
    std::cin >> scale_vec1.vec_y;
    std::cout << "scalar value= ";
    std::cin >> value;
    std::cout << "Multiplying a vector by a scalar is equal Multi( "<<scale_vec1.vec_x*value<<" , "<<scale_vec1.vec_y*value<<" ).";
}

void function_length()
{
    vector length_vec1 ;

    std::cout << "Enter a vector and a scalar value."<<std::endl;
    std::cout << "X_1=";
    std::cin >> length_vec1.vec_x;
    std::cout << "Y_1=";
    std::cin >> length_vec1.vec_y;
    std::cout << "the length of the vector : "<<sqrt(pow(length_vec1.vec_x,2)+pow(length_vec1.vec_y,2));
}

void function_normalize()
{
    vector normalize_vec1 ;

    std::cout << "Enter the coordinates of the vector."<<std::endl;
    std::cout << "X_1=";
    std::cin >> normalize_vec1.vec_x;
    std::cout << "Y_1=";
    std::cin >> normalize_vec1.vec_y;
    std::cout << "Normalized vector: Nor( "<<normalize_vec1.vec_x/(sqrt(pow(normalize_vec1.vec_x,2)+pow(normalize_vec1.vec_y,2)))
    <<" , "<<normalize_vec1.vec_y/(sqrt(pow(normalize_vec1.vec_x,2)+pow(normalize_vec1.vec_y,2)))<<" ).";
}



int main()
{
    int operation;


    std::cout << "Mathematical vector program." << std::endl;
    std::cout << "Enter the operation number (1-add,2-subtract,3-scale,4-length,5-normalize): ";
    std::cin>>operation;

    switch (operation)
    {
        case 1: function_add(); break ;
        case 2: function_subtract(); break ;
        case 3: function_scale(); break ;
        case 4: function_length(); break ;
        case 5: function_normalize(); break ;
        default: std::cout<<"Input error.";
    }


    return 0;
}
