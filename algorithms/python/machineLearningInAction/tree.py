#!/usr/bin/python
# -*- coding: UTF-8 -*-
from math import log
import operator

#创建数据集
def createDataSet():
    dataSet = [[1, 1, 'yes'],
               [1, 1, 'yes'],
               [1, 0, 'no'],
               [0, 1, 'no'],
               [0, 1, 'no']]
    labels = ['no surfacing', 'flippers']
    return dataSet, labels

"""
#香农商的概念；商越高，则混的数据也越多
    
"""
def calcShannonEnt( dataSet):
    numEntries = len(dataSet)
    labelCounts = {}
    # 统计每个label出现的次数
    for featVec in dataSet:
        currentLabel = featVec[-1]
        if currentLabel not in labelCounts.keys():
            labelCounts[currentLabel] = 0
        labelCounts[currentLabel] += 1
    shannonEnt = 0.0
    # 计算香农商的结果-Xilog2(Xi)
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntries
        shannonEnt -= prob * log(prob, 2)
    return shannonEnt


"""
注意列表之间append和extend之间的区别：
a = [1,2,3];b=[4,5,6]
a.append(b) = [1,2,3,[4,5,6]]
a.extend(b) = [1,2,3,4,5,6]

该方法相当于降维处理
"""


def splitDataSet( dataSet, axis, value):
    retDataSet = []
    for featVec in dataSet:
        if featVec[axis] == value:
            reduceFeatVec = featVec[:axis]
            reduceFeatVec.extend(featVec[axis + 1:])
            retDataSet.append(reduceFeatVec)
    return retDataSet


"""
选择最优的数据集划分方式：
求出子集的商：
有max（总商-子集的商）
求出对应最大的商值，求出最好的信息增益
"""
def chooseBestFeatureToSplit( dataSet):
    numFeatures = len(dataSet[0]) - 1
    baseEntropy = calcShannonEnt(dataSet)
    bestInfoGain = 0.0
    bestFeature = -1
    count = 0
    smallCount = 0
    for i in range(numFeatures):

        #获取第0-n行中，所有列的数据 -> list
        featList = [example[i] for example in dataSet]
        #将list数据，整合成set,即去除了相同的key；
        #创建唯一的分类标签列表
        uniqueVals = set(featList)
        newEntropy = 0.0
        count += 1
        #找出所有所有列的的商，
        #计算每种划分模式的信息商
        for value in uniqueVals:
            smallCount += 1
            subDataSet = splitDataSet(dataSet, i, value)
            prob = len(subDataSet) / float(len(dataSet))
            newEntropy += prob * calcShannonEnt( subDataSet)
        infoGain = baseEntropy - newEntropy
        #计算最好的信息增益
        if (infoGain > bestInfoGain):
            bestInfoGain = infoGain
            bestFeature = i;
    return bestFeature;

def majorityCnt(classList):
    classCount ={}
    for vote in classList:
        if vote not in classCount.keys():classCount[vote] = 0
        classCount[vote] += 0
    sortedClassCount = sorted(classCount.iteritems(),key=operator.itemgetter(1),reverse=True)
    return sortedClassCount[0][0]

def createTree(dataSet,labels):
    classList = [example[-1] for example in dataSet]
    #类别完全相同，则停止划分
    if classList.count(classList[0] == len(classList)):
        return classList[0]
    #遍历完所有的特征时，返回出现次数最多的
    if len(dataSet[0]) == 1:
        return majorityCnt(classList)
    bestFeat = chooseBestFeatureToSplit(dataSet)
    if bestFeat == -1:
        return
    bestFeatLabel = labels[bestFeat]
    myTree = {bestFeatLabel:{}}
    #得到列表中包含的所有属性值
    del (labels[bestFeat])
    featValues = [example[bestFeat] for example in dataSet]
    uniqueVals = set(featValues)
    for value in uniqueVals:
        subLabels = labels[:]
        myTree[bestFeatLabel][value] = createTree(splitDataSet(dataSet,bestFeat,value),subLabels);
        print myTree
    return myTree



mydat, labels = createDataSet()
# print mydat
# print calcShannonEnt(mydat)
# mydat[0][-1] = 'maybe'
# print calcShannonEnt(mydat)
# print splitDataSet(object,mydat,0,0)
#print chooseBestFeatureToSplit( mydat)
print createTree(mydat,labels)
