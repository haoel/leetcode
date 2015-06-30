package rectangleArea

import (
	"math"
)

func computeArea(A, B, C, D, E, F, G, H float64) float64 {
	area := (D-B)*(C-A) + (H-F)*(G-E)
	if A >= G || B >= H || C <= E || D <= F {
		return area
	}
	top, bottom, left, right := math.Min(D, H), math.Max(B, F), math.Max(A, E), math.Min(C, G)
	return area - (top-bottom)*(right-left)
}
