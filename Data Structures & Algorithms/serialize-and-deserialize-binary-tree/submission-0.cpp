class Codec {
    int read_num(const string_view str) {
        int res = 0;
        for (int i = 0; i < str.size(); ++i) 
            res = res * 10 + (str[i] - '0');
        return res;
    }

    TreeNode* read_word(string_view& str) {
        TreeNode* res = nullptr;
        auto word_end = str.begin();
        for (
            ;
            word_end < str.end() && *word_end != ','; 
            ++word_end
        );

        const string_view word = {str.begin(), word_end};
        if (word.size() && word != "null") 
            res = new TreeNode(read_num(word));  
        str = {word_end + 1, str.end()};

        return res;
    }
public:
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> st; st.push(root);
        while (st.size()) {
            TreeNode* node = st.front(); st.pop();

            int nulls_counter = 0;
            while (node == nullptr) {
                if (st.empty()) return res;
                ++nulls_counter;
                node = st.front(); st.pop();
            }
            while (nulls_counter--) res += "null,";
            
            res += format("{},", node->val);
            st.push(node->left);
            st.push(node->right);
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string_view data) {
        TreeNode *res = read_word(data);
        queue<TreeNode*> q; q.push(res);

        while (q.size()) {
            auto cur = q.front(); q.pop();
            if (!cur) continue;

            q.push(cur->left = read_word(data));
            q.push(cur->right = read_word(data));
        }

        return res;
    }
};
