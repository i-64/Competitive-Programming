#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define watch(x) cout << (#x) << " is " << x << endl;


void constructBlanceArray(int BOP[], int BCP[],
						char* str, int n)
{

	// Create a stack and push -1 as initial index to it.
	stack<int> stk;

	// Initialize result
	int result = 0;

	// Traverse all characters of given string
	for (int i = 0; i < n; i++) {
		// If opening bracket, push index of it
		if (str[i] == '(')
			stk.push(i);

		else // If closing bracket, i.e., str[i] = ')'
		{
			// If closing bracket, i.e., str[i] = ')'
			// && stack is not empty then mark both
			// "open & close" bracket indexs as 1 .
			// Pop the previous opening bracket's index
			if (!stk.empty()) {
				BCP[i] = 1;
				BOP[stk.top()] = 1;
				stk.pop();
			}

			// If stack is empty.
			else
				BCP[i] = 0;
		}
	}

	for (int i = 1; i < n; i++) {
		BCP[i] += BCP[i - 1];
		BOP[i] += BOP[i - 1];
	}
}

// Function return output of each query in O(1)
int query(int BOP[], int BCP[],
		int s, int e)
{
	if (BOP[s - 1] == BOP[s]) {
		return (BCP[e] - BOP[s]) * 2;
	}

	else {
		return (BCP[e] - BOP[s] + 1) * 2;
	}
}
/*
// Driver program to test above function
int main()
{

	char str[] = "())(())(())(";


	int startIndex = 5, endIndex = 11;

	cout << "Maximum Length Correct Bracket"
			" Subsequence between "
		<< startIndex << " and " << endIndex << " = "
		<<  << endl;

	startIndex = 4, endIndex = 5;
	cout << "Maximum Length Correct Bracket"
			" Subsequence between "
		<< startIndex << " and " << endIndex << " = "
		<< query(BOP, BCP, startIndex, endIndex) << endl;

	startIndex = 1, endIndex = 5;
	cout << "Maximum Length Correct Bracket"
			" Subsequence between "
		<< startIndex << " and " << endIndex << " = "
		<< query(BOP, BCP, startIndex, endIndex) << endl;

	return 0;
}*/




int findMaxLen(string str)
{
  int n = str.length();

  // Create a stack and push -1 as initial index to it.
  stack<int> stk;
  stk.push(-1);

  // Initialize result
  int result = 0;

  // Traverse all characters of given string
  for (int i=0; i<n; i++)
  {
      // If opening bracket, push index of it
      if (str[i] == '(')
        stk.push(i);

      else // If closing bracket, i.e.,str[i] = ')'
      {
          // Pop the previous opening bracket's index
          stk.pop();

          // Check if this length formed with base of
          // current valid substring is more than max
          // so far
          if (!stk.empty())
              result = max(result, i - stk.top());

          // If stack is empty. push current index as
          // base for next valid substring (if any)
          else stk.push(i);
      }
  }

  return result;
}

int32_t main () {
  string str;
  cin >> str;
  int q;
  cin >> q;
  while (q--) {
    int u, v, w;
    cin >> u >> v;
    if (u == 1) {
      cin >> w;
      string s(str.begin() + v-1, str.begin() + w-1);
      int n = s.length();
      char s2[n];
      for (int i = 0; i < n; i++) {s2[i] = s[i];}
      // cout<<s<<endl;

    	int BCP[n + 1] = { 0 };
    	int BOP[n + 1] = { 0 };

    	constructBlanceArray(BOP, BCP, s2, n);
      cout << query(BOP, BCP, v-1, w-1) << endl;
      // cout << findMaxLen(*(new string(s))) << endl;
    }
    else {
      if (str[v-1] == ')') str[v-1] = '(';
      else str[v-1] = ')';
    }
  }
  return 0;
}
