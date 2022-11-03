#include "AttributeTranslator.h"
#include <fstream>
AttributeTranslator::AttributeTranslator() {};

bool AttributeTranslator::Load(std::string filename) {
    return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
    std::vector<AttValPair> matches;
    std::set<AttValPair> s = *pairs.search(source.attribute + "," + source.value);
    for (AttValPair av: s) {
        matches.push_back(av);
    }
    return matches;
}
