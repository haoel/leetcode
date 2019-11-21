#Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#An input string is valid if:
#Open brackets must be closed by the same type of brackets.
#Open brackets must be closed in the correct order.
#Note that an empty string is also considered valid.

p_strings = '({}))'
def valid_parentheses(p_strings):
    stack=list()
    if len(p_strings ) == 0:
        return True
    else:
        for str in p_strings:
            if str == '(' or str == '{' or str == '[':
                stack.append(str)
            else:
                if len(stack) ==0:
                    return False
                else:
                    temp = stack.pop()
                    if ( str == ')' and temp == '(' ) or ( str == '}' and temp == '{' ) or ( str == ']' and temp == '[' ):
                        continue
                    else:
                        return False
        if len(stack) == 0:
            return True
        else:
            return False


print( valid_parentheses(p_strings) )
