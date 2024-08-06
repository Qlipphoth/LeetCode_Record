#include "header.h"
#include <atomic>
#include <mutex>

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

// 三路快排
void quickSort3Ways(vector<int>& nums, int left, int right)
{
    if (left >= right) return;
    int lt = left, gt = right, i = left + 1;
    int pivot = nums[left];
    while (i <= gt)
    {
        if (nums[i] < pivot) swap(nums[i++], nums[lt++]);
        else if (nums[i] > pivot) swap(nums[i], nums[gt--]);
        else ++i;
    }
    quickSort3Ways(nums, left, lt - 1);
    quickSort3Ways(nums, gt + 1, right);
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
    
    // Method 1
    // while (left <= right)
    // {
    //     int mid = (left + right) >> 1;
    //     if (nums[mid] == target) return mid;
    //     else if (nums[mid] < target) left = mid + 1;
    //     else right = mid - 1;
    // }
    // return -1;

    // Method 2
    // while (left < right)
    // {
    //     int mid = (left + right) >> 1;
    //     if (nums[mid] < target) left = mid + 1;
    //     else right = mid;
    // }
    // return nums[left] == target ? left : -1;

    // Method 3
    while (left < right)
    {
        int mid = (left + right + 1) >> 1;
        if (nums[mid] > target) right = mid - 1;
        else left = mid;
    }
    return nums[left] == target ? left : -1;
}

}


namespace STLAlgo {

template<typename KeyType, typename ValueType>
class HashTable {
private:
    std::vector<std::pair<KeyType, ValueType>> table;
    std::vector<bool> occupied;
    size_t capacity;
    size_t size;
    const float load_factor = 0.75;

    size_t hashFunction(const KeyType& key) const {
        return std::hash<KeyType>{}(key) % capacity;
    }

    void rehash() {
        size_t old_capacity = capacity;
        capacity *= 2;
        std::vector<std::pair<KeyType, ValueType>> new_table(capacity);
        std::vector<bool> new_occupied(capacity, false);

        for (size_t i = 0; i < old_capacity; ++i) {
            if (occupied[i]) {
                size_t new_index = std::hash<KeyType>{}(table[i].first) % capacity;
                while (new_occupied[new_index]) {
                    new_index = (new_index + 1) % capacity;
                }
                new_table[new_index] = std::move(table[i]);
                new_occupied[new_index] = true;
            }
        }

        table = std::move(new_table);
        occupied = std::move(new_occupied);
    }

public:
    HashTable(size_t initial_capacity = 8) 
        : capacity(initial_capacity), size(0), table(initial_capacity), occupied(initial_capacity, false) {}

    void insert(const KeyType& key, const ValueType& value) {
        if (static_cast<float>(size) / capacity >= load_factor) {
            rehash();
        }

        size_t index = hashFunction(key);
        while (occupied[index]) {
            if (table[index].first == key) {
                table[index].second = value;
                return;
            }
            index = (index + 1) % capacity;
        }
        table[index] = std::make_pair(key, value);
        occupied[index] = true;
        ++size;
    }

    ValueType get(const KeyType& key) const {
        size_t index = hashFunction(key);
        size_t start_index = index;
        while (occupied[index]) {
            if (table[index].first == key) {
                return table[index].second;
            }
            index = (index + 1) % capacity;
            if (index == start_index) break;
        }
        throw std::out_of_range("Key not found");
    }

    void remove(const KeyType& key) {
        size_t index = hashFunction(key);
        size_t start_index = index;
        while (occupied[index]) {
            if (table[index].first == key) {
                occupied[index] = false;
                --size;
                return;
            }
            index = (index + 1) % capacity;
            if (index == start_index) break;
        }
        throw std::out_of_range("Key not found");
    }

    size_t getSize() const {
        return size;
    }

    bool contains(const KeyType& key) const {
        size_t index = hashFunction(key);
        size_t start_index = index;
        while (occupied[index]) {
            if (table[index].first == key) {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == start_index) break;
        }
        return false;
    }
};

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


namespace DesignPattern {

// =========================== Singleton =========================== //

// 1. 饿汉式：程序运行时就创建好实例，线程安全，但初始化顺序不确定。
class Singleton1
{
private:
    static Singleton1* instance;

private:
    Singleton1() {}
    ~Singleton1() {}
    Singleton1(const Singleton1&) = delete;
    Singleton1& operator=(const Singleton1&) = delete;

public:
    static Singleton1* getInstance()
    {
        return instance;
    }

