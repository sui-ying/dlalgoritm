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
    int partition(int low, int high) {
        int pivot = arr[high];  // 将最后一个元素选为基准值
        int i = low - 1;
        
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);  // 将较小的元素交换到前面
            }
        }
        
        swap(arr[i + 1], arr[high]);  // 将基准值放置到正确的位置
        return (i + 1);
    }

    void quickSortMain(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);      // 划分数组
            // cout << "pivotIndex: " << pivotIndex << " low: " << low << " high: "  << high << endl;
            quickSortMain(low, pivotIndex - 1);         // 递归左子数组排序
            quickSortMain(pivotIndex + 1, high);        // 递归右子数组排序
        }
    }

    /**
     * @brief quickSort
     * 
     */
    void quickSort(){
        quickSortMain(0, this->size - 1);
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
    // sort.bubbleSort();
    // sort.insertSort();
    // sort.quickSort(); 
    sort.selectionSort();
    sort.PrintArr();

    return 0;
}