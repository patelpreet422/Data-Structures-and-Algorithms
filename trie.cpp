#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

struct tries {
    map<char, tries> trie;
    bool is_end = false;

    template <typename It>
    void insert(It b, It e) {
        if(b == e) {
            is_end = true;
            return;
        }
        trie[*b].insert(next(b), e);
    }

    size_t size() { return trie.size(); }

    void insert(const string& s) {
        insert(begin(s), end(s));
    }

    void insert_all(initializer_list<string> s) {
        for(auto&& str: s) insert(begin(str), end(str));
    }

    template <typename It>
    void remove(It b, It e) {
        if(b == e) {
            is_end = false;
        } else {
            auto found = trie.find(*b);
            if(found == trie.end()) return;
            found->second.remove(next(b), e);
        }
    }

    void remove(const string& s) {
        remove(begin(s), end(s));
    }

    void print(string& s) {
        if(is_end) {
            cout << s << '\n';
        }
        for(auto&& p: trie) {
            s += p.first;
            p.second.print(s);
            s.pop_back();
        }
    }

    void print() {
        string s = "";
        print(s);
    }

    template <typename It>
    bool contains(It b, It r) {
        if(b == r) return is_end;
        auto found = trie.find(*b);
        if(found == trie.end()) return false;
        return found->second.contains(next(b), r);
    }

    bool contains(const string& s) {
        return contains(begin(s), end(s));
    }

    template <typename It>
    void predecessor(It b, It e) {
        if(b == e) print();
        else {
            auto found = trie.find(*b);
            if(found == trie.end()) return;
            found->second.predecessor(next(b), e);
        }
    }

    void predecessor(const string& s) {
        predecessor(begin(s), end(s));
    }
};

int main() {
    tries trie;
    trie.insert_all(
            { "the", "a", "there",
                "answer", "any", "by",
                "bye", "their", "hero", "heroplane", "thes", "these"
            });
    cout << boolalpha << trie.contains("the") << '\n';
    trie.remove("these");
    cout << boolalpha << trie.contains("thes") << '\n';
    cout << boolalpha << trie.contains("these") << '\n';
    return 0;
}
