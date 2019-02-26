def diffWaysToCompute(self, input):
    return [a + b if c == '+' else a - b if c == '-' else a * b \
            for i, c in enumerate(input) if c in '+-*' \
            for a in self.diffWaysToCompute(input[:i]) \
            for b in self.diffWaysToCompute(input[i+1:])] or [int(input)]