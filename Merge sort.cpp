// 内置tmp数组，复杂度高
void Merge(vector<int>& nums, int left, int right){
	// 终止条件
	if(left >= right) return;
	
	// 递归拆分
	int mid = (left+right)/2;
	Merge(nums, left, mid);
	Merge(nums, mid+1, right);
	
	// 合并排序
	vector<int> tmp(right-left+1);
	// 新建临时数组用以保存排序好的元素
	int i = left, j = mid + 1, p = 0;
	while(i<=mid && j<=right){ // 升序排列
		if(nums[i] < nums[j]) tmp[p++] = nums[i++];
		else tmp[p++] = nums[j++];
	}
	// 处理剩余左\右子数组元素
    while(i <= mid) tmp[p++] = nums[i++];
    while(j <= right) tmp[p++] = nums[j++];
    
    //结果储存
    for(int i=0; i<tmp.size(); i++){
        nums[i + left] = tmp[i];
    }
}

// 外置tmp数组，复杂度低
void Merge(vector<int>& nums, int left, int right, vector<int>& tmp){
	// 终止条件
	if(left >= right) return;
	
	// 递归拆分
	int mid = (left+right)/2;
	Merge(nums, left, mid, tmp);
	Merge(nums, mid+1, right, tmp);
	
	// 合并排序
	int i = left, j = mid + 1, p = left;
	while(i<=mid && j<=right){ // 升序排列
		if(nums[i] < nums[j]) tmp[p++] = nums[i++];
		else tmp[p++] = nums[j++];
	}
	// 处理剩余左\右子数组元素
    while(i <= mid) tmp[p++] = nums[i++];
    while(j <= right) tmp[p++] = nums[j++];
    
    //结果储存
    for(int i=left; i<=right; i++){
        nums[i] = tmp[i];
    }
}
