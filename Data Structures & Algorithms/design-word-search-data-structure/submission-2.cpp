class WordDictionary {
    struct TrieNode;
    using NodesMapping = map<char, TrieNode>;
    struct TrieNode {
        char ch;
        bool is_complete = false;
        NodesMapping children; 
    };

    TrieNode root{'#'};
public:
    WordDictionary() {}
    
    void addWord(string_view word) {
        TrieNode *cur = &root;
        for (char ch : word) {
            if (!cur->children.contains(ch))
                cur->children[ch] = TrieNode{ch};
            
            cur = &cur->children[ch];
        }

        cur->is_complete = true;
    }
    
    bool search(string_view word) {
        queue<pair<TrieNode*, string_view>> q;
        q.push({&root, word});

        while (q.size()) {
            auto [node, pattern] = q.front(); q.pop();

            if (pattern.size() == 0) {
                if (node->is_complete) return true;
            }
            else {
                const char ch = pattern[0];
                pattern = {pattern.begin() + 1, pattern.end()};
                if (ch == '.')
                    for (auto& [_, value] : node->children) 
                        q.push({
                            &value, 
                            pattern
                        });
                else if (node->children.contains(ch))
                    q.push({
                        &node->children[ch], 
                        pattern
                    });
            }
        }

        return false;
    }
};
