#ifndef QUESTION_HPP
#define QUESTION_HPP

#include "ios_lib.hpp"
#include "mylist.hpp"
#include "mytree.hpp"
#include "myqueue.hpp"
#include "mystack.hpp"

//2 对于长度为n的数组里所有数字都在0~n-1,数组中部分数组是重复的，无法得知具体的重复数字和重复的次数，找出任意一个重复的数组

//先排序再查找
int find_dup_number(vector<int> &vec);
//通过map进行索引
int find_dup_number_map(vector<int> &vec);
int find_dup_number_scan(vector<int> &vec);

//还有一个解法便是利用归并排序的parition进行分割统计两边的元素总量，进而将重复数组确定在其中一边

void find_dup_no_test();

//3 长度为n+1的数组中数字的范围在1~n，其中至少有一个重复的，找出任意的重复数，不能修改数组
//快慢指针
int find_dup_no_p(vector<int> &vec);
//二分查找
int find_dup_no_bin(vector<int> &vec);
void find_dup_no_no_test();

//4 在一个二维有序的矩阵中查找一个数是否存在，矩阵同一行左边的数小于右边的数，同一列上面的数小于下面的数

bool matrix_find(vector<vector<int>> &matrix, int target);
void matrix_find_test();

//5 替换字符串中的空格为%20
string replace_space(const string &str);
void replace_space_test();

//6 反向输出链表的元素
void reverse_print_list(mylist *l);
void test_reverse_print_list();

//7 根据树的前序遍历和中序遍历构建树的结构，已知不存在重复数
mytree *rebuild_tree(vector<int> &pre, vector<int> &mid);
mytree *rebuild_tree_sub(vector<int> &pre, int pre_left, int pre_right, vector<int> &mid, int mid_left, int mid_right);
void test_rebuild_tree();

//8 二叉树中序遍历的下一个节点，这本身是一个线索二叉树的问题
ptree *next_node_tree(ptree *root);

void next_node_tree_test();

//10 斐波那契数列
int fibonacci(int n);
void fibonacci_test();

//青蛙跳台阶问题
int frog_step(int n);
void test_frog_step();

//11 有序数组的旋转数组 3,4,5,1,2 --> 1
int rotate_array_p(vector<int> &vec);
void rotate_array_p_test();

//12 矩阵中的字母匹配问题
bool matrix_alhoa_match(vector<vector<char>> &matrix, int i, int j, string &str, int id, vector<vector<bool>> &visited);
bool matrix_alpha_match(vector<vector<char>> &matrix, string &str);
void test_matrix_alpha_match();

//13 机器人移动问题，机器人从(0,0)开始无法移动各个位之和大于等于k的格子，该机器人最大能够到达多少个格子
int max_grid_robot_moving(int row, int col, int k);
int max_grid_robot_moving_sub(int row, int col, int i, int j, int k, vector<vector<bool>> &visited);
int get_digits_sum(int n);
void test_max_grad_robot_moing();

//14 长为n的绳子，截断成m段，求截断后所有段的最大乘积
int cut_rope(int n);
void test_cut_rope();

//15 给定一个数字，返回给定数字二进制中的1的位数
int cnt_1_1(int n);
int cnt_1_2(int n);
int test_cnt_1();

//16 不考虑大数问题是先看书power(double n, int exp);
double mypower(double n, int exp);
void test_mypower();

//17 打印1到最大的n位数字
void add_one(vector<int> &);
void print_max_no(int n);
void print_max_no_re(int n);
void print_max_no_re_sub(string &str, int len, int id);
void test_print_max_no();

//18 删除链表的结点
void delete_node(mylist *l, mylist *node);
void test_delete_node();

//19 正则表达式匹配.*
bool match(string &str, int i, string &pattern, int j);
bool regex_match(string &str, string &pattern);
void test_regex_match();

//20 判断给定的字符串是不是一个数字
bool is_number(string &str);
void test_is_number();

//21 调整数组将偶数置于奇数的前面
void re_order(vector<int> &vec);
void test_re_order();

//22 链表中的倒数第k个结点
mylist *nth_node(mylist *head, int k);
void test_nth_node();

//23 寻找链表中的环入口
mylist *cycle_list(mylist *head);
void test_cycle_list();

