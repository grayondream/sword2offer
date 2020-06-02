#include "question.hpp"

int find_dup_number(vector<int> &vec)
{
    if (vec.size() < 1)
        return -1;

    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] == vec[i])
            return vec[i];
    }

    return -1;
}

int find_dup_number_map(vector<int> &vec)
{
    if (vec.size() < 1)
        return -1;

    map<int, int> table;
    for (int val : vec)
    {
        if (table.find(val) == table.end())
            table[val] = 0;

        table[val]++;
    }

    for (auto it = table.begin(); it != table.end(); it++)
    {
        if (it->second > 1)
        {
            return it->first;
        }
    }

    return -1;
}

int find_dup_number_scan(vector<int> &vec)
{
    if (vec.size() < 1)
        return -1;

    for (int i = 0; i < vec.size(); i++)
    {
        int val = vec[i];
        if (val >= vec.size() || val < 0) //出现非法数据
            return -1;

        while (i != vec[i])
        {
            if (vec[i] == vec[vec[i]])
            {
                return vec[i];
            }

            swap(vec[i], vec[vec[i]]);
            if (vec[i] >= vec.size() || vec[i] < 0) //出现非法数据
                return -1;
        }
    }

    return -1;
}

void find_dup_no_test()
{
    vector<int> vec = {2, 1, 3, 5, 2, 3, 1};
    int ret = find_dup_number_scan(vec);
    cout << ret << endl;

    vec = {0, 1, 2, 3, 4, 5};
    ret = find_dup_number_scan(vec);
    cout << ret << endl;

    vec = {0, 0, 0, 0, 0, 0};
    ret = find_dup_number_scan(vec);
    cout << ret << endl;

    vec = {-1, 0, 0, 0, 0, 0};
    ret = find_dup_number_scan(vec);
    cout << ret << endl;
}

int find_dup_no_p(vector<int> &vec)
{
    if (vec.size() < 1)
        return -1;

    int cnt = 0;
    int fast = 0;
    int slow = 0;

    slow = (slow + 1) % vec.size();
    if (vec[slow] < 0 || vec[slow] > vec.size())
        return -1;

    fast = (fast + 1) % vec.size();
    if (vec[slow] < 0 || vec[slow] > vec.size())
        return -1;
    if (vec[fast] == vec[slow] && fast != slow)
        return vec[slow];

    fast = (fast + 1) % vec.size();
    if (vec[fast] < 0 || vec[fast] > vec.size())
        return -1;

    if (vec[fast] == vec[slow] && fast != slow)
        return vec[slow];

    while (true)
    {
        slow = (slow + 1) % vec.size();
        if (vec[slow] < 0 || vec[slow] > vec.size())
            return -1;

        fast = (fast + 1) % vec.size();
        if (vec[slow] < 0 || vec[slow] > vec.size())
            return -1;
        if (vec[fast] == vec[slow] && fast != slow)
            return vec[slow];

        fast = (fast + 1) % vec.size();
        if (vec[fast] < 0 || vec[fast] > vec.size())
            return -1;

        if (vec[fast] == vec[slow] && fast != slow)
            return vec[slow];

        if ((long long)(cnt) > (long long)(vec.size() * vec.size())) //需要注意的是数组过大这里可能会出现溢出的风险
            return -1;
        cnt++;
    }

    return -1;
}

int find_dup_no_bin(vector<int> &vec)
{
    if (vec.size() <= 1)
        return -1;

    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cnt = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] <= mid && vec[i] >= left)
                cnt++;
        }

        if (left == right)
        {
            if (cnt > 1)
                return vec[left];
            else
                return -1;
        }

        if (cnt > (mid - left + 1))
            right = mid;
        else
            left = mid + 1;
    }

    return -1;
}

void find_dup_no_no_test()
{
    vector<int> vec = {2, 1, 3, 5, 2, 3, 1};
    int ret = find_dup_no_p(vec);
    cout << ret << endl;

    vec = {0, 1, 2, 3, 4, 5};
    ret = find_dup_no_p(vec);
    cout << ret << endl;

    vec = {0, 0, 0, 0, 0, 0};
    ret = find_dup_no_p(vec);
    cout << ret << endl;

    vec = {-1, 0, 0, 0, 0, 0};
    ret = find_dup_no_p(vec);
    cout << ret << endl;
}

bool matrix_find(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() < 1)
        return false;

    int row = matrix.size();
    int col = matrix[0].size();
    //以左上角或者右下角为锚点进行查找，
    int i = col - 1;
    int j = 0;
    while (i >= 0 && j < row)
    {
        if (matrix[j][i] == target)
        {
            return true;
        }
        else
        {
            if (matrix[j][i] < target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
    }

    return false;
}

void matrix_find_test()
{
    vector<vector<int>> matrix;
    matrix = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    bool ret = matrix_find(matrix, 2);
    cout << ret << endl;
    ret = matrix_find(matrix, 5);
    cout << ret << endl;
}

string replace_space(const string &str)
{
    int len = str.size();
    for (char ch : str)
    {
        if (ch == ' ')
        {
            len += 2;
        }
    }

    string ret = string(' ', len);
    for (int i = len - 1, j = str.size() - 1; i >= 0 && j >= 0;)
    {
        if (str[j] == ' ')
        {
            ret[i--] = '0';
            ret[i--] = '2';
            ret[i--] = '%';
            j--;
        }
        else
        {
            ret[i--] = str[j--];
        }
    }

    return ret;
}

void replace_space_test()
{
    string str = "we are nothing";
    string ret;
    ret = replace_space(str);
    cout << ret << endl;

    str = "";
    ret = replace_space(str);
    cout << ret << endl;

    str = "      ";
    ret = replace_space(str);
    cout << ret << endl;
}

void reverse_print_list(mylist *l)
{
    if (l == nullptr)
    {
        cout << endl;
        return;
    }

    reverse_print_list(l->next);
    cout << l->val << "\t";
}

void test_reverse_print_list()
{
    mylist l = {1, 2, 3, 4, 5, 6};
    reverse_print_list(l.next);

    l = {};
    reverse_print_list(l.next);
}

mytree *rebuild_tree_sub(vector<int> &pre, int pre_left, int pre_right, vector<int> &mid, int mid_left, int mid_right)
{
    if (pre_right - pre_left != mid_right - mid_left)
        throw out_of_range("vector is invalid!");

    if (pre_right < pre_left || mid_right < mid_left)
        return nullptr;

    mytree *root = new mytree(pre[pre_left], nullptr, nullptr);
    //直接返回root的情况
    if (pre_left == pre_right)
    {
        if (mid_left == mid_right && pre[pre_left] == mid[mid_left])
            return root;
        else
            throw out_of_range("vector is invalid");
    }

    //处理子节点问题
    //在中序遍历中寻找根节点所对应的位置，需要考虑一个因素便是
    int root_id = mid_left;
    //在中序遍历中寻找当前先序遍历根节点对应的节点
    while (root_id <= mid_right && mid[root_id] != root->val)
        root_id++;

    if (root_id > mid_right) //列表中不存在该根节点
        throw out_of_range("vector is invalid");

    int left_len = root_id - mid_left;
    if (left_len > 0)
        root->left = rebuild_tree_sub(pre, pre_left + 1, pre_left + left_len,
                                      mid, mid_left, root_id - 1);

    if (left_len < mid_right - mid_left + 1)
        root->right = rebuild_tree_sub(pre, pre_left + left_len + 1, pre_right,
                                       mid, root_id + 1, mid_right);

    return root;
}

mytree *rebuild_tree(vector<int> &pre, vector<int> &mid)
{
    if (mid.size() != pre.size())
        return nullptr; //非法

    return rebuild_tree_sub(pre, 0, pre.size() - 1, mid, 0, mid.size() - 1);
}

void test_rebuild_tree()
{
    vector<int> pre;
    vector<int> mid;

    mid = {4, 7, 2, 1, 5, 3, 8, 6};
    pre = {1, 2, 4, 7, 3, 5, 6, 8};
    mytree *root = rebuild_tree(pre, mid);
    root->in_traversal(root);
    cout << endl;
    root->pre_traversal(root);
    cout << endl;

    pre = {1, 2, 3, 4, 5, 6};
    mid = {1, 2, 3, 4, 5, 6};
    root = rebuild_tree(pre, mid);
    root->in_traversal(root);
    cout << endl;
    root->pre_traversal(root);
    cout << endl;

    pre = {1, 2, 3, 4, 5, 7};
    mid = {1, 2, 3, 4, 5, 6};
    root = rebuild_tree(pre, mid);
    root->in_traversal(root);
    cout << endl;
    root->pre_traversal(root);
    cout << endl;
}

ptree *next_node_tree(ptree *root)
{
    if (nullptr == root)
        return nullptr;

    if (root->right != nullptr) //有右子树，则其next为右子树的最左子节点
    {
        ptree *cur = root->right;
        while (cur->left != nullptr)
            cur = cur->left;

        return cur;
    }

    if (root->parent != nullptr && root->parent->left == root) //当前节点为根节点的左子树，则next为当前节点的父节点
        return root->parent;

    if (root->right == nullptr && root->parent->right == root) //当前节点为根节点的右子树
    {
        ptree *cur = root->parent;
        while (cur->parent != nullptr && cur->parent->left != cur)
            cur = cur->parent;

        return cur->parent;
    }
}

void next_node_tree_test()
{
    ptree *root = new ptree(1, nullptr, nullptr, nullptr);
    root->left = new ptree(2, nullptr, nullptr, root);
    root->right = new ptree(3, nullptr, nullptr, root);

    root->left->left = new ptree(4, nullptr, nullptr, root->left);
    root->left->right = new ptree(5, nullptr, nullptr, root->left);

    root->right->left = new ptree(6, nullptr, nullptr, root->right);

    ptree *ret;
    ret = next_node_tree(root);
    cout << root->val << "\t" << ret->val << endl;

    ret = next_node_tree(root->left->right);
    cout << root->left->right->val << "\t" << ret->val << endl;

    ret = next_node_tree(root->right);
    cout << root->right->val << "\t" << ret->val << endl;
}

int test_queue_with_stack()
{
    myqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}

void test_stack_with_queue()
{
    mystack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);

    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
}

