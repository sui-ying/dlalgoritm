#include "../../utils/common.hpp"

class Topk
{
public:
    vector<int> arr;
    int k;
    
    Topk(vector<int>& arr, int k){
        this->arr = arr;
        this->k = k;
    }

    void printVector(){
        for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }

    void printVectorK(vector<int>& v){
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }

    vector<int> by_bubble_sort(){
        if (k > arr.size()){
            return arr;
        }
        for (int i=0; i<k; i++){
            for (int j=i+1; j<this->arr.size(); j++){
                if (arr[i] < arr[j]){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        vector<int> vk(arr.begin(), arr.begin() + k);
        return vk;
    }

    void quickSelect(vector<int> &v, int start, int end, int k)
    {
        int i = start;
        int j = end;
        if (i < j)
        {

            while (i < j)
            {
                while (i<j && temp>v[j])
                {
                    j--;
                }
                if (i < j)
                {
                    v[i] = v[j];
                    i++;
                }
                while (i < j && temp < v[i])
                {
                    i++;
                }
                if (i < j)
                {
                    v[j] = v[i];
                }
            }
            v[i] = temp;
            if (i == k)
            {
                return;
            }
            else if(i < k)
            {
                quickSelect(v, i + 1, end, k);
            }
            else
            {
                quickSelect(v, start, i - 1, k);
            }
        }
        return;
    }

    vector<int> by_quick_sort() {
        int n = arr.size();
        quickSelect(arr, 0, n-1, k);
        vector<int> vk(arr.begin(), arr.begin() + k);
        return vk;
    }

    // ~Topk();
};


int main(){
    vector<int>v = {10, 17, 50, 7, 30, 30, 27, 45, 15, 5, 36, 21};
    int k = 5;
    Topk topk(v, k);

    vector<int> vk = topk.by_bubble_sort();
    topk.printVectorK(vk);

    vector<int> vk = topk.by_quick_sort();
    topk.printVectorK(vk);

    return 0;
}