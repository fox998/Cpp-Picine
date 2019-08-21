// Example program
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

template<typename T>
void print_validated_type(T t)
{
    std::cout << t;
}

template<>
void print_validated_type(float t)
{
    std::cout << t << "f";
}

template<>
void print_validated_type(char t)
{
    if (std::iscntrl(t) || std::isspace(t))
    {
        std::cout << "Non displayable";
        return;
    }

    std::cout << "'" << t << "'";
}

template<typename T>
void print_type(T t, std::string name)
{
    std::cout << name << " : ";
    print_validated_type(t);
    std::cout << std::endl;
}

#define PRINT(TYPE, VALUE) \
{\
    print_type<TYPE>(VALUE, #TYPE);\
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << " usage : ./convert value" << std::endl;
        return 1;
    }

    char* end = NULL;
    double const dbl_value = strtod(argv[1], &end);
    
    if (isnan(dbl_value) || isinf(dbl_value))
    {
        std::cout << "char : impossible " << std::endl;
        std::cout << "int : impossible " << std::endl;
    }
    else
    {
        PRINT(char, dbl_value);
        PRINT(int, dbl_value);
    }

    std::cout << std::fixed << std::setprecision(1);

    PRINT(float, dbl_value);
    PRINT(double, dbl_value);
}
