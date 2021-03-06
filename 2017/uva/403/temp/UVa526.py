'''/* UVa problem: 
 *
 * Topic: 
 *
 * Level: 
 * 
 * Brief problem description: 
 *
 *   
 *
 * Solution Summary:
 *
 *   
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
def edit(s1, s2):
    table = []
    if len(s1) > len(s2):
        s1, s2 = s2, s1
    distances = range(len(s1) + 1)
    for i2, c2 in enumerate(s2):
        distances_ = [i2+1]
        for i1, c1 in enumerate(s1):
            if c1 == c2:
                distances_.append(distances[i1])
            else:
                distances_.append(1 + min((distances[i1], distances[i1 + 1], distances_[-1])))
        table.append(distances_)
        distances = distances_
    return distances[-1]
a=edit(input(),input())
# a=edit(input(),input())

