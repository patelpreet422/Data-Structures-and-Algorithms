#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

enum State { UNDISCOVERED, BEING_ASSIGNED_SCC, ASSIGNED_SCC };

int c = 0;
vector<vector<int>> g;
vector<int> id, low;
vector<State> state;
stack<int> stk;
vector<vector<int>> components;

void dfs(int v) {
  state[v] = BEING_ASSIGNED_SCC;
  id[v] = low[v] = c++;
  stk.push(v);

  for (auto e : g[v]) {
    if (state[e] == UNDISCOVERED) {
      dfs(e);
      low[v] = min(low[v], low[e]);
    }

    /*
    Note that v.lowlink := min(v.lowlink, w.index) is the correct way to update v.lowlink if w is on stack. Because w is on the stack already, (v, w) is a back-edge in the DFS tree and therefore w is not in the subtree of v. Because v.lowlink takes into account nodes reachable only through the nodes in the subtree of v we must stop at w and use w.index instead of w.lowlink.
    It must be noted that if we update the low link on as soon as the back edge is encountered we may end-up with wrong number of scc's.
    This is because the value of low is highly dependant on the order in which we perform the dfs and to prevent this from happening we use 
    Tarjan's invariant which is the meat of the algorithm which prevents us from labeling nodes incorrectly.
    
    The invariant says that we update the low value of a node on encounter a tree edge or only if the child node is part of back edge (i.e, the node has yet been traversed completely)
    we do not update the low link in case of forward edge and cross edge
    
    */
    if (state[e] == BEING_ASSIGNED_SCC) {
      low[v] = min(low[v], id[e]);
    }
  }

  if (id[v] == low[v]) {
    vector<int> comp;
    while (true) {
      int top = stk.top();
      stk.pop();
      state[top] = ASSIGNED_SCC;
      comp.push_back(top);
      if (top == v) {
        break;
      }
    }
    components.push_back(comp);
  }
}

void scc() {
  for (int i = 0; i < g.size(); ++i) {
    if (state[i] == UNDISCOVERED) {
      dfs(i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  low.assign(n, -1);
  id.assign(n, -1);
  state.assign(n, UNDISCOVERED);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  scc();

  for (auto &comp : components) {
    for (auto e : comp) {
      cout << e << ", ";
    }
    cout << '\n';
  }

  return 0;
}
