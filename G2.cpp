class Solution {
public:
    string decodeString(string s) {
        stack<int> nums, braces;
        stack<string> strs;
        strs.push("");

        int num = 0;
        for (int i = 0, n = s.size(); i <= n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num*10+s[i]-'0';
            } else if (s[i] == '[') {
                nums.push(num); num = 0;
                braces.push(i);
                strs.push("");
            } else if (s[i] == ']') {
                braces.pop();
                string s = strs.top(); strs.pop();
                int count = nums.top(); nums.pop();

                while (count--) strs.top() += s;
            } else {
                strs.top().push_back(s[i]);
            }
        }

        return strs.top();
    }
};