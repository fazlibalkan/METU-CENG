#include "Graph.h"

/*Do not add new libraries or files*/


Graph::Graph() {
    // TODO: IMPLEMENT THIS FUNCTION.
    
}

Graph::Graph(const Graph& rhs) {
    // TODO: IMPLEMENT THIS FUNCTION.
    adjList = rhs.adjList;
}

Graph& Graph::operator=(const Graph& rhs) {
    // TODO: IMPLEMENT THIS FUNCTION.
    adjList = rhs.adjList;
}

Graph::~Graph() {
// TODO: IMPLEMENT THIS FUNCTION.

}


void Graph::addNode(const Node &node) {
    // TODO: IMPLEMENT THIS FUNCTION.
    list<Edge> emptylist;
    adjList.Insert(node.getVid(), emptylist);
    mark.Insert(node.getVid(), 0);
    distance.Insert(node.getVid(), INT_MAX);
    previous.Insert(node.getVid(), NULL);
}

void Graph::addConnection(const Node& headNode, const Node& tailNode, int import) {
    // TODO: IMPLEMENT THIS FUNCTION.
    Edge tail(tailNode, long(import));
    adjList.Get(headNode.getVid()).push_back(tail);

    
}

list<Node> Graph::getAdjacentNodes(const Node& node) {
    // TODO: IMPLEMENT THIS FUNCTION.
    //exception u unutma
    
    list<Node> list;
    typename list<Edge>::const_iterator it;
    for (it  = adjList.Get(node.getVid()).begin(); it != adjList.Get(node.getVid()).end(); ++it) {
        list.push_back(it->getTailNode());
    }
    return list;
    
}

long Graph::getTotalImports(const Node& node) {
    // TODO: IMPLEMENT THIS FUNCTION.
    //exception u unutma

    long totalimports = 0;
    typename list<Edge>::const_iterator it;
    for (it  = adjList.Get(node.getVid()).begin(); it != adjList.Get(node.getVid()).end(); ++it) {
        totalimports += it->getImport();
    }
    return totalimports;

}

void Graph::deleteNode(const Node& node) {
    // TODO: IMPLEMENT THIS FUNCTION.
    
    int size = adjList.Size();
    int arr[size];
    adjList.getKeys(arr);
    
    for (int a = 0; a < size; a++) {    
        list<Edge> & le = adjList.Get(arr[a]);
        typename list<Edge>::iterator it = le.begin();
        
        while (it != le.end()) {
            if (node.getVid() == it->getTailNode().getVid()) {
                it = le.erase(it);
            } else if (it == le.end()) {
                break;
            } else {
                ++it;
            }
        }
    }
    
    adjList.Delete(node.getVid());
}

list<string> Graph::findLeastCostPath(const Node& srcNode, const Node& destNode) {
    // TODO: IMPLEMENT THIS FUNCTION.
    priority_queue<int> pq;
    
    qentry qe;
    qe.id = srcNode.getVid();
    qe.distance = 0;
    
    distance.Get(srcNode.getVid()) = 0;
    
    
    
    
    
}


bool Graph::isCyclic() {
    // TODO: IMPLEMENT THIS FUNCTION.
    int size = adjList.Size();
    int arr[size];
    adjList.getKeys(arr);
    
    stack<int> s;
    
    for (int i = 0; i < size; i++) {
        
        if (mark.Get(arr[i]) == 0) {
            s.push(arr[i]);
            mark.Insert(s.top(), 1);
            
            while (!s.empty()) {
                int a = -1;
                list<Edge> & tracing = adjList.Get(s.top());
                typename list<Edge>::iterator it = tracing.begin();
                
                for (int j = 0; j < tracing.size(); j++) {
                    if (mark.Get(it->getTailNode().getVid()) == 0) {
                        a = it->getTailNode().getVid();
                        break;
                    } else if (mark.Get(it->getTailNode().getVid()) == 1) {
                        return true;
                    }
                    it++;
                }
                
                if (a == -1) {
                    mark.Insert(s.top(), 2);
                    s.pop();
                } else {
                    mark.Insert(a, 1);
                    s.push(a);
                }
                
            }
        }
        
    }
    
    
    return false;
}


list<string> Graph::getBFSPath(const Node& srcNode, const Node& destNode) {
    
    list<string> l;
    
    queue<int> q;
    
    q.push(srcNode.getVid());
    l.push_back(srcNode.getCountry());
    mark.Get(srcNode.getVid()) = 1;
    
    while (!q.empty()) {
        list<Edge> & tracing = adjList.Get(q.front());
        q.pop();
        
        typename list<Edge>::iterator it = tracing.begin();

        for (int i = 0; i < tracing.size(); i++) {
            if (it->getTailNode().getVid() == destNode.getVid()) {
                l.push_back(destNode.getCountry());
                return l;
            }
            if (mark.Get(it->getTailNode().getVid()) == 0) {
                q.push(it->getTailNode().getVid());
                l.push_back(it->getTailNode().getCountry());
                
                mark.Get(it->getTailNode().getVid()) = 1;
            }
            
            it++;
        }
    }
    
}