#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void solution(std::string str)
{
    std::vector<std::vector<int>> map(str.size(),std::vector<int>(str.size()));
    int prev_index = (str.size() -1);
    int len=0;
    for(int i=(str.size()-1);i>=0;--i)
    {
        for(int j = 0 ; j<i; ++j)
        {
            if(str[i] == str[j])
            {
            	if((i == str.size() -1) || j ==0)
            	{
                	map[i][j] = 2;
            	}
            	else
            	{
            		map[i][j] = map[i+1][j-1] + 2;	
            	}
                
            }          
            else
            {
            	if((i == str.size() -1) && j ==0)
            	{
            		map[i][j] = 0;
            	}
            	else if(j ==0)
            	{
            		map[i][j] = map[i+1][j];
            	}
            	else
            	{
            		map[i][j] = map[i][j-1];	
            	}
            }
        }
        if(i == (str.size() -1 ) )
        {
            map[i][i] = 1;
        }
        else if(i == 0)
        {
            map[i][i] = 1;
        }
        else
        {
            map[i][i] = 1+ map[i+1][i-1];
        }
    }
    int i =0;
    std::cout<<"  "<<str<<std::endl;
    for(auto row : map)
    {
        std::cout<<str[i]<<' ';
        i++;
        for(auto col : row)
        {
            std::cout<<col;
        }
        std::cout<<std::endl;
    }
    for(int i =0;i<str.size()-1;i++)
    {
        if(map[i][i] > len)
        {
            len = map[i][i];
        }
        if(map[i+1][i] > len)
        {
            len = map[i+1][i];   
        }
    }
    if(map[str.size()-1][str.size()-1] > len)
    {
        len = map[str.size()-1][str.size()-1];
    }
    std::cout<<len<<std::endl;
}

int main(int argc, char const* argv[]) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // int cases;
    // cin>>cases
    // for (int i = 0; i < cases; ++i)
    // {
    // 	string input;
    // 	cin>> input;
    // }
    solution(argv[1]);
    return 0;
}
