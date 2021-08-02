class BIT {
    vector<int> tree; // 从下标1开始保存元素
    int len;
public:
    BIT(int n):len(n), tree(n+1){}

	BIT(vector<int>& nums>{
		len = nums.size();
		tree = vector<int>(nums.size()+1);
	} 
    
    static int Lowbit(int x){
        return x & -x;
    }
    
    int query(int x){ // 区间查询
        int res = 0;
        while(x){
            res += tree[x];
            x -= Lowbit(x);
        }
        return res;
    }
    
    void update(int x){ // 单点更新
        while(x<len){
            tree[x]++;
            x += Lowbit(x);
        }
    }
};
