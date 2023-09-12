#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

struct bbox
{
    float x1, y1, x2, y2, score;
};

bool compareByScore(const bbox& a, const bbox& b)
{
    return a.score > b.score; // 按照分数从大到小排序
}

float calculateIOU(const bbox& bbox1, const bbox& bbox2) {
    float intersectionArea = max(0.0f, min(bbox1.x2, bbox2.x2) - max(bbox1.x1, bbox2.x1))
        * max(0.0f, min(bbox1.y2, bbox2.y2) - max(bbox1.y1, bbox2.y1));
    float bbox1Area = (bbox1.x2 - bbox1.x1) * (bbox1.y2 - bbox1.y1);
    float bbox2Area = (bbox2.x2 - bbox2.x1) * (bbox2.y2 - bbox2.y1);
    float unionArea = bbox1Area + bbox2Area - intersectionArea;
    return intersectionArea / unionArea;
}

void printDects(vector<bbox>& dects){
    for (vector<bbox>::iterator it = dects.begin(); it != dects.end(); it++){
        cout << (*it).x1 << " " << (*it).y1 << " " << (*it).x2 << " " << (*it).y2 << " " << (*it).score << endl;
    }

}

void printIndex(vector<int> & Index){
    cout << "Kept boxes: ";
    for (int i : Index) {
        cout << i << " ";
    }
    cout << endl;
}


vector<int> nonMaximumSuppression_bak(vector<bbox>& dects, float iouThreshold, float boxScore = 0.001){
    vector<int> keepIndex;
    vector<int> suppressed(dects.size(), 0);

    // 1. Sort the detections based on scores in descending order
    vector<int> index(dects.size());
    for (int i = 0; i < dects.size(); i++) {
        index[i] = i;
    }
    printIndex(index);
    sort(index.begin(), index.end(), [&](int i1, int i2) {
        return dects[i1].score > dects[i2].score;
    });
    printIndex(index);

    for (int i = 0; i < dects.size(); i++) {

        if (dects[index[i]].score < boxScore) {
            suppressed[index[i]] = 1;
        }
        if (suppressed[index[i]] == 1) {
            continue;
        }

        keepIndex.push_back(index[i]);

        for (int j = i + 1; j < dects.size(); j++) {
            if (dects[index[j]].score < boxScore) {
                suppressed[index[j]] = 1;
            }
            if (suppressed[index[j]] == 1) {
                continue;
            }

            float iou = calculateIOU(dects[index[i]], dects[index[j]]);
            if (iou > iouThreshold) {
                suppressed[index[j]] = 1;
            }
        }
    }

    return keepIndex;
}

/**
 * @brief nonMaximumSuppression
 * @param dects [[x1, y1, x2, y2, score], ...]
 * @param iouThreshold: float
 * @param boxScore: minest socre of bbox 
 * @return vector<bbox> 
 */
vector<bbox> nonMaximumSuppression(vector<bbox>& dects, float iouThreshold, float boxScore = 0.001){
    vector<int> keepIndex;
    vector<int> suppressed(dects.size(), 0);
    vector<bbox> keep_dects;

    // 1. Sort the detections based on scores in descending order: 对bbox按照分数大小排序
    sort(dects.begin(), dects.end(), compareByScore);

    // 2. filter by iou of two bbox
    for (int i = 0; i < dects.size(); i++){
        if (dects[i].score < boxScore){
            suppressed[i] = 1;
        }
        if (suppressed[i] == 1){
            continue;
        }

        keepIndex.push_back(i);
        keep_dects.push_back(dects[i]);

        for (int j = i + 1; j < dects.size(); j++) {
            if (dects[j].score < boxScore){
                suppressed[j] = 1;
            }
            if (suppressed[j] == 1){
                continue;
            }

            float iou = calculateIOU(dects[i], dects[j]);
            if (iou > iouThreshold) {
                suppressed[j] = 1;
            }
        }
    }

    return keep_dects;
}


int main(){
    vector<bbox> dects = {
        {10, 10, 50, 50, 0.8},
        {10, 10, 50, 50, 0.6},
        {30, 30, 70, 70, 0.7},
        {40, 40, 80, 80, 0.5}
    };

    vector<bbox> keep_dects = nonMaximumSuppression(dects, 0.5);
    printDects(keep_dects);
    return 0;
}