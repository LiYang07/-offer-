#include<iostream>


using namespace std;
void HeapAdjust(int a[], int s, int len);
void swap_(int a[], int i, int j);
//稳定的排序有：直接插入，冒泡，归并，基数
//算法OnlogN的有堆排序，快排，归并排序



//冒泡排序：时间复杂度O(n^2),O(n)，O(n^2)稳定
//冒泡排序1
//大的往后面冒，一次只能将一个数放到应该放的位置
void BubbleSort1(int a[], int len) {
	for(int i=0;i<len-1;i++)
		for (int j = i + 1; j < len; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		
		}

}
//冒泡排序2，每次都将最小的排到应该放的位置
//同时将一些元素排到了正确的位置，减少了以后的交换次数
void BubbleSort2(int a[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = len - 1; j > i; j--) {//区别在此
			if (a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		
		}
	
	}

}

//冒泡算法3，同2，但是可以避免在已经有序的情况下，增加无用的比较次数

void BubbleSort3(int a[], int len) {
	bool flag = true;
	for (int i = 0; i < len - 1&&true; i++) {
		flag = false;
		for (int j = len - 1; j > i; j--) {//区别在此
			if (a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = true;//一次交换也没有则会退出循环
			}

		}

	}

}
//直接选择排序，时间复杂度，O(n^2),不稳定
//特点：交换次数少
void SelectSort1(int a[], int len) {
	int min_pos;
	for (int i = 0; i < len - 1; i++) {
		min_pos = i;
		for (int j = i + 1; j < len; j++)
			if (a[min_pos] > a[j])
				min_pos = j;
		int temp = a[i];
		a[i] = a[min_pos];
		a[min_pos] = temp;
	}
}

//堆排序也属于选择排序，时间复杂度O（nlogn），不稳定
//堆排序一般在数组第一个位置不存放元素，从而保证第i个结点的左孩子是2*i，右结点是2*i+1
//任意结点i的根结点为i/2
void HeapSort(int a[], int len) {
	for (int i = len / 2; i >= 1; i--)
		HeapAdjust(a, i, len);
	for (int i = len; i > 1; i--) {
		swap_(a, 1, i);
		HeapAdjust(a, 1, i - 1);
	}
}

void HeapAdjust(int a[], int s, int len) {//调整树的结构，从根结点s开始
	int temp, j;
	temp = a[s];
	for (j = 2 * s; j <= len;j*=2) {
		if (j < len&&a[j] < a[j + 1])
			++j;
		if (temp >= a[j])//待插入点已经比最大的孩子结点大
			break;
		a[s] = a[j];//上移
		s = j;//应该插入的子树的根为i
	}
	a[s] = temp;//插入应该插入的位置
}
void swap_(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


//直接插入排序，平均O（n^2）,最好O(n)（已经有序的情况），最差O(n^2)，性能略好于选择和冒泡，平均次数n^2/4
//稳定排序

void InsertSort(int a[], int len) {
	int i, j, temp;
	for (i = 1; i < len; i++) {
		if (a[i] < a[i - 1]) {
			temp = a[i];
			for (j = i - 1; temp < a[j]&&j>=0; j--)
				a[j + 1] = a[j];//向右移动
			a[j+1] = temp;//插入应该插入的位置
		}
	
	}
}

//希尔排序
//仍然是插入排序,实际上是模拟的是人插牌的操作，更大步长的插入
//时间复杂度O(n^1.5),最好O(n)，最坏O(n^2),不稳定
void ShellSort(int a[], int len) {
	int i, j, temp;
	int increment = len;
	do {
		increment = increment / 3 + 1;
		for (i = increment; i < len; i++) {
			if (a[i] < a[i - increment]) {
				temp = a[i];
				for (j = i - increment; temp < a[j]; j -= increment)
					a[j + increment] = a[j];
				a[j + increment] = temp;
			}
		}
	} 
	while (increment > 1);
}
//归并排序，时间复杂度O(nlogn)
void _merge(int a[], int l, int m, int r) {
	int *aux=new int[r-l+1];
	int i, j, k;
	for (int k = l; k <= r; k++) {
		aux[k - l] = a[k];//将要归并的区间存放在临时数组中
	}


	for (k = l,i=l,j=m+1;i<=m&&j<=r; k++)//按大小顺序归并到元素组中
	{
		if (aux[i - l] < aux[j - l])
		{
			a[k] = aux[i - l];
			i++;
		}
		else {
			a[k] = aux[j - l];
			j++;
		}
	}
	while (i <= m)a[k++] = aux[(i++) - l];//左边序列还没有归并完
	while (j <= r) a[k++] = aux[(j++) - l];//右边序列还没有归并完
	delete[] aux;
}

void _merge_sort(int a[],int l,int r){
	if (r <= l)
		return;
	int m = (l + r) / 2;
	_merge_sort(a, l, m);
	_merge_sort(a, m + 1, r);
	_merge(a, l, m, r);
}

void MergSort(int a[], int len) {
	_merge_sort(a, 0, len - 1);
}


//快速排序, 时间复杂度O(nlogn), 在最极端情况下，privot每次选取都为边缘值时会退化为O(n ^ 2)
//优化方法：1.枢值选取时用三中值选取 2.区间较短时采用插入排序法
//在STL中还对递归调用层数进行了限制，如果层数过深，则采用堆排序（层数限制根据数组长度决定的）


int _Partition(int a[], int low, int high) {//最重要的函数，将数组按某一个值分割成两部分，并返回分割后的pivot值位置
	int pivotkey = a[low];//实际应该选取三点中值法
	while (low < high) {
		while (low < high&&a[high] >= pivotkey)
			high--;
		swap_(a, low, high);
		while (low < high&&a[low] < pivotkey)
			low++;
		swap_(a, low, high);
	}
	return low;
}

void _Qsort(int a[], int low, int high) {
	int pivot;
	if (low < high) {
		pivot = _Partition(a, low, high);
		_Qsort(a, low, pivot);
		_Qsort(a, pivot + 1, high); //此处可以改为尾递归，删去，用low=pivot+1替代，if改为while，用迭代取代了部分递归
	}
	//当长度小于某个值时采用插入排序。
}


void QuickSort(int a[], int len) {
	_Qsort(a, 0, len - 1);
}
int main() {
	int a[] = {9,1,5,8,3,7,4,6,2 };
	QuickSort(a, 9);
	for (auto i : a)
		cout << i << endl;
	system("pause");

}