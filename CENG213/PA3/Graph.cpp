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
    distance.Insert(node.getVid(), LONG_MAX);
    previous.Insert(node.getVid(), NULL);
    changekey.Insert(node.getVid(), node.getCountry());
    activekeys.push_back(node.getVid());
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
    typename list<int>::iterator iter = activekeys.begin();
    while (iter != activekeys.end()) {
        list<Edge> & le = adjList.Get(*iter);
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
        iter++;
    }
    
    adjList.Delete(node.getVid());
    activekeys.remove(node.getVid());
    
    
}

list<string> Graph::findLeastCostPath(const Node& srcNode, const Node& destNode) {
    typename list<int>::iterator iter = activekeys.begin();
    while (iter != activekeys.end()) {
        mark.Get(*iter) = 0;
        distance.Get(*iter) = LONG_MAX;
        previous.Get(*iter) = NULL;
        iter++;
    }
    
    priority_queue<pqentry, vector<pqentry>, Compare> pq;
    
    pqentry pqe;
    pqe.id = srcNode.getVid();
    pqe.distance = 0;
    distance.Get(pqe.id) = 0;
    
    pq.push(pqe);
    
    while (!pq.empty()) {
        pqentry vertex = pq.top();
        pq.pop();
        
        list<Edge> & tracing = adjList.Get(vertex.id);
        typename list<Edge>::iterator it = tracing.begin();
        
        int distofcurrent = distance.Get(vertex.id);
        for (int j = 0; j < tracing.size(); j++) {
            int newdistance = distofcurrent + it->getImport();
            
            if (newdistance < distance.Get(it->getTailNode().getVid())) {
                distance.Get(it->getTailNode().getVid()) = newdistance;
                pqe.id = it->getTailNode().getVid();
                pqe.distance = newdistance;
                pq.push(pqe);
                previous.Get(it->getTailNode().getVid()) = vertex.id;
            }
            it++;
        }
    }
    
    list<string> leastcostpath;
    
    int idnow = destNode.getVid();
    leastcostpath.push_front(destNode.getCountry());
    while ( idnow != srcNode.getVid() ) {
        idnow = previous.Get(idnow);
        leastcostpath.push_front(changekey.Get(idnow));
    }
    
    return leastcostpath;
}


bool Graph::isCyclic() {
    
    typename list<int>::iterator iter = activekeys.begin();
    while (iter != activekeys.end()) {
        mark.Get(*iter) = 0;
        iter++;
    }
    
    stack<int> s;
    
    iter = activekeys.begin();
    while (iter != activekeys.end()) {
        if (mark.Get(*iter) == 0) {
            s.push(*iter);
            mark.Insert(s.top(), 1);
            
            while (!s.empty()) {
                int a = -1;
                list<Edge> & tracing = adjList.Get(s.top());
                typename list<Edge>::iterator it = tracing.begin();
                
                for (int j = 0; j < tracing.size(); j++) {
                    if (mark.Get(it->getTailNode().getVid()) == 1) {
                        return true;
                    } else if (mark.Get(it->getTailNode().getVid()) == 0) {
                        a = it->getTailNode().getVid();
                        break;
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
        
        iter++;
    }
    
    return false;
}


list<string> Graph::getBFSPath(const Node& srcNode, const Node& destNode) {
    
    typename list<int>::iterator iter = activekeys.begin();
    while (iter != activekeys.end()) {
        mark.Get(*iter) = 0;
        iter++;
    }
    
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
