#define x first
#define y second

class RangeModule {
private:
  map<int, int> mp;

public:
  RangeModule() {}

  void addRange(int left, int right) {
    int l = left, r = right;
    auto p = mp.lower_bound(left);
    while (p != mp.end() && p->y <= right) {
      l = min(l, p->y);
      r = max(r, p->x);
      mp.erase(p++);
    }

    mp[r] = l;
  }

  bool queryRange(int left, int right) {
    auto p = mp.lower_bound(left);
    if (p == mp.end())
      return false;
    if (p->y <= left && p->x >= right)
      return true;
    return false;
  }

  void removeRange(int left, int right) {
    auto p = mp.lower_bound(left + 1);
    while (p != mp.end() && p->y <= right) {
      if (p->y < left)
        mp[left] = p->y;
      if (p->x > right) {
        mp[p->x] = right;
        break;
      } else
        mp.erase(p++);
    }
  }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
