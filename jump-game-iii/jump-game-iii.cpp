class Solution {
    bool inside(int index, int n) {
        return (index >= 0 and index < n) ? true : false;
    }
    
    bool helper(vector<int>& arr, vector<int>& vis, int cur, int n) {
        
        if(arr[cur] == 0)
            return true;
        vis[cur] = 1;
        
        int left = cur - arr[cur];
        int right = arr[cur] + cur;
        
        if(inside(left, n) and cur != left and !vis[left] and left>=0) {
            if(helper(arr, vis, left, n))
                return true;
        }
        
        if(inside(right, n) and cur != right and !vis[right]) {
            if(helper(arr, vis, right, n))
                return true;
        }
        
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return helper(arr, vis, start, n) ? true : false;
    }
};

/*

4,2,3,0,3,1,2
0 1 2 3 4 5 6

inside() - if its false: im going out of bound

n - 1 = 6

start = 5
curIdx = 1
Positions to jump: (arr[arr[i] + i], arr[abs(i - arr[i])])
*/