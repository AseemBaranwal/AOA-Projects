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

// Custom Sort function for the strategy 3
class sortSmallestDuration{
public:
    bool operator() (vector<int> &v1, vector<int> &v2){
        // First index signifies the start date, second index signifies the end date
        // The third index signifies the index at which the particular house appears in original array

        // sorted based on ascending duration which is difference of end day and start day
        return v1[1] - v1[0] > v2[1] - v2[0];
    }
};

// Custom Sort function for the strategy 4 & 5
class sortSmallestEndDay{
public:
    bool operator() (vector<int> &v1, vector<int> &v2){
        // First index signifies the start date, second index signifies the end date
        // The third index signifies the index at which the particular house appears in original array

        // sorted based on the smallest ending times to paint house that will stop being available the earliest
        return v1[1] > v2[1];
    }
};

vector<int> maximumHousesStrategy1(int n, vector<vector<int>> houseAvailability) {
    // The function sorts the houses in increasing order of their start times and gives an output accordingly
    // Given that the houses are already sorted according to their start dates so no sorting is required

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    vector<int> res;

    // Using a Queue to Makefile sure that we use a complexity of O(N)
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

vector<int> maximumHousesStrategy2(int n, vector<vector<int>> houseAvailability) {
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

vector<int> maximumHousesStrategy3(int n, vector<vector<int>> houseAvailability) {
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

vector<int> maximumHousesStrategy4(int n, vector<vector<int>> houseAvailability) {
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

vector<int> maximumHousesStrategy5(int n, vector<vector<int>> &houseAvailability) {
    // The function gets all the houses who have an availability at a given day and then selects the houses having the minimum Ending time

    // Using indexes to keep track of duplicated testcase {{1,2}, {1,2}}
    for(int i = 0; i < (int)houseAvailability.size(); i++){
        houseAvailability[i].push_back(i+1);
    }

    // minHeap
    priority_queue<vector<int>, vector<vector<int>>, sortSmallestEndDay> pq;

    // Variables to keep track of the last executed job and the resultant answer
    int idx = 0;
    vector<int> res;

    // Inserting all houses into the priority queue which have an availability at a given day
    int currentDay = houseAvailability[idx][0];
    while(idx < houseAvailability.size() and houseAvailability[idx][0] <= currentDay){
        pq.push(houseAvailability[idx]);
        idx++;
    }

    while(currentDay <= n and (!pq.empty() or idx < houseAvailability.size())){
        // Updating the current day to next day possible from pq.top()[0] if it exists else take from nextAvailable house else end
        if(!pq.empty()){
            currentDay = max(currentDay, pq.top()[0]);
        }else if(houseAvailability[idx][0] <= n){
            currentDay = max(currentDay, houseAvailability[idx][0]);
        }else{
            break;
        }

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

        // updating the current day after current day has been used up
        currentDay ++;
    }
    return res;
}

int main() {
    // Taking user input for availability of painter and the total number of houses
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << tc << endl;
        int n, m;
        cin >> n >> m;

        // Taking user input for the availability times of houses when they can be painted
        vector<vector<int>> houseAvailability(m, vector<int> (2));

        for(int i = 0; i < m; i++) {
            cin >> houseAvailability[i][0] >> houseAvailability[i][1];
        }

        // Result of strategy 1 below
        vector<int> res = maximumHousesStrategy1(n, houseAvailability);
        cout << "Count by Strategy 1: " << res.size() << endl;
        cout << "Indexes returned by strategy 1: ";
        for (int &re: res)
            cout << re << " ";
        cout << endl;

        // Result of strategy 2 below
        res = maximumHousesStrategy2(n, houseAvailability);
        cout << "Count by Strategy 2: " << res.size() << endl;
        cout << "Indexes returned by strategy 2: ";
        for (int &re: res)
            cout << re << " ";
        cout << endl;

        // Result of strategy 3 below
        res = maximumHousesStrategy3(n, houseAvailability);
        cout << "Count by Strategy 3: " << res.size() << endl;
        cout << "Indexes returned by strategy 3: ";
        for (int &re: res)
            cout << re << " ";
        cout << endl;

        // Result of strategy 4 below
        vector<int> res1 = maximumHousesStrategy4(n, houseAvailability);
        cout << "Count by Strategy 4: " << res1.size() << endl;
        cout << "Indexes returned by strategy 4: ";
        for (int &re: res1)
            cout << re << " ";
        cout << endl;

        // Result of strategy 5 below
        vector<int> res2 = maximumHousesStrategy5(n, houseAvailability);
        cout << "Count by Strategy 5: " << res2.size() << endl;
        cout << "Indexes returned by strategy 5: ";
        for (int &re: res2)
            cout << re << " ";
        cout << endl << endl;
//        if(res1.size() == res2.size()){
//            for(int i = 0; i < res1.size(); i++){
//                if(res1[i] != res2[i]){
//                    cout << "Difference at " << i << " Str4 gives " << res1[i] << " Str5 gives " << res2[i] << endl;
//                    cout << t << endl;
//                    break;
//                }
//            }
//        }else{
//            cout << "Different sizes" << endl;
//            cout << t << endl;
//            continue;
//        }
    }
    return 0;
}