int fibonacci(int n)
{
    if (n <= 2)
        return 1;

    int rst = 1;
    int snd = 1;
    for (int i = 2; i < n; i++)
    {
        int tmp = rst + snd;
        rst = snd;
        snd = tmp;
    }

    return snd;
}

void fibonacci_test()
{
    for (int i = 1; i < 10; i++)
    {
        cout << fibonacci(i) << "\t";
    }

    cout << endl;
}

int frog_step(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    int rst = 1;
    int snd = 2;
    for (int i = 2; i < n; i++)
    {
        int tmp = rst + snd;
        rst = snd;
        snd = tmp;
    }

    return snd;
}

void test_frog_step()
{
    for (int i = 1; i < 10; i++)
    {
        int ret = frog_step(i);
        cout << ret << "\t";
    }

    cout << endl;
}

int rotate_array_p(vector<int> &vec)
{
    if (vec.size() <= 1)
        return 0;

    int left = 0;
    int right = vec.size() - 1;
    //因为原数组为有序数组，因此肯定能够保证旋转后的后半部元素的值小于等于旋转后的前半部分的值，当找到不符合这个条件的点时便是目标旋转点
    //但是同样要考虑当大部分元素相等的情况
    int mid = 0;
    while (vec[left] >= vec[right])
    {
        if (right == left + 1)
        {
            mid = right;
            break;
        }

        mid = left + (right - left) / 2;
        if (vec[left] == vec[right] && vec[mid] == vec[left])
        {
            int ret = vec[left];
            for (int i = left; i <= right; i++)
            {
                if (ret > vec[i])
                {
                    ret = vec[i];
                }
            }

            return ret;
        }

        if (vec[mid] >= vec[left])
            left = mid;
        else if (vec[mid] <= vec[right])
            right = mid;
    }

    return vec[mid];
}

void rotate_array_p_test()
{
    vector<int> vec;

    vec = {3, 4, 5, 1, 2};
    cout << rotate_array_p(vec) << endl;

    vec = {1, 2, 3, 4, 5};
    cout << rotate_array_p(vec) << endl;

    vec = {1, 1, 1, 0, 1};
    cout << rotate_array_p(vec) << endl;

    vec = {1, 0, 1, 1, 1};
    cout << rotate_array_p(vec) << endl;

    vec = {1, 1, 1, 1, 1};
    cout << rotate_array_p(vec) << endl;

    vec = {1};
    cout << rotate_array_p(vec) << endl;
}

bool matrix_alhoa_match(vector<vector<char>> &matrix, int i, int j, string &str, int id, vector<vector<bool>> &visited)
{
    if (id == str.size())
        return true;

    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
    {
        return false;
    }

    if (visited[i][j] == true)
        return false;

    if (str[id] != matrix[i][j])
        return false;

    visited[i][j] = true;
    bool ret = false;
    ret += matrix_alhoa_match(matrix, i, j - 1, str, id + 1, visited);
    if (ret)
        return true;

    ret += matrix_alhoa_match(matrix, i, j + 1, str, id + 1, visited);
    if (ret)
        return true;

    ret += matrix_alhoa_match(matrix, i + 1, j, str, id + 1, visited);
    if (ret)
        return true;

    ret += matrix_alhoa_match(matrix, i + 1, j, str, id + 1, visited);
    visited[i][j] = false;
    return ret;
}

bool matrix_alpha_match(vector<vector<char>> &matrix, string &str)
{
    if (str.size() < 1)
        return false;
    int row = matrix.size();
    int col = matrix[0].size();
    if (row < 1 || col < 1)
        return false;

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            bool ret = matrix_alhoa_match(matrix, i, j, str, 0, visited);
            if (ret)
                return ret;
        }
    }

    return false;
}

void test_matrix_alpha_match()
{
    vector<vector<char>> matrix = {{'a', 'b', 't', 'g'},
                                   {'c', 'f', 'c', 's'},
                                   {'j', 'd', 'e', 'h'}};

    string str;
    str = "abf";
    cout << matrix_alpha_match(matrix, str) << endl;

    str = "abc";
    cout << matrix_alpha_match(matrix, str) << endl;

    str = "abfca";
    cout << matrix_alpha_match(matrix, str) << endl;

    str = "cshe";
    cout << matrix_alpha_match(matrix, str) << endl;
}

int get_digits_sum(int n)
{
    int ret = 0;
    while (n != 0)
    {
        ret += n % 10;
        n = n / 10;
    }

    return ret;
}

int max_grid_robot_moving_sub(int row, int col, int i, int j, int k, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i >= row || j >= col || visited[i][j])
        return 0;

    if ((get_digits_sum(i) + get_digits_sum(j)) >= k)
        return 0;

    visited[i][j] = true;
    int ret = 0;
    ret += max_grid_robot_moving_sub(row, col, i, j - 1, k, visited);
    ret += max_grid_robot_moving_sub(row, col, i, j + 1, k, visited);
    ret += max_grid_robot_moving_sub(row, col, i - 1, j, k, visited);
    ret += max_grid_robot_moving_sub(row, col, i + 1, j, k, visited);
    return ret + 1;
}

int max_grid_robot_moving(int row, int col, int k)
{
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    return max_grid_robot_moving_sub(row, col, 0, 0, k, visited);
}

void test_max_grad_robot_moing()
{
    int row = 0;
    int col = 0;
    int k = 9;

    row = 3;
    col = 3;
    cout << max_grid_robot_moving(row, col, k) << endl;

    row = 6;
    col = 6;
    cout << max_grid_robot_moving(row, col, k) << endl;

    row = 9;
    col = 9;
    cout << max_grid_robot_moving(row, col, k) << endl;
}

int cut_rope(int n)
{
    if (n < 2) //非法输入
        return 0;

    if (n == 2)
        return 1;

    if (n == 3)
        return 2;

    int *ever = new int[n + 1];
    ever[0] = 0;
    ever[1] = 1;
    ever[2] = 2;
    ever[3] = 3; //如果能够执行到这里那么说明剪短的长度大于下标，即不仅仅包含当前长度而已
    int ret = 0;
    for (int i = 4; i <= n; i++)
    {
        ret = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            int last = ever[j] * ever[i - j];
            if (last > ret)
                ret = last;

            ever[i] = ret;
        }
    }

    ret = ever[n];
    delete ever;
    return ret;
}

void test_cut_rope()
{
    for (int m = 0; m <= 11; m++)
    {
        cout << m << "\t" << cut_rope(m) << endl;
    }
}

int cnt_1_1(int n)
{
    int bit = 1;
    int cnt = 0;
    while (bit)
    {
        if (bit & n)
            cnt++;

        bit = bit << 1; //如果使用>>则无法处理负数
    }

    return cnt;
}

int cnt_1_2(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n = (n - 1) & n;
    }

    return cnt;
}

int test_cnt_1()
{
    for (int i = 0; i < 10; i++)
    {
        cout << cnt_1_1(i) << "\t" << cnt_1_2(i) << endl;
    }
}

double mypower(double n, int exp)
{
    if (n == 0)
        return 0;

    if (exp == 0)
        return 1;

    double ret = 1;
    for (int i = 0; i < abs(exp); i++)
    {
        ret *= n;
    }

    if (exp < 0)
        return 1 / ret;

    return ret;
}

void add_one(string &no)
{
    int cx = 1;
    for (int i = 0; i < no.size(); i++)
    {
        int tmp = no[i] - '0' + cx;
        cx = tmp / 10;
        no[i] = tmp % 10 + '0';
    }

    if (cx != 0)
    {
        no += (cx + '0');
    }
}

void print_max_no(int n)
{
    if (n <= 0)
        return;

    string no("1");
    while (no.size() <= n)
    {
        for (int i = no.size() - 1; i >= 0; i--)
        {
            cout << no[i];
        }

        cout << endl;
        add_one(no);
    }
}

void print_max_no_re(int n)
{
    if (n <= 0)
        return;

    string str(n, '0');
    for (int i = 0; i < 10; i++)
    {
        str[0] = i + '0';
        print_max_no_re_sub(str, n, 0);
    }
}

void print_max_no_re_sub(string &str, int len, int id)
{
    if (id == len - 1)
    {
        cout << str << endl;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        str[id + 1] = i + '0';
        print_max_no_re_sub(str, len, id + 1);
    }
}

void test_print_max_no()
{
    print_max_no_re(-1);
    cout << endl;
    print_max_no_re(1);
    cout << endl;
    print_max_no_re(2);
    cout << endl;
}

