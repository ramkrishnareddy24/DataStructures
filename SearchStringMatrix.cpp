#include <vector>
#include <string>
#include <iostream>

using namespace std;

void searchCharacter(vector<vector<string>>& grid, char target) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j].find(target) != string::npos) {
                if (i > 1) {
                    cout << grid[i - 2][j][0] << grid[i - 1][j][0] << endl;
                } else if (i > 0) {
                    cout << grid[i - 1][j][0] << endl;
                } else {
                    cout << "N/A" << endl;
                }
                
                if (j > 1) {
                    cout << grid[i][j - 2][0] << grid[i][j - 1][0] << endl;
                } else if (j > 0) {
                    cout << grid[i][j - 1][0] << endl;
                } else {
                    cout << "N/A" << endl;
                }
                return;
            }
        }
    }
    
}

int main() {
    vector<vector<string>> grid = {{"A", "X", "D","E","R"}, {"S", "U", "J","Q","W"},{"Y","T","M","B","C"},{"O","L","F","G","H"}};
    char target = 'M';
    searchCharacter(grid, target);
    return 0;
}
