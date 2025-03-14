# 题目描述

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

 

示例 1：

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

```

示例 2：

```
输入：nums = [3,2,4], target = 6
输出：[1,2]

```

示例 3：

```
输入：nums = [3,3], target = 6
输出：[0,1]

```

 

提示：

* 2 <= nums.length <= 104

* -109 <= nums[i] <= 109

* -109 <= target <= 109

* 只会存在一个有效答案

 

进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？



# 算法

```c
struct hash_node{
    int key;
    int ival;
    UT_hash_handle hh;
};

struct hash_node* hash_table;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //没有考虑没有找到的情况，没有找到应该返回NULL，就不用malloc了
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // //n2的解法
    // for(int i = 0;i < numsSize-1;i++){
    //     for(int j = i+1;j < numsSize;j++){
    //         if(nums[i] + nums[j] == target){
    //             int* returned = (int*)malloc(sizeof(int) * 2);
    //             returned[0] = i;
    //             returned[1] = j;
    //             *returnSize = 2;
    //             return returned;
    //         }
    //     }
    // }
    // // //没有找到返回NULL
    // *returnSize = 0;
    // return NULL;

    /*hash解法。
    注意，hash_table每一次调用的时候都初始化一次，否则会存储上一个case中的内容，影响下个case的判断
    如：如果把hash_table定义为全局变量，且只在外面初始化一次，每运行一个case，都会在这个hash_table中放入数据
    影响下一个case的判断。
    */
    hash_table = NULL;
    for(int i = 0;i < numsSize;i++){
        // printf("i=%d\n",i);
        struct hash_node* tmp;
        int restNum = target - nums[i];
        HASH_FIND_INT(hash_table,&restNum,tmp);

        // printf("tmp is %d\n",tmp==NULL?0:1);
        if(tmp == NULL){
            struct hash_node* node = malloc(sizeof(struct hash_node));
            node->key = nums[i];
            node->ival = i;
            HASH_ADD_INT(hash_table,key,node); 
        }else{
            int* returned = (int*)malloc(sizeof(int)*2);
            *returnSize = 2;
            returned[0] = tmp->ival;
            returned[1] = i;
            return returned;
        }
    }

    *returnSize = 0;
    return NULL;
}
```