void test_mypower()
{
    cout << mypower(0, 0) << endl;
    cout << mypower(1, 0) << endl;
    cout << mypower(2, 0) << endl;
    cout << mypower(2, -2) << endl;
    cout << mypower(2, 2) << endl;
    cout << mypower(-2, -3) << endl;
    cout << mypower(-2, 2) << endl;
    cout << mypower(-2, 3) << endl;
}

void delete_node(mylist **l, mylist *node)
{
    if ((*l) == nullptr || node == nullptr)
    {
        return;
    }

    if (node->next != nullptr)
    {
        int tmp = node->val;
        node->val = node->next->val;
        node->next->val = tmp;

        //删除结点
        mylist *cur = node->next;
        node->next = node->next->next;
        delete cur;
    }
    else if ((*l) == node)
    {
        delete *l;
        (*l) = nullptr;
        return;
    }
    else
    {
        mylist *cur = *l;
        while ((*l)->next != node)
        {
            (*l) = (*l)->next;
        }

        delete node;
        (*l)->next = nullptr;
    }
}

void test_delete_node()
{
    mylist l = {1, 2, 3};
    cout << &l << endl;

    delete_node(&l.next, l.next->next);
    cout << &l << endl;

    delete_node(&l.next, l.next);
    cout << &l << endl;

    delete_node(&l.next, l.next);
    cout << &l << endl;
}

bool match(string &str, int i, string &pattern, int j)
{
    if (i >= str.size() || j >= pattern.size())
        return true;

    if (j >= pattern.size() && i < str.size())
        return false;

    if (j < pattern.size() - 1 && pattern[j + 1] == '*')
    {
        if (pattern[j] == str[i] || (pattern[j] == '.' && i < str.size()))
        {
            bool ret = false;
            ret += match(str, i + 1, pattern, j + 2);
            ret += match(str, i + 1, pattern, j);
            ret += match(str, i, pattern, j + 2);
            return ret;
        }
        else
        {
            return match(str, i, pattern, j + 2);
        }
    }

    if (str[i] == pattern[j] || (pattern[j] == '.') && i < str.size())
    {
        return match(str, i + 1, pattern, j + 1);
    }
}

bool regex_match(string &str, string &pattern)
{
    if (str.empty() || pattern.empty())
        return false;

    return match(str, 0, pattern, 0);
}

void test_regex_match()
{
    string str = "abab";
    string pattern = ".*";
    cout << regex_match(str, pattern) << endl;
}

bool scan_uninter(string &str, int &id)
{
    int start = id;
    while (id < str.size() && str[id] <= '9' && str[id] >= '0')
        id++;

    return start != id;
}

bool scan_inter(string &str, int &id)
{
    if (str[id] == '-' || str[id] == '+')
        id++;

    return scan_uninter(str, id);
}

bool is_number(string &str)
{
    if (str.empty())
        return false;

    int id = 0;
    bool ret = scan_inter(str, id);
    if (!ret)
        return ret;

    if (str[id] == '.')
    {
        id++;
        ret += scan_uninter(str, id);
    }

    if (str[id] == 'E' || str[id] == 'e')
    {
        id++;
        ret += scan_inter(str, id);
    }

    return ret && id == str.size();
}

void test_is_number()
{
    string no = "1.2234";
    cout << no << "\t" << is_number(no) << endl;

    no = "+1.23E+15";
    cout << no << "\t" << is_number(no) << endl;

    no = "+1.23e-15";
    cout << no << "\t" << is_number(no) << endl;

    no = "+1.23E15";
    cout << no << "\t" << is_number(no) << endl;

    no = "-1.23e-1.15";
    cout << no << "\t" << is_number(no) << endl;

    no = "-1.e-1.15";
    cout << no << "\t" << is_number(no) << endl;
}

void re_order(vector<int> &vec)
{
    if (vec.size() < 2)
        return;

    int left = 0, right = vec.size() - 1;
    while (left < right)
    {
        while (left < vec.size() && vec[left] % 2 == 0)
            left++;

        while (right >= 0 && vec[right] % 2 == 1)
            right--;

        if (left < right)
        {
            swap(vec[left], vec[right]);
        }
    }
}

void test_re_order()
{
    vector<int> vec;

    vec = {1, 2, 3, 4, 5, 6};
    for (int v : vec)
    {
        cout << v << "\t";
    }

    cout << endl;
    re_order(vec);
    for (int v : vec)
    {
        cout << v << "\t";
    }

    cout << endl;

    vec = {1, 3, 3, 9, 5, 5};
    for (int v : vec)
    {
        cout << v << "\t";
    }

    cout << endl;
    re_order(vec);
    for (int v : vec)
    {
        cout << v << "\t";
    }

    cout << endl;

    vec = {2, 2, 4, 4, 6, 6};
    for (int v : vec)
    {
        cout << v << "\t";
    }

    cout << endl;
    re_order(vec);
    for (int v : vec)
    {
        cout << v << "\t";
    }

    cout << endl;
}

mylist *nth_node(mylist *head, int k)
{
    if (head == nullptr)
        return nullptr;

    mylist *it = head;
    int i = 0;
    for (i = 0; i < k && it != nullptr; i++)
    {
        it = it->next;
    }

    if (i != k)
        return nullptr;

    mylist *ret = head;
    while (it != nullptr)
    {
        ret = ret->next;
        it = it->next;
    }

    return ret;
}

void test_nth_node()
{
    int k = 1;
    mylist head = {1, 2, 3};

    k = 1;
    cout << nth_node(head.next, k)->val << endl;

    k = 2;
    cout << nth_node(head.next, k)->val << endl;

    k = 3;
    cout << nth_node(head.next, k)->val << endl;

    k = 4;
    cout << nth_node(head.next, k)->val << endl;
}

mylist *cycle_list(mylist *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    mylist *fast = head;
    mylist *slow = head;
    do //证明有环
    {
        fast = fast->next;
        if (fast == nullptr)
            return nullptr;
        fast = fast->next;
        if (fast == nullptr)
            return nullptr;
        slow = slow->next;
        if (slow == nullptr)
            return nullptr;
        /* code */
    } while (fast != slow);

    //统计环中结点的数目
    int cnt = 0;
    do
    {
        fast = fast->next;
        cnt++;
    } while (fast != slow);

    fast = head;
    for (int i = 0; i < cnt; i++)
    {
        fast = fast->next;
    }

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

void test_cycle_list()
{
    mylist head = {1, 2, 3};
    head.next->next->next->next = head.next->next;
    cout << cycle_list(head.next)->val << endl;
}

mylist *reverse_list(mylist *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    mylist *new_head;
    mylist *pre = nullptr, *node = head, *next = head->next;
    while (next != nullptr)
    {
        next = node->next;
        if (next == nullptr)
            new_head = node;

        node->next = pre;
        pre = node;
        node = next;
    }

    return new_head;
}

void test_reverse_list()
{
    mylist head(0, nullptr);

    head = {1, 2, 3, 4, 5, 6};
    cout << reverse_list(head.next) << endl;
}

mylist *merge_sort_list(mylist *rst, mylist *snd)
{
    mylist head(0, nullptr);
    mylist *node = &head;
    while (rst != nullptr && snd != nullptr)
    {
        int val = 0;
        if (rst->val < snd->val)
        {
            val = rst->val;
            rst = rst->next;
        }
        else
        {
            val = snd->val;
            snd = snd->next;
        }

        mylist *new_node = new mylist(val, nullptr);
        node->next = new_node;

        node = node->next;
    }

    while (rst != nullptr)
    {
        node->next = new mylist(rst->val, nullptr);
        node = node->next;
        rst = rst->next;
    }

    while (snd != nullptr)
    {
        node->next = new mylist(snd->val, nullptr);
        node = node->next;
        snd = snd->next;
    }

    return head.next;
}

void test_merge_sort_list()
{
    mylist head1 = {1, 2, 3, 4, 5};
    mylist head2 = {1, 2, 3, 4};
    cout << merge_sort_list(head1.next, head2.next) << endl;
    cout << merge_sort_list(head1.next, nullptr) << endl;
    cout << merge_sort_list(nullptr, head2.next) << endl;
}

bool is_same(mytree *rst, mytree *snd)
{
    if (rst == nullptr && snd != nullptr)
        return false;

    if (rst == nullptr && snd == nullptr)
        return true;

    if (rst != nullptr && snd == nullptr)
        return true;

    if (rst->val == snd->val)
    {
        bool ret = is_same(rst->right, snd->right);
        ret &= is_same(rst->left, snd->left);
        return ret;
    }
    else
    {
        return false;
    }
}

bool find_root(mytree *rst, mytree *snd)
{
    if (rst == nullptr || snd == nullptr)
        return false;

    if (rst->val == snd->val)
    {
        return is_same(rst, snd);
    }
    else
    {
        bool ret = find_root(rst->left, snd);
        if (ret)
            return ret;

        ret = find_root(rst->right, snd);
        return ret;
    }

    return false;
}

bool is_child_tree(mytree *rst, mytree *snd)
{
    if (rst == nullptr || nullptr == snd)
        return false;

    return find_root(rst, snd);
}

void test_is_child_tree()
{
    mytree root(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);

    root.left = &node2;
    root.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.right = &node6;

    cout << is_child_tree(&root, &root) << endl;
    cout << is_child_tree(&root, &node2) << endl;
    cout << is_child_tree(&root, &node3) << endl;
    cout << is_child_tree(&root, &node4) << endl;
    cout << is_child_tree(&root, &node5) << endl;
    cout << is_child_tree(&root, &node6) << endl;
    cout << is_child_tree(&root, new mytree(7, nullptr, nullptr)) << endl;
}

mytree *mrrior_tree(mytree *root)
{
    if (root == nullptr)
        return nullptr;

    mytree *tmp = root->left;
    root->left = mrrior_tree(root->right);
    root->right = mrrior_tree(tmp);
    return root;
}

void test_mrrior_tree_test()
{
    mytree root(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);

    root.left = &node2;
    root.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.right = &node6;

    root.in_traversal(&root);
    cout << endl;

    mytree *node = mrrior_tree(&root);
    root.in_traversal(node);
    cout << endl;
}

bool is_aysm_tree_sub(mytree *rst, mytree *snd)
{
    if (rst == nullptr && snd == nullptr)
        return true;

    if (rst == nullptr || snd == nullptr)
        return false;

    if (rst->val != snd->val)
        return false;

    return is_aysm_tree_sub(rst->left, snd->right) && is_aysm_tree_sub(rst->right, snd->left);
}

bool is_asysm_tree(mytree *root)
{
    if (root == nullptr)
        return true;

    return is_aysm_tree_sub(root, root);
}

void test_is_asysm_tree()
{
    mytree root(1, nullptr, nullptr);
    mytree node21(2, nullptr, nullptr);
    mytree node22(2, nullptr, nullptr);
    mytree node31(3, nullptr, nullptr);
    mytree node32(3, nullptr, nullptr);
    mytree node41(4, nullptr, nullptr);
    mytree node42(4, nullptr, nullptr);

    root.left = &node21;
    root.right = &node22;

    node21.left = &node31;
    node21.right = &node41;

    node22.left = &node42;
    node22.right = &node32;

    root.in_traversal(&root);
    cout << endl;
    cout << is_asysm_tree(&root) << endl;

    node41.left = new mytree(3, nullptr, nullptr);
    root.in_traversal(&root);
    cout << endl;
    cout << is_asysm_tree(&root) << endl;
}

void print_matrix_clock(vector<vector<int>> &m)
{
    if (m.empty() || m[0].empty())
        return;

    int top = 0;
    int bottom = m.size() - 1;
    int left = 0;
    int right = m[0].size() - 1;
    while (bottom >= top && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << m[top][i] << "\t";
        }

        cout << endl;
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << m[i][right] << "\t";
        }

        cout << endl;
        right--;
        for (int i = right; i >= left; i--)
        {
            cout << m[bottom][i] << "\t";
        }

        cout << endl;
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            cout << m[i][left] << "\t";
        }

        cout << endl;
        left++;
    }
}

