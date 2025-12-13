def findLUSlength(a: str, b: str) -> int:
    if a == b:
        return -1
    return max(len(a), len(b))

a = input()
b = input()
print(findLUSlength(a, b))
