class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = {src: [] for src, dst in tickets}
        tickets.sort()
        for src, dst in tickets:
            adj[src].append(dst)
        
        # reverse so we can pop from end efficiently
        for src in adj:
            adj[src].reverse()

        res = []

        def dfs(src):
            while adj.get(src):
                v = adj[src].pop()  # always pops smallest (from end)
                dfs(v)
            res.append(src)         # add AFTER all flights used

        dfs("JFK")
        return res[::-1]            # reverse at the end