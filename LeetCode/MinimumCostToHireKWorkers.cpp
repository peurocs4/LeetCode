#ifndef MinimumCostToHireKWorkers_h__
#define MinimumCostToHireKWorkers_h__


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

class Solution {
public:
  struct Worker {
    int quality;
    int wage;
    double rate;

    Worker(int quality, int wage, double rate) 
      :quality(quality), wage(wage), rate(rate) {}
  };

  struct RateComparator {
    bool operator()(const Worker& worker1, const Worker& worker2) const {
      return worker1.rate < worker2.rate;
    }
  };

  struct QualityComparator {
    bool operator()(const Worker& worker1, const Worker& worker2) const {
      return worker1.quality <= worker2.quality;
    }
  };

  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    vector<Worker> workers;

    for (int i = 0; i < quality.size(); ++i) {
      const auto& q = quality[i];
      const auto& w = wage[i];
      const auto r = static_cast<double>(w) / q;
      workers.push_back(*new Worker(q, w, r));
    }

    sort(workers.begin(), workers.end(), RateComparator());

    set<Worker, QualityComparator> s;
    double minCost = static_cast<double>(INT_MAX);
    for (int i = 0; i < workers.size(); ++i) {
      const auto& worker = workers[i];

      if (i >= K - 1) {
        int accumQuality = worker.quality;
        auto it = s.begin();
        for (int j = 1; j < K; ++j) {
          accumQuality += it->quality;
          ++it;
        }

        double cost = accumQuality * worker.rate;
        minCost = min(minCost, cost);
      }

      s.insert(worker);
    }

    return minCost;
  }
};


#endif // MinimumCostToHireKWorkers_h__