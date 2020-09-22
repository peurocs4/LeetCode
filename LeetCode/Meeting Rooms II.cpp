#ifndef Meeting_Rooms_II_h__
#define Meeting_Rooms_II_h__



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  struct Comparator {
    bool operator()(const vector<int>& vector1, const vector<int>& vector2) {
      if (vector1[0] == vector2[0]) {
        return vector1[1] < vector2[1];
      }
      return vector1[0] < vector2[0];
    }
  };

  int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), Comparator());
    print(intervals);

    vector<int> roomEndTimes;

    for (const auto& interval : intervals) {
      const auto& start = interval[0];
      const auto& end = interval[1];

      int minIndex = -1;
      for (int i = 0; i < roomEndTimes.size(); ++i) {
        if (roomEndTimes[i] <= start) {
          minIndex = i;
          break;
        }
      }

      if (minIndex == -1) {
        roomEndTimes.push_back(end);
      }
      else {
        roomEndTimes[minIndex] = end;
      }
    }

    return roomEndTimes.size();
  }
};



void print(vector<vector<int>>& intervals) {
  for (const auto& item : intervals) {
    cout << item[0] << ", " << item[1] << endl;
  }
}



#endif // Meeting_Rooms_II_h__