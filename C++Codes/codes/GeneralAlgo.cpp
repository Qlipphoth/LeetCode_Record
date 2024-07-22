#include "header.h"

namespace GeneralAlgo {

// =========================== Bubble Sort =========================== //

void bubbleSort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}


//============================ Quick Sort =============================//

int partition(vector<int>& nums, int left, int right)
{
    int i = left, j = right;
    while (i < j) 
    {
        while ((i < j) && nums[j] >= nums[left]) --j;
        while ((i < j) && nums[i] <= nums[left]) ++i;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

void quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right) return;
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}


// =========================== Heap Sort =========================== //

void heapify(vector<int>& nums, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && nums[l] > nums[largest]) largest = l;
    if (r < n && nums[r] > nums[largest]) largest = r;
    // If largest is not root
    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        // Recursively heapify the affected sub-tree
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int>& nums)
{
    int n = nums.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(nums, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; --i)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}


//============================ Binary Search =============================//

int binary_search(const vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

}

namespace TreeAlgo {

void PreorderTraversal(TreeNode* root, vector<int>* res)
{
    if (root == nullptr)  return;
    res->emplace_back(root->val);
    PreorderTraversal(root->left, res);
    PreorderTraversal(root->right, res);
}

void PreorderTraversal(TreeNode* root, vector<int>* res, bool)
{
    vector<TreeNode*> stk{root};
    while (!stk.empty())
    {
        TreeNode* Cur = stk.back();
        stk.pop_back();
        res->emplace_back(Cur->val);
        if (Cur->right != nullptr) stk.emplace_back(Cur->right);
        if (Cur->left != nullptr) stk.emplace_back(Cur->left);
    }
}

void InorderTraversal(TreeNode* root, vector<int>* res)
{
    if (root == nullptr)  return;
    InorderTraversal(root->left, res);
    res->emplace_back(root->val);
    InorderTraversal(root->right, res);
}

void InorderTraversal(TreeNode* root, vector<int>* res, bool)
{
    vector<TreeNode*> stk;
    TreeNode* cur = root, *node;
    while (!stk.empty() || cur != nullptr)
    {
        while (cur != nullptr)
        {
            stk.emplace_back(cur);
            cur = cur->left;
        }
        node = stk.back();
        stk.pop_back();
        res->emplace_back(node->val);
        if (node->right) cur = node->right;
    }
}

void PostorderTraversal(TreeNode* root, vector<int>* res)
{
    if (root == nullptr)  return;
    PostorderTraversal(root->left, res);
    PostorderTraversal(root->right, res);
    res->emplace_back(root->val);
}

void PostorderTraversal(TreeNode* root, vector<int>* res, bool)
{
    vector<TreeNode*> stk;
    TreeNode *cur = root, *pre;
    while (!stk.empty() || cur != nullptr)
    {
        while (cur != nullptr)
        {
            stk.emplace_back(cur);
            cur = cur->left;
        }
        cur = stk.back();
        stk.pop_back();
        if (cur->right == nullptr || pre == cur->right)
        {
            res->emplace_back(cur->val);
            pre = cur;
            cur = nullptr;
        }
        else 
        {
            stk.emplace_back(cur);
            cur = cur->right;
        }
    }
}

}

namespace GraphAlgo {

// 并查集 (Union Find Set)
// 并查集的重要思想在于，用集合中的一个元素代表集合。
// 1. 路径压缩：把沿途的每个节点的父节点都设为根节点即可。下一次再查询时，我们就可以省很多事。
// 2. 按秩合并：我们应该把简单的树往复杂的树上合并，而不是相反。因为这样合并后，到根节点距离变长的节点个数比较少。

class UFS
{
public:
    vector<int> fa;

public:
    UFS(int n) : fa(n)
    {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }
};


class PathCompressUFS 
{
public:
    vector<int> fa;

public:
    PathCompressUFS(int n): fa(n) {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);  // 将每个节点的父节点都指向根节点
        return fa[x];
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }
};


class RankUFS
{
public:
    vector<int> fa, rank;

public:
    RankUFS(int n): fa(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        // 按秩合并
        if (rank[fx] > rank[fy]) swap(fx, fy);
        fa[fx] = fy;
        if (rank[fx] == rank[fy]) ++rank[fy];
    }

};


}

void GeneralAlgoTest()
{
    vector<int> nums = { 5, 2, 4, 6, 1, 3 };
    GeneralAlgo::quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;

    int target = 3;
    int index = GeneralAlgo::binary_search(nums, target);
    if (index == -1) cout << "Not found" << endl;
    else cout << "Found at index " << index << endl;
}

void TreeAlgoTest()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<int> res;
    TreeAlgo::PreorderTraversal(root, &res, false);
    // TreeAlgo::InorderTraversal(root, &res, false);
    // TreeAlgo::PostorderTraversal(root, &res, false);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}

void GraphAlgoTest()
{
    GraphAlgo::UFS ufs(5);
    ufs.merge(0, 1);
    ufs.merge(1, 2);
    ufs.merge(3, 4);
    cout << ufs.find(0) << endl;
    cout << ufs.find(2) << endl;
    cout << ufs.find(3) << endl;
}

int main()
{
    // GeneralAlgoTest();
    // TreeAlgoTest();
    GraphAlgoTest();
    return 0;
}