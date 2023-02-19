#include<vector>
#include<map>
#include<iostream>
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
bool sortDescending(const vector<int> &v1, const vector<int> &v2){
    if(v1[0] == v2[0])
        return v1[1] > v2[1];
    return v1[0] > v2[0];
}

vector<int> maximumHousesStrategy2(int n, vector<vector<int>> &houseAvailability) {
    // The function sorts the houses in decreasing order of their end times and gives an output accordingly
    int m = (int)houseAvailability.size();

    // We would need to perform sorting using custom sorting operation keeping in mind that sorting will change the order of houses
    // Hence using a hashmap to index the houses with correct index

    // Correcting this for testcase {{1,2}, {1,2}}
    for(int i = 0; i < m; i++){
        houseAvailability[i].push_back(i+1);
    }

    // Sorting the array using custom sort function defined above
    sort(houseAvailability.begin(), houseAvailability.end(), sortDescending);

    /* ====================== WE COULD USE A HASHMAP TO STORE WHAT DAYS HAS THE GUY WORKED TO CHECK EVERY DAY =============== */
    /* +++++++++++ HASHMAP THOUGHT TO BE ANALYZED AND IMPLEMENTED ++++++++++++++ */

    vector<int> res;
    int i = 0;
    int lastAvailableDay = n;
    while(i < m){
        if(lastAvailableDay >= houseAvailability[i][0] ){
            res.push_back(houseAvailability[i][2]);

            // Updating the last available day after considering first day into consideration
            lastAvailableDay = min(houseAvailability[i][1], lastAvailableDay) - 1;

            // if the available days for the painter are over, they can no longer paint any more houses and hence we end the loop.
            if(lastAvailableDay < 1) break;
        }
        i++;
    }



    // Finally sorting the resultant index array for sequential way
    sort(res.begin(), res.end());
    return res;
}

vector<int> maximumHousesStrategy3(int n, vector<vector<int>> &houseAvailability) {

}

int main() {
    // Taking user input for availability of painter and the total number of houses
    int n = 7, m = 8;
//    cout << "Enter the value of painter Availability: "; cin >> n;
//    cout << "Enter the number of houses present: "; cin >> m;

    // Taking user input for the availability times of houses when they can be painted
//    cout << "Enter the start and end house availability paint dates in each line: " << endl;
    vector<vector<int>> houseAvailability(m, vector<int> (2));
    houseAvailability = {{1,7}, {1,8}, {2,3}, {2,4}, {2,8}, {3,4}, {4, 5}, {5, 6}};

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