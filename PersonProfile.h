#ifndef PersonProfile_h
#define PersonProfile_h
#include "provided.h"
#include <vector>
#include "RadixTree.h"
#include <set>
class PersonProfile {
public:
    PersonProfile(std::string name, std::string email);
    std::string GetName() const;
    std::string GetEmail() const;
    void AddAttValPair(const AttValPair& attval);
    int GetNumAttValPairs() const;
    bool GetAttVal(int attribute_num, AttValPair& attval) const;
private:
    std::string m_name;
    std::string m_email;
    int size;
    std::vector<AttValPair> attributes;
    RadixTree<std::set<std::string>> traits;
};

#endif
