class Solution {
public:
struct Candidate {
    span<int> coins;
    int amount;
    int k = 0;
};
struct CandidateComparator {
    bool operator()(const Candidate& a, const Candidate& b) {
        if (a.k != b.k)
            return a.k > b.k;
        else if (a.amount != b.amount)
            return a.amount > b.amount;
        else
            return a.coins.size() < b.coins.size();
    }
};

int coinChange(span<int> coins, int amount) {
    sort(coins.begin(), coins.end());
            
    priority_queue<Candidate, std::vector<Candidate>, CandidateComparator> q; 
    q.push({coins, amount, 0});
    while(q.size()) {
        auto [cns, sum, k] = q.top(); q.pop();
        
        if (sum == 0) return k;
        if (cns.empty()) continue;

        q.push({ {cns.begin(), cns.end() - 1}, sum, k });

        if (cns.back() <= sum)
            q.push({cns, sum - cns.back(), k + 1});
    }

    return -1;
}
};
