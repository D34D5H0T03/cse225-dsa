#include <iostream>
#include <stack>
#include <unordered_map>
#include "graph.cpp"

void initialize(Graph<std::string>& worldMap){
    try {
        // --- LEVEL 1: Starting Zone ---
        worldMap.addVertex("Desolate Village");

        // --- LEVEL 2: Early Game Areas ---
        worldMap.addVertex("Cursed Woods");
        worldMap.addVertex("Ashen Plains");
        worldMap.addVertex("Whispering Bog");

        // --- LEVEL 3: Mid Game Zones ---
        worldMap.addVertex("Ruined Keep");
        worldMap.addVertex("Forsaken Graveyard");
        worldMap.addVertex("Shattered Bridge");
        worldMap.addVertex("Bloodstained Altar");
        worldMap.addVertex("Rotting Marsh");

        // --- LEVEL 4: Deep Zones ---
        worldMap.addVertex("Hollow Crypt");
        worldMap.addVertex("Obsidian Spire");
        worldMap.addVertex("Wraith's Peak");
        worldMap.addVertex("Serpent's Pass");
        worldMap.addVertex("Sunken City");

        // --- LEVEL 5: Late Game ---
        worldMap.addVertex("Forgotten Catacombs");
        worldMap.addVertex("Crimson Citadel");
        worldMap.addVertex("Echoing Cavern");

        // --- LEVEL 6: Endgame / Eldritch Horrors ---
        worldMap.addVertex("Abyssal Depths");
        worldMap.addVertex("Eldritch Void");
        worldMap.addVertex("Throne of Dust");

        // --- ESTABLISH PATHWAYS (Edges) ---
        // Village branches out (Level 1 -> 2)
        worldMap.addEdge("Desolate Village", "Cursed Woods", 10);
        worldMap.addEdge("Desolate Village", "Ashen Plains", 15);
        worldMap.addEdge("Desolate Village", "Whispering Bog", 12);

        // Woods Progression (Level 2 -> 3)
        worldMap.addEdge("Cursed Woods", "Ruined Keep", 20);
        worldMap.addEdge("Cursed Woods", "Forsaken Graveyard", 15);
        
        // Plains Progression (Level 2 -> 3)
        worldMap.addEdge("Ashen Plains", "Shattered Bridge", 25);
        worldMap.addEdge("Ashen Plains", "Bloodstained Altar", 30);

        // Bog Progression (Level 2 -> 3)
        worldMap.addEdge("Whispering Bog", "Rotting Marsh", 18);

        // Keep & Graveyard Progression (Level 3 -> 4)
        worldMap.addEdge("Ruined Keep", "Hollow Crypt", 35);
        worldMap.addEdge("Ruined Keep", "Obsidian Spire", 40);
        worldMap.addEdge("Forsaken Graveyard", "Hollow Crypt", 20); // Cross-connection

        // Bridge & Altar Progression (Level 3 -> 4)
        worldMap.addEdge("Shattered Bridge", "Wraith's Peak", 45);
        worldMap.addEdge("Shattered Bridge", "Serpent's Pass", 30);
        worldMap.addEdge("Bloodstained Altar", "Crimson Citadel", 60); // Fast track to late game

        // Marsh Progression (Level 3 -> 4)
        worldMap.addEdge("Rotting Marsh", "Sunken City", 35);

        // Deep Zones to Late Game (Level 4 -> 5)
        worldMap.addEdge("Hollow Crypt", "Forgotten Catacombs", 40);
        worldMap.addEdge("Obsidian Spire", "Crimson Citadel", 50);
        worldMap.addEdge("Serpent's Pass", "Echoing Cavern", 45);
        worldMap.addEdge("Sunken City", "Echoing Cavern", 40);

        // Late Game to Endgame (Level 5 -> 6)
        worldMap.addEdge("Forgotten Catacombs", "Abyssal Depths", 70);
        worldMap.addEdge("Echoing Cavern", "Eldritch Void", 80);
        worldMap.addEdge("Crimson Citadel", "Throne of Dust", 100);

        // Cross-connections in Endgame (Interlinked final areas)
        worldMap.addEdge("Abyssal Depths", "Eldritch Void", 50);
        worldMap.addEdge("Eldritch Void", "Throne of Dust", 60);

        // One-way drops / traps (You can fall in, but can't walk back)
        worldMap.addEdge("Wraith's Peak", "Abyssal Depths", 90); 

        // --- PREPARATION FOR BFS/DFS ---
        std::cout << "Map initialization complete. 20 locations loaded.\n" << std::endl;

        std::cout << "--- Adjacent Zones Test (From Desolate Village) ---" << std::endl;
        std::queue<std::string> startNeighbors;
        worldMap.getToVertices("Desolate Village", startNeighbors);
        while (!startNeighbors.empty()) {
            std::cout << "- " << startNeighbors.front() << std::endl;
            startNeighbors.pop();
        }

        std::cout << "\n--- Adjacent Zones Test (From Eldritch Void) ---" << std::endl;
        std::queue<std::string> voidNeighbors;
        worldMap.getToVertices("Eldritch Void", voidNeighbors);
        while (!voidNeighbors.empty()) {
            std::cout << "- " << voidNeighbors.front() << std::endl;
            voidNeighbors.pop();
        }

    } catch (FullGraph) {
        std::cerr << "Error: Graph capacity exceeded." << std::endl;
    } catch (EmptyGraph) {
        std::cerr << "Error: Graph is empty." << std::endl;
    }
}

template <class Vertex>
void breadthFirstSearch(Graph<Vertex>& map, Vertex start, Vertex target){
    std::queue<Vertex> queue;
    std::queue<Vertex> vertexQ;
    std::unordered_map<Vertex, Vertex> comeFrom;

    bool found = false;
    Vertex vertex;
    Vertex item;

    map.clearMarks();
    queue.push(start);

    comeFrom[start] = start;

    do{
        vertex = queue.front();
        queue.pop();

        if(vertex == target){
            found = true;
            break;
        }

        if(!map.isMarked(vertex)){
            map.markVertex(vertex);
            map.getToVertices(vertex, vertexQ);

            while(!vertexQ.empty()){
                item = vertexQ.front();
                vertexQ.pop();

                if(!map.isMarked(item)){
                    queue.push(item);

                    comeFrom[item] = vertex;
                }
            }
        }
    }while(!queue.empty() && !found);

    if(found){
        std::cout << "\nPath Discovered:\n";
        std::stack<Vertex> actualPath;
        Vertex current = target;

        while(current != start){
            actualPath.push(current);
            current = comeFrom[current];
        }
        actualPath.push(start);

        while (!actualPath.empty()) {
            std::cout << actualPath.top();
            actualPath.pop();
            if (!actualPath.empty()){
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "Path not found." << std::endl;
    }
}

int main(){
    Graph<std::string> worldMap(20);
    
    initialize(worldMap);

    std::string start = "Desolate Village";
    std::string target = "Throne of Dust";
    breadthFirstSearch(worldMap, start, target);
    return 0;
}