void test_print_matrix()
{
    vector<vector<int>> matrix;
    matrix = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    print_matrix_clock(matrix);
}

void test_minstk()
{
    min_stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(1);
    cout << stk.min() << endl;
    stk.pop();
    cout << stk.min() << endl;
    stk.pop();
    cout << stk.min() << endl;
    stk.pop();
    cout << stk.min() << endl;
    stk.pop();
}

bool is_pop_order(vector<int> &push, vector<int> &pop)
{
    if (push.size() != pop.size())
        return false;

    stack<int> stk;
    int i = 0;
    int j = 0;
    bool ret = false;
    while (j < pop.size())
    {
        while (stk.empty() || stk.top() != pop[j])
        {
            if (i == push.size())
                return false;

            stk.push(push[i]);
            i++;
        }

        if (stk.top() != pop[j])
            return false;

        stk.pop();
        j++;
    }

    if (j == pop.size() && stk.empty())
        return true;

    return ret;
}

void is_pop_order_test()
{
    vector<int> rst, snd;

    rst = {1, 2, 3, 4};
    snd = {1, 2, 3, 4};
    cout << is_pop_order(rst, snd) << endl;

    rst = {1, 2, 3, 4};
    snd = {1, 2, 4, 3};
    cout << is_pop_order(rst, snd) << endl;

    rst = {1, 2, 3, 4};
    snd = {4, 3, 2, 1};
    cout << is_pop_order(rst, snd) << endl;

    rst = {1, 2, 3, 4};
    snd = {4, 1, 2, 3};
    cout << is_pop_order(rst, snd) << endl;
}

void test_layer_trav()
{
    mytree root(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);

    root.left = &node2;
    root.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.right = &node6;

    node3.layer_traversal(&root);
}

void layer_traversal(mytree *root)
{
    if (nullptr == root)
        return;

    queue<mytree *> q;
    q.push(root);
    int layer_cnt = 0;
    int last = 1;
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        last--;
        cout << root->val << "\t";

        if (root->left)
        {
            q.push(root->left);
            layer_cnt++;
        }

        if (root->right)
        {
            q.push(root->right);
            layer_cnt++;
        }

        if (last == 0)
        {
            last = layer_cnt;
            layer_cnt = 0;
            cout << endl;
        }
    }
}

void test_layer_traversal()
{
    mytree root(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);

    root.left = &node2;
    root.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.right = &node6;

    layer_traversal(&root);
}

void z_traversal(mytree *root)
{
    if (nullptr == root)
        return;

    queue<mytree *> q;
    stack<int> stk;
    q.push(root);
    int layer_cnt = 0;
    int last = 1;
    int layer = 1;
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        last--;
        if (layer % 2 == 1) //奇数层
        {
            bool stk_not_empty = false;
            while (!stk.empty())
            {
                cout << stk.top() << "\t";
                stk.pop();
                stk_not_empty = true;
            }

            if (stk_not_empty)
            {
                cout << endl;
            }

            cout << root->val << "\t";
        }
        else //偶数层
        {
            stk.push(root->val);
        }

        if (root->left)
        {
            q.push(root->left);
            layer_cnt++;
        }

        if (root->right)
        {
            q.push(root->right);
            layer_cnt++;
        }

        if (last == 0)
        {
            last = layer_cnt;
            layer_cnt = 0;
            layer++;
            if (layer % 2 == 1)
                cout << endl;
        }
    }
}

void test_z_traversal()
{
    mytree root(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);

    root.left = &node2;
    root.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.right = &node6;

    z_traversal(&root);
}

bool is_post_tra_sub(vector<int> &vec, int left, int right)
{
    if (left >= right)
        return true;

    int sent = vec[right];
    int i = left;
    while (i <= right && vec[i] <= sent)
    {
        i++;
    }

    if (i > right)
        return true;

    int j = i;
    while (j <= right && vec[j] > sent)
    {
        j++;
    }

    if (j != right)
        return false;

    return is_post_tra_sub(vec, left, i - 1) && is_post_tra_sub(vec, i, right - 1);
}

//根据二叉搜索树的特性，根节点一定是大于等于左子树的节点，小于等于右子树的节点
bool is_post_tra(vector<int> &vec)
{
    return is_post_tra_sub(vec, 0, vec.size() - 1);
}

void test_is_post_tra()
{
    vector<int> vec;

    vec = {};
    cout << is_post_tra(vec) << endl;

    vec = {1, 2, 3, 4, 3};
    cout << is_post_tra(vec) << endl;

    vec = {1, 2, 3, 4, 2, 3};
    cout << is_post_tra(vec) << endl;

    vec = {1, 2, 3, 4, 5};
    cout << is_post_tra(vec) << endl;
}

void tree_target_path_sub(mytree *root, int target, vector<int> &path)
{
    if (root == nullptr || target < 0)
        return;

    path.push_back(root->val);
    if (target - root->val == 0 && root->left == nullptr && root->right == nullptr)
    {
        for (int val : path)
        {
            cout << val << "\t";
        }

        cout << endl;
    }

    tree_target_path_sub(root->left, target - root->val, path);
    tree_target_path_sub(root->right, target - root->val, path);
    path.pop_back();
}

void tree_target_path(mytree *root, int target)
{
    if (root == nullptr)
        return;

    vector<int> ret;
    return tree_target_path_sub(root, target, ret);
}

void test_tree_target_path()
{
    mytree root(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);

    root.left = &node2;
    root.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.right = &node6;

    int target = 1;

    target = 1;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 2;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 3;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 4;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 5;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 6;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 7;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 8;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 9;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;

    target = 10;
    cout << "input:" << target << endl;
    tree_target_path(&root, target);
    cout << endl;
}

com_list *copy_com_list(com_list *head)
{
    if (head == nullptr)
        return head;

    //复制链表中的每一个节点并且将复制后的节点插入到被复制的节点后面
    com_list *cur = head;
    while (cur != nullptr)
    {
        com_list *copy_node = new com_list(cur->val);
        copy_node->next = cur->next;
        cur->next = copy_node;
        cur = cur->next->next;
    }

    //根据链接的情况将slibing的指针指向目标节点
    cur = head;
    while (cur != nullptr)
    {
        if (cur->sibling != nullptr)
        {
            cur->next->sibling = cur->sibling->next;
        }

        cur = cur->next->next;
    }

    //拆分链表
    cur = head;
    com_list src_head(0), dst_head(0);
    com_list *rst = &src_head, *snd = &dst_head;
    while (nullptr != cur)
    {
        rst->next = cur;
        snd->next = cur->next;

        rst = rst->next;
        snd = snd->next;
        cur = cur->next->next;
    }

    rst->next = nullptr;
    return dst_head.next;
}

