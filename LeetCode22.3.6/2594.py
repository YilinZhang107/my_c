class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        ans = len(ranks) * [1]
        print(ans)
        return max(ans)


ability = [4, 2, 3, 1]
cars = 10
print(Solution.repairCars(ability, cars))
