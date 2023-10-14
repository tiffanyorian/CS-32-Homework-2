//
//  recursion.cpp
//  Homework 2

#include <iostream>


// uses recursion to simulate multiplication but only uses addition
int productOfTheSystem(unsigned int m, unsigned int n)
{
    
    if(n == 0 || m == 0)// base case
    {
        return 0;
    }
    
    return m + productOfTheSystem(m, n - 1);// adds 5 to returned value
}



// counts amount of times "digit" appears in int "num" and returns it
int accountForADigit(int num, int digit)
{
    
    if (num == 0)// base case
    {
        return 0;//
    }
    
    
    int count = 0;// counts number of matches in the variable num with digit
    
    if (num % 10 == digit)// if # on the end of the num variable matches digit
    {
        count++;
    }
    
    count += accountForADigit(num / 10, digit);// [1] pass in simplified num variable
    // [2] add current count # to returned count #
    
    return count;
}



// prints "88" in between the same neighboring characters
std::string eightClap(std::string n)
{
    // base case
    if(n.size() == 0)
    {
        return "";// when size reaches 0 return empty string to caller which initiates rest of return process
    }
    
    // determines if need to just return or add 88 in between same consecutive letters
    if(n.substr(0,1) == n.substr(1,1))
    {
        return n.substr(0,1) + "88" + eightClap(n.substr( 1 , n.size() - 1));
    }
    
    else
    {
        return n.substr(0,1) + eightClap(n.substr(1, n.size() -1));
    }
}



// returns only a substr values in between < and >, inclusive of the < > signs.
std::string coneHeads(std::string str)
{
    
    if(str == "" || str.size() == 1)
    {
        return str;// return the substr if string is empty or there is only 1 element
    }
    
    else if(str.substr(0,1) == "<")// if first element is <
    {
        if(str.substr(str.size() - 1,1) == ">")// if last element is >
        {
            return str;// return entire susbtr if the last element is >
        }
        else
        {
            return coneHeads(str.substr(0, str.size() - 1));// keep returning first element, but decrease scope of last element by 1
        }
    }
    
    else
    {
        return coneHeads(str.substr(1, str.size() - 1));// limit the scope of the string for the next recursion by setting 1 to be 0
    }
    
    
}



// returns true if sum of any arbitrary pairing adds up to input "target"
bool conglomerateOfNumbers(const int a[], int size, int target)
{
    if(target == 0)
    {
        return true; // if two integers in the array eventually subtract to equal 0
    }
    
    if(target < 0 || size == 0)
    {
        return false;// if the subtraction is larger than target, or it reached the end without finding a match
    }
    
    // one of them needs to return true, if both return false, meaning that there was no combination, return false
    return (conglomerateOfNumbers(a, size - 1, target - a[size - 1]) || conglomerateOfNumbers(a, size - 1, target));
    // lhs removes last element and checks if it can find a number that evenly subtracts it, if returned false, rhs decreases the scope by one and tries lhs again.
}



// checks each open spot ('.') and recurses until its unable to move in any direction except for moving to previous position
// then checks all sides of previous position and returns true if able to get to passed in spot
bool findAWay(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    // base case, if it reaches the end point, return true
    if (sr == er && sc == ec)
    {
        return true;
    }
    
    // if there is an open spot
    if (maze[sr - 1][sc] == '.')
    {
        maze[sr - 1][sc] = '#';// mark as previously visited
        if (findAWay(maze, nRows, nCols, sr - 1, sc, er, ec))// check row above
        {
            return true;
        }
        maze[sr - 1][sc] = '.';//backtracks
    }
    
    // if there is an open spot
    if (maze[sr + 1][sc] == '.')
    {
        maze[sr + 1][sc] = '#';// mark as previously visited
        if (findAWay(maze, nRows, nCols, sr + 1, sc, er, ec))// check row below
        {
            return true;
        }
        maze[sr + 1][sc] = '.';//backtracks
    }
    
    // if there is an open spot
    if (maze[sr][sc - 1] == '.')
    {
        maze[sr][sc - 1] = '#';// mark as previously visited
        if (findAWay(maze, nRows, nCols, sr, sc - 1, er, ec))//check column to the left
        {
            return true;
        }
        maze[sr][sc - 1] = '.';//backtracks
    }
    
    // if there is an open spot
    if (maze[sr][sc + 1] == '.')
    {
        maze[sr][sc + 1] = '#';// mark as previously visited
        if (findAWay(maze, nRows, nCols, sr, sc + 1, er, ec))// check column to the right
        {
            return true;
        }
        maze[sr][sc + 1] = '.';//backtracks
    }
    
    
    // if nothing returns true, return false
    return false;
    
}


int main()
{
    return 0;
}

 