void test_copy_com_list()
{
    com_list *head = new com_list(1);
    com_list *node2 = new com_list(2);
    com_list *node3 = new com_list(3);
    com_list *node4 = new com_list(4);
    com_list *node5 = new com_list(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node2->sibling = node4;
    node3->sibling = node5;
    node4->sibling = head;

    com_list *new_head = copy_com_list(head);
}

void generate_list_with_tree_sub(mytree *root, mytree *&pre)
{
    if (root == nullptr)
        return;

    if (root->left)
        generate_list_with_tree_sub(root->left, pre);

    if (pre != nullptr)
        pre->right = root;

    root->left = pre;
    pre = root;
    if (root->right)
        generate_list_with_tree_sub(root->right, pre);
}

mytree *generate_list_with_tree(mytree *root)
{
    if (root == nullptr)
        return nullptr;

    mytree *p = nullptr;
    generate_list_with_tree_sub(root, p);
    mytree *left = root;
    while (left->left != nullptr)
        left = left->left;

    return left;
}

void test_genreate_list()
{
    mytree node1(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);
    mytree node7(7, nullptr, nullptr);

    node4.left = &node2;
    node4.right = &node6;

    node2.left = &node1;
    node2.right = &node3;

    node6.left = &node5;
    node6.right = &node7;

    node1.in_traversal(&node4);
    cout << endl;

    mytree *head = generate_list_with_tree(&node4);
}

void serialize(mytree *root)
{
    if (root == nullptr)
    {
        cout << "$"
             << " ";
        return;
    }

    cout << root->val << " ";
    serialize(root->left);
    serialize(root->right);
}

mytree *deserialize(vector<int> &vec, int &id)
{
    if (id < vec.size())
    {
        if (vec[id] == -1)
            return nullptr;
        else
        {
            int no = vec[id];
            mytree *node = new mytree(no, nullptr, nullptr);
            id++;
            node->left = deserialize(vec, id);
            id++;
            node->right = deserialize(vec, id);
            return node;
        }
    }

    return nullptr;
}

void test_serialize()
{
    mytree node1(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);
    mytree node7(7, nullptr, nullptr);

    node4.left = &node2;
    node4.right = &node6;

    node2.left = &node1;
    node2.right = &node3;

    node6.left = &node5;
    node6.right = &node7;

    serialize(&node4);

    vector<int> vec = {1, 2, 4, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};
    int id = 0;
    mytree *root = deserialize(vec, id);
    return;
}

void string_random_bat_recur(string &str, int id, string &ret)
{
    if (ret.size() == str.size() && id >= str.size())
    {
        cout << ret << "\t";
        return;
    }

    for (int i = id; i < str.size(); i++)
    {
        swap(str[id], str[i]);
        string tmp = ret + string(1, str[id]);
        string_random_bat_recur(str, id + 1, tmp);
        swap(str[id], str[i]);
    }
}

void string_random_bat(string &str)
{
    if (str.size() <= 1)
    {
        cout << str << endl;
        return;
    }

    string ret;
    return string_random_bat_recur(str, 0, ret);
}

void test_string_random_bat()
{
    string str = "abc";
    string_random_bat(str);
    cout << endl;

    str = "aa"; //这个不知道算不算问题
    string_random_bat(str);
    cout << endl;
}

int parition(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int sent = vec[left];
        while (left < right)
        {
            while (left < right && vec[right] > sent)
                right--;

            vec[left] = vec[right];
            while (left < right && vec[left] <= sent)
                left++;

            vec[right] = vec[left];
        }

        vec[left] = sent;
        return left;
    }

    return left;
}

int over_half_no(vector<int> &vec)
{
    if (vec.size() <= 1)
        return -1;

    int left = 0;
    int right = vec.size() - 1;
    int id = 0;
    do
    {
        id = parition(vec, left, right);
        if (id > vec.size() / 2)
        {
            right = id - 1;
        }
        else
        {
            left = id + 1;
        }

    } while (id != (vec.size() / 2));

    //验证找到的目标的确是超过数量的一半
    int cnt = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[id] == vec[i])
            cnt++;
    }

    if (cnt > (vec.size() / 2))
        return vec[id];

    return -1; //没有目标
}

int over_half_no_on(vector<int> &vec)
{
    if (vec.size() <= 1)
        return -1;

    int ret = vec[0];
    int cnt = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (cnt == 0)
        {
            ret = vec[i];
            cnt = 1;
        }
        else if (ret == vec[i])
        {
            cnt++;
        }
        else
            cnt--;
    }

    cnt = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (ret == vec[i])
            cnt++;
    }

    if (cnt > (vec.size() / 2))
        return ret;

    return -1;
}

void test_over_half_no()
{
    vector<int> vec;
    vec = {1, 2, 3, 1, 1, 1, 1};
    cout << over_half_no_on(vec) << endl;
    cout << over_half_no(vec) << endl;

    vec = {1};
    cout << over_half_no_on(vec) << endl;
    cout << over_half_no(vec) << endl;
}

vector<int> min_k_no(vector<int> &vec, int k)
{
    if (vec.size() <= 0 || k <= 0)
        return vector<int>();

    if (k >= vec.size())
        return vec;

    int left = 0;
    int right = vec.size() - 1;
    int mid = parition(vec, left, right);
    while (left != k - 1)
    {
        if (mid > k - 1)
        {
            right = mid - 1;
            mid = parition(vec, left, right);
        }
        else
        {
            left = mid + 1;
            mid = parition(vec, left, right);
        }
    }
    while (left != k - 1)
        ;

    vector<int> ret;
    for (int i = 0; i <= left; i++)
        ret.push_back(vec[i]);

    return ret;
}

vector<int> min_k_no_heap(vector<int> &vec, int k)
{
    if (vec.size() <= 0 || k <= 0)
        return vector<int>();

    if (vec.size() <= k)
        return vec;

    priority_queue<int, vector<int>, greater<int>> q(vec.begin(), vec.end());
    vector<int> ret;
    for (int i = 0; i < k; i++)
    {
        ret.push_back(q.top());
        q.pop();
    }

    return ret;
}

void test_min_k()
{
    vector<int> vec = {1, 2, 3, 6, 2, 3, 4, 1};
    vector<int> ret;
    ret = min_k_no(vec, 3);
    for (int val : ret)
    {
        cout << val << "\t";
    }

    cout << endl;

    ret = min_k_no_heap(vec, 3);
    for (int val : ret)
    {
        cout << val << "\t";
    }

    cout << endl;
}

void test_dymanic_array()
{
    dynamic_array arr;
    //cout<<arr.medium()<<endl;
    arr.insert(1);
    cout << arr.medium() << endl;
    arr.insert(3);
    cout << arr.medium() << endl;
    arr.insert(1);
    cout << arr.medium() << endl;
    arr.insert(2);
    cout << arr.medium() << endl;
    arr.insert(1);
    cout << arr.medium() << endl;
    arr.insert(10);
    cout << arr.medium() << endl;
}

int max_sub_array_sum(vector<int> &vec)
{
    if (vec.empty())
        return 0;

    int max_sum = 0;
    int cur_sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (cur_sum <= 0)
        {
            cur_sum = vec[i];
        }
        else
        {
            cur_sum += vec[i];
        }
        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
        }
    }

    return max_sum;
}

void test_max_sub_sum()
{
    vector<int> vec;
    cout << max_sub_array_sum(vec) << endl;
    vec.push_back(1);
    cout << max_sub_array_sum(vec) << endl;
    vec.push_back(-2);
    cout << max_sub_array_sum(vec) << endl;
    vec.push_back(3);
    cout << max_sub_array_sum(vec) << endl;
    vec.push_back(4);
    cout << max_sub_array_sum(vec) << endl;
    vec.push_back(-9);
    cout << max_sub_array_sum(vec) << endl;
    vec.push_back(10);
    cout << max_sub_array_sum(vec) << endl;
}

int count_1_range(int n)
{
    if (n <= 0)
        return 0;

    if (n < 10)
        return 1;

    string strnum = to_string(n);

    int high_no = strnum[0] - '0';
    int size = strnum.size();
    int low_no = n - high_no * pow(10, size - 1);

    // 1. 统计首位为1出现次数:
    //    - 若n首位是1(如12345), 那么有 2346个
    //    - 若n的首位U不是1(如23456), 那么有 10000个
    int first_one_cnt = high_no == 1 ? (low_no + 1)
                                     : pow(10, size - 1);
    // 统计其他位为1的出现次数
    // 2. 大于 3456
    //    - 可以划分为两个区间，例如对 23456 划分为
    //      [10000, 19999], [3457, 9999]U[20001, 23456]
    //    - 对任意一个区间，后面4个数字，选择其中一个为1，其他三个都可以在0~9中任意选择，因此一共有 2*4*10^3 个1
    int other_one_cnt = high_no * (size - 1) * pow(10, size - 2);

    // 3. 递归求 [1, 3456]中1出现的次数
    return first_one_cnt + other_one_cnt + count_1_range(low_no);
}

void test_count_1_range()
{
    int i = 10;
    cout << i << "\t" << count_1_range(-1 * i) << endl;
    cout << i << "\t" << count_1_range(i) << endl;
    i = i * 10;
    cout << i << "\t" << count_1_range(i) << endl;
    i = i * 10;
    cout << i << "\t" << count_1_range(i) << endl;
    i = i * 10;
    cout << i << "\t" << count_1_range(i) << endl;
    i = 55;
    cout << i << "\t" << count_1_range(i) << endl;
}

