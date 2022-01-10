#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
      vector<int> ans;
        deque<int> q;
        for(int i = 0 ; i < k ; i++){
            int v = arr[i];
            while(!q.empty() && q.back() < v) q.pop_back();
            q.push_back(v);
        }
        ans.push_back(q.front());
        for(int i = 0 , j = k ; j < n ; i++ , j++){
            if(arr[i] == q[0]) q.pop_front();
            int v = arr[j];
            while(!q.empty() && q.back() < v) q.pop_back();
            q.push_back(v);
            ans.push_back(q[0]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends