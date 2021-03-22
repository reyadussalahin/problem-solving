// problem name: Number of Orders in the Backlog
// problem link: https://leetcode.com/contest/weekly-contest-233/problems/number-of-orders-in-the-backlog/
// contest link: https://leetcode.com/contest/weekly-contest-233/
// time: (?)
// author: reyad


// other_tags: segment tree
// difficulty_level: beginner



class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int, long long> buy_backlog;
        map<int, long long> sell_backlog;
        int order_length = (int)orders.size();
        for(int i=0; i<order_length; i++) {
            if(orders[i][2] == 0) { // i.e. type is `buy`
                while(!sell_backlog.empty()) {
                    auto smallest_sell = sell_backlog.begin();
                    if(smallest_sell->first <= orders[i][0]) {
                        long long reduce = min((long long)orders[i][1], smallest_sell->second);
                        orders[i][1] -= (int)reduce;
                        smallest_sell->second -= reduce;
                        if(smallest_sell->second == 0) {
                            sell_backlog.erase(smallest_sell);
                        }
                        if(orders[i][1] == 0) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if(orders[i][1]) {
                    buy_backlog[orders[i][0]] += (long long)orders[i][1];
                }
            } else { // i.e. type is `sell`
                while(!buy_backlog.empty()) {
                    auto largest_buy = buy_backlog.end();
                    largest_buy--;
                    if(largest_buy->first >= orders[i][0]) {
                        long long reduce = min((long long)orders[i][1], largest_buy->second);
                        orders[i][1] -= (int)reduce;
                        largest_buy->second -= reduce;
                        if(largest_buy->second == 0) {
                            buy_backlog.erase(largest_buy);
                        }
                        if(orders[i][1] == 0) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if(orders[i][1]) {
                    sell_backlog[orders[i][0]] += (long long)orders[i][1];
                }
            }
        }
        long long ans = 0;
        for(auto it: buy_backlog) {
            ans += it.second;
        }
        for(auto it: sell_backlog) {
            ans += it.second;
        }
        printf("ans: %lld", ans);
        return (ans % (int)(1e9+7));
    }
};