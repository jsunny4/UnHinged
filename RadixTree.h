#ifndef RadixTree_h
#define RadixTree_h
#include <vector>
#include <map>

template <typename ValueType>
class RadixTree {
public:
    RadixTree() {
        root = nullptr;
    }
    ~RadixTree() {
        clear(root);
    }
    void print() {
        PostOrder(root);
    }
    void insert(std::string key, const ValueType& value) {
        Node* cur = root;
        std::string curWord = key;
        while (curWord.size() != 0) {
            if (cur == nullptr) {
                root = new Node("");
                root->children[curWord[0]] = new Node(curWord.substr(1, curWord.size()), value, true);
                curWord = "";
            }
            else {
                int i = 0;
                for (; i < cur->str.size() && i < curWord.size(); i++) {
                    if (cur->str[i] != curWord[i]) {
                        break;
                    }
                }
                if (i == cur->str.size()) {
                    curWord = curWord.substr(i, curWord.size());
                    if (curWord == "") {
                        cur->end = true;
                        cur->val = value;
                    }
                    else {
                        if (cur->children[curWord[0]] == nullptr) {
                            cur->children[curWord[0]] = new Node(curWord.substr(1, curWord.size()), value, true);
                            curWord = "";
                        }
                        else {
                            cur = cur->children[curWord[0]];
                            curWord = curWord.substr(1, curWord.size());
                            if (curWord == "") {
                                cur->end = true;
                                cur->val = value;
                            }
                        }
                    }
                }
                else {
                    Node* n = new Node(cur->str.substr(i + 1, cur->str.size()), cur->val, cur->end);
                    for (int j = 0; j < 128; j++) {
                        n->children[j] = cur->children[j];
                        cur->children[j] = nullptr;
                    }
                    cur->children[cur->str[i]] = n;
                    cur->str = cur->str.substr(0, i);
                    if (curWord.size() != i) {
                        cur->children[curWord[i]] = new Node(curWord.substr(i + 1, curWord.size()), value, true);
                        cur->val = ValueType();
                        cur->end = false;
                    }
                    else {
                        cur->val = value;
                        cur->end = true;
                    }
                    curWord = "";
                }
            }
        }
    }
    
    ValueType* search(std::string key) const {
        Node* cur = root;
        std::string curWord = key;
        while (curWord.size() != 0) {
            if (cur != nullptr && cur->str.size() <= curWord.size() && cur->str == curWord.substr(0, cur->str.size())) {
                if (cur->str.size() == curWord.size()) {
                    break;
                }
                std::string temp = curWord;
                curWord = curWord.substr(cur->str.size() + 1, curWord.size());
                cur = cur->children[temp[cur->str.size()]];
            }
            else {
                return nullptr;
            }
        }
        if (cur->end) {
            return &cur->val;
        }
        return nullptr;
    }
private:
    struct Node {
        Node(std::string s, ValueType v, bool b) : str(s), val(v), end(b) {};
        Node(std::string s, ValueType v) : str(s), val(v), end(false) {};
        Node(std::string s) : str(s), end(false)  {};
        std::string str;
        ValueType val;
        bool end;
        Node* children[128] = {nullptr};
    };
    Node* root;
    void clear(Node* n) {
        if (n == nullptr) {
            return;
        }
        for (int i = 1; i < 128; i++) {
            clear(n->children[i]);
        }
        delete n;
    }

    void PostOrder(Node *cur)
    {
    if (cur == nullptr) // if empty, return...
    return;
        for (auto i: cur->children) {
            PostOrder(i);
        }
    std::cout << cur-> str << " " << cur->val << std::endl; // Process the current node.
    }
};

#endif
