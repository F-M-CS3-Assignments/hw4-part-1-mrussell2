
#include <vector>  // use vectors
#include <iostream> // enable cin, cout
#include <string> // use strings
#include <algorithm>  // to use sort : source: https://www.digitalocean.com/community/tutorials/sort-in-c-plus-plus 
#include "bdc.h"  // include bdc header


using namespace std;
int find_next_dividend_position(vector<int> input, int start, int divisor) { //helper to find next dividend position
    for (size_t i = start; i < input.size(); i++) { // loop through the vector 
        if (input[i] % divisor == 0) { // check if int at i is divisible by divisor
            return i;  // if divisible return that position
        }
    }
    return -1; // if no position found return invalid index for use in check later on
}
vector<int> sub_vec(const vector<int> input, int start) { // helper to return sub vector
    return vector<int>(input.begin() + start, input.end()); // return sub vector
}

vector<int> longest_vector(vector<vector<int> > candidates){ // find the longest vector in candidates

    if (candidates.empty()) return {}; // if candidates is empty return empty vector

    vector<int> longest = candidates[0]; // set longest to first vector in candidates as base
    for (vector<int> vec : candidates) { // loop through each vector in candidates 
        if (vec.size() > longest.size()) { // check if greater than current longest
            longest = vec;  // if vec is greater than longest, set longest to vec
        }
    }
    return longest; // return the longest vector
}

vector<int> bdc_helper(vector<int> input){ // helper function for biggest_divisible_conglomerate, allows us to use recursion
    if (input.size() <=1){  // base case: return input if the size of the vector is less than or equal to 1 (0 or 1)
        return input;
    }

    vector <vector <int> > candidates;  //Initialize a vector with each item being also a int vector
    for (size_t i =0; i < input.size(); i++){
        vector<int> L = {input[i]};  //a small vector with input[i] as the only item
        
        //From the position i+1, find the position of next number in the input vector which is divisible by input[i]
        int j = find_next_dividend_position(input, i + 1, input[i]);
        if (j == -1) { // check if invalid position(i.e. no positon found)
            continue;  // Skip processing if no valid next divisor exists
        }
        vector<int> Rin = sub_vec(input, j); //extract the sub vector from position j to the rest
        
        if (!Rin.empty()) { // ensure Rin is not empty
            vector<int> R = bdc_helper(Rin); // recursive call to function
            for (int num : R) { 
                if (num % L.back() == 0) { // check if num is divisible by previous number
                    L.push_back(num); // add num to L
                }
            }
        }

        candidates.push_back(L); //append the conglomerate to the list/vector 
    } 
    return longest_vector(candidates); // return the longest vector in candidates
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    if (input.empty()) return {}; // handle empty sets

    sort(input.begin(), input.end());  // sort input in ascending order
    vector<int> result = bdc_helper(input); // result equals the output of helper funciton / call helper

    if (result.empty()) {
        return {input[0]};  // If no valid subset found, return one element
    }

    return result;
}
string vec_to_string(vector<int> v){ // function for vector to string
    if (v.empty()) return "[]"; // if v is empty retun empty set

    string s = "["; // added open bracker
    for (size_t i = 0; i < v.size() - 1; i++) { // loop through v

        s += to_string(v[i]) + ", "; // add each element to the string followed by a comma and a space, do not include last element

    }
    s += to_string(v.back()) + "]"; // add last element followed by close bracket
    return s; // return string
}