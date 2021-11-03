package best_time_to_buy_and_sell_stock_121

func max(num1, num2 int) int {
	if num1 > num2 {
		return num1
	}
	return num2
}

func maxProfit(prices []int) int {
	maxP := 0
	if len(prices) == 1 {
		return maxP
	}
	lp, rp := 0, 1

	for rp < len(prices) {
		if prices[lp] < prices[rp] {
			profit := prices[rp] - prices[lp]
			maxP = max(maxP, profit)
			rp++
		} else {
			lp = rp
			rp++
		}
	}
	return maxP
}
