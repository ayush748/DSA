#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
vector<int> parent, sz;
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) {
        return;
    }
    if (sz[px] > sz[py]) {
        parent[py] = px;
        sz[px] += sz[py];
    } else {
        parent[px] = py;
        sz[py] += sz[px];
    }
}
int getSize(int x) {
    return sz[find(x)];
}
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int totalCells = n * n;
    parent.resize(totalCells);
    sz.assign(totalCells, 1);
    for (int i = 0; i < totalCells; i++) {
        parent[i] = i;
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int idx = i * n + j;
                for (auto &d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        int nidx = ni * n + nj;
                        Union(idx, nidx);
                    }
                }
            }
        }
    }
    for (int idx = 0; idx < totalCells; idx++) {
        if (grid[idx / n][idx % n] == 1) {
            maxArea = max(maxArea, getSize(idx));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                unordered_set<int> st;
                for (auto &d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni >= 0 && ni < n &&
                        nj >= 0 && nj < n &&
                        grid[ni][nj] == 1) {
                        int nidx = ni * n + nj;
                        st.insert(find(nidx));
                    }
                }
                int area = 1;
                for (auto p : st) {
                    area += getSize(p);
                }
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << largestIsland(grid) << endl;
    return 0;
}

