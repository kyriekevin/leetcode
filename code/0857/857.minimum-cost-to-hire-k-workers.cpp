// @leet start
typedef pair<double, int> PDI;

#define x first
#define y second

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    vector<PDI> q;
    priority_queue<int> heap;

    for (int i = 0; i < quality.size(); i++) {
      q.push_back({(double)wage[i] / quality[i], quality[i]});
    }
    sort(q.begin(), q.end());

    double res = 1e18, sum = 0;
    for (auto &p : q) {
      heap.push(p.y);
      sum += p.y;

      if (heap.size() > k) {
        sum -= heap.top();
        heap.pop();
      }

      if (heap.size() == k)
        res = min(res, sum * p.x);
    }

    return res;
  }
};
// @leet end
