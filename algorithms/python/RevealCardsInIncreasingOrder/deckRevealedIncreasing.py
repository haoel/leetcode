def deckRevealedIncreasing(self, deck):
    deck.sort()
    res = [0] * len(deck)
    index = list(range(len(deck)))
    
    for i in range(len(deck)):
        res[index.pop(0)] = deck[i]
        if index: index.append(index.pop(0))
    return res