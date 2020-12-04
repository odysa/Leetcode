class Solution(object):
    def merge(self, intervals):
        if not intervals:
            return []
        intervals = sorted(intervals, key=lambda x: x[0])

        def overlap(l1, l2):
            if l1[1] < l2[0] or l1[0] > l2[1]:
                return False
            else:
                return True

        def merge_list(l1, l2):
            l1[0] = min(l1[0], l2[0])
            l1[1] = max(l1[1], l2[1])

        ans = [intervals[0]]
        for i in range(1, len(intervals)):
            if overlap(ans[-1], intervals[i]):
                merge_list(ans[-1], intervals[i])
            else:
                ans.append(intervals[i])
        return ans
