class SegmentTree {
  SegmentTree *left, *right;
  int L, R, val;
    
  public:
  SegmentTree(vector<int>& nums, int l, int r) : L(l), R(r), left(NULL), right(NULL) {
      build(nums);
  }
    
  void build(vector<int>& nums) {
      if(L == R) {
          val = nums[R];
          return;
      }
      
      int mid = (L + R)/2;
      left = new SegmentTree(nums, L, mid);
      right = new SegmentTree(nums, mid + 1, R);
      val = left->val + right->val;
  }
    
  void update(int i, int newVal) {
      if(L == R) {
          val = newVal;
          return;
      }
      
      int mid = (L + R)/2;
      if(i <= mid) left->update(i, newVal);
      else right->update(i, newVal);
      val = left->val + right->val;
  }
    
  int sum(int l, int r) {
      if(l > r) return 0;
      if(l == L and r == R) return val;
      int mid = (L + R)/2;
      return left->sum(l, min(mid, r)) + right->sum(max(mid + 1, l), r);
  }
    
};

class NumArray {
SegmentTree* tree;
public:
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        tree->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree->sum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */