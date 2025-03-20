
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>  // to use sort : source: https://www.digitalocean.com/community/tutorials/sort-in-c-plus-plus 
#include "bdc.h"


using namespace std;
int find_next_dividend_position(const vector<int> input, int start, int divisor) { //helper to find next dividend position
    for (size_t i = start; i < input.size(); i++) {
        if (input[i] % divisor == 0) {
            return i;
        }
    }
    return -1;
}
vector<int> sub_vec(const vector<int> input, int start) { // helper to return sub vector
    return vector<int>(input.begin() + start, input.end());
}

vector<int> longest_vector(vector<vector<int> > candidates){

    if (candidates.empty()) return {}; 

    vector<int> longest = candidates[0];
    for (vector<int> vec : candidates) {
        if (vec.size() > longest.size()) {
            longest = vec;
        }
    }
    return longest;
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
        if (j == -1) {
            continue;  // Skip processing if no valid next divisor exists
        }
        vector<int> Rin = sub_vec(input, j); //extract the sub vector from position j to the rest
        ///call the recursive function with a subproblem (a smaller input vector)
        if (!Rin.empty()) {
            vector<int> R = bdc_helper(Rin);
            for (int num : R) {
                if (num % L.back() == 0) {
                    L.push_back(num);
                }
            }
            
        }

        candidates.push_back(L); //append the conglomerate to the list/vector 
    } 
    return longest_vector(candidates);
}

vector<int> biggest_divisible_conglomerate(vector<int> input){
    if (input.empty()) return {}; // handle empty sets

    sort(input.begin(), input.end()); 
    vector<int> result = bdc_helper(input);

    if (result.empty()) {
        return {input[0]};  // If no valid subset found, return one element
    }

    return result;
}
string vec_to_string(vector<int> v){
    if (v.empty()) return "[]";

    string s = "[";
    for (size_t i = 0; i < v.size() - 1; i++) {

        s += to_string(v[i]) + ", ";

    }
    s += to_string(v.back()) + "]";
    return s;
}