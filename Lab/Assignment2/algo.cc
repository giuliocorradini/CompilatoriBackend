#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef set<char> input_set_t;
typedef set<char> output_set_t;
typedef map<char, pair<output_set_t, input_set_t> > cfg_t;
typedef char node_t;
typedef set<char> dominator_set_t;

ostream &operator <<(ostream &out, set<char> const &s) {
    for (auto const &c: s) {
        out << c << " ";
    }
    return out;
}


set<char> transfer_function(char x, set<char> const &in) {
    auto gen = {x};
    set<char> out = {};

    set_union(gen.begin(), gen.end(), in.begin(), in.end(), inserter(out, out.end()));

    return out;
}

input_set_t meet(cfg_t const &cfg, map<node_t, dominator_set_t> &out, char x) {
    input_set_t in_for_x = {};
    auto const &[outs, ins] = cfg.at(x);

    if (ins.size() == 0)
        return {};
    
    cerr << "[meet] incoming edges: " << ins << endl;
    
    in_for_x = out[*ins.begin()];
    
    cerr << "in for x " << in_for_x << endl;

    for (auto in_bb = ins.begin(); in_bb != ins.end(); in_bb++) {
        input_set_t result = {};

        cerr << "[meet] merging outs of " << *in_bb << endl << " " << out[*in_bb] << endl;
        
        set_intersection(out[*in_bb].begin(), out[*in_bb].end(), in_for_x.begin(), in_for_x.end(), inserter(result, result.end()));
        cerr << "in for x " << in_for_x << endl;

        in_for_x = result;
    }
    return in_for_x;
}


int main() {

    cfg_t cfg = {
        {'A', {{'B', 'C'}, {}}},
        {'B', {{'G'}, {'A'}}},
        {'C', {{'D', 'E'}, {'A'}}},
        {'D', {{'F'}, {'C'}}},
        {'E', {{'F'}, {'C'}}},
        {'F', {{'G'}, {'D', 'E'}}},
        {'G', {{}, {'B', 'F'}}}
    };

    set<char> universe = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    map<node_t, dominator_set_t> out;
    out['A'] = {'A'};
    for (char c: "BCDEFG") {
        out[c] = universe;
    }

    const node_t entry = 'A';
    vector<node_t> queue = {};
    for(auto o: cfg[entry].first)
        queue.push_back(o);

    while (not queue.empty()) {
        node_t x = queue.front();
        queue.erase(queue.begin());

        auto const &[out_edges, in_edges] = cfg[x];

        cerr << x << "\n";

        auto in = meet(cfg, out, x);
        auto newout = transfer_function(x, in);

        cerr << "\tin dominator:" << in << "\n\tnew out dominators:" << newout << endl;

        if (newout != out[x]) {
            out[x] = newout;
            cerr << "updating out for " << x << " with " << out[x] << endl;
            for (auto out_bb: out_edges)
                queue.push_back(out_bb);
        }
    }

    for (auto const [bb, adj]: cfg) {
        cout << bb << ", out: " << out[bb] << endl;
    }

    return 0;
}