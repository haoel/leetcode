const twoSum = (sourceArray: number[], targetValue: number): number[] => {
    let sourceArrayMap = new Map();
    let resultArray: number[] = [];
    for (let [index, value] of sourceArray.entries()) {
        if (sourceArrayMap.has(targetValue - value)) {
            resultArray = [index, sourceArrayMap.get(value)];
        } else {
            sourceArrayMap.set(value, index);
        }
    }

    return resultArray;
};
