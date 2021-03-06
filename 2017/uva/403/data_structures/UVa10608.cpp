/* UVa problem: 10608 Friends
 *
 * Topic: data structures
 *
 * Level: mandatory
 * 
 * Brief problem description: 
 *
 *   Given a pairs of friendships between two people,
 *   find the longest 
 *
 * Solution Summary:
 *
 *   For this problem, an Union Find Disjoint Set is used with 
 *   an additional array to count the size of each set and keeping track of
 *   the max.
 *
 * Used Resources:
 *
 *   CP3
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Dennis Truong
 */
#include <iostream> 
#include <cstdio>
#include <vector>
using namespace std;
// Union Find Disjoint Set from CP3 p.79
class UnionFind {
  // OOP style
  private: vector<int> p, rank, size;
  // remember: vi is vector<int>
  public:
    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      size.assign(N,1);
      for (int i = 0; i < N; i++) {
      	p[i] = i;
      }
    }
  int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  int unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      // if from different set
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
      	p[y] = x;
      	return size[x] += size[y];
      }
      // rank keeps the tree short
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        return size[y] += size[x];        
      }
    }
    return -1;
  }

};

int main() {
	int t,n,m,a,b;
	cin >> t;
	for (int _ = 0; _ < t; ++_)
	{
		cin >> n >> m;
		//create UFDS
		UnionFind uf(n);
		int max = 1;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			a--;b--;
			//union
			int cur = uf.unionSet(a,b);
			if (cur > max) max = cur;
		}
		cout << max << endl;
	}
  	return 0;
};