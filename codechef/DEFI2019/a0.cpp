// A Dynamic Programming based C++ Program for the Egg Dropping Puzzle
# include <bits/stdc++.h>
# include <limits.h>

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a: b; }

/* Function to get minimum number of trials needed in worst
case with n eggs and k floors */


/* Driver program to test to pront printDups*/
int main()
{
	// int n = 2, k = 36;;
  int n, k;
  std::cin >> n >> k;
	printf ("nMinimum number of trials in worst case with %d eggs and "
			"%d floors is %d \n", n, k, eggDrop(n, k));
	return 0;
}