int digits_str_at(int id)
{
    if (id < 0)
        throw out_of_range("invalid number!");

    int digit = 1;
    while (true)
    {
        int dig_no = 0;
        if (digit == 1)
            dig_no = 10;
        else
            dig_no = pow(10, digit - 1) * 9;

        if (id < dig_no) //目标数字的范围已经找到，因为每个范围内的目标数字的位数是明确的比如digit=1时，每一位所占字符为1，digit为2时每一位所占字符为2，，以此类推
        {
            int val = id / digit;
            if (digit != 1)
                val = pow(10, digit - 1) + val;

            id = id % digit;
            string tmp = to_string(val);
            return tmp[id] - '0';
        }

        id -= dig_no;
        digit++;
    }
}

void test_digits_str_at()
{
    cout << digits_str_at(0) << endl;
    cout << digits_str_at(1) << endl;
    cout << digits_str_at(2) << endl;
    cout << digits_str_at(3) << endl;
    cout << digits_str_at(10) << endl;
    cout << digits_str_at(11) << endl;
}

void merge_min_no(vector<int> &vec)
{
    vector<string> str;
    for (int i = 0; i < vec.size(); i++)
    {
        str.push_back(to_string(vec[i]));
    }

    sort(str.begin(), str.end());
    for (string val : str)
    {
        cout << val;
    }

    cout << endl;
}

void test_merge_min_no()
{
    vector<int> vec;
    vec = {1, 2, 3, 4, 5};
    merge_min_no(vec);
    vec = {22, 11, 444, 221};
    merge_min_no(vec);
}

int count_encoder_chars_sub(string &str, int id)
{
    if (id >= str.size())
        return 1;

    if (id == str.size() - 1)
        return 1;

    if (str[id] == '1')
        return count_encoder_chars_sub(str, id + 1) + count_encoder_chars_sub(str, id + 2);
    else if (str[id] == '2' && str[id + 1] <= '6')
        return count_encoder_chars_sub(str, id + 1) + count_encoder_chars_sub(str, id + 2);
    else
    {
        return count_encoder_chars_sub(str, id + 1);
    }
}

int count_encoder_chars_recur(string &str)
{
    if (str.empty())
        return 0;

    return count_encoder_chars_sub(str, 0);
}

int count_encoder_chars(string &str)
{
    if (str.size() <= 0)
        return 0;

    vector<int> ret(str.size(), 0);
    ret[ret.size() - 1] = 1;
    for (int i = ret.size() - 2; i >= 0; i--)
    {
        int cnt = ret[i + 1];
        char first = str[i];
        char second = str[i + 1];
        if (first == '1' || (first == '2' && (second <= '6' && second >= '0')))
        {
            if (i < ret.size() - 2)
            {
                cnt += ret[i + 2];
            }
            else
            {
                cnt += 1;
            }
        }

        ret[i] = cnt;
    }

    return ret[0];
}

void test_count_encoder_chars()
{
    string str;
    str = "12";
    cout << endl
         << str << endl;
    cout << count_encoder_chars(str) << endl;
    cout << count_encoder_chars_recur(str) << endl;

    str = "1234";
    cout << endl
         << str << endl;
    cout << count_encoder_chars(str) << endl;
    cout << count_encoder_chars_recur(str) << endl;

    str = "123423";
    cout << endl
         << str << endl;
    cout << count_encoder_chars(str) << endl;
    cout << count_encoder_chars_recur(str) << endl;

    str = "123411";
    cout << endl
         << str << endl;
    cout << count_encoder_chars(str) << endl;
    cout << count_encoder_chars_recur(str) << endl;

    str = "12341111";
    cout << endl
         << str << endl;
    cout << count_encoder_chars(str) << endl;
    cout << count_encoder_chars_recur(str) << endl;

    str = "11111111";
    cout << endl
         << str << endl;
    cout << count_encoder_chars(str) << endl;
    cout << count_encoder_chars_recur(str) << endl;
}

int persent_maximum(vector<vector<int>> &vec) //动态规划
{
    if (vec.empty())
        return 0;

    vector<vector<int>> table(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] < 0)
                throw out_of_range("invalid input!");

            if (i == 0 && j == 0)
            {
                continue;
            }
            else if (i == 0)
            {
                table[i][j] += table[i][j - 1];
            }
            else if (j == 0)
            {
                table[i][j] += table[i - 1][j];
            }
            else
            {
                table[i][j] += max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    return table[table.size() - 1][table[0].size() - 1];
}

int persent_maximum_im(vector<vector<int>> &vec) //优化
{
    if (vec.empty())
        return 0;

    vector<int> table(vec[0].size(), 0);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] < 0)
                throw out_of_range("invalid input!");

            int top = 0;
            int left = 0;
            if (j > 0)
                left = table[j - 1];
            if (i > 0)
                top = table[j];

            table[j] = max(left, top) + vec[i][j];
        }
    }

    return table[table.size() - 1];
}

void test_persent_maximum() //测试
{
    vector<vector<int>> vec = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};

    cout << persent_maximum(vec) << endl;
    cout << persent_maximum_im(vec) << endl;
}

int longest_nondup_str(string &str)
{
    if (str.size() <= 1)
        return str.size();

    int table[26] = {-1};
    int max_longest = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            throw out_of_range("invalid input!");

        int id = str[i] - 'a';
        if (table[id] == -1)
        {
            table[id] = i;
        }
        else
        {
            int cur_len = i - table[id];
            max_longest = max(max_longest, cur_len);
            table[id] = i;
        }
    }

    return max_longest;
}

void test_longest_nnondup_str()
{
    string str;

    str = "ababababababab";
    cout << str << "\t" << longest_nondup_str(str) << endl;
    str = "b";
    cout << str << "\t" << longest_nondup_str(str) << endl;
    str = "aaaaaaaaaaaaaaaaaaaaaa";
    cout << str << "\t" << longest_nondup_str(str) << endl;
    str = "zxcvbnmz";
    cout << str << "\t" << longest_nondup_str(str) << endl;
}

int nth_ugly(int n)
{
    if (n <= 0)
        return 1;

    vector<int> ret(n, 0);
    ret[0] = 1;

    int id2 = 0;
    int id3 = 0;
    int id5 = 0;
    int i = 1;
    for (i = 1; i < n; i++)
    {
        int min_no = min(min(ret[id2] * 2, ret[id3] * 3), ret[id5] * 5);
        ret[i] = min_no;
        while (ret[id2] * 2 <= ret[i])
            id2++;

        while (ret[id3] * 3 <= ret[i])
            id3++;

        while (ret[id5] * 5 <= ret[i])
            id5++;
    }

    return ret[i - 1];
}

void test_nth_ugly()
{
    for (int i = 1; i < 20; i++)
    {
        cout << nth_ugly(i) << endl;
    }
}

char first_one_time(string &str)
{
    if (str.empty())
        return 0;

    int table[256] = {0};
    for (int i = str.size() - 1; i >= 0; i--)
    {
        table[str[i]]++;
    }

    for (char ch : str)
    {
        if (table[ch] == 1)
            return ch;
    }

    return 0;
}

void test_first_one_time()
{
    string str;

    str = "abcasd";
    cout << first_one_time(str) << endl;

    str = "aaaaaaa";
    cout << first_one_time(str) << endl;

    str = "ababababababa";
    cout << first_one_time(str) << endl;
}

int reverse_pair_merge(vector<int> &vec, int left, int mid, int right)
{
    //[left, mid][mid + 1, right]
    if (vec[mid] < vec[mid + 1])
        return 0;

    vector<int> clone_vec = vec;
    int left_id = left;
    int right_id = mid + 1;
    int id = left;
    int ret = 0;
    while (left_id <= mid && right_id <= right)
    {
        if (clone_vec[left_id] <= clone_vec[right_id])
        {
            vec[id++] = clone_vec[left_id++];
        }
        else
        {
            vec[id++] = clone_vec[right_id++];
            ret += mid - left_id + 1;
        }
    }

    while (left_id <= mid)
    {
        vec[id++] = clone_vec[left_id++];
    }

    while (right_id <= right)
    {
        vec[id++] = clone_vec[right_id++];
    }

    return ret;
}

int reverse_pair_merge_sort(vector<int> &vec, int left, int right)
{
    if (left < right)
    {

        int mid = left + (right - left) / 2;
        int ret = reverse_pair_merge_sort(vec, left, mid);
        ret += reverse_pair_merge_sort(vec, mid + 1, right);
        ret += reverse_pair_merge(vec, left, mid, right);
        return ret;
    }

    return 0;
}

int all_reverse_pair(vector<int> &vec)
{
    if (vec.size() <= 1)
        return 0;

    return reverse_pair_merge_sort(vec, 0, vec.size() - 1);
}

void test_all_reverse_pair()
{
    vector<int> vec = {1};

    int ret;
    ret = all_reverse_pair(vec);
    cout << ret << endl;

    vec = {1, 2, 3, 4};
    ret = all_reverse_pair(vec);
    cout << ret << endl;

    vec = {3, 2, 4, 1};
    ret = all_reverse_pair(vec);
    cout << ret << endl;
}

mylist *com_node(mylist *rst, mylist *snd)
{
    if (rst == nullptr || snd == nullptr)
        return nullptr;

    mylist *cur1 = rst;
    mylist *cur2 = snd;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    int cnt = 0;
    mylist *cnt_cur = cur1 == nullptr ? cur2 : cur1;
    while (cnt_cur != nullptr)
    {
        cnt++;
        cnt_cur = cnt_cur->next;
    }

    if (cur1 == nullptr) //同上三元表达式
    {
        swap(rst, snd);
    }

    for (int i = 0; i < cnt; i++)
    {
        rst = rst->next;
    }

    while (rst != snd)
    {
        rst = rst->next;
        snd = snd->next;
    }

    return rst;
}

