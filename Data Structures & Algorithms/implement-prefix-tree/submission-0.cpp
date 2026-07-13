class PrefixTree {
    struct PrefixTreeNode;
    using NodesMapping = map<char, PrefixTreeNode>;
    struct PrefixTreeNode {
        char ch;
        bool is_complete = false;
        NodesMapping children; 
    };

    PrefixTreeNode root{'#'};
public:
    PrefixTree() {}
    
    void insert(string_view word) {
        PrefixTreeNode *cur = &root;
        for (char ch : word) {
            if (!cur->children.contains(ch))
                cur->children[ch] = PrefixTreeNode{ch};
            
            cur = &cur->children[ch];
        }
            

        cur->is_complete = true;
    }
    
    bool search(string_view word) {
        const auto *cur = &root;
        for (char ch : word) {
            if (!cur->children.contains(ch)) 
                return false;
            
            cur = &cur->children.at(ch);
        }

        return cur->is_complete;
    }
    
    bool startsWith(string_view prefix) {
        const auto *cur = &root;
        for (char ch : prefix) {
            if (!cur->children.contains(ch)) 
                return false;
            
            cur = &cur->children.at(ch);
        }

        return true;
    }
};
