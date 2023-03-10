//
// Created by aseem on 2/23/23.
//
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// Custom Sort function for the strategy 2
class sortLatestStartDay{
public:
    bool operator ()(vector<int> &v1, vector<int> &v2){
        // First index signifies the start date, second index signifies the end date
        // The third index signifies the index at which the particular house appears in original array

        // Sorted based on first part descending based on latest start day
        return v1[0] < v2[0];
    }
};

vector<int> maximumHousesStrategy2(int n, vector<vector<int> > &houseAvailability) {
    // The function selects the first house available to be painted that day having the maximum start time

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    priority_queue<vector<int>, vector<vector<int> >, sortLatestStartDay> pq;

    // Variables to keep track of last executed job and resultant answer
    int idx = 0;
    vector<int> res;
    for(int currentDay = 1; currentDay <= n; currentDay++){

        // Inserting all houses into the priority queue which have an availability at a given day
        while(idx < houseAvailability.size() and houseAvailability[idx][0] <= currentDay){
            pq.push(houseAvailability[idx]);
            idx++;
        }

        // Removing all the houses whose end day is less than the current day
        while(!pq.empty() and pq.top()[1] < currentDay)
            pq.pop();

        // If all jobs are finished for the current day, hop on to the next day
        if(pq.empty()) continue;

        // inserting the first job with the latest time which comes from the priority queue using MaxHeap
        res.push_back(pq.top()[2]);

        // Removing the current house with maximum start time from the queue
        pq.pop();
    }
    return res;
}

int main() {
    // Taking user input for availability of painter and the total number of houses
    int n, m; cin >> n >> m;

    // Taking user input for the availability times of houses when they can be painted
    vector<vector<int> > houseAvailability(m, vector<int> (2));

    for(int i = 0; i < m; i++) {
        cin >> houseAvailability[i][0] >> houseAvailability[i][1];
    }

    // Result of strategy 2 below
    vector<int> res = maximumHousesStrategy2(n, houseAvailability);
    for (int &re: res)
        cout << re << " ";
    return 0;
}