void test_com_node()
{
    mylist head = {1, 2, 3, 4, 5, 6};
    mylist node(33, nullptr);
    node.next = head.next->next->next->next->next;

    mylist *ret;
    ret = com_node(head.next, &node);
    cout << ret->val << endl;

    mylist head1 = {1, 2, 3, 4};
    mylist head2 = {1, 2, 3, 4};
    ret = com_node(head1.next, head2.next);
    if (ret != nullptr)
        cout << ret->val << endl;
}

int get_first_border(vector<int> &vec, int left, int right, int k)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] == k && mid == left)
        {
            return left;
        }
        else if (vec[mid] == k && vec[mid - 1] != k)
        {
            return mid;
        }
        else if (vec[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

int get_last_border(vector<int> &vec, int left, int right, int k)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] == k && mid == right)
        {
            return left;
        }
        else if (vec[mid] == k && vec[mid + 1] != k)
        {
            return mid;
        }
        else if (vec[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int sort_count(vector<int> &vec, int k)
{
    if (vec.size() < 1)
        return 0;

    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] == k)
        {
            left = get_first_border(vec, left, mid, k);
            right = get_last_border(vec, mid, right, k);
            return right - left + 1;
        }
        else if (vec[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return 0;
}

void test_sort_count()
{
    vector<int> vec;
    vec = {1, 2, 2, 2, 3, 4, 5};
    cout << sort_count(vec, 2) << endl;

    vec = {2, 2, 2, 2, 3, 4, 5};
    cout << sort_count(vec, 2) << endl;
    vec = {2, 2, 2, 2, 2, 2, 2};
    cout << sort_count(vec, 2) << endl;
    vec = {1, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5};
    cout << sort_count(vec, 5) << endl;
    vec = {1, 2};
    cout << sort_count(vec, 2) << endl;
    cout << sort_count(vec, 3) << endl;
}

int find_the_missing(vector<int> &vec)
{
    if (vec.size() <= 0)
        return -1;

    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid == 0 && vec[mid] != mid)
            return mid;
        else if (mid == vec.size() - 1 && vec[mid] == mid)
        {
            return mid + 1;
        }
        else if (vec[mid] == mid)
        {
            left = mid + 1;
        }
        else if (vec[mid] != mid)
        {
            right = mid - 1;
        }
    }

    return left;
}

void test_find_the_missing()
{
    vector<int> vec;

    vec = {1, 2, 3, 4};
    cout << find_the_missing(vec) << endl;
    vec = {0, 1, 2, 3};
    cout << find_the_missing(vec) << endl;
    vec = {0, 1, 2, 4};
    cout << find_the_missing(vec) << endl;
    vec = {1};
    cout << find_the_missing(vec) << endl;
    vec = {0};
    cout << find_the_missing(vec) << endl;
}

int find_equal_index(vector<int> &vec)
{
    if (vec.empty())
        return -1;

    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid == vec[mid])
            return mid;
        else if (mid < vec[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

void test_find_equal_index()
{
    vector<int> vec;
    vec = {0, 1, 2, 3, 4};
    cout << find_equal_index(vec) << endl;
    vec = {0};
    cout << find_equal_index(vec) << endl;
    vec = {-1, -1, 2};
    cout << find_equal_index(vec) << endl;
    vec = {0, 3, 4, 5, 6};
    cout << find_equal_index(vec) << endl;
}

mytree *kth_tree_node(mytree *root, int &k)
{
    if (k == 0 || root == nullptr)
        return nullptr;

    mytree *ret = kth_tree_node(root->left, k);
    if (ret != nullptr)
        return ret;

    if (k == 1)
        return root;
    k--;
    ret = kth_tree_node(root->right, k);
    return ret;
}

void test_kth_tree_node()
{
    mytree node1(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);
    mytree node7(7, nullptr, nullptr);

    node4.left = &node2;

    node2.left = &node1;
    node2.right = &node3;

    node4.right = &node6;
    node6.left = &node5;
    node6.right = &node7;

    mytree *ret;
    int i = 0;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 1;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 2;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 3;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 4;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 5;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 6;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 7;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;

    i = 8;
    ret = kth_tree_node(&node4, i);
    if (ret != nullptr)
        cout << ret->val << endl;
}

bool is_balanced_sub(mytree *root, int &depth)
{
    if (root == nullptr)
    {
        depth = 0;
        return true;
    }

    int left = 0;
    int right = 0;
    if (is_balanced_sub(root->left, left) && is_balanced_sub(root->right, right))
    {
        if (abs(left - right) > 1)
            return false;
        else
        {
            depth = 1 + max(left, right);
            return true;
        }
    }

    return false;
}

bool is_balanced(mytree *root)
{
    int depth;
    return is_balanced_sub(root, depth);
}

void test_is_balanced()
{
    mytree node1(1, nullptr, nullptr);
    mytree node2(2, nullptr, nullptr);
    mytree node3(3, nullptr, nullptr);
    mytree node4(4, nullptr, nullptr);
    mytree node5(5, nullptr, nullptr);
    mytree node6(6, nullptr, nullptr);
    mytree node7(7, nullptr, nullptr);

    cout << is_balanced(&node1) << endl;

    node1.left = &node2;
    cout << is_balanced(&node1) << endl;

    node1.left->left = &node3;
    cout << is_balanced(&node1) << endl;
}

vector<int> unique_no_array(vector<int> &vec)
{
    if (vec.empty() || (vec.size() & 1) == 1)
        return vector<int>();

    int ret = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        ret ^= vec[i];
    }

    //找到ret中的第一个二进制1的位置
    int bits = 0;
    while ((ret & 1) == 0 && bits < (8 * sizeof(int)))
    {
        ret = ret >> 1;
        ++bits;
    }

    int rst = 0;
    int snd = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int val = vec[i];
        if ((val >> bits) & 1)
        {
            rst ^= vec[i];
        }
        else
        {
            snd ^= vec[i];
        }
    }

    return vector<int>({rst, snd});
}

void test_unique_no_array()
{
    vector<int> vec = {1, 2, 1, 3, 4, 2};
    vector<int> ret = unique_no_array(vec);
    cout << endl;
}

