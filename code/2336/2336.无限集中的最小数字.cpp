class SmallestInfiniteSet {
private:
  int minv = 1;
  set<int> s;

public:
  SmallestInfiniteSet() {}

  int popSmallest() {
    if (s.empty()) {
      int ans = minv;
      minv++;
      return ans;
    }

    int t = *s.begin();
    s.erase(s.begin());
    return t;
  }

  void addBack(int num) {
    if (num < minv)
      s.insert(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