//24 反转链表
mylist *reverse_list(mylist *head);
void test_reverse_list();

//25 合并两个有序链表
mylist *merge_sort_list(mylist *rst, mylist *snd);
void test_merge_sort_list();

//26 输入两棵树，判断第二棵是不是第一棵的子结构
bool is_same(mytree *rst, mytree *snd);
bool find_root(mytree *rst, mytree *snd);

bool is_child_tree(mytree *rst, mytree *snd);
void test_is_child_tree();

//27 二叉树的镜像
mytree *mrrior_tree(mytree *root);
void test_mrrior_tree_test();

//28 判断树是不是对称二叉树
bool is_aysm_tree_sub(mytree *rst, mytree *snd);
bool is_asysm_tree(mytree *root);
void test_is_asysm_tree();

//29 按照顺时针打印矩阵
void print_matrix_clock(vector<vector<int>> &m);
void test_print_matrix();

//30 最小栈 见mystack.hpp中的min_stack的类定义

//31 给定两个栈的压入和弹出的序列，判断弹出的序列是不是合理
bool is_pop_order(vector<int> &push, vector<int> &pop);
void is_pop_order_test();

//32 二叉树的层序遍历 实现见mytree中的layer_traversal
void test_layer_trav();

//33 从上到下分层打印二叉树
void layer_traversal(mytree *root);
void test_layer_traversal();

//34 二叉树的之字形遍历
void z_traversal(mytree *root);
void test_z_traversal();

//35 判断给定的序列是不是二叉搜索树的后序遍历序列
bool is_post_tra_sub(vector<int> &vec, int left, int right);
bool is_post_tra(vector<int> &vec);
void test_is_post_tra();

//34 打印出树中从根节点开始，结点之和等于给定值的路径
void tree_target_path_sub(mytree *root, int target, vector<int> &path);
void tree_target_path(mytree *root, int target);
void test_tree_target_path();

//35 复制复杂链表
com_list *copy_com_list(com_list *head);
void test_copy_com_list();

//36 给定二叉排序树，生成有序的双向链表，left为pre,right为next，解题思路是二叉树的线索化
void generate_list_with_tree_sub(mytree *root, mytree *&pre);
mytree *generate_list_with_tree(mytree *root);
void test_genreate_list();

//37 序列化二叉树，实现两个函数分别用来序列化和反序列化二叉树
void serialize(mytree *root);
mytree *deserialize(vector<int> &vec, int &id);
void test_serialize();

//38 给定字符串，输出该字符串所有可能的组合方式
void string_random_bat_recur(string &str, int id, string &ret);
void string_random_bat(string &str);
void test_string_random_bat();

//39 找出数组中出现次数超过一半的数字
int parition(vector<int> &vec, int left, int right);
int over_half_no(vector<int> &vec);
int over_half_no_on(vector<int> &vec);
void test_over_half_no();

//40 最小的k个数字
vector<int> min_k_no(vector<int> &vec, int k);
vector<int> min_k_no_heap(vector<int> &vec, int k);
void test_min_k();

//41 寻找中位数，实现见myqueue里面的dymaic_array
void test_dymanic_array();

//42 最大子数组之和
int max_sub_array_sum(vector<int> &vec);
void test_max_sub_sum();

//43 给定数字n,返回给定数字1~n中1的个数，比如n=10，1的个数为2
int count_1_range(int n); //
void test_count_1_range();

//44 给定序列012345678910111213...返回该序列中的第n个位置的数字
int digits_str_at(int id);
void test_digits_str_at();

//45 给定一组数字，输出这组数字组成的最小数
void merge_min_no(vector<int> &vec);
void test_merge_min_no();

//46 将字符编码为数字a-z=1-26比如，a=1,b=2,c=3,...,z=26，给定一串字符串判断该字符串有多少种可能的目标编码（比如26既可以是z也可以是bf）
int count_encoder_chars_sub(string &str, int id);
int count_encoder_chars_recur(string &str); //利用递归解决
int count_encoder_chars(string &str);       //动态规划
void test_count_encoder_chars();

//47 给定一个棋盘，棋盘上每一个格子都放有一定的礼物数，从0，0位置开始，每次可以右向下移动，求路径上获得礼物之和最大为多少
//可以用递归和动态规划求解
int persent_maximum(vector<vector<int>> &vec);                         //动态规划
int persent_maximum_im(vector<int> &vec);                   //优化
void test_persent_maximum();                                           //测试


