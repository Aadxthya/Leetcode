// Last updated: 9/16/2025, 9:51:06 AM
class MyCalendar {
public:
    vector<pair<int, int>> ranges;
    MyCalendar() {}
    bool book(int start, int end) {
        for (auto const& pair : ranges) {
            int r_start = pair.first;
            int r_end = pair.second;
            if (start < r_end && end > r_start)
                return false;
        }
        ranges.push_back(make_pair(start, end));
        return true;
    }
};