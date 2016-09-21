#include <iostream>
#include <vector>
#include <stdio.h>
#include <climits>


class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        
       std::vector<int> Level;
       if(amount == 0)
             return 0;
       else
       {
            return breadthFirst(coins,amount);   
       }
        
        
        
    }
private:
    int getDenominations(std::vector<int>& Denominations,std::vector<int>& Level,int value)
    {
    	int min =INT_MAX;
    	std::vector<int> Levelmin = Level;
    	for (auto denom : Denominations)
    	{
    		int temp = value -	denom;
    		std::vector<int> tempv = Level;
    		tempv.push_back(denom);
    		if(temp > 0)
    		{	
    			int size = getDenominations(Denominations,tempv,temp);
    			if(size < min)
    			{
    				Levelmin = tempv;
    				min = size;
    			}
    		}
    		else if( temp == 0)
    		{
    			Level = tempv;
    			return Level.size();
    		}
    	}
    	Level=Levelmin;
    	return min;
    }

    int breadthFirst(std::vector<int>& Denominations,int value)
    {
    	std::vector<int> upperLevel;
    	upperLevel.push_back(value);
    	std::vector<int> lowerLevel;
    	for(int i =1;i<=value;i++)
    	{
    		for( auto tempval : upperLevel)
    		{
	    		for( auto denom : Denominations)
	    		{
	    			std::cout<<tempval-denom<<",";
	    			if ((tempval-denom) == 0)
	    			{
	    				return i;
	    			}
	    			else
	    				lowerLevel.push_back(tempval-denom);
	    		}
	    	}
	    	upperLevel = lowerLevel;
	    	lowerLevel.empty();
	    	std::cout<<std::endl;
    	}
    }

};

class SolutionAditi {
public:
int minimum;
int possibility = -1;
    int coinChange(std::vector<int>& coins, int amount) 
    {
        int change = 0;
        if(amount >= 0)
        {
            possibility = 1;
        }
        minimum = amount;
        for ( int i : coins) 
        {
            recursion(amount, coins, i, change);
            change =0;
        }
        if ( possibility != -1) 
        {
            return minimum;
        } 
        else 
        {
            return possibility;
        }
        
    }
    void recursion(int sum, std::vector<int>& coins,int denom, int &change) 
    {
        sum -= denom;
        std::cout<<sum<<","<<denom<<","<<change<<std::endl;
        change += 1;
        int origchange = change;
	    if (sum > 0) 
        {
            for ( int i : coins) 
            {
                recursion (sum, coins, i, change);
                change = origchange;   
            }
            
        } 
        else if( sum == 0) 
        {
            if ( change < minimum) 
            {
                minimum = change;
            }
        }
        
    }
};

int main(int argc, char const *argv[])
{
	SolutionAditi sol;
	std::vector<int> v ={1,3,5};
	std::cout<<std::endl<<sol.coinChange(v,8)<<std::endl;
	return 0;
}