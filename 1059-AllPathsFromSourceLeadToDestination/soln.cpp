/* Copyright (c) 2019-2021 Grant Hadlich
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the Software), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
class Solution {
class Node {
    public:
    unordered_map<Node*,int> edges;
    int value_;
    bool traversed_;
    
    Node(int value) {
        value = value;
        traversed_ = false;
    }
};
    
    bool findCycle(Node* n, unordered_map<Node*,bool> visited, unordered_map<Node*,bool> recStack) {
        if (n == 0) {return false;}
        
        // Mark the current node as visited and 
        // part of recursion stack 
        if (recStack[n]) 
            return true; 
  
        if (visited[n]) 
            return false; 
              
        visited[n] = true; 
  
        recStack[n] = true; 
                  
        for (auto edge : n->edges) {
            if (findCycle(edge.first, visited, recStack)) 
                return true; 
        }
        
        recStack[n] = false; 
  
        return false;
    }
    
    bool findDestination(Node* n, int destination) {
        if (n == 0) {
            return false;
        }
        
        n->traversed_ = true;
        
        cout << "findDestination: " << n->value_ << endl;
        
        int edges = 0;
        
        for (auto edge : n->edges) {
            if (!findDestination(edge.first,destination))
                return false;
            edges++;
        }
        
        if (edges > 0) {
            return true;
        }
        
        return n->value_ == destination;
    }
    
    bool findCycleOrDestination(Node* n, int destination) {
        if (n == 0) return false;
        if (n->value_ == destination) {
            return true;
        }
        
        int edges = 0;
        
        for (auto edge : n->edges) {
            edges++;
            unordered_map<Node*,bool> seen;
            unordered_map<Node*,bool> stack;
            bool cycle = findCycle(edge.first, seen, stack);
            if (cycle) {
                cout << "Cycle Detected" << endl;
                return false;
            }
            if (!findDestination(edge.first,destination)) {
                cout << "No Destination Found" << endl;
                return false;
            }
        }
        
        n->traversed_ = true;
        
        if (edges == 0) return false;
        
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if (edges.size() == 0 && n == 1 && source == destination) return true;
        if (source == destination) return false;
        
        for (auto edge : edges) {
            int start = edge[0];
            int end = edge[1];
            
            // Loop at end == false
            if ((start == end) && (destination==start)) {
                return false;
            }
            
            if (m_[start] == 0) {
                m_[start] = new Node(start);
                m_[start]->value_ = start;
            }
            
            if (m_[end] == 0) {
                m_[end] = new Node(end);
                m_[end]->value_ = end;
            }
            
            Node* s = m_[start];
            Node* e = m_[end];
            
            s->edges[e] = end;
        }
        
        if (findCycleOrDestination(m_[source], destination) == false) {
            return false;
        }
        
        for (auto node : m_) {
            if (node.second->traversed_ == false) {
                cout << "Not Traversed: " << node.first << endl;
                //return false;
            }
        }
        
        return true;
    }
    
    unordered_map<int,Node*> m_;
    unordered_map<Node*,bool> cycle_detected_;
};