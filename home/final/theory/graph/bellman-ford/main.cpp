#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>
#include <limits>
#include "graph.cpp"

template <class Vertex>
void bellmanFordSearch(Graph<Vertex>& map, Vertex start, Vertex target) {
    std::vector<Vertex> allVertices;
    std::queue<Vertex> discoverQ;
    std::unordered_map<Vertex, bool> visited;

    // 1. Discover all vertices via BFS
    discoverQ.push(start);
    visited[start] = true;
    allVertices.push_back(start);

    while (!discoverQ.empty()) {
        Vertex current = discoverQ.front();
        discoverQ.pop();

        std::queue<Vertex> neighbors;
        map.getToVertices(current, neighbors);
        while (!neighbors.empty()) {
            Vertex neighbor = neighbors.front();
            neighbors.pop();
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                discoverQ.push(neighbor);
                allVertices.push_back(neighbor);
            }
        }
    }

    // 2. Initialize Distances
    std::unordered_map<Vertex, int> distances;
    std::unordered_map<Vertex, Vertex> comeFrom;
    const int INF = std::numeric_limits<int>::max() / 2; 

    for (const Vertex& v : allVertices) {
        distances[v] = INF;
    }
    distances[start] = 0;
    comeFrom[start] = start;

    int V = allVertices.size();

    // 3. Relax all edges V - 1 times
    for (int i = 0; i < V - 1; ++i) {
        bool updated = false;
        for (const Vertex& u : allVertices) {
            if (distances[u] == INF) continue;

            std::queue<Vertex> neighbors;
            map.getToVertices(u, neighbors);

            while (!neighbors.empty()) {
                Vertex v = neighbors.front();
                neighbors.pop();

                int weight = map.weightIs(u, v);
                if (distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    comeFrom[v] = u;
                    updated = true;
                }
            }
        }
        if (!updated) break; 
    }

    // 4. Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (const Vertex& u : allVertices) {
        if (distances[u] == INF) continue;

        std::queue<Vertex> neighbors;
        map.getToVertices(u, neighbors);
        while (!neighbors.empty()) {
            Vertex v = neighbors.front();
            neighbors.pop();
            
            int weight = map.weightIs(u, v);
            if (distances[u] + weight < distances[v]) {
                hasNegativeCycle = true;
                break;
            }
        }
        if (hasNegativeCycle) break;
    }

    // 5. Path Reconstruction
    if (hasNegativeCycle) {
        std::cout << "Error: Graph contains a negative weight cycle." << std::endl;
        return;
    }

    if (distances.find(target) != distances.end() && distances[target] != INF) {
        std::cout << "\nShortest Path Discovered (Total Cost: " << distances[target] << "):\n";
        std::stack<Vertex> actualPath;
        Vertex current = target;

        while (current != start) {
            actualPath.push(current);
            current = comeFrom[current];
        }
        actualPath.push(start);

        while (!actualPath.empty()) {
            std::cout << actualPath.top();
            actualPath.pop();
            if (!actualPath.empty()) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "Path not found." << std::endl;
    }
}

void initialize(Graph<std::string>& worldMap) {
    try {
        worldMap.addVertex("Desolate Village");
        worldMap.addVertex("Cursed Woods");
        worldMap.addVertex("Ashen Plains");
        worldMap.addVertex("Whispering Bog");
        worldMap.addVertex("Ruined Keep");
        worldMap.addVertex("Forsaken Graveyard");
        worldMap.addVertex("Shattered Bridge");
        worldMap.addVertex("Bloodstained Altar");
        worldMap.addVertex("Rotting Marsh");
        worldMap.addVertex("Hollow Crypt");
        worldMap.addVertex("Obsidian Spire");
        worldMap.addVertex("Wraith's Peak");
        worldMap.addVertex("Serpent's Pass");
        worldMap.addVertex("Sunken City");
        worldMap.addVertex("Forgotten Catacombs");
        worldMap.addVertex("Crimson Citadel");
        worldMap.addVertex("Echoing Cavern");
        worldMap.addVertex("Abyssal Depths");
        worldMap.addVertex("Eldritch Void");
        worldMap.addVertex("Throne of Dust");

        worldMap.addEdge("Desolate Village", "Cursed Woods", 10);
        worldMap.addEdge("Desolate Village", "Ashen Plains", 15);
        worldMap.addEdge("Desolate Village", "Whispering Bog", 12);
        worldMap.addEdge("Cursed Woods", "Ruined Keep", 20);
        worldMap.addEdge("Cursed Woods", "Forsaken Graveyard", 15);
        worldMap.addEdge("Ashen Plains", "Shattered Bridge", 25);
        worldMap.addEdge("Ashen Plains", "Bloodstained Altar", 30);
        worldMap.addEdge("Whispering Bog", "Rotting Marsh", 18);
        worldMap.addEdge("Ruined Keep", "Hollow Crypt", 35);
        worldMap.addEdge("Ruined Keep", "Obsidian Spire", 40);
        worldMap.addEdge("Forsaken Graveyard", "Hollow Crypt", 20);
        worldMap.addEdge("Shattered Bridge", "Wraith's Peak", 45);
        worldMap.addEdge("Shattered Bridge", "Serpent's Pass", 30);
        worldMap.addEdge("Bloodstained Altar", "Crimson Citadel", 60);
        worldMap.addEdge("Rotting Marsh", "Sunken City", 35);
        worldMap.addEdge("Hollow Crypt", "Forgotten Catacombs", 40);
        worldMap.addEdge("Obsidian Spire", "Crimson Citadel", 50);
        worldMap.addEdge("Serpent's Pass", "Echoing Cavern", 45);
        worldMap.addEdge("Sunken City", "Echoing Cavern", 40);
        worldMap.addEdge("Forgotten Catacombs", "Abyssal Depths", 70);
        worldMap.addEdge("Echoing Cavern", "Eldritch Void", 80);
        worldMap.addEdge("Crimson Citadel", "Throne of Dust", 100);
        worldMap.addEdge("Abyssal Depths", "Eldritch Void", 50);
        worldMap.addEdge("Eldritch Void", "Throne of Dust", 60);
        worldMap.addEdge("Wraith's Peak", "Abyssal Depths", 90);
        
        std::cout << "Map initialization complete. 20 locations loaded.\n" << std::endl;
    } catch (FullGraph) {
        std::cerr << "Error: Graph capacity exceeded." << std::endl;
    } catch (EmptyGraph) {
        std::cerr << "Error: Graph is empty." << std::endl;
    }
}

int main() {
    Graph<std::string> worldMap(20);
    initialize(worldMap);
    
    std::string start = "Desolate Village";
    std::string target = "Throne of Dust";
    
    std::cout << "Executing Bellman-Ford Algorithm..." << std::endl;
    bellmanFordSearch(worldMap, start, target);
    
    return 0;
}