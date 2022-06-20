/*
DFS (Depth-First Search) :
Vertical first, use of stack

preorder: parent => left => right


inorder: left => parent => right
vector<int> inorder(TreeNode* node){
    if(!node){
        return;
    }
    inorder(node->left);
    visit(node);
    inorder(node->right)
}

postorder: left => right => parent


*/

/*
BFS (Breath-First Search):
Horizontal first, use of queue
*/



