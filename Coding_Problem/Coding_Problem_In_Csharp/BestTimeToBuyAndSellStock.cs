using System.Collections.Generic;

namespace Coding_Problem_In_Csharp {
    public class BestTimeToBuyAndSellStock {
        private int minPrice = 10001;
        private int maxProfit = 0;

        public int Calculate(IEnumerable<int> prices) {
            foreach (var price in prices) {
                minPrice = min(minPrice, price);
                maxProfit = max(maxProfit, price - minPrice);
            }

            return maxProfit;
        }

        int min(int n1, int n2) => (n1, n2) switch {
            var a when a.n1 < a.n2 => n1,
            var a when a.n1 > a.n2 => n2,
            _ => n1
        };

        int max(int n1, int n2) => (n1, n2) switch {
            var a when a.n1 > a.n2 => n1,
            var a when a.n1 < a.n2 => n2,
            _ => n1
        };
    }
}