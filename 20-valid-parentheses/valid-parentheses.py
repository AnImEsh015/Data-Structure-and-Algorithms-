class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if i == '(' or i == '{' or i == '[':
                stack.append(i)
            else :
                if not stack :
                    return False
                char = stack[-1]

                if (i == ')' and char == '(') or (i == '}' and char == '{') or (i == ']' and char == '[') :
                    stack.pop()
                else :
                    return False
        return not stack
        