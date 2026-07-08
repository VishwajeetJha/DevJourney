#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    string to;
    int weight;

    Edge(const string& to, int weight) : to(to), weight(weight) {}
};

struct NodeDistance {
    string node;
    int distance;

    NodeDistance(const string& node, int distance) : node(node), distance(distance) {}

    bool operator>(const NodeDistance& other) const {
        return distance > other.distance;
    }
};

struct PathResult {
    vector<string> path;
    int totalCost;

    PathResult(const vector<string>& path, int totalCost) : path(path), totalCost(totalCost) {}
};

class Graph {
private:
    map<string, vector<Edge>> adjacency;

public:
    void addEdge(const string& from, const string& to, int weight) {
        adjacency[from].push_back(Edge(to, weight));
        adjacency[to].push_back(Edge(from, weight));
    }

    PathResult shortestPath(const string& source, const string& destination) {
        map<string, int> distance;
        map<string, string> parent;

        for (const auto& pair : adjacency) {
            distance[pair.first] = INT_MAX;
        }
        distance[source] = 0;

        priority_queue<NodeDistance, vector<NodeDistance>, greater<NodeDistance>> pq;
        pq.push(NodeDistance(source, 0));

        while (!pq.empty()) {
            NodeDistance current = pq.top();
            pq.pop();

            if (current.distance != distance[current.node]) {
                continue;
            }

            for (const auto& edge : adjacency[current.node]) {
                int candidate = current.distance + edge.weight;
                if (candidate < distance[edge.to]) {
                    distance[edge.to] = candidate;
                    parent[edge.to] = current.node;
                    pq.push(NodeDistance(edge.to, candidate));
                }
            }
        }

        if (distance.find(destination) == distance.end() || distance[destination] == INT_MAX) {
            return PathResult(vector<string>(), INT_MAX);
        }

        vector<string> path;
        string cursor = destination;
        while (!cursor.empty()) {
            path.push_back(cursor);
            if (parent.find(cursor) != parent.end()) {
                cursor = parent[cursor];
            } else {
                cursor = "";
            }
        }
        reverse(path.begin(), path.end());

        return PathResult(path, distance[destination]);
    }
};

int main(int argc, char* argv[]) {
    Graph cityMap;
    cityMap.addEdge("A", "B", 4);
    cityMap.addEdge("A", "C", 2);
    cityMap.addEdge("B", "C", 1);
    cityMap.addEdge("B", "D", 5);
    cityMap.addEdge("C", "D", 8);
    cityMap.addEdge("C", "E", 10);
    cityMap.addEdge("D", "E", 2);
    cityMap.addEdge("D", "F", 6);
    cityMap.addEdge("E", "F", 3);

    string source = argc > 1 ? argv[1] : "A";
    string destination = argc > 2 ? argv[2] : "F";

    PathResult result = cityMap.shortestPath(source, destination);

    cout << "=== Dijkstra Route Planner ===" << endl;
    cout << "Nodes: A B C D E F" << endl;
    if (result.totalCost == INT_MAX) {
        cout << "No route found from " << source << " to " << destination << endl;
    } else {
        cout << "Best route from " << source << " to " << destination << ": ";
        for (size_t i = 0; i < result.path.size(); i++) {
            if (i > 0) cout << " -> ";
            cout << result.path[i];
        }
        cout << endl;
        cout << "Total cost: " << result.totalCost << endl;
    }

    return 0;
}
