#ifndef MatchMaker_h
#define MatchMaker_h
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
class MatchMaker {
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    std::vector<EmailCount> IdentifyRankedMatches(std::string email, int threshold) const;
private:
    MemberDatabase m_mdb;
    AttributeTranslator m_at;
};
#endif
