#include <iostream>
using namespace std;

struct Vertex
{
    char data;
    Vertex *next;
    struct Edge *edgeList;
} *vStart = nullptr;

struct Edge
{
    Vertex *toVertex;
    Edge *next;
};

void insertVertex()
{
    char inputData;
    struct Vertex *tempV = new Vertex();
    cout << "Enter Node Data" << endl;
    cin >> inputData;
    tempV->data = inputData;
    tempV->next = nullptr;
    tempV->edgeList = nullptr;
    if (vStart == nullptr)
    {
        vStart = tempV;
    }
    else
    {
        struct Vertex *tempV1 = vStart;
        while (tempV1->next != nullptr)
        {
            tempV1 = tempV1->next;
        }
        tempV1->next = tempV;
    }
}

struct Vertex *searchVertex(char data)
{
    struct Vertex *tempV = vStart;
    while (tempV != nullptr)
    {
        if (tempV->data == data)
        {
            return tempV;
        }
        tempV = tempV->next;
    }
    return nullptr;
}

void insertEdge()
{
    struct Vertex *tempV = new Vertex();
    int search = 0;
    char fromData;
    char toData;
    cout << "From Where" << endl;
    cin >> fromData;
    cout << "To Where" << endl;
    cin >> toData;
    struct Vertex *to = searchVertex(toData);
    struct Vertex *from = searchVertex(fromData);
    struct Edge *tempE = new Edge();
    tempE->toVertex = to;
    tempE->next = nullptr;
    if (to != nullptr && from != nullptr)
    {
        if (from->edgeList == nullptr)
        {
            from->edgeList = tempE;
        }
        else
        {
            struct Edge *tempE1 = from->edgeList;
            while (tempE1->next != nullptr)
            {
                tempE1 = tempE1->next;
            }
            tempE1->next = tempE;
        }
    }
}

void printVertex()
{
    struct Vertex *tempV1 = vStart;
    while (tempV1 != nullptr)
    {
        cout << tempV1->data;
        tempV1 = tempV1->next;
    }
    cout << endl;
}

void printEdge()
{
    struct Edge *tempE = new Edge();
    char inputData;
    cout << "Which node's edges to be printed: " << endl;
    cin >> inputData;
    struct Vertex *tempV1 = searchVertex(inputData);
    tempE = tempV1->edgeList;
    cout << tempV1->data << " : ";
    while (tempE != nullptr)
    {
        cout << tempE->toVertex->data << ",";
        tempE = tempE->next;
    }
    cout << "null" << endl;
}

int degree(char data)
{
    struct Vertex *tempV1 = searchVertex(data);
    struct Edge *tempE = tempV1->edgeList;
    int degree = 0;
    while (tempE != nullptr)
    {
        degree++;
        tempE = tempE->next;
    }
    return degree;
}

int main()
{
    insertVertex();
    insertVertex();
    insertVertex();
    insertVertex();
    insertEdge();
    insertEdge();
    printEdge();
    cout << "Degree :" << degree('A') << endl;
    return 0;
}
