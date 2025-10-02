// //
// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;


// int main(){
//   int n; cin>> n;
//   set<int> s;
//   vector<int> a(n);
//   for(int i=0; i<n; i++){
//     cin>> a[i];
//     s.insert(a[i]);
//   }
//   cout<< s.size()<<endl;
//   return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
class Node {
public:
    string nm;
    Node* par;
vector<Node*> ch;
    bool islock;
    int lockby;
    int lockcount;
    
    Node(const string& nodeName) 
        : nm(nodeName), par(nullptr), islock(false), 
          lockby(-1), lockcount(0) {}
};

class TreeLockingSystem {
private:
    Node* root;
    unordered_map<string, Node*> namenode;
    int m; // number of children per node
    
public:
    TreeLockingSystem(const vector<string>& nodenm, int chcount) 
        : m(chcount) {
        buildTree(nodenm);
    }
    
    ~TreeLockingSystem() {
        deleteTree(root);
    }
    
    void buildTree(const vector<string>& nodenm) {
        if (nodenm.empty()) return;
        
        // Create root node
        root = new Node(nodenm[0]);
        namenode[nodenm[0]] = root;
        
      queue<Node*> q;
        q.push(root);
        
        int index = 1;
        while (!q.empty() && index < nodenm.size()) {
            Node* current = q.front();
            q.pop();
            
            // Add m children to current node
            for (int i = 0; i < m && index < nodenm.size(); i++) {
                Node* child = new Node(nodenm[index]);
                child->par = current;
                current->ch.push_back(child);
                namenode[nodenm[index]] = child;
                q.push(child);
                index++;
            }
        }
    }
    
    bool lock(const std::string& nodeName, int uid) {
        auto it = namenode.find(nodeName);
        if (it == namenode.end()) {
            return false; // Node not found
        }
        
        Node* node = it->second;
        
        // Check if node is already locked
        if (node->islock) {
            return false;
        }
        
        // Check if any descendant is locked
        if (node->lockcount > 0) {
            return false;
        }
        
        // Check if any ancestor is locked
        Node* ances = node->par;
        while (ances != nullptr) {
            if (ances->islock) {
                return false;
            }
            ances = ances->par;
        }
        
        // All checks passed, lock the node
        node->islock = true;
        node->lockby = uid;
        
        // Update ancestor counts
        ances = node->par;
        while (ances != nullptr) {
            ances->lockcount++;
            ances = ances->par;
        }
        
        return true;
    }
    
    bool unlock(const std::string& nodenm, int uid) {
        auto it = namenode.find(nodenm);
        if (it == namenode.end()) {
            return false; // Node not found
        }
        
        Node* node = it->second;
        
        // Check if node is locked and owned by the same user
        if (!node->islock || node->lockby != uid) {
            return false;
        }
        
        // Unlock the node
        node->islock = false;
        node->lockby = -1;
        
        // Update ancestor counts
        Node* ances = node->par;
        while (ances != nullptr) {
            ances->lockcount--;
            ances = ances->par;
        }
        
        return true;
    }
    
    bool upgrade(const std::string& nodeName, int uid) {
        auto it = namenode.find(nodeName);
        if (it == namenode.end()) {
            return false; // Node not found
        }
        
        Node* node = it->second;
        
        // Check if node is already locked
        if (node->islock) {
            return false;
        }
        
        // Check if there are any locked descendants
        if (node->lockcount == 0) {
            return false;
        }
        
        // Find all locked descendants and verify ownership
        std::vector<Node*> lockdes;
        if (!findlockdes(node, uid, lockdes)) {
            return false; // Not all locked descendants belong to uid
        }
        
        // Unlock all descendants
        for (Node* des : lockdes) {
            unlock(des->nm, uid);
        }
        
        // Lock the current node
        return lock(nodeName, uid);
    }
    
private:
    bool findlockdes(Node* node, int uid, std::vector<Node*>& lockedDescendants) {
        // If this node has no locked descendants, we can skip its subtree
        if (node->lockcount == 0) {
            return true;
        }
        
        for (Node* child : node->ch) {
            if (child->islock) {
                if (child->lockby != uid) {
                    return false; // Found a locked node not owned by uid
                }
                lockedDescendants.push_back(child);
            }
            
            // Recursively check this child's subtree
            if (!findlockdes(child, uid, lockedDescendants)) {
                return false;
            }
        }
        
        return true;
    }
    
    void deleteTree(Node* node) {
        if (node == nullptr) return;
        
        for (Node* child : node->ch) {
            deleteTree(child);
        }
        delete node;
    }
    
// public:
//     // Utility function to print tree structure (for debugging)
//     void printTree() {
//         if (root == nullptr) return;
//         printNode(root, 0);
//     }
    
// private:
//     void printNode(Node* node, int depth) {
//         if (node == nullptr) return;
        
//         for (int i = 0; i < depth; i++) {
//             std::cout << "  ";
//         }
        
//         std::cout << node->nm;
//         if (node->islock) {
//             std::cout << " [LOCKED by " << node->lockby << "]";
//         }
//         std::cout << " (descendants: " << node->lockcount << ")";
//         std::cout << std::endl;
        
//         for (Node* child : node->ch) {
//             printNode(child, depth + 1);
//         }
//     }
};

int main() {
    int n, m, q;
    cin >> n;
    cin >> m;
    cin >> q;
    
    // Input node names
    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    
    // Create the tree
    TreeLockingSystem tls(nodes, m);
    
    for (int i = 0; i < q; i++) {
        int operation, userId;
        string nodeName;
        
        cin >> operation >> nodeName >> userId;
        
        bool result = false;
        string operationName;
        
        switch (operation) {
            case 1:
                result = tls.lock(nodeName, userId);
                operationName = "lock";
                break;
            case 2:
                result = tls.unlock(nodeName, userId);
                operationName = "unlock";
                break;
            case 3:
                result = tls.upgrade(nodeName, userId);
                operationName = "upgradeLock";
                break;
            default:
                cout << "Invalid operation: " << operation << endl;
                continue;
        }
        
        cout << (result ? "true" : "false") << endl;
    }
    
    return 0;
}