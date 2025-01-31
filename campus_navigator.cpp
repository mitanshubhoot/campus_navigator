#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

/*
Campus Navigation System
- The grid represents a campus map with open paths (-), obstacles (|), and the shortest path (*).
- Landmarks are represented with their respective initials.
- You will first see the map, then choose your current landmark and destination.
- The program calculates and displays the optimal path using A* algorithm.
- Legend:
  L = Library
  C = Cafeteria
  H = Hostel
  A = Auditorium
  G = Gymnasium
  M = Main Gate
  S = Science Block
  T = Technology Center
  D = Dormitory
  P = Parking Lot
  F = Football Field
  R = Research Center
  B = Basketball Court
  N = Nursing Block
  O = Office Block
*/

struct Node {
    int x, y;
    double g, h;
    Node* parent;
    
    Node(int x, int y, double g, double h, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}
    
    double f() const { return g + h; }
};

struct CompareNode {
    bool operator()(const Node* a, const Node* b) {
        return a->f() > b->f();
    }
};

class CampusMapNavigator {
private:
    vector<vector<int>> grid; 
    map<pair<int, int>, char> landmarks;
    map<pair<int, int>, double> terrainWeights;
    int rows, cols;

    double heuristic(int x1, int y1, int x2, int y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
    
    vector<pair<int, int>> getNeighbors(int x, int y) {
        vector<pair<int, int>> neighbors = {
            {x-1, y}, {x+1, y}, {x, y-1}, {x, y+1},
            {x-1, y-1}, {x-1, y+1}, {x+1, y-1}, {x+1, y+1}
        };
        
        vector<pair<int, int>> validNeighbors;
        for (auto [nx, ny] : neighbors) {
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0) {
                validNeighbors.emplace_back(nx, ny);
            }
        }
        return validNeighbors;
    }
    
public:
    CampusMapNavigator(vector<vector<int>> mapGrid, map<pair<int, int>, char> mapLandmarks, map<pair<int, int>, double> terrain)
        : grid(mapGrid), landmarks(mapLandmarks), terrainWeights(terrain) {
        rows = grid.size();
        cols = grid[0].size();
    }
    
    vector<pair<int, int>> findPath(pair<int, int> start, pair<int, int> end) {
        priority_queue<Node*, vector<Node*>, CompareNode> openSet;
        unordered_map<int, Node*> allNodes;
        set<pair<int, int>> closedSet;
        
        Node* startNode = new Node(start.first, start.second, 0, heuristic(start.first, start.second, end.first, end.second));
        openSet.push(startNode);
        allNodes[start.first * cols + start.second] = startNode;
        
        while (!openSet.empty()) {
            Node* current = openSet.top();
            openSet.pop();
            
            if (current->x == end.first && current->y == end.second) {
                vector<pair<int, int>> path;
                while (current) {
                    path.emplace_back(current->x, current->y);
                    current = current->parent;
                }
                reverse(path.begin(), path.end());
                return path;
            }
            
            closedSet.insert({current->x, current->y});
            
            for (auto [nx, ny] : getNeighbors(current->x, current->y)) {
                if (closedSet.count({nx, ny})) continue;
                
                double terrainCost = terrainWeights.count({nx, ny}) ? terrainWeights[{nx, ny}] : 1.0;
                double gNew = current->g + heuristic(current->x, current->y, nx, ny) * terrainCost;
                int key = nx * cols + ny;
                
                if (!allNodes.count(key) || gNew < allNodes[key]->g) {
                    Node* neighbor = new Node(nx, ny, gNew, heuristic(nx, ny, end.first, end.second), current);
                    openSet.push(neighbor);
                    allNodes[key] = neighbor;
                }
            }
        }
        return {}; 
    }
    
    void displayMap(vector<pair<int, int>> path = {}) {
        cout << "\nCampus Grid:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (landmarks.count({i, j})) cout << landmarks[{i, j}] << " ";
                else if (grid[i][j] == 1) cout << "| ";
                else if (!path.empty() && find(path.begin(), path.end(), make_pair(i, j)) != path.end()) cout << "* ";
                else cout << "- ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> campusGrid(40, vector<int>(40, 0));
    
    map<pair<int, int>, char> campusLandmarks = {
        {{1, 2}, 'L'}, {{5, 6}, 'C'}, {{10, 8}, 'H'}, {{12, 15}, 'A'},
        {{18, 22}, 'G'}, {{25, 10}, 'M'}, {{30, 5}, 'S'}, {{35, 25}, 'T'},
        {{38, 12}, 'D'}, {{39, 30}, 'P'}, {{8, 18}, 'F'}, {{20, 35}, 'R'},
        {{28, 22}, 'B'}, {{33, 14}, 'N'}, {{15, 28}, 'O'}
    };
    
    CampusMapNavigator navigator(campusGrid, campusLandmarks, {});
    navigator.displayMap();
    
    char startLandmark, endLandmark;
    cout << "\nEnter the initial landmark letter: ";
    cin >> startLandmark;
    cout << "Enter the destination landmark letter: ";
    cin >> endLandmark;
    
    pair<int, int> start, end;
    for (const auto& landmark : campusLandmarks) {
        if (landmark.second == startLandmark) start = landmark.first;
        if (landmark.second == endLandmark) end = landmark.first;
    }
    
    vector<pair<int, int>> path = navigator.findPath(start, end);
    
    if (!path.empty()) {
        cout << "\nOptimal Path: \n";
        navigator.displayMap(path);
    } else {
        cout << "No Path Found" << endl;
    }
    return 0;
}
