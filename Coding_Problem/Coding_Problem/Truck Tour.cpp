// HackerRank problem 
// Truck Tour

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Complete the truckTour function below.
 */
int truckTour(vector<vector<int>> petrolpumps) {
    int nTruck = petrolpumps.size();
    int turn = 0;
    for (; turn < nTruck; ++turn)
    {
        int cnt = nTruck;
        int idx = turn;
        int restPetrol = 0;
        while (cnt--)
        {
            int amount = petrolpumps[idx][0];
            int distance = petrolpumps[idx][1];
            restPetrol += amount;
            restPetrol -= distance;
            if (restPetrol < 0)
                break;
            idx = (idx + 1) % nTruck;
        }
        if (cnt < 0)
            return turn;
    }
    return nTruck - 1;
}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

    cout << result << "\n";

    return 0;
}
