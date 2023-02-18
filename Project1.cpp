#include <bits/stdc++.h>
using namespace std;

vector<int> maximumHousesStrategy1(int n, vector<vector<int>> &houseAvailability){
    // The function sorts the houses in increasing order of their start times and gives an output based on the same
    // Given that the houses are already sorted according to their start dates so no sorting is required
    vector<int> res;
    int i = 0, firstAvailableDay = 1;
    while(i < houseAvailability.size() and houseAvailability[i][0] <= firstAvailableDay){
        if(firstAvailableDay <= houseAvailability[i][1]){
            res.push_back(i+1); // 1-indexing system
            // handling of non-overlapping intervals
            firstAvailableDay = max(houseAvailability[i][0], firstAvailableDay) + 1;
            // if the available days for the painter are over, they can no longer paint any more houses and hence we end the loop.
            if(firstAvailableDay > n)
                break;
        }
        i++;
    }
    return res;
}

int main() {
    int n, m;
    cout << "Enter the value of painter Availability: "; cin >> m;
    cout << "Enter the number of houses present: "; cin >> m;

    // Taking user input
    cout << "Enter the start and end house availability paint dates in each line: " << endl;
    vector<vector<int>> houseAvailability(m, vector<int> (2));
    for(int i = 0; i < m; i++) {
        cin >> houseAvailability[i][0] >> houseAvailability[i][1];
    }

    vector<int> res = maximumHousesStrategy1(n, houseAvailability);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