//48 给定字符串计算出该字符串的最长不包含重复字符的字符串长度
int longest_nondup_str(string &str);
void test_longest_nnondup_str();

//49 丑数为因子只有2,3,5的数，给出第n给丑数，从1开始计算
int nth_ugly(int n);
void test_nth_ugly();

//50 第一个只出现一次的字符
char first_one_time(string &str);
void test_first_one_time();

//51 给定一组数字，输出该数字的所有逆序对
int reverse_pair_merge(vector<int> &vec, int left, int mid, int right);
int reverse_pair_merge_sort(vector<int> &vec, int left, int right);
int all_reverse_pair(vector<int> &vec);
void test_all_reverse_pair();

//52 输入两个链表返回两个链表的公共节点
mylist *com_node(mylist *rst, mylist *snd);
void test_com_node();

//53 统计一个排序数组中制定数字出现的次数
//最直观的是直接线性搜索，但是完全可以使用二分查找法进行查找
//先用二分查找法查到目标元素位置，再在两边通过二分法找到边界
int get_first_border(vector<int> &vec, int left, int right, int k);
int get_last_border(vector<int> &vec, int left, int right, int k);
int sort_count(vector<int> &vec, int k);
void test_sort_count();

//54 一个长度为n-1的有序数组中的值取值范围为0~n-1，其中每个数字走只存在一个，找出0~n-1不在数组中的元素
int find_the_missing(vector<int> &vec);
void test_find_the_missing();

//给定一个有序数组找出数组中下标和元素的值相等的值(该数组元素唯一)
int find_equal_index(vector<int> &vec);
void test_find_equal_index();

//55 二叉搜索树的第k大的节点
mytree *kth_tree_node(mytree *root, int &k);
void test_kth_tree_node();

// 判断给定的二叉树是不是平衡树
bool is_balanced(mytree *root);
void test_is_balanced();

//56 数组中只有两个数字出现一次，其他所有数字都出现了两次
vector<int> unique_no_array(vector<int> &vec);
void test_unique_no_array();

//只有一个数字出现一次其他所有数字都出现3次，返回出现一次的元素
int find_unique_number(vector<int> &vec);
void test_find_unique_number();

//57 给定一个有序的数组，返回其中一对和为k的数字
vector<int> find_both_sum(vector<int> &vec, int k);
void test_find_both_sum();

//打印和为目标值的连续序列，比如1,2,3,4,5,6其中k=15，输出[1,2,3,4,5][4,5,6]和[7,8]
void sum2target(int n);
void test_sum2target();

//58 翻转字符串
void reverse_string_sub(string &str, int left, int right);
string reverse_string(string &str);
void test_reverse_string();

//左旋字符串
string lrotate_string(string &str, int k);
void test_lrotate_string();

//59 队列的最大值，执行滑动窗口大小为3，返回每个窗口的最大值
vector<int> max_slide_window(vector<int> &vec, int k);
void test_max_slide_window();

//在O(1)的时间复杂度里实现队列的pop,push,max三个操作，实现见myqueue中的max_queue

//60 n个色子，打印出所有筛子正面朝上的和的概率TODO:
void print_prob(int n);
void print_prob_ii(int n);
void test_print_prob();

//61 扑克牌的顺子问题，从扑克牌中随意抽取5n张牌，大小王可以算作任意牌，抽中的是不是顺子，大小王定义为0
bool is_contiuous(vector<int> &vec);
void test_is_contiuous();

//62 对于一个环每次删除第m个元素，返回删除的第m个数字
int mkson_question(int n, int m);
int mkson_question_II(int n, int m);
void test_mkson_question();

//63 股票问题
int max_diff(vector<int> &vec);
void test_max_diff();

//64 不使用循环，+-*/运算符计算1~n的和
//书上列举的是模板元编程，函数指针，构造函数之类的，感觉越界了，算法不应该有这些

//65 不用加减做+
int add(int rst, int snd);
void test_add();

//66 构建乘积表
void mulity_II(vector<int> &rst, vector<int> &snd);
void test_multy();

void test();
#endif