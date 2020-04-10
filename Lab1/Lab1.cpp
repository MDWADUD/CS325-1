#include <iostream>

using namespace std;
class NAND
{
public:
    static bool operation(bool oper1, bool oper2)
    {
        return !(bool oper1 && bool oper2);
    }
};
class AND
{
public:
    static bool Operation(bool Oper1, bool Oper2)
    {
        return (Oper1 && Oper2);
    }
};
class OR
{
public:
    static bool Operation(bool Oper1, bool Oper2)
    {
        return (oper1 || oper2);
    }
};
class XOR
{
public:
    static bool Operation(bool oper1, bool oper2)
    {
        return (oper1 ^ oper2);
    }
};
class NOR
{
public:
    static bool Operation(bool oper1, bool oper2)
    {
        return !(oper1 || oper2);
    }
};
class NOT
{
public:
    static bool Operation(bool oper1, bool oper2)
    {
        return !(oper1) || !(oper2);
    }
};
