#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> distances;

int read_input() {
    ifstream fin("graph.txt");
    if (!fin.is_open()) {
        cerr << "Error: Could not open file\n";
        return -1;
    }
    int vertices;
    int edges;
    fin >> vertices >> edges;
    graph.resize(vertices);
    for (int i = 0; i < edges; i++) {
        int from, to;
        fin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int start;
    fin >> start;
    return start;
}

void bfs(int start) {
    distances.resize((int)graph.size(), (int)graph.size());
    queue<int> q;
    distances[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (int to : graph[from]) {
            if (distances[from] + 1 < distances[to]) {
                distances[to] = distances[from] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int vertex = read_input();
    if (vertex != -1) {
        bfs(vertex);
        for (int distance : distances) {
            cout << distance << endl;
        }
    }
    return 0;
}

