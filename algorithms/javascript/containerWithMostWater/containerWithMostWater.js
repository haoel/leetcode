/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let i = 0;
    let j = height.length - 1;
    let result = Number.MIN_SAFE_INTEGER;
    
    while (i < j) {
        const volume = Math.min(height[i], height[j]) * (j - i); 
        result = Math.max(result, volume);
        
        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
    }
    
    return result;
};