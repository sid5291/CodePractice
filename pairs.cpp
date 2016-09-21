#include <iostream>
#include <map>
#include <pair>
#include <vector>


int countPairs(std::vector<int> a, int k)
{
    if( k ==0)
    {
        int cnt = 0;
        for( auto i : a) if(i == 0) {cnt++;}
        return((cnt >=2) ? 1 : 0);
    }
    else
    {
        std::map<int,bool> numberMap;
        std::for_each(a.begin(),a.end(),[&numberMap](int i){numberMap[i] = true;});
        std::map<std::pair<int,int>,bool> pairMap;
        int result = 0;
        for(auto i : a)
        {
            if (numberMap[k-i])
            {
                if(not pairMap[std::make_pair(i,k-i)])
                {
                    pairMap[std::make_pair(i,k-i)] = true;
                    pairMap[std::make_pair(k-i,i)] = true;
                    result++;
                }
            }
        }
        return result;
    }
}