    static void destroyInstance()
    {
        if (instance != nullptr)
        {
            delete instance;
            instance = nullptr;
        }
    }
};

Singleton1* Singleton1::instance = new Singleton1();

// 2. 懒汉式：第一次调用时才创建实例，线程不安全。
class Singleton2
{

private:
    static Singleton2* instance;

private:
    Singleton2() {}
    ~Singleton2() {}
    Singleton2(const Singleton2&) = delete;
    Singleton2& operator=(const Singleton2&) = delete;

public:
    static Singleton2* getInstance()
    {
        if (instance == nullptr)
            instance = new Singleton2();
        return instance;
    }

    static void destroyInstance()
    {
        if (instance != nullptr)
        {
            delete instance;
            instance = nullptr;
        }
    }
};

Singleton2* Singleton2::instance = nullptr;

// 3. 懒汉式：加锁，线程安全。

class Singleton3
{
private:
    static atomic<Singleton3*> instance;
    static mutex mtx;

private:
    Singleton3() {}
    ~Singleton3() {}
    Singleton3(const Singleton3&) = delete;
    Singleton3& operator=(const Singleton3&) = delete;

public:
    static Singleton3* getInstance()
    {
        if (instance == nullptr)
        {
            // 使用 lock_guard 控制锁的生命周期，在作用域结束时自动释放锁
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) instance = new Singleton3();
        }
        return instance;
    }

    static void destroyInstance()
    {
        if (instance != nullptr)
        {
            delete instance;
            instance = nullptr;
        }
    }
};

atomic<Singleton3*> Singleton3::instance{ nullptr };

// 4. 静态局部变量，线程安全。

class Singleton4
{
private:
    Singleton4() {}
    ~Singleton4() {}
    Singleton4(const Singleton4&) = delete;
    Singleton4& operator=(const Singleton4&) = delete;

public:
    static Singleton4* getInstance()
    {
        // C++11 之后，局部静态变量是线程安全的
        static Singleton4 instance;
        return &instance;
    }

    static void destroyInstance()
    {
        // 在局部静态变量的作用域外访问不到该变量
    }
};

}


namespace SmartPointer {

template <class T>
class UniquePtr
{
private:
    T* ptr;

public:
    UniquePtr(T* p = nullptr) : ptr(p) {}
    ~UniquePtr() { delete ptr; }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) { other.ptr = nullptr; }
    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }

    T* get() const { return ptr; }
    void reset(T* p = nullptr)
    {
        if (ptr != p)
        {
            delete ptr;
            ptr = p;
        }
    }

    T* release()
    {
        T* p = ptr;
        ptr = nullptr;
        return p;
    }

    bool operator==(const UniquePtr& other) const { return ptr == other.ptr; }
    bool operator!=(const UniquePtr& other) const { return ptr != other.ptr; }
};


template <class T>
class SharedPtr
{
private:
    T* ptr;
    int* count;

public:
    SharedPtr(T* p = nullptr) : ptr(p), count(new int(1)) {}
    ~SharedPtr()
    {
        if (--(*count) == 0)
        {
            delete ptr;
            delete count;
        }
    }

    SharedPtr(const SharedPtr& other) : ptr(other.ptr), count(other.count) { ++(*count); }
    SharedPtr& operator=(const SharedPtr& other)
    {
        if (this != &other)
        {
            if (--(*count) == 0)
            {
                delete ptr;
                delete count;
            }
            ptr = other.ptr;
            count = other.count;
            ++(*count);
        }
        return *this;
    }

    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), count(other.count)
    {
        other.ptr = nullptr;
        other.count = nullptr;
    }
    SharedPtr& operator=(SharedPtr&& other) noexcept
    {
        if (this != &other)
        {
            if (--(*count) == 0)
            {
                delete ptr;
                delete count;
            }
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }

    T* get() const { return ptr; }
    int use_count() const { return *count; }

    bool operator==(const SharedPtr& other) const { return ptr == other.ptr; }
    bool operator!=(const SharedPtr& other) const { return ptr != other.ptr; }
};


template <class T>
class WeakPtr
{

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