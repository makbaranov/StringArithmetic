// StringArithmetic.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

std::string divide(std::string a, int b)
{
    std::string res = "";
    bool over = false;
    int digit = 0;

    for (char symbol : a) {
        digit = symbol - '0';
        if (over) {
            digit += 10;
            over = false;
        }
        if (digit < b) {
            res += "0";
            if (digit == 1)
                over = true;
        }
        else {
            res += std::to_string(digit / b);
            if (digit % b)
                over = true;
        }
    }

    if (res == "")
        res = "0";
    else if (res.length() > 1 && res[0] == '0')
        res = res.substr(1);

    return res;
}


int main()
{
    std::string result;
    result = divide("0", 2);
    result = divide("1", 2);
    result = divide("10",2);
    result = divide("1012", 2);


    system("pause");
    return 0;
}

