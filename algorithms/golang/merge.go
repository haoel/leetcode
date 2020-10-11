package merge

func merge(intervals [][]int) [][]int {
    if len(intervals) < 1 {
        return [][]int{}
    }
    res := [][]int{}
    sort.Slice(intervals, func(i,j int) bool{
        return intervals[i][0] < intervals[j][0]
    })
    
    l := intervals[0][0]
    r := intervals[0][1]
    
    for i := 1; i < len(intervals); i++ {
        curr := intervals[i]
        if l <= curr[0] && curr[0] <= r {
            if r <= curr[1] {
                r = curr[1]
            }
        }else {
            res = append(res, []int{l, r})
            l = curr[0]
            r = curr[1]
        }
    }
    res = append(res, []int{l, r})
    return res
}
