#include <queue>

const int NULL_EDGE = 0;

class FullGraph
{
};
class EmptyGraph
{
};

template <class Vertex>
class Graph
{

private:
    Vertex *vertices;
    int numVertice;
    int maxVertice;
    int **edges;
    bool *marks;

    int indexIs(Vertex vertex)
    {
        for (int i = 0; i < numVertice; i++)
        {
            if (vertices[i] == vertex)
            {
                return i;
            }
        }
        return -1;
    }

public:
    Graph()
    {
        numVertice = 0;
        maxVertice = 50;
        vertices = new Vertex[maxVertice]{};
        edges = new int *[maxVertice]{};
        for (int i = 0; i < maxVertice; i++)
        {
            edges[i] = new int[maxVertice]{};
        }
        marks = new bool[maxVertice]{};
    }

    Graph(int size)
    {
        numVertice = 0;
        maxVertice = size;
        vertices = new Vertex[maxVertice]{};
        edges = new int *[maxVertice]{};
        for (int i = 0; i < maxVertice; i++)
        {
            edges[i] = new int[maxVertice]{};
        }
        marks = new bool[maxVertice]{};
    }

    ~Graph()
    {
        for (int i = 0; i < maxVertice; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
        delete[] vertices;
        delete[] marks;

        edges = nullptr;
        vertices = nullptr;
        marks = nullptr;
    }

    void makeEmpty()
    {
        numVertice = 0;
    }

    bool isEmpty()
    {
        return (numVertice == 0);
    }

    bool isFull()
    {
        return (numVertice == maxVertice);
    }

    void addVertex(Vertex vertex)
    {
        if (numVertice < maxVertice)
        {
            vertices[numVertice] = vertex;
        }
        else
        {
            throw FullGraph();
        }

        for (int i = 0; i <= numVertice; i++)
        {
            edges[i][numVertice] = NULL_EDGE;
            edges[numVertice][i] = NULL_EDGE;
        }
        numVertice++;
    }

    void addEdge(Vertex from, Vertex to, int weight)
    {
        if (isEmpty())
        {
            throw EmptyGraph();
        }
        int row = indexIs(from);
        int column = indexIs(to);

        if (row != -1 && column != -1)
        {
            edges[row][column] = weight;
        }
    }

    int weightIs(Vertex from, Vertex to)
    {
        if (isEmpty())
        {
            throw EmptyGraph();
        }

        int row = indexIs(from);
        int column = indexIs(to);

        if (row != -1 && column != -1)
        {
            return edges[row][column];
        }
        return NULL_EDGE;
    }

    void clearMarks()
    {
        for (int i = 0; i < numVertice; i++)
        {
            marks[i] = false;
        }
    }

    void markVertex(Vertex vertex)
    {
        int index = indexIs(vertex);

        if (index != -1)
        {
            marks[index] = true;
        }
    }

    bool isMarked(Vertex vertex)
    {
        int index = indexIs(vertex);

        if (index != -1)
        {
            return marks[index];
        }
        return false;
    }

    void getToVertices(Vertex vertex, std::queue<Vertex> &adjVertices)
    {
        int fromIndex = indexIs(vertex);

        if (fromIndex == -1)
        {
            return;
        }

        for (int toIndex = 0; toIndex < numVertice; toIndex++)
        {
            if (edges[fromIndex][toIndex] != NULL_EDGE)
            {
                adjVertices.push(vertices[toIndex]);
            }
        }
    }

    void deleteEdge(Vertex from, Vertex to)
    {
        if (isEmpty())
        {
            throw EmptyGraph();
        }
        int row = indexIs(from);
        int column = indexIs(to);

        if (row != -1 && column != -1)
        {
            edges[row][column] = NULL_EDGE;
        }
    }

    void deleteVertex(Vertex vertex)
    {
        if (isEmpty())
        {
            throw EmptyGraph();
        }

        int index = indexIs(vertex);
        if (index == -1)
        {
            return;
        }

        int lastIndex = numVertice - 1;

        // If the deleted vertex isn't already the last one,
        // we swap the last vertex into its vacated spot to keep the arrays contiguous.
        if (index != lastIndex)
        {
            // 1. Move the vertex label and traversal mark
            vertices[index] = vertices[lastIndex];
            marks[index] = marks[lastIndex];

            // 2. Overwrite the deleted vertex's row with the last vertex's row
            for (int col = 0; col < numVertice; col++)
            {
                edges[index][col] = edges[lastIndex][col];
            }

            // 3. Overwrite the deleted vertex's column with the last vertex's column
            for (int row = 0; row < numVertice; row++)
            {
                edges[row][index] = edges[row][lastIndex];
            }
        }

        // 4. Shrink the active graph size
        numVertice--;
    }
};
