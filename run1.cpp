//
// Created by aseem on 2/23/23.
//
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace  std;
vector<int> maximumHousesStrategy1(int n, vector<vector<int>> &houseAvailability) {
    // The function sorts the houses in increasing order of their start times and gives an output accordingly
    // Given that the houses are already sorted according to their start dates so no sorting is required

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    vector<int> res;

    // Using a Queue to make sure that we use a complexity of O(N)
    queue<vector<int>> Q;
    int idx = 0;
    for(int currentDay = 1; currentDay <= n; currentDay++){
        // Pushing all the houses which can be done till currentDay in the queue
        while(idx < houseAvailability.size() and houseAvailability[idx][0] <= currentDay){
            Q.push(houseAvailability[idx]);
            idx++;
        }

        // Popping all houses which don't satisfy the criteria
        while(!Q.empty() and Q.front()[1] < currentDay) Q.pop();
        if(Q.empty()) continue;

        // Adding the value of 1-based index to the result and popping the current Value out
        res.push_back(Q.front()[2]);
        Q.pop();
    }
    return res;
}

int main() {
    // Taking user input for availability of painter and the total number of houses
    int n, m; cin >> n >> m;

    // Taking user input for the availability times of houses when they can be painted
    vector<vector<int>> houseAvailability(m, vector<int> (2));

    for(int i = 0; i < m; i++) {
        cin >> houseAvailability[i][0] >> houseAvailability[i][1];
    }

    // Result of strategy 1 below
    vector<int> res = maximumHousesStrategy1(n, houseAvailability);
    for (int &re: res)
        cout << re << " ";
    return 0;
}