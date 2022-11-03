#ifndef AttributeTranslator_h
#define AttributeTranslator_h
#include "provided.h"
#include <unordered_map>
#include <set>
#include <vector>
#include "RadixTree.h"
class AttributeTranslator {
public:
    AttributeTranslator();
    bool Load(std::string filename);
    std::vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
private:
    RadixTree<std::set<AttValPair>> pairs;
};
#endif
