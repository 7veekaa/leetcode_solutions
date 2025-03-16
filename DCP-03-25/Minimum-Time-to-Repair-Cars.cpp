#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

//reverse engineering
//binary search on time - > compare each car with, add up anf check w total cars 
//cars formulation

class Solution {
    private:
    bool isacceptable(std::vector<int>& ranks, long long mid, int cars){  
     long long carsdone = 0;
     for(int i=0; i<ranks.size();i++){
          if (mid<ranks[i]) continue;  
         carsdone+= sqrt(mid /ranks[i]);  
        }
 return carsdone>= cars;
    }

public:
    long long repairCars(std::vector<int>& ranks, int cars) {
        long long le= 1;
        int maximum= *max_element(begin(ranks), end(ranks));
        long long ri= (long long)maximum* cars* cars;  
        long long sol =-1;

        while (le <= ri) {
    long long mid = le + (ri - le) / 2;
     if (isacceptable(ranks, mid, cars)) {  
                sol= mid;
                ri= mid-1;  
            } else {
                le=mid+ 1;
            }
        }
            return sol;
    }
};