int find_unique_number(vector<int> &vec)
{
    if (vec.size() <= 0)
        return -1;

    int bits[32] = {0}; //low->top
    for (int i = 0; i < vec.size(); i++)
    {
        int val = vec[i];
        for (int j = 0; j < 32; j++)
        {
            if (val & (1 << j))
            {
                bits[j]++;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < 32; i++)
    {
        if (bits[i] != 3 && bits[i] > 0)
        {
            ret |= (1 << i);
        }
    }

    return ret;
}

void test_find_unique_number()
{
    vector<int> vec = {1, 1, 3, 3, 5, 3, 1};
    cout << find_unique_number(vec) << endl;
}

vector<int> find_both_sum(vector<int> &vec, int k)
{
    if (vec.empty())
        return vector<int>();

    int left = 0;
    int right = vec.size() - 1;
    while (left < right)
    {
        if (vec[left] + vec[right] == k)
        {
            return vector<int>({vec[left], vec[right]});
        }
        else if (vec[left] + vec[right] > k)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return vector<int>();
}

void test_find_both_sum()
{
    vector<int> vec = {1, 3, 4, 6, 7, 13, 16};
    vector<int> ret;

    ret = find_both_sum(vec, 1);
    if (ret.size() == 2)
        cout << ret[0] << "\t" << ret[1] << endl;

    ret = find_both_sum(vec, 4);
    if (ret.size() == 2)
        cout << ret[0] << "\t" << ret[1] << endl;

    ret = find_both_sum(vec, 13);
    if (ret.size() == 2)
        cout << ret[0] << "\t" << ret[1] << endl;

    ret = find_both_sum(vec, 20);
    if (ret.size() == 2)
        cout << ret[0] << "\t" << ret[1] << endl;

    ret = find_both_sum(vec, 17);
    if (ret.size() == 2)
        cout << ret[0] << "\t" << ret[1] << endl;

    ret = find_both_sum(vec, 500);
    if (ret.size() == 2)
        cout << ret[0] << "\t" << ret[1] << endl;
}

//滑动窗口
void sum2target(int n)
{
    if (n < 3)
        return;

    int left = 1;
    int right = 2;
    int border = (n + 1) / 2;
    int sum = 3;
    while (left < border)
    {
        if (sum == n)
        {
            for (int i = left; i <= right; i++)
            {
                cout << i << "\t";
            }

            cout << endl;
        }
        else
        {
            while (left < border && sum > n)
            {
                sum -= left;
                left++;
                if (sum == n)
                {
                    for (int i = left; i <= right; i++)
                    {
                        cout << i << "\t";
                    }

                    cout << endl;
                }
            }
        }
        right++;
        sum += right;
    }
}

void test_sum2target()
{
    sum2target(15);
    sum2target(1);
}

void reverse_string_sub(string &str, int left, int right)
{
    if (right <= left)
        return;
    for (int i = left; i <= (right + left) / 2; i++)
    {
        swap(str[i], str[right - (i - left)]);
    }
}

string reverse_string(string &str)
{
    string ret = str;
    reverse_string_sub(ret, 0, str.size() - 1);
    return ret;
}

void test_reverse_string()
{
    string ret;
    ret = "abc";
    cout << reverse_string(ret) << endl;

    ret = "abcd";
    cout << reverse_string(ret) << endl;

    ret = "";
    cout << reverse_string(ret) << endl;
}

string lrotate_string(string &str, int k)
{
    k = k % str.size();
    if (k <= 0)
        return str;

    string ret = str;
    reverse_string_sub(ret, 0, ret.size() - 1);
    reverse_string_sub(ret, k, ret.size() - 1);
    reverse_string_sub(ret, 0, k - 1);
    return ret;
}

void test_lrotate_string()
{
    string ret;
    ret = "12345678";
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t" << lrotate_string(ret, i) << endl;
    }
}

vector<int> max_slide_window(vector<int> &vec, int k)
{
    vector<int> ret;
    if (vec.size() >= k && k >= 1)
    {
        deque<int> ids;
        for (int i = 0; i < k; i++)
        {
            while (!ids.empty() && vec[i] >= vec[ids.back()])
                ids.pop_back();

            ids.push_back(i);
        }

        for (int i = k; i < vec.size(); i++)
        {
            ret.push_back(vec[ids.front()]);
            while (!ids.empty() && vec[i] >= vec[ids.back()])
                ids.pop_back();

            while (!ids.empty() && ids.front() <= (i - k))
                ids.pop_front();

            ids.push_back(i);
        }
    }

    return ret;
}

void test_max_slide_window()
{
    vector<int> vec = {2, 3, 4, 2, 6, 2, 5, 1};
    int k = 1;
    vector<int> ret;
    ret = max_slide_window(vec, k);
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << "\t";

    cout << endl;

    k = 2;
    ret = max_slide_window(vec, k);
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << "\t";

    cout << endl;

    k = 3;
    ret = max_slide_window(vec, k);
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << "\t";

    cout << endl;

    k = 4;
    ret = max_slide_window(vec, k);
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << "\t";

    cout << endl;
}

void prob(int **cnt, int n, int &sum)
{
    if (n == 1)
    {
        (*cnt)[sum]++;
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        int cur = i + sum;
        prob(cnt, n - 1, cur);
    }
}

void print_prob(int n)
{
    if (n <= 0)
        return;

    int min_val = n;
    int max_val = 6 * n;
    int *cnt = new int[max_val + 1];
    for (int i = 0; i < max_val + 1; i++)
        cnt[i] = 0;

    for (int i = 1; i <= 6; i++)
    {
        prob(&cnt, n, i);
    }

    double total = pow(6, n);
    for (int i = min_val; i <= max_val; i++)
    {
        double ratio = cnt[i] / total;
        cout << ratio << "\t";
    }

    delete cnt;
    cout << endl;
}

void print_prob_ii(int number)
{
    if (number < 1)
        return;

    vector<vector<int>> probs(2, vector<int>(6 * number + 1, 0));
    int which_one = 0;
    for (int i = 1; i <= 6; ++i)
        probs[which_one][i] = 1;

    for (int k = 2; k <= number; ++k)
    {
        for(int i = 0; i < k; ++i)
            probs[1 - which_one][i] = 0;

        for (int i = k; i <= 6 * k; ++i)
        {
            probs[1 - which_one][i] = 0;
            for(int j = 1; j <= i && j <= 6; ++j)
                probs[1 - which_one][i] += probs[which_one][i - j];
        }

        which_one = 1 - which_one;
    }

    double total = pow(6, number);
    for (int i = number; i <= number * 6; i++)
    {
        double ratio = probs[which_one][i] / total;
        cout << ratio << "\t";
    }

    cout << endl;
}

void test_print_prob()
{
    for (int i = 0; i < 5; i++)
    {
        cout<<i<<endl;
        print_prob(i);
        print_prob_ii(i);
    }
}

bool is_contiuous(vector<int> &vec)
{
    sort(vec.begin(), vec.end());
    int zero_cnt = 0;
    int gap_cnt = 0;
    int last = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0)
        {
            zero_cnt++;
        }
        else if (last == 0)
        {
            last = vec[i];
        }
        else if (vec[i] == last + 1)
        {
            last = vec[i];
        }
        else
        {
            gap_cnt += vec[i] - last - 1;
            last = vec[i];
        }
    }

    return zero_cnt >= gap_cnt;
}

void test_is_contiuous()
{
    vector<int> vec;
    vec = {1, 2, 3, 4, 5};
    cout << is_contiuous(vec) << endl;
    vec = {1, 0, 3, 4, 5};
    cout << is_contiuous(vec) << endl;
    vec = {1, 0, 3, 5, 6};
    cout << is_contiuous(vec) << endl;
}

int mkson_question(int n, int m)
{
    if (n < 1 || m < 1)
        return -1;

    int last = 0;
    for (int i = 2; i <= n; i++)
        last = (last + m) % i;

    return last;
}

int mkson_question_II(int n, int m)
{
    if (n < 1 || m < 1)
        return -1;

    vector<int> table;
    for (int i = 0; i < n; i++)
        table.push_back(i);

    int id = 0;
    while (table.size() != 1)
    {
        for (int i = 0; i < m; i++)
        {
            id = (id + 1) % table.size();
        }

        table.erase(table.begin() + id);
    }

    return table[0];
}

void test_mkson_question()
{
    cout << mkson_question(1, 1) << endl;
    cout << mkson_question_II(1, 1) << endl;
    cout << mkson_question(4, 4) << endl;
    cout << mkson_question_II(4, 4) << endl;
    cout << mkson_question(4, 2) << endl;
    cout << mkson_question_II(4, 2) << endl;
}

int max_diff(vector<int> &vec)
{
    if (vec.size() < 2)
        return 0;

    int min_val = vec[0];
    int diff = vec[1] - min_val;
    for (int i = 2; i < vec.size(); i++)
    {
        min_val = min(vec[i - 1], min_val);
        if (diff < (vec[i] - min_val))
            diff = vec[i] - min_val;
    }

    return diff;
}

void test_max_diff()
{
    vector<int> vec = {9, 11, 8, 5, 7, 12, 16, 14};
    cout << max_diff(vec) << endl;
}

int add(int rst, int snd)
{
    int sum, cx;
    do
    {
        sum = rst ^ snd;
        cx = (rst & snd) << 1;
        rst = sum;
        snd = cx;
    } while (snd != 0);

    return rst;
}

void test_add()
{
    int rst, snd;

    rst = 1;
    snd = 2;
    cout << rst + snd << "\t" << add(rst, snd) << endl;
    rst = 11;
    snd = 28;
    cout << rst + snd << "\t" << add(rst, snd) << endl;
    rst = 15;
    snd = 27;
    cout << rst + snd << "\t" << add(rst, snd) << endl;
}

void mulity_II(vector<int> &rst, vector<int> &snd)
{
    if (rst.size() != snd.size())
        return;

    snd[0] = 1;
    for (int i = 1; i < rst.size(); i++)
    {
        snd[i] = rst[i - 1] * snd[i - 1];
    }

    long long tmp = 1;
    for (int i = snd.size() - 2; i >= 0; i--)
    {
        tmp *= rst[i + 1];
        snd[i] *= tmp;
    }
}

void test_multy()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> rst(vec), snd(vec);
    mulity_II(vec, snd);
}

void test()
{
    //string_test();
    //singleton_test();
    //find_dup_no_test();
    //find_dup_no_no_test();
    //matrix_find_test();
    //replace_space_test();
    //test_reverse_print_list();
    //test_rebuild_tree();
    //next_node_tree_test();
    //test_queue_with_stack();
    //test_stack_with_queue();
    //fibonacci_test();
    //test_frog_step();
    //rotate_array_p_test();
    //test_matrix_alpha_match();
    //test_max_grad_robot_moing();
    //test_cut_rope();
    //test_cnt_1();
    //test_cut_rope();
    //test_mypower();
    //test_print_max_no();
    //test_delete_node();
    //test_regex_match();
    //test_is_number();
    //test_re_order();
    //test_nth_node();
    //test_cycle_list();
    //test_reverse_list();
    //test_merge_sort_list();
    //test_is_child_tree();
    //test_mrrior_tree_test();
    //test_is_asysm_tree();
    //test_print_matrix();
    //test_minstk();
    //is_pop_order_test();
    //test_layer_trav();
    //test_layer_traversal();
    //test_z_traversal();
    //test_is_post_tra();
    //test_tree_target_path();
    //test_copy_com_list();
    //test_genreate_list();
    //test_serialize();
    //test_string_random_bat();
    //test_over_half_no();
    //test_min_k();
    //test_dymanic_array();
    //test_max_sub_sum();
    //test_digits_str_at();
    //test_merge_min_no();
    //test_count_encoder_chars();
    //test_persent_maximum();
    //test_longest_nnondup_str();
    //test_nth_ugly();
    //test_first_one_time();
    //test_all_reverse_pair();
    //test_com_node();
    //test_sort_count();
    //test_find_the_missing();
    //test_find_equal_index();
    //test_kth_tree_node();
    //test_is_balanced();
    //test_unique_no_array();
    //test_find_unique_number();
    //test_find_both_sum();
    //test_sum2target();
    //test_reverse_string();
    //test_lrotate_string();
    //test_max_slide_window();
    test_print_prob();
    //test_is_contiuous();
    //test_mkson_question();
    //test_max_diff();
    //test_add();
    //test_multy();
    //test_count_1_range();
}
