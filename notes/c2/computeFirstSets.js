function computeFirstSets(grammar) {
    let firstSets = {};

    function addToFirstSet(nonTerminal, terminal) {
        if (!firstSets[nonTerminal]) {
            firstSets[nonTerminal] = new Set();
        }
        firstSets[nonTerminal].add(terminal);
    }

    function computeFirst(symbol) {
        if (!grammar[symbol]) {
            addToFirstSet(symbol, symbol);
            return;
        }

        for (let production of grammar[symbol]) {
            let firstSymbol = production[0];

            if (!grammar[firstSymbol]) {
                addToFirstSet(symbol, firstSymbol);
            } else {
                computeFirst(firstSymbol);

                for (let terminal of firstSets[firstSymbol]) {
                    addToFirstSet(symbol, terminal);
                }
            }
        }
    }

    for (let nonTerminal in grammar) {
        computeFirst(nonTerminal);
    }

    return firstSets;
}



let grammar = {
    'S': ['AB', 'BC'],
    'A': ['a', ''],
    'B': ['b', ''],
    'C': ['c', '']
};

let firstSets = computeFirstSets(grammar);


console.log("First sets:");
for (let nonTerminal in firstSets) {
    console.log(nonTerminal + ": " + Array.from(firstSets[nonTerminal]).join(', '));
}

