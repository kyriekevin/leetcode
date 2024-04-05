// @leet start
const int N = 19997;
typedef pair<int, int> PII;

#define x first
#define y second

class MyHashMap {
public:
  vector<PII> h[N];

  MyHashMap() {}

  int find(vector<PII> &h, int key) {
    for (int i = 0; i < h.size(); i++)
      if (h[i].x == key)
        return i;
    return -1;
  }

  void put(int key, int value) {
    int t = key % N;
    int k = find(h[t], key);
    if (k == -1)
      h[t].push_back({key, value});
    else
      h[t][k].y = value;
  }

  int get(int key) {
    int t = key % N;
    int k = find(h[t], key);
    if (k == -1)
      return -1;
    return h[t][k].y;
  }

  void remove(int key) {
    int t = key % N;
    int k = find(h[t], key);
    if (k != -1)
      h[t].erase(h[t].begin() + k);
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @leet end
