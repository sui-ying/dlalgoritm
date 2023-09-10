#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

struct bbox
{
    float x1, y1, x2, y2, score;
};

float calculateIOU(const bbox& bbox1, const bbox& bbox2) {
    float intersectionArea = max(0.0f, min(bbox1.x2, bbox2.x2) - max(bbox1.x1, bbox2.x1))
        * max(0.0f, min(bbox1.y2, bbox2.y2) - max(bbox1.y1, bbox2.y1));
    float bbox1Area = (bbox1.x2 - bbox1.x1) * (bbox1.y2 - bbox1.y1);
    float bbox2Area = (bbox2.x2 - bbox2.x1) * (bbox2.y2 - bbox2.y1);
    float unionArea = bbox1Area + bbox2Area - intersectionArea;
    return intersectionArea / unionArea;
}

vector<int>  nonMaximumSuppression(vector<bbox>& dects, float iouThreshold, float boxScore = 0.001){
    vector<int> keepIndex;
    vector<int> suppressed(dects.size(), 0);

    // 1. Sort the detections based on scores in descending order
    vector<int> index(dects.size());
    for (int i = 0; i < dects.size(); i++) {
        index[i] = i;
    }
    sort(index.begin(), index.end(), [&](int i1, int i2) {
        return dects[i1].score > dects[i2].score;
    });

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

int main(){
    std::vector<bbox> dects = {
        {10, 10, 50, 50, 0.8},
        {10, 10, 50, 50, 0.6},
        {30, 30, 70, 70, 0.7},
        {40, 40, 80, 80, 0.5}
    };

    std::vector<int> keepIndex = nonMaximumSuppression(dects, 0.5);

    std::cout << "Kept boxes: ";
    for (int i : keepIndex) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}