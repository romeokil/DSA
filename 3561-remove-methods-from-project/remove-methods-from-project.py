class Solution:
    def dfs(self,source,visited,suspicion,um):
        visited[source]=True
        suspicion.add(source)
        for v in um[source]:
            if visited[v] == False:
                self.dfs(v,visited,suspicion,um)

    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        result=[]
        suspicion=set()
        um=defaultdict(list)
        invoked_by=defaultdict(list)
        visited=[False]*n
        for u,v in invocations:
            um[u].append(v)
            invoked_by[v].append(u)

        self.dfs(k,visited,suspicion,um)

        canRemove=True
        for u in suspicion:
            for v in invoked_by[u]:
                if v not in suspicion:
                    canRemove=False
                    break
            if not canRemove:
                break

        if not canRemove:
            for i in range(n):
                result.append(i)
        else:
            for i in range(n):
                if i not in suspicion:
                    result.append(i)
        return result