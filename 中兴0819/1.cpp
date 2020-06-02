

#include <iostream>
using namespace std;
#define Max(a, b) ((a > b) ? (a) : (b))

const int MAXM = 205;
const int MAXV = 605;

int dp[MAXV][MAXM];

int maxE(int reactorCap, int numberOfRadLiquid,
	int criticalMass, int* volumes, int* masses, int* energies) {
	for (int i = 0; i < numberOfRadLiquid; i++) {
		for (int ind1 = reactorCap; ind1 >= volumes[i]; --ind1)
			for (int ind2 = criticalMass; ind2 >= masses[i]; --ind2)
				dp[ind1][ind2] = Max(dp[ind1][ind2], dp[ind1 - volumes[i]][ind2 - masses[i]] + energies[i]);
	
	}
	return dp[reactorCap][criticalMass];

}