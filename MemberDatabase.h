#ifndef MemberDatabase_h
#define MemberDatabase_h
#include "provided.h"
#include "PersonProfile.h"
#include <vector>
class MemberDatabase {
public:
    MemberDatabase();
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
private:
    RadixTree<std::vector<std::string>> avToEmail;
    RadixTree<PersonProfile> emailToProf;
};

#endif 
