#include <iostream>
#include <string>
#include <queue>
#include "graph.cpp"

// Paste your template class here, or #include "Graph.h" if saved separately

int main() {
    try {
        // Initialize graph with a max capacity of 10 zones
        Graph<std::string> worldMap(10);

        // 1. Add game locations (Vertices)
        worldMap.addVertex("Desolate Village");
        worldMap.addVertex("Cursed Woods");
        worldMap.addVertex("Ruined Keep");
        worldMap.addVertex("Abyssal Depths");

        // 2. Create connecting paths (Edges) with travel danger/distance (Weights)
        // Directed graph: You can enter the woods from the village, but maybe not go back the same way
        worldMap.addEdge("Desolate Village", "Cursed Woods", 5);
        worldMap.addEdge("Desolate Village", "Ruined Keep", 15);
        worldMap.addEdge("Cursed Woods", "Abyssal Depths", 50);
        worldMap.addEdge("Ruined Keep", "Abyssal Depths", 30);
        
        // Two-way path example
        worldMap.addEdge("Ruined Keep", "Desolate Village", 15);

        // 3. Test edge weight retrieval
        std::cout << "--- Travel Costs ---" << std::endl;
        std::cout << "Village to Woods: " 
                  << worldMap.weightIs("Desolate Village", "Cursed Woods") << std::endl;
        std::cout << "Woods to Village (No Path): " 
                  << worldMap.weightIs("Cursed Woods", "Desolate Village") << std::endl;

        // 4. Test neighbor retrieval
        std::cout << "\n--- Adjacent Zones ---" << std::endl;
        std::queue<std::string> adjacentZones;
        worldMap.getToVertices("Desolate Village", adjacentZones);

        std::cout << "From the Desolate Village, you can travel to:" << std::endl;
        while (!adjacentZones.empty()) {
            std::cout << "- " << adjacentZones.front() << std::endl;
            adjacentZones.pop(); // Remove the front element after reading it
        }

    } catch (FullGraph) {
        std::cerr << "Error: Attempted to add a vertex to a full graph." << std::endl;
    } catch (EmptyGraph) {
        std::cerr << "Error: Attempted to modify or read an empty graph." << std::endl;
    }

    return 0;
}