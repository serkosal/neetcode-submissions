class Solution {
    struct PrefixTree {
        struct Node;
        using NodesMapping = map<char, Node>;
        struct Node {
            char ch;
            bool is_complete = false;
            NodesMapping children; 
        };

        Node root{'#'};

        void insert(string_view word) {
            Node *cur = &root;
            for (char ch : word) {
                if (!cur->children.contains(ch))
                    cur->children[ch] = Node{ch};
                    
                cur = &cur->children[ch];
            }

            cur->is_complete = true;
        }
    };
    PrefixTree tree;
    unordered_map<string_view, bool> memo;
  public:
    bool wordBreak(
        string_view s, 
        const vector<string>& wordDict = {},
        PrefixTree::Node *cur = nullptr
    ) {
        if (s.size() == 0) return true;
        if (memo.contains(s)) return memo[s];
        bool res = false;

        for (const auto& word: wordDict) tree.insert(word);
        if (!cur) cur = &tree.root;

        for (int i = 0, sz = s.size(); i < sz && !res; ++i) {
            if (!cur->children.contains(s[i])) 
                break;

            if (cur->children[s[i]].is_complete)
                res += wordBreak({s.begin() + i + 1, s.end()}, {});

            cur = &cur->children[s[i]];
        }

        return memo[s] = res;
    }
};
