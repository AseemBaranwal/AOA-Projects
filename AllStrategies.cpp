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

        // Sorted based on first part descending and second part ascending
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
};

// Custom Sort function for the strategy 3
class sortSmallestDuration{
public:
    bool operator() (vector<int> &v1, vector<int> &v2){
        // First index signifies the start date, second index signifies the end date
        // The third index signifies the index at which the particular house appears in original array

        // sorted based on ascending duration and ascending end date
        if(v1[1] - v1[0] == v2[1] - v2[0])
            return v1[1] > v2[1];
        return v1[1] - v1[0] > v2[1] - v2[0];
    }
};

// Custom Sort function for the strategy 4
class sortSmallestEndDay{
public:
    bool operator() (vector<int> &v1, vector<int> &v2){
        // First index signifies the start date, second index signifies the end date
        // The third index signifies the index at which the particular house appears in original array

        // sorted based on the smallest ending times and then indices
        if(v1[1] == v2[1])
            return v1[2] > v2[2];
        return v1[1] > v2[1];
    }
};

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

vector<int> maximumHousesStrategy2(int n, vector<vector<int>> &houseAvailability) {
    // The function selects the first house available to be painted that day having the maximum start time

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    priority_queue<vector<int>, vector<vector<int>>, sortLatestStartDay> pq;

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

    // Finally sorting the resultant index array for sequential way
//    sort(res.begin(), res.end());
    return res;
}

vector<int> maximumHousesStrategy3(int n, vector<vector<int>> &houseAvailability) {
    // The function selects the first house available to be painted that day having the shortest duration

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    // minHeap
    priority_queue<vector<int>, vector<vector<int>>, sortSmallestDuration> pq;

    // Variables to keep track of the last executed job and the resultant answer
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

    // Finally sorting the resultant index array for sequential way
//    sort(res.begin(), res.end());
    return res;
}

vector<int> maximumHousesStrategy4(int n, vector<vector<int>> &houseAvailability) {
    // The function gets all the houses who have an availability at a given day and then selects the house
    // having the minimum Ending time

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    // minHeap
    priority_queue<vector<int>, vector<vector<int>>, sortSmallestEndDay> pq;

    // Variables to keep track of the last executed job and the resultant answer
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

    // Finally sorting the resultant index array for sequential way
//    sort(res.begin(), res.end());
    return res;
}

int main() {
    // Taking user input for availability of painter and the total number of houses
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << tc << endl;
        int n, m;
        cin >> n >> m;

        // Taking user input for the availability times of houses when they can be painted
        vector<vector<int>> houseAvailability(m, vector<int> (2));

//    Uncomment code below after code completion
        for(int i = 0; i < m; i++) {
            cin >> houseAvailability[i][0] >> houseAvailability[i][1];
        }

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

        // Result of strategy 3 below
        res = maximumHousesStrategy3(n, houseAvailability);
        cout << "Indexes returned by strategy 3: ";
        for (int &re: res)
            cout << re << " ";
        cout << endl;

        // Result of strategy 4 below
        res = maximumHousesStrategy4(n, houseAvailability);
        cout << "Indexes returned by strategy 4: ";
        for (int &re: res)
            cout << re << " ";
        cout << endl << endl;
    }
//    cout << "Correct Greedy Strategy is Strategy 4";
    return 0;
}