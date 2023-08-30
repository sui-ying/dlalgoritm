"""
NMS(Non-Maximum Suppression)的目的是筛选出重叠程度高的目标框，并将其合并为一个单独的框，以减少重复检测和提高检测精度。
在该过程中，NMS算法会计算每个目标框与其他框之间的IoU（Intersection over Union），并删除IoU大于某个阈值的重叠框。
这样可以确保检测到的目标框不会有太大的重叠，使得目标检测结果更加准确且不重复。
"""

import numpy as np


def non_max_suppression(dects, iou_threshold):
    """
    非极大值抑制函数，用于目标框去重。
    :param dects: numpy-2d, 待处理的目标框列表，每个目标框为一个含有5个元素的列表或元组，
                  分别为左上角x坐标、左上角y坐标、右下角x坐标、右下角y坐标和得分。
    :param iou_threshold: IOU阈值，用于判断两个目标框是否重叠。
    :return: 保留的目标框索引列表。
    """
    # 提取目标框得分，按得分降序排序，得到新的索引顺序
    index = np.argsort(dects[:, -1])[::-1]
    # 获取排序后的dects
    sort_dects = dects[index]

    # 初始化被抑制的目标框
    num_dects = sort_dects.shape[0]
    suppressed = np.zeros(num_dects, dtype=int)

    # 记录保留的目标框的索引
    keep_index = []

    for i in range(num_dects):
        # 如果当前目标框已被抑制，则跳过
        if suppressed[i] == 1:
            continue

        # 否则将当前目标框的索引添加到保留列表中
        keep_index.append(i)

        # 遍历之后的目标框，判断是否重叠并抑制重叠的目标框
        for j in range(i+1, num_dects):
            if suppressed[j] == 1:
                continue
            iou, area_i, area_j = bbox_iou(sort_dects[i], sort_dects[j])
            if iou > iou_threshold:
                suppressed[j] = 1

    return keep_index


def bbox_iou(box1, box2):
    """
    计算两个矩形框的交并比(IOU)
    :param box1: 第一个矩形框，格式为[x1, y1, x2, y2, score]
    :param box2: 第二个矩形框，格式为[x1, y1, x2, y2, score]
    :return: 交并比(IOU)
    """
    x1 = max(box1[0], box2[0])
    y1 = max(box1[1], box2[1])
    x2 = min(box1[2], box2[2])
    y2 = min(box1[3], box2[3])
    area1 = (box1[2] - box1[0]) * (box1[3] - box1[1])
    area2 = (box2[2] - box2[0]) * (box2[3] - box2[1])
    if x1 < x2 and y1 < y2:
        intersection = (x2 - x1) * (y2 - y1)
        union = area1 + area2 - intersection
        return intersection / union, area1, area2
    else:
        return 0, area1, area2


if __name__ == '__main__':
    dects = np.array([[30, 30, 40, 40, 0.7],
                      [32, 32, 42, 42, 0.8],
                      [30, 30, 40, 40, 0.6]])
    index_lst = non_max_suppression(dects, 0.5)
    print(index_lst)