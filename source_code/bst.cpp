#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
 
    TreeNode(int n) {
        value = n;
        left = NULL;
        right = NULL;
    }
};

TreeNode* bst(vector<int>& key, int left, int right){
    if (left > right){
        return NULL;
    }
    int mid = left + (right - left)/2;
    TreeNode* root = new TreeNode(key[mid]);

    root->left = bst(key, left, mid - 1);
    root->right = bst(key, mid + 1, right);

    return root;
}

int predecessorSearch(int p, int target, TreeNode* root){
    if (root == NULL){
        return p;
    }
    if (root->value == target){
        p = target;
        return p;
    }
    else if (root->value > target){
        return predecessorSearch(p, target, root->left);
    }
    p = root->value;
    return predecessorSearch(p, target, root->right);
}

int minSearch(TreeNode* root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL){
        return root->value;
    }
    else {
        return minSearch(root->left);
    }
}

int main() {

    vector<int> key;
    ifstream myfile;
    myfile.open("ds.txt");

    int n;
    while (myfile >> n){
        key.push_back(n);
    }

    myfile.close();

    sort(key.begin(), key.end());

    TreeNode* root = bst(key, 0, key.size() - 1);

    vector<int> target;
    ifstream queryfile("qry.txt");
    string tmp;
    ofstream outputfile("output.txt");
    int min = minSearch(root);

    while (getline(queryfile, tmp)){
        tmp = tmp.substr(4);
        int v = stoi(tmp);
        if (v < min){
            outputfile << "no" << "\n";
        }
        else {
            int predecessor = predecessorSearch(INT_MIN, v, root);
            outputfile << predecessor << "\n";
        }
    }
    return 0;
}
