#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
using Graph = unordered_map<T, vector<T>>;

template <typename T>
void bfs(Graph<T> graph, T vertex)
{
  queue<T> to_be_processed;
  unordered_set<T> visited;
//  map<T, T> parent;
  to_be_processed.push(vertex);

  while(!to_be_processed.empty())
    {
      T current_vertex = to_be_processed.front();
      cout << current_vertex << "\n";
      to_be_processed.pop();
      visited.insert(current_vertex);

      for(auto child: graph[current_vertex])
        {
          if(visited.find(child) == visited.end())
            {
              to_be_processed.push(child);
//              parent[child] = current_vertex;
              visited.insert(child);
            }
        }
    }
}

template <typename T>
void dfs(Graph<T> graph, T vertex)
{
  stack<T> to_be_processed;
  unordered_set<T> visited;
  map<T, T> parent;
  to_be_processed.push(vertex);

  while(!to_be_processed.empty())
    {
      T current_vertex = to_be_processed.top();
      cout << current_vertex << "\n";
      to_be_processed.pop();
      visited.insert(current_vertex);

      for(auto child: graph[current_vertex])
        {
          if(visited.find(child) == visited.end())
            {
              to_be_processed.push(child);
              parent[child] = current_vertex;
              visited.insert(child);
            }
        }
    }
}

int main()
{
  Graph<char> graph {
    {'r', {'s', 'v'}},
    {'v', {'r'}},
    {'s', {'r', 'w'}},
    {'w', {'s', 't', 'x'}},
    {'t', {'w', 'x'}},
    {'x', {'w', 't', 'u', 'y'}},
    {'u', {'t', 'x', 'y'}}
  };

  dfs(graph, 'r');
  return 0;
}
