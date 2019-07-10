/**
 * @param {number[]} digits
 * @return {number[]}
 */
const plusOne = sourceArray => {
  let len = sourceArray.length;
  for (let i = len - 1; i >= 0; i--) {
    if (sourceArray[i] < 9) {
      sourceArray[i] += 1;
      return sourceArray;
    }
    sourceArray[i] = 0;
  }
  return [1, ...sourceArray];
};
