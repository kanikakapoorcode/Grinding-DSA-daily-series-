class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};