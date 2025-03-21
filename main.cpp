
#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);

	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	//Test 3 : an empty set input should return an empty set
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {};
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3 == soln);

	//Test 4 : identical numbers should return themselves
	values = {3, 3, 3, 3, 3};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {3, 3, 3, 3};
	set<int> answerSet4(ans.begin(), ans.end());
	assert(answerSet4 == soln);

	//Test 5: prime numbers should have no valid subsets
	values = {37, 17, 19, 23, 29};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {17};
	set<int> answerSet5(ans.begin(), ans.end());
	assert(answerSet5 == soln);

	//Test 6: 
	values = {1, 12, 6, 3, 24};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {1, 3, 6, 12, 24};
	set<int> answerSet6(ans.begin(), ans.end());
	assert(answerSet6 == soln);

	//Test 7: Duplicates should not affect testing
	values = {4, 2, 8, 2, 16};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {2, 2, 4, 8, 16};
	set<int> answerSet7(ans.begin(), ans.end());
	assert(answerSet7 == soln);

	//Test 8: Large numbers should still be handled
	values = {1000000000, 500000000, 1};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {1000000000, 500000000, 1};
	set<int> answerSet8(ans.begin(), ans.end());
	assert(answerSet8 == soln);

	//Test 9 
	values = {2, 8, 28, 56};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {2, 8, 56,};
	set<int> soln2 = {2, 28, 56};
	set<int> answerSet9(ans.begin(), ans.end());
	assert(answerSet9 == soln || answerSet9 == soln2);

	//Test 10: a Set with one number should return itself
	values = {88};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {88};
	set<int> answerSet10(ans.begin(), ans.end());
	assert(answerSet10 == soln);



	cout << "ALL TESTS PASSED!!" << endl;

	return 0;
}
