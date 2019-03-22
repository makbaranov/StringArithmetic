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

std::string plus(std::string a, std::string b) 
{
    std::string res;
    int diff = a.length() - b.length();
    if (diff < 0)
        a.insert(0, -diff, '0');
    else if (diff > 0)
        b.insert(0, diff, '0');
    
    bool over = false;
    for (auto it_a = a.rbegin(), it_b = b.rbegin();
        it_a < a.rend() && it_b < b.rend();
        ++it_a, ++it_b)
    {
        int r = (*it_a - '0') + (*it_b - '0');

        if (over)
        {
            r++;
            over = false;
        }

        if (r >= 10)
        {
            over = true;
            r %= 10;
        }
        res.insert(0, std::to_string(r));
    }
    if (over)
        res.insert(0, "1");

    return res;
}


int main()
{
    std::string result;
    //result = plus("25", "35");
    //result = plus("5", "35");
    //result = plus("25", "5");
    int int_result;
    for (int i = 0; i <= 1000; i++) 
    {
        for (int k = 0; k <= 1000; ++k)
        {
            result = plus(std::to_string(k), std::to_string(i));
            int_result = k + i;
            if (int_result == std::stoi(result))
                std::cout << "\rsuccess";
            else
                std::cout << "\rfail: " << k << " + " << i << " should be " << int_result << " returned: " << result << std::endl;
        }
    }



    system("pause");
    return 0;
}

