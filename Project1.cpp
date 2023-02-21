#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> maximumHousesStrategy1(int n, vector<vector<int>> &houseAvailability){
    // The function sorts the houses in increasing order of their start times and gives an output accordingly
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

// Custom Sort function for the strategy 2
class sortDescending{
public:
    bool operator ()(vector<int> &v1, vector<int> &v2){
        // Based on first part descending and second part ascending
        // First part signifies the start tine of a job and the second part signifies the index of it
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
};

vector<int> maximumHousesStrategy2(int n, vector<vector<int>> &houseAvailability) {
    // The function selects the first house available to be painted that day having the maximum start time

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    priority_queue<vector<int>, vector<vector<int>>, sortDescending> pq;

    // Variables to keep track of last executed job and resultant answer
    int idx = 0;
    vector<int> res;
    for(int i = 1; i <= n; i++){

        // Inserting all houses into the priority queue which have an availability at a given day
        while(idx < houseAvailability.size() and houseAvailability[idx][0] <= i){
            pq.push({houseAvailability[idx][0], houseAvailability[idx][2]});
            idx++;
        }

        // Removing all the houses whose end day is less than the current day
        while(!pq.empty() and houseAvailability[pq.top()[1] - 1][1] < i)
            pq.pop();

        // If all jobs are finished for the current day, hop on to the next day
        if(pq.empty()) continue;

        // inserting the first job with the latest time which comes from the priority queue using MaxHeap
        res.push_back(pq.top()[1]);

        // Removing the current house with maximum start time from the queue
        pq.pop();
    }

    // Finally sorting the resultant index array for sequential way
    sort(res.begin(), res.end());
    return res;
}

int main() {
    // Taking user input for availability of painter and the total number of houses
    int n = 9, m = 9;
//    cout << "Enter the value of painter Availability: "; cin >> n;
//    cout << "Enter the number of houses present: "; cin >> m;

    // Taking user input for the availability times of houses when they can be painted
//    cout << "Enter the start and end house availability paint dates in each line: " << endl;
    vector<vector<int>> houseAvailability(m, vector<int> (2));
    houseAvailability = {{1,10},{1,7}, {1,8}, {2,3}, {2,4}, {2,8}, {3,4}, {4, 5}, {5, 6}};

    /* Uncomment it after code completion
    for(int i = 0; i < m; i++) {
        cin >> houseAvailability[i][0] >> houseAvailability[i][1];
    }
    */

    // Result of strategy 1 below
    vector<int> res = maximumHousesStrategy1(n, houseAvailability);
    cout << "Indexes returned by strategy 1: ";
    for (int &re: res)
        cout << re << " ";
    cout << endl;

    // Result of strategy 2 below
    res = maximumHousesStrategy2(n, houseAvailability);
    cout << "Indexes returned by strategy 2: ";
    for (int &re: res)
        cout << re << " ";
    cout << endl;
    return 0;
}

// Testcase
//7 8
//1 7
//1 8
//2 3
//2 4
//2 8
//3 4
//4 5
//5 6