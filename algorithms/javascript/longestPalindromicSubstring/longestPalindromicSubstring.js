/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    // ll: Left index of the longest palindrome.
  // rr: Right index of the longest palindrome.
  let ll = 0, rr = 0;

  // Iterate all palindromes with center indices
  // [..., i, ...] or [... i, i+1, ...]
  for (let i = 0; i < s.length; i++) {
    for (let j of [i, i+1]) {
        // console.log(j);
      for (l = i, r = j; s[l] && s[l] === s[r]; l--, r++)

        // Found a new palindrome [l, ..., i, j, ..., r]
        // Update the ll, rr if the newly found palindrome is longer than the
        // existing one.
        [ll, rr] = (r-l+1) > (rr-ll+1) ? [l, r] : [ll, rr];
        // console.log(ll + ' + ' + rr);
    }
  }
  return s.substring(ll, rr+1);
};