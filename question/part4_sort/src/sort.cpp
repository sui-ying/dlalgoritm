#include <iostream>
#include <vector>

using namespace std;


/**
 * @brief 包含各种排序算法
 * 
 */
class Sort
{
public:
    vector<int> arr;
    int size;

    Sort(vector<int>& arr, int size){
        this->arr = arr;
        this->size = size;
    }
    
    void PrintArr(){
        for (int i = 0; i < this->size; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
    
    /**
     * @brief swap two nums
     * @param num1 
     * @param num2 
     */
    void swap(int & num1, int & num2){
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    /**
     * @brief bubbleSort
     * O(n)=O(n^2), T(n)=O(1)
     */
    void bubbleSort(){
        for (int i = 0; i < this->size-1; i++){
            for (int j = 0; j < this->size-1-i; j++){
                if (this->arr[j] > this->arr[j+1]){
                    swap(this->arr[j], this->arr[j+1]);
                }
            }
        }
    }

    /**
     * @brief 
     * O(n)=O(n^2), T(n)=O(n)
     */
    void insertSort(){
        for (int i = 1; i<this->size; i++){
            int base = this->arr[i];
            int j = i-1;
            while (j>=0 && this->arr[j] > base){
                this->arr[j+1] = this->arr[j];
                j--;
            }
            this->arr[j+1] = base;
        }    
    }

    // ****************************** quickSort ****************************** //
    /**
     * 选基准元素，小于基准元素移向左边，大于基准元素移向右边，直到从小到大排列好
    */
    void quickSortMain(int l, int r, bool reverse = false) {
        if (l + 1 >= r) {
            return;
        }
        if ( ! reverse ){  // 正序
            int first = l, last = r, key = arr[first];
            while (first < last){
                while(first < last && arr[last] >= key) { // 比基准数key大，直到找到比基准数小的数last--
                    --last;  
                }
                arr[first] = arr[last];  // 将小于基准数arr[last] 赋值给arr[first]
                while (first < last && arr[first] <= key) {  // 比基准数key小，first++
                    ++first;
                } 
                arr[last] = arr[first];  // 将大于基准数arr[first] 赋值给arr[last]
            }
            arr[first] = key;   // 直到first 和 last 相遇， 将基准值key赋值给arr[first]
            quickSortMain(l, first, reverse);   // 对左边{l, first}进行快排
            quickSortMain(first + 1, r, reverse);  // 对右边{first+1, last}进行快排
        } else {  // 逆序
            int first = l, last = r, key = arr[first];
            while (first < last){
                while(first < last && arr[last] <= key) { // 比基准数key小，直到找到比基准数大的数last--
                    --last;  
                }
                arr[first] = arr[last];  // 将大于基准数arr[last] 赋值给arr[first]
                while (first < last && arr[first] >= key) {  // 比基准数key大，first++
                    ++first;
                } 
                arr[last] = arr[first];  // 将小于基准数arr[first] 赋值给arr[last]
            }
            arr[first] = key;   // 直到first 和 last 相遇， 将基准值key赋值给arr[first]
            quickSortMain(l, first, reverse);   // 对左边{l, first}进行快排
            quickSortMain(first + 1, r, reverse);  // 对右边{first+1, last}进行快排
        }
    }

    void quickSort(){
        quickSortMain(0, size-1);
    }
  
    /**
     * @brief selectionSort
     * O(n)=O(n^2), T(n)=O(1)
     */
    void selectionSort(){
        for (int i=0; i<this->size; i++){
            for (int j=i+1; j<this->size; j++){
                if (arr[i] > arr[j]){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    // ~Sort();
};


int main() {
    vector<int> arr = {3, 1, 8, 4, 2};
    int n = arr.size();

    Sort sort(arr, n);
    sort.bubbleSort();
    sort.insertSort();
    sort.quickSort(); 
    sort.selectionSort();
    sort.PrintArr();

    return 0;
}