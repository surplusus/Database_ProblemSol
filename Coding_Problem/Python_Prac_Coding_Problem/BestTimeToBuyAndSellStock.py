# LeetCode - 121. Best Time to Buy and Sell Stock
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

def buyAndSell(self, prices: List[int]) -> int:
    min_price, max_profit = prices[0], 0
    for price in prices:
        min_price = min(min_price, price)
        max_profit = max(max_profit, price - min_price)
    return max_profit


buyAndSell([7, 1, 5, 3, 6, 4])
