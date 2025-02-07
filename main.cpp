#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> result;
vector<int> result2;
unordered_set<int> visited;

void dfs(map<int, vector<int>>& match, int R)
{
    visited.insert(R);
    result.push_back(R);

    for (int neighbor : match[R])  // `first_dot`을 사용하지 않음
    {
        if (visited.find(neighbor) == visited.end())
        {
            dfs(match, neighbor);
        }
    }
}

void bfs(map<int, vector<int>>& match, int R)
{
    unordered_set<int> local_visited;
    queue<int> q;

    q.push(R);
    local_visited.insert(R);
    result2.push_back(R);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : match[node])
        {
            if (local_visited.find(neighbor) == local_visited.end())
            {
                q.push(neighbor);
                local_visited.insert(neighbor);
                result2.push_back(neighbor);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, R;
    cin >> N >> M >> R;

    map<int, vector<int>> match;

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        match[u].push_back(v);
        match[v].push_back(u);  // 양방향 그래프 처리
    }

    // DFS 실행
    dfs(match, R);

    // DFS 결과 출력
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    // BFS 실행
    bfs(match, R);

    // BFS 결과 출력
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }
}
