'''/* UVa problem: tower of babylon
 *
 * Topic: graph traversal
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   build the tallest tower with blocks types, 
 *   blocks bases must be smaller than previous
 *
 * Solution Summary:
 *
 *   Longest increasing subsequence
 *
 * Used Resources:
 *
 *   
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Dennis Truong
 */'''
tc = int(input())
for i in range(tc):
    S = input()
    q = int(input())
    for j in range(q):
        T = input()
        if T in S:
            print('y')
        else:
            print('n')