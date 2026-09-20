#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void f(vector<string>& nums, int i, vector<string>& ans);
    string way1(vector<string>& nums) {
        vector<string>ans;
        f(nums, 0, ans);
        return *max_element(ans.begin(), ans.end());
    }
    void f(vector<string>& nums, int i, vector<string>&ans) {
        if (i == nums.size()) {
            string path;
            for (string n : nums) {
                path += n;
            }
            ans.push_back(path);
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            f(nums, i + 1, ans);
            swap(nums[i], nums[j]);
        }
    }
    bool cmp(string a, string b) {
        return a + b > b + a;
    }
    string way2(vector<string>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (string n : nums) {
            ans += n;
        }
        return ans;
    }
    string randomString(int maxLen) {
        int len = rand() % maxLen + 1;
        string ans;
        for (int i = 0; i < len; i++) {
            ans += to_string(rand() % 10);
        }
        return ans;
	}
    vector<string> largestNumber(int maxN,int maxLen) {
        int n = rand() % maxN + 1;
        vector<string>ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = randomString(maxLen);
        }
        return ans;
    }
    int main(){
		int times = 1000;
		cout << "test begin" << endl;
        for (int i = 0; i < times; i++) {
            vector<string> nums = largestNumber(6, 3);
            string ans1 = way1(nums);
            string ans2 = way2(nums);
            if (ans1 != ans2) {
                cout << "error!";
				cout << "nums: ";
                for (string n : nums) {
                    cout << n << " ";
                }
				cout << endl;
				cout << "ans1: " << ans1 << endl;
				cout << "ans2: " << ans2 << endl;
            }
        }
		cout << "test end" << endl;
    }
