#include "MemberDatabase.h"
MemberDatabase::MemberDatabase() {}

bool MemberDatabase::LoadDatabase(std::string filename){
    return true;
}

std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const{
    return *avToEmail.search(input.attribute + "," + input.value);
}

const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const {
    return emailToProf.search(email